<?php

// include the helper file
require("../includes/helpers.php");


// get all the greeting rows from the database
$greeting_rows = CS50::query("SELECT * FROM greetings");

// RENDER STUFF --------------------

$header_data = ["title" => "Greetings"];
render("header.php", $header_data);

//add a key, value pair to send the array and the ability to index into the array
$form_data = ["greeting" => $greeting_rows];

render("greeting_form.php", $form_data);

render("footer.php");

?>

