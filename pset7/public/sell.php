<?php
    // configure
    require("../includes/config.php");
    // if user gets to page via GET
    if ($_SERVER["REQUEST_METHOD"]=="GET"){
        // find the stock symbols and the amount of shares the user owns so they can be displayed for sales purposes
        $symbols = CS50::query("SELECT symbol, shares FROM portfolio WHERE user_id={$_SESSION['id']}");
        // then render form and send the data
        render("sell_form.php", ["title"=>"Sell", "symbols" => $symbols]);
    }
    else if ($_SERVER["REQUEST_METHOD"]=="POST"){
        // look up the stock to validate
        $stock = lookup($_POST["stock_symbol"]);
        // if not found, apologize
        if ($stock === false){
            apologize("Stock not found");
        }
        // check to make sure the user chose a stock or apologize
        if (empty($_POST["stock_symbol"])){
            apologize("You did not select a stock");
        }
        // check to see if they added the amount of shares to sell, if not, apologize
        if ($_POST["sharesToSell"]===""){
            apologize("You didn't choose how many shares of " . $stock["name"] . " to sell");
        }
        // get the amount of shares that the user owns from that stock
        $shares = CS50::query("SELECT shares FROM portfolio WHERE user_id=? AND symbol=?", $_SESSION["id"], $_POST["stock_symbol"]);
        // get to the correct array
        $shares_original = $shares[0]["shares"];
        // check to make sure the amount the user wants to sell is less than or equal to what the user owns
        if ($_POST["sharesToSell"]<= $shares_original){
            // keep the original amount to compare later
            $shares = $shares_original;
            // figure out how many shares the user has left over
            $shares = $shares - $_POST["sharesToSell"];
            // calculate the price of the shares sold
            $total = $_POST["sharesToSell"] * $stock["price"];
            // round them
            $total = $total*100;
            $total = round($total, 2);
            $total = $total/100;
            // if the user sells all of their stock, delete the stock entry else just update the shares
            if ($_POST["sharesToSell"] == $shares_original){
                CS50::query("DELETE FROM portfolio WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["stock_symbol"]);
            }
            else{
                CS50::query("UPDATE portfolio SET shares = ? WHERE user_id = ? AND symbol = ?", $shares, $_SESSION["id"], $_POST["stock_symbol"]);
            }
            // not dependant on the deletion or update, correct the cash amount the user has from the sale of the stock
            CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $total, $_SESSION['id']);
            // log the transaction
            CS50::query("INSERT INTO history(userID, time, symbol, shares, action, price) VALUES({$_SESSION['id']}, NOW(),  '". strtoupper($stock['symbol']) ."' , {$_POST['sharesToSell']}, 'SELL', '". number_format($stock['price'], 2, '.', ',')."')");
            
            redirect("/");
        } // if the shares the user wants to sell is MORE than the shares owned, apologize
        else{
            apologize("You don't have " . number_format($_POST['sharesToSell'], 0, '', ',') . " shares of " . $stock["name"] . "to sell");
        }
    }

?>