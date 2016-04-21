<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // if any field is empty, apologize
        if (empty($_POST["username"]) || empty($_POST["password"]) || empty($_POST["confirmation"])){
            apologize("Username and/or password are blank!");
        }
        // if the password is not confirmed, apologize
        if ($_POST["password"]!==$_POST["confirmation"]){
            apologize("The password fields did not match. Please try again!");
        }
        // insert the username, password hash and cash, ignoring the query if there is already a user by that username
        $result = CS50::query("INSERT IGNORE INTO users (username, hash, cash) VALUES(?, ?, 10000.0000)", $_POST["username"], password_hash($_POST["password"], PASSWORD_DEFAULT));
        // query will return 0 if there is a duplicate user, so... apologize
        if ($result === 0){
            apologize("Duplicate username!");
        }
        // if all checks out, grab the last inserted ID
        $rows = CS50::query("SELECT LAST_INSERT_ID() AS id");
        // get directly to the id
        $id = $rows[0]["id"];
        // assign that id to the session
        $_SESSION["id"] = $id;
        // go to index
        redirect("/");
        
    }

?>