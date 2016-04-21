<?php
    extract($data);
    // gives the greeting to the person
    $message = "{$greeting_text}, {$recipient_name}";
    
    // shows how many times the greeting has been used
    $report_num_times = "This is the {$num_times}th time I have said '{$greeting_text}' to someone"

?>

<h2><?= htmlspecialchars($message) ?></h2>
<p><?= htmlspecialchars($report_num_times) ?></p>