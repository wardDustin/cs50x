<?php

    $w = $_POST["width"];
    $h = $_POST["height"];
    
    
// if we don't have a number, redirect back to the form page
if (empty($w) || empty($h)) {
    header("Location: ./mult_form.php");
    exit;
}

?>

<!DOCTYPE html>
<html>
    <head>
        <style>
            table, td {
                border: 1px solid blue;
                border-collapse: collapse;
                padding: 20px;
                text-align: center;
                background-color: red;
                color: white;
            }
        </style>
        <title>Your Table is Ready</title>
    </head>
    <body>
        <table>
            <?php for ($i = 1; $i <= $h; $i++): ?>
                <tr>
                    <?php for ($j = 1; $j <= $w; $j++): ?>
                    <td><?= $j * $i ?></td>
                    <?php endfor ?>
                </tr>
            <?php endfor ?>
        </table>
    </body>
</html>