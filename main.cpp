//created by Tucker Schulz 10/27/23
#include "IrFrame.h"
using namespace std;

//my machine uses pthon3
const string python = "python";

int main(int argc, char *argv[]){

    //get asset fileName from cmd line
    string fileName = argv[1];


    // cout << "<p>" << fileName << "</p>" << endl; //testing file name

    //irFrame object 
    IrFrame framework = IrFrame(fileName);


    cout << "<link rel='stylesheet' href='css/custom.css' type='text/css'>" << endl;
    //table
    //cout << "<p>" << framework.getAssetVectorSize() << "</p><br>" << endl; //testing for vector size
    cout << "<table>\n<tr><th>Type</th><th>Title</th><th>Currency</th><th>Value</th><th>Description</th></tr>" << endl;

    //loop for printing rows
    for(int i = 0; i < framework.getAssetVectorSize(); i++){
        Asset iteratedAsset = (framework.getAssetByIndex(i));

        cout << "<tr><td>" << iteratedAsset.getClassType() << "</td><td>" << iteratedAsset.getTitle() << "</td><td>" << iteratedAsset.getCurrency() 
            << "</td><td>" << iteratedAsset.getCapitalValue() << "</td><td>" << iteratedAsset.getDescription() << "</td></tr>" << endl;
    }

    cout << "</table>";

    //cout an image statement

    cout << "<p>";

    //python call and graphing 
    string command = python + " graphs.py " + fileName + " 2>&1";
    system(command.c_str());


    //cout closing image statmenet
    cout << "</p>" << endl ;

    return 0;
    
}
