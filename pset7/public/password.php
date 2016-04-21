<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // render form
        render("password_form.php", ["title" => "Change PW"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST"){
        if (empty($_POST["current"]) || empty($_POST["newPassword"]) || empty($_POST["confirmation"])){
            apologize("You left a field blank");
        }
        
        // CS50::query("");
        
        // query database for user
        $rows = CS50::query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);

        // first (and only) row
        $row = $rows[0];

        // compare hash of user's input against hash that's in database... if they do not match apologize... if the newpassword and confirmation
        // don't match, apologize... if all of that passes, update the hash and congratulate them on changing their password
        if (!password_verify($_POST["current"], $row["hash"]))
        {
            apologize("Incorrect current password");
        }
        else{
            if ($_POST["newPassword"]!==$_POST["confirmation"]){
                apologize("Password fields did not match");
            }
            
            CS50::query("UPDATE users SET hash = ? WHERE id = ?", password_hash($_POST["newPassword"], PASSWORD_DEFAULT), $_SESSION["id"]);
            
            congratulate("You have now changed your password");
        }
        
    }
?>

