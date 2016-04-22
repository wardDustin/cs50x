<?php

require("../includes/helpers.php");

// extract the $_POST dictionary into local variables (e.g. $recipient_name, $select_greeting, $custum_greeting etc)
extract($_POST);

// VALIDATION ----------------------------------------------

// if the user didn't type their name, redirect back to the form OR they don't give a greeting at all
if (empty($recipient_name) || $select_greeting == "blank" && empty($custom_greeting))
{
    header("Location: index.php");
}



// DETERMINE GREETING TEXT -------------------------------

// decide what the greeting text (e.g. "What is up") should be. 
// by default, use whatever was chosen from the <select> menu
$greeting_text = $select_greeting;
// if there is a custom greeting, use that instead
// create_new_greeting is a function that simply populates the greeting in the database via a query in mySQL
if ($custom_greeting!==''){
    $greeting_text = $custom_greeting;
    create_new_greeting($custom_greeting);
}




// UPDATE `num_times` ---------------------------------------

// This checks the database for num_times but it returns an array we can't use yet
$new_num_times = CS50::query("SELECT num_times FROM greetings WHERE text = '{$greeting_text}'");
// array_pop gets us the part of the array we need (num_times)
$new_num_times = array_pop($new_num_times)["num_times"];
// starts new_num_times at one and subsequently adds one each time the same $greeting_text is called
++$new_num_times;
// sends the updated $new_num_times back into the database
CS50::query("UPDATE greetings SET num_times = {$new_num_times} WHERE text = '{$greeting_text}'");




// RENDER STUFF -------------------------------------------

render("header.php", ["title" => $greeting_text]);
// packs all the data we need into an associative array to send to 
$data = [
    "num_times" => $new_num_times, 
    "recipient_name" => $recipient_name,
    "greeting_text" => $greeting_text,
];

render("greeting_display.php", $data);

render("footer.php");

?>