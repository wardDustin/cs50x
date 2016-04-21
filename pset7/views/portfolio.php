<div id="test">
    <table class="table table-hover table-striped">
        <thead>
            <tr>
                <th>Symbol</th>
                <th>Name</th>
                <th>Shares</th>
                <th>Price</th>
                <th>TOTAL</th>
            </tr>
        </thead>
        
    <?php foreach ($positions as $position): ?>
    <?php $total = $position["price"] * $position["shares"] ?>
    
        <tbody>
            <tr>
                <td><?= strtoupper($position["symbol"]) ?></td>
                <td><?= $position["name"] ?></td>
                <td><?= $position["shares"] ?></td>
                <td>$<?= number_format($position["price"], 2, '.', ',') ?></td>
                <td>$<?= number_format($total, 2, '.', ',') ?></td>
            </tr>
        </tbody>
        
    <?php endforeach ?>
    
        <tfoot>
            <tr>
                <th>Cash</th>
                <th></th>
                <th></th>
                <th></th>
                <th>$<?= number_format($cash, 2, '.', ',') ?></th>
            </tr>
        </tfoot>
    </table>
</div>