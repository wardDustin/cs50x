
<h1>Build Your Greeting</h1>
<form action="greet.php" method="POST"/>
    <label>Your name:</label>
    <input type="text" name="recipient_name" />
    <br/>
    <label>Select a greeting:</label>
    <select name="select_greeting">
        <option value="blank"></option>
        <!-- Adding this php to autogenerate the option values so when someone creates a custom greeting
        it is saved into the form... $greeting is an array, so this iterates through the array and gets
        each greeting-->
        <?php
        
        foreach($greeting as $greets){
            echo ("<option value=\"{$greets['text']}\">{$greets['text']}</option>");
        }
        
        ?>
    </select>
    <label>Or create your own:</label>
    <input type="text" name="custom_greeting" />
    <br/>
    <input type="submit"/>
</form>
