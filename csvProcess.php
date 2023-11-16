<?php 
        //input validating company name
        $errorMessage = '';

        function getData($field){
            if (!isset($_POST[$field])){
                $data = "";
            } else{
                $data = trim($_POST[$field]);
                $data = htmlspecialchars($data);
            }
            return $data;
        }

        function verifyNoSpace($name){
            global $errorMessage;
            if(strpos($name, ' ') === false){
                return true;
            } else{
                $errorMessage .= '<p class="mistake">Company name cannot contain spaces (use _ instead)</p>';
                return false;   
            }
        }

        //get company name 
        $companyName = getData("company");

        if(verifyNoSpace($companyName)){

        //working directory
        $rand_number = rand();
        while(file_exists($rand_number)){
            $rand_number = rand();
        }
        $command_mkdir = escapeshellcmd("mkdir " . $rand_number);
        $output_mkdir = shell_exec($command_mkdir);
            
        //filepath puts {companyName}_assets.csv in the working directory
        $filePath = $rand_number . "/" . $companyName . "_assets.csv";

        //asset file
        $assetFile = fopen($filePath, "w"); //rightnow this is called everytime form submitted

        $csvHeader = "type,title,currency,value,description\n";
        fwrite($assetFile, $csvHeader);
        fclose($assetFile);

        //redirecturl goes to input php bringing company and the random number with
        $redirecturl = "input.php" . "?companyName=" . urlencode($companyName) . "&randNum=" . urlencode($rand_number);

        //redirect to input.php and pass along file path for future appendices
        header("Location: " . $redirecturl);
        exit();

    }else{
        echo $errorMessage; //testing 
    }    
    
    
?> 