<?php
    // configure
    require("../includes/config.php");
    // if method is GET
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("quote_form.php", ["title" => "Quote"]);
    }
    // if method is POST
    else if ($_SERVER["REQUEST_METHOD"] == "POST"){
        // make sure the user has inputted a stock
        if (empty($_POST["symbol"])){
            apologize("Stock symbol field is empty!");
        }
        // make sure the stock symbol is valid
        $stock = lookup($_POST["symbol"]);
        // if not, apologize
        if ($stock === false){
            apologize("Stock not found!");
        }
        // format the number for display
        $stock_price = number_format($stock["price"], 2, '.', ',');
        // send stock information through render
        render("quote.php", ["title" => strtoupper("{$_POST['symbol']}"), "stock_price" => $stock_price, "stock"=>$stock]);
    }
?>