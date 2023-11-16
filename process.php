<?php

    $companyName = urldecode($_GET['companyName']);
    $directoryKey = urldecode($_GET['randNum']);


    $assetFile = $directoryKey . "/" . $companyName . "_assets.csv";

    function getData($field){
        if (!isset($_POST[$field])){
            $data = "";
        } else{
            $data = trim($_POST[$field]);
            $data = htmlspecialchars($data);
        }
        return $data;
    }

    //get action command
    if($_SERVER["REQUEST_METHOD"] == "POST"){
        // Check which button was clicked
        if (isset($_POST["actionAddAsset"])) {
            $action = "addAsset";
            
        } elseif (isset($_POST["actionSubmit"])) {
        $action = "submit";
        }
    }

    //replacing get variables with function to trim html chars
    $type = getData("assetType");
    $title = getData("title");
    $currency = getData("currency");
    $value = getData("value");
    $description = getData("description");

        

    //if value = addAsset then just push onto a file
    if($action == "addAsset"){

        //filewriter 
        $assetAppend = fopen($directoryKey . "/" . $companyName . "_assets.csv", 'a'); 
        $txt = $type . "," . $title . "," . $currency . "," .(float)$value . "," . $description . "\n";
        
        //writes to ---asset.csv
        fwrite($assetAppend, $txt);
        fclose($assetAppend);


    }

    //if submit process full c++ program
    else if($action == "submit"){

        //first write any final input to the file
        //filewriter 
        $assetAppend = fopen($directoryKey . "/" . $companyName . "_assets.csv", 'a'); 
        $txt = $type . "," . $title . "," . $currency . "," .(float)$value . "," . $description . "\n";
        
        //writes to ---asset.csv
        fwrite($assetAppend, $txt);
        fclose($assetAppend);

        
        //call c++
        $command_cp = escapeshellcmd("cp *.h *.cpp " . $rand_number);
        $output_cp = shell_exec($command_cp);

        //TODO: make output correct 
        $output = shell_exec("cd " . $rand_number . ";g++ -std=c++1y -o program.exe main.cpp IrFrame.cpp Asset.cpp; ./program.exe " . $assetFile . ";"); //commented out "; cd .."

        //display/redirect with output
        //echo $output;

        $piGraphPath = "piGraphs/" . $directoryKey . ".png";
        //delete directory and subsequet files

        //right now this causes errors for my if you want to add more assets after submitting
        // event listener to execute on close?

        // array_map("unlink", glob($directoryKey . "/*"));
        // rmdir($directoryKey);

    }   
    

?>
 
