<!DOCTYPE html>
<head>
    <title>IR FrameWorks</title>
    <meta author="Tucker Schulz">
    <meta name="description" content = "My module 3 open ended project for CS 2300">
    <link rel="stylesheet" href="css/custom.css" type="text/css">
</head>

<body class ="wrapper">
    <header class="header">
        <h1>Integrated Reporting Frameworks</h1>
        <h3>CS 2300</h3>
        <h3>M3OEP-taschulz</h3>
    </header>

    <section class="inputTitleSection">
        <h2>Enter your business's information</h2>

        <!-- getting the company name beforehand to create their csv file-->
        <form enctype="x/www-form-urlencoded" action="csvProcess.php" method="POST">
        <!-- user input -->
        <label for="company">Company name:</label>
            <input type="text" id="company" name="company" required><br>

            <input type="submit" value="Enter" name="enterSubmit">

        </form>

    </section>

</body>

</html>