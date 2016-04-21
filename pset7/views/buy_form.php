<form action="buy.php" method="post">
    <fieldset>
        <div class="form-group">
            <input class="form-control" autocomplete="off" type="text" name="stockToBuy" placeholder="Stock to buy" />
        </div>
        <div class="form-group">
            <input class="form-control" type="number" min="1" name="sharesToBuy" placeholder="Shares to buy" />
        </div>
        <div class="form-group">
            <button class="btn btn-default" type="submit">Buy</button>
        </div>
    </fieldset>
</form>