<?php

    // configuration
    require("../includes/config.php"); 

    // log out current user, if any
    logout();
    
    // end session
    session_destroy();

    // redirect user
    redirect("/");

?>
