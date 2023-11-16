//
// Created by Tucker Schulz on 10/23/23.
//
#ifndef M2OEP_TASCHULZ_ASSET_H
#define M2OEP_TASCHULZ_ASSET_H
#include <iostream>
#include <iomanip>
using namespace std;
class Asset {

private:

    //initializers
    string type, title, currency, description;
    double capitalValue;

    
    

public:

    //default
    Asset();

    //with parameters
    Asset(string aType, string aTitle, string aCurrency, double aValue, string aDescription);

    //getters
    string getType() const;

    string getTitle() const;

    string getCurrency() const;

    double getCapitalValue() const;

    string getDescription() const;

    virtual string getClassType() const;

    //setters
    void setType(string newType);

    void setTitle(string newTitle);

    void setCurrency(string newCurrency);

    void setCapitalValue(double newValue);

    void setDescription(string newDescription);


    //additional functions


    //TODO: once finished with getAssetData() streamline asset creation for all types from main
    //getAssetData
    void getAssetData();


    //overloaded operators
    //ostream
    friend ostream& operator << (ostream& outs, const Asset& asst) {   
        outs << left << setw(20) << asst.getTitle() 
            << right << setw(10) << asst.getCurrency() << setw(10) << asst.getCapitalValue();
        return outs;
    }

};
#endif //M2OEP_TASCHULZ_ASSET_H
