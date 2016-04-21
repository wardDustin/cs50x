<form action="sell.php" method="post">
    <fieldset>
        <div class="form-group">
            <select class="form-control" name="stock_symbol">
                <option disabled selected value="empty">Stock | Shares</option>
                <?php foreach($symbols as $stock_symbol): ?>
                
                <option value="<?= $stock_symbol['symbol'] ?>"><?= strtoupper($stock_symbol['symbol']) . " | " . $stock_symbol["shares"] ?></option>
                
                <?php endforeach ?>
            </select>
            <input class="form-control" type="number" min="1" name="sharesToSell" placeholder="Shares to sell" />
        </div>
        <div class="form-group">
            <button class="btn btn-default" type="submit">Sell</button>
        </div>
    </fieldset>
</form>
