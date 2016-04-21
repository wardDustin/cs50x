<?php
    // configure
    require("../includes/config.php");
    // if user got to the page via GET 
    if ($_SERVER["REQUEST_METHOD"]=="GET"){
        // render page
        render("buy_form.php", ["title"=>"Buy"]);
    }
    else if ($_SERVER["REQUEST_METHOD"]=="POST"){
        // if stock is empty, apologize
        if (empty($_POST["stockToBuy"])){
            apologize("You did not select any stock to buy");
        }
        // lookup stock
        $stock = lookup($_POST["stockToBuy"]);
        // if shares is empty, apologize
        if ($_POST["sharesToBuy"]===""){
            apologize("You didn't choose how many shares of " . $stock['name'] . " to buy");
        }
        // didn't need to use this function due to the input type=number
        // not using it also lets the user put in decimals (only if .0)
        // if (preg_match("/^\d+$/", $_POST["sharesToBuy"])!==true){
        //     apologize("You can only buy full shares of stocks!");
        // }
        
        // if the stock lookup returns false, apologize
        if ($stock === false){
            apologize("Stock not found");
        }
        // get the amount of cash the user currently owns
        $cash = CS50::query("SELECT cash FROM users WHERE id={$_SESSION['id']}");
        // get to the correct array
        $cash = $cash[0]["cash"];
        // calculate expense of the shares
        $expense = $_POST["sharesToBuy"] * $stock["price"];
        // check to make sure the user has enough cash to buy that amount of stock
        if ($expense>$cash){
            apologize("You cannot afford " . number_format($_POST['sharesToBuy'], 0,'.',',') . " shares of " . $stock["name"]);
        }
        // insert the stock and amount of shares for the user... if there is already shares of that stock, add the stock onto what is already owned
        CS50::query("INSERT INTO portfolio (user_id, symbol, shares) VALUES ({$_SESSION['id']},  '". strtoupper($stock['symbol']) ."' , {$_POST['sharesToBuy']}) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)");
        // deduct the expense of the purchase from the user's cash
        CS50::query("UPDATE users SET cash = cash - {$expense} WHERE id={$_SESSION['id']}");
        // log the transaction
        CS50::query("INSERT INTO history(userID, time, symbol, shares, action, price) VALUES({$_SESSION['id']}, NOW(),  '". strtoupper($stock['symbol']) ."' , {$_POST['sharesToBuy']}, 'BUY', '". number_format($stock['price'], 2, '.', ',')."')");
        // redirect to portfolio
        redirect("/");
        
    }
    
?>