<?php
    // configure
    require("../includes/config.php");
    // if the method is get
    if ($_SERVER["REQUEST_METHOD"]=="GET"){
        // render
        render("deposit_form.php", ["title"=>"Add Funds"]);
    }
    else if ($_SERVER["REQUEST_METHOD"]=="POST"){
        // you cannot deposit less than a dollar
        if ($_POST["funds"]<1){
            apologize("Choose a positive amount to deposit");
        }
        // check how much cash the user already has
        $cash = CS50::query("SELECT cash FROM users WHERE id=?", $_SESSION["id"]);
        // get to the correct array
        $cash = $cash[0]["cash"];
        // update the cash amount
        CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $_POST["funds"], $_SESSION["id"]);
        // congratule the user on depositing cash
        congratulate("You have now deposited $" . $_POST["funds"] . " into your account");
        
    }


?>