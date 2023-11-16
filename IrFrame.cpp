//
// Created by Tucker Schulz on 10/23/23.
//
#include "IrFrame.h" // Include your IrFrame header
#include <memory>     // Include the memory header for make_unique
#include "Asset.h"    // Include the header for the Asset class
#include <sstream>
//default 
IrFrame::IrFrame(){

}

IrFrame::IrFrame(string fileName) : fileName(fileName), assetsVector(getDataFromFile(fileName)) {
}


/***********************     getters     *********************************/


const vector<Asset> IrFrame::getAssetVector() const{
    return assetsVector;
}

//get asset by index
const Asset IrFrame::getAssetByIndex(int x) const{
    Asset iteratedAsset = assetsVector[x];
    return iteratedAsset;
}

const int IrFrame::getAssetVectorSize(){
    return assetsVector.size();
}

/*Thought process for getters*/
// TODO: come back and finish after assets vector has been better defined
// const vector<unique_ptr<Asset>>& IrFrame::getFinancialVector(){

//     vector<unique_ptr<Asset>> financialVector;

//     //pasrse through vector searching types == "financial"

//     // for(int i = 0; i < AssetsVector.size()-1; i++){
//     //     if(AssetsVector[i]. == "financial")
//     // }

//     return financialVector;
// }

/* getDataFromFile */
vector<Asset> IrFrame::getDataFromFile(string fileName){

    //vector for return
    vector<Asset> vec;

    //variable declaration
    ifstream inFile;
    string header;
    char comma = ',';

    //opening the file
    inFile.open(fileName);
    //open file test
    if(inFile){
        //cout << " <p> File can be read from" << endl; line for testing fstream
        //read full line from file into header string
        getline(inFile, header);
        // cout << header << "</p>" << endl;
    }


    //declare variables to be read in
    string type = "", title = "", currency = "", description ="";
    double value = 0;

    //loop to read through file
    while(inFile && inFile.peek() != EOF){

        //type
        getline(inFile, type, ',');

        //title
        getline(inFile, title, ',');

        //currency
        getline(inFile, currency, ',');

        //vaule
        string valueStr;
        getline(inFile, valueStr, ',');
        //using 
        stringstream ss(valueStr);
        ss >> value;


        //description
        getline(inFile, description, '\n');


        Asset newAsset = (Asset(type, title, currency, value, description));

        vec.push_back(newAsset);
    }    

    return vec;

}