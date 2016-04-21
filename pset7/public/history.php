<?php
    // configure
    require("../includes/config.php");
    // get the whole user's history
    $rows = CS50::query("SELECT * FROM history WHERE userID = ?", $_SESSION["id"]);
    // create an array to send through render
    $arr = [];
    // get the correct array and use associative array to store the data
    foreach ($rows as $row){
        $arr[] = [
            "time"=>$row["time"],
            "symbol"=>$row["symbol"],
            "shares"=>$row["shares"],
            "action"=>$row["action"],
            "price"=>$row["price"]
            ];
    }
    // render and send
    render("history_form.php", ["title"=>"History", "arr"=>$arr]);
    
?>