//
// Created by Tucker Schulz on 10/23/23.
//
//includes
#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>
#include "Asset.h"

using namespace std;

class IrFrame{

private:

    //declaration
    string fileName; 
    vector<Asset> assetsVector;

public:

    IrFrame();

    IrFrame(string fileName);

     /**** getters ****/

    const vector<Asset> getAssetVector() const;

    const Asset getAssetByIndex(int x)const;

    const int getAssetVectorSize();

     //since I am storing all assets in one vector, the getVector functions will 
     //return the address of a vector that has been filtered ofr it type
//    const vector<unique_ptr<Asset>>& getFinancialVector();
//
//    const vector<unique_ptr<Asset>>& getManufacturedVector();
//
//    const vector<unique_ptr<Asset>>& getIntellectualVector();
//
//    const vector<unique_ptr<Asset>>& getHumanVector();
//
//
//    const vector<unique_ptr<Asset>>& getSocialVector();
//
//    const vector<unique_ptr<Asset>>& getNaturalVector();

    vector<Asset> getDataFromFile(string fileName);
};
