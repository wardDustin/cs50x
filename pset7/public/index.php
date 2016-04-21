<?php

    // configuration
    require("../includes/config.php"); 
    // get symbol and shares from the database
    $rows = CS50::query("SELECT symbol, shares FROM portfolio WHERE user_id=?", $_SESSION["id"]);
    // get the user's cash
    $cash = CS50::query("SELECT cash FROM users WHERE id=?", $_SESSION["id"]);
    // correct array
    $cash = $cash[0]["cash"];
    // declare an empty array to hold pertinent data and send through render
    $positions = [];
    
    foreach ($rows as $row)
    {
        // get the stock's information and store it in the empty array
        $stock = lookup($row["symbol"]);
        
        if ($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"]
            ];
        }
        else{
            apologize("Stock not found");
        }
    }

    // render portfolio, send cash and the data from the array
    render("portfolio.php", ["positions"=> $positions, "title" => "Portfolio", "cash"=> $cash]);

?>
