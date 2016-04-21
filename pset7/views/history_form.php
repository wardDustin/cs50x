<div id="test">
    <table class="table table-striped">
    
        <thead>
            <tr>
                <th>Transaction</th>
                <th>Date/Time</th>
                <th>Symbol</th>
                <th>Shares</th>
                <th>Price</th>
            </tr>
        </thead>
        <tbody>
            
    <?php foreach ($arr as $info): ?>
    
        <tbody>
            <tr>
                <td><?= strtoupper($info["action"]) ?></td>
                <td><?= $info["time"] ?></td>
                <td><?= $info["symbol"] ?></td>
                <td><?= $info["shares"] ?></td>
                <td>$<?= number_format($info["price"], 2, '.', ',') ?></td>
            </tr>
        </tbody>
        
    <?php endforeach ?>
    
    </table>
</div>