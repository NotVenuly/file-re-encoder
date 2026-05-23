#include "Filereader.h"
#include "Filetransformer.h"
#include "filewriter.h"

#include <string> 
#include <iostream>

using namespace std;

string AskFileName(string jsonFilePath, string jsonFile){
    string jsonFileName;
    cout << "Type the name you want for your JSON file: ";
    getline(cin, jsonFileName);
    if(jsonFileName != ""){
        return jsonFileName;
    }
    else{
        cout << "Please do not input an empty string" << endl;
        return AskFileName(jsonFilePath, jsonFile);
    }
}

int main(){

    // variable for checking if the whole code is executed
    bool done = false;


    while(!done){
        string jsonFilePath;
        string jsonFileName;

        string openedFile = OpenFile();

        if(openedFile == ""){
            cout << "Please do not input an empty string" << endl;
            continue;
        }

        cout << "opened file: " << openedFile << std::endl;

        string jsonFile = TransformFile(openedFile);
        cout << "JSON file: " << jsonFile << std::endl;

        cout << "Paste the address of the folder you want your JSON file to be saved at: ";
        getline(cin, jsonFilePath);

        bool validName = false;
        
        // as long as user doesn't input the correct name keep running this code
        while (!validName) {

            jsonFileName = AskFileName(jsonFilePath, jsonFile);
            int result = WriteFile(jsonFilePath, jsonFileName, jsonFile);

            if (result == 1) {
                validName = false;
                done = false;
            } else if (result == 0) {
                done = true;
                validName = true;
            }
        }
    }

    return 0;
}