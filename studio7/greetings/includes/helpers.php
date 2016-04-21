<?php

// include the CS50 library
require("../vendor/library50-php-5/CS50/CS50.php");

// initialize connection to the database
CS50::init(__DIR__ . "/../config.json");


function render($template, $data=[])
{
    $path = "../views/" . $template;
    
    if (file_exists($path)){
        extract($data);
        require($path);
    }
}


function create_new_greeting($new_greeting)
{
    // inserts the new_greeting into the database but ignores it if it exists already
    $newRow = "INSERT IGNORE INTO greetings (text) VALUES ('{$new_greeting}')";
    CS50::query($newRow);
    
}


?>