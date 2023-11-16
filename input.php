<!DOCTYPE html>
<head>
    <title>IR FrameWorks</title>
    <meta author="Tucker Schulz">
    <meta name="description" content = "The form page for my module 3 open ended project for CS 2300">
    <link rel="stylesheet" href="css/custom.css" type="text/css">
</head>

<body class="wrapper">
    <header class="header">
        <h1>Integrated Reporting Frameworks</h1>
        <h3>CS 2300</h3>
        <h3>M3OEP-taschulz</h3>
    </header>

    <section class="inputSection">
        <h2 style="text-align: center;">Form</h2>
        <form enctype="/x-www-form-urlencoded" action="#" method="POST">

        <!-- get asset type-->
        <label for="assetType">Choose Asset Type: </label>
        <select name="assetType" id="assetType"> 
            <option value="financial">Financial</option>
            <option value="manufactured">Manufactured</option>
            <option value="intellectual">Intellectual</option>
            <option value="human">Human</option>
            <option value="social">Social</option>
            <option value="natural">Natural</option>
        </select><br>

        <br>

        <!-- get asset title, value, currency, and description-->
        <label for="title">Title:</label>
        <input type="text" id="title" name="title" required><br>

        <br>

        <label for="currency">Currency:</label>
        <select name="currency" id="currency">
            <option value="usd">USD</option>
            <option value="eur">EUR</option>
            <option value="jpy">JPY</option>
            <option value="gbp">GBP</option>
            <option value="aud">AUD</option>
            <option value="cad">CAD</option>
            <option value="chf">CHF</option>
            <option value="cnh">CNH</option>
            <option value="hkd">HKD</option>
            <option value="usd">USD</option>
            <option value="nzd">NZD</option>
        </select><br>

        <br>

        <label for="value">Value:</label>
        <input type="number" id="value" name="value"><br>

        <br>

        <label for="description">Description:</label><br>
        <input type="text" id="description" name="description" style="width: 200px; height: 100px;"><br>

        <br>

        <label for="addAsset">Add Asset</label>
        <input type="submit" value="addAsset" name="actionAddAsset" id="submitAddAsset">

        <br>

        <label for="submit">Submit</label>
        <input type="submit" value="submit" name="actionSubmit" id="submitSubmit">

        </form>

    </section>    
    
    <?php include "process.php"; ?>

    <section class="displaySection">
        <h2 style="text-align: center;">Graphs and Visuals</h2>

        <!-- Table displaying vectors added-->
        <table class="assetTable">
            <!--Labels -->
            <?php echo $output ?>
            <!--refresh and add assets to table as added -->


        </table>
        <!-- Python graphs -->
        <figure>
            <img src=<?php echo $piGraphPath?> alt="Asset Diversity Display">
            <figcaption>Fig.1 - Pie Graph of Asset Diversity.</figcaption>
        </figure>


    </section>

</body>