//
// Created by Tucker Schulz on 10/23/23.
//
#include "Asset.h"
//default
Asset::Asset() : type(""), title(""), currency(""), capitalValue(0.0), description("") {
}
//initializer list
Asset::Asset(string aType, string aTitle, string aCurrency, double aValue, string aDescription):
    type(aType), title(aTitle), currency(aCurrency), capitalValue(aValue), description(aDescription){}

//getters
string Asset::getType() const{
    return type;
}
string Asset::getTitle() const{
    return title;
}

string Asset::getCurrency() const{
    return currency;
};

double Asset::getCapitalValue() const{
    return capitalValue;
}

string Asset::getDescription() const {
    return description;
}

string Asset::getClassType() const {
    return type;
}

//setters
void Asset::setType(string newType){
    type = newType;
}
void Asset::setTitle(string newTitle){
    title = newTitle;
}

void Asset::setCurrency(string newCurrency){
    currency = newCurrency;
}

void Asset::setCapitalValue(double newValue){
    capitalValue = newValue;
}

void Asset::setDescription(std::string newDescription) {
    description = newDescription;
}

//TODO: replace cin with getlines
/******** Other Functions *********/
void Asset::getAssetData() {

    const int MAX_TITLE_LENS = 60;
    const int MAX_CURRENCY_LENS = 10;
    const int MAX_DESCRIPTION_LENS = 200;


    string title, currency, description;
    double capitalValue;


    cout << "Enter asset title: ";
    getline(cin, title);

    cout << "Enter asset currency: ";
    getline(cin, currency);

    cout << "Enter asset capital value: ";
    cin >> capitalValue;
    cin.ignore();

    cout << "Enter asset description: ";

    getline(cin, description);

    setTitle(title);
    setCurrency(currency);
    setCapitalValue(capitalValue);
    setDescription((description));

}
