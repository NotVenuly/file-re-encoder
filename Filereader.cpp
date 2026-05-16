#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Trim(string* address, int index){
    int length = (*address).length()-1;
    if (index != length){
        for (int i=index; i<length; i++){
            (*address)[i] = (*address)[i+1];
        }
        address->pop_back();
    }
    else{
        address->pop_back();
    }
}

void OpenFile(){
    string fileAddress;
    
    cout << "Type the address of the file you want to re-encode: ";
    getline(cin, fileAddress);
    if(fileAddress[0] == '"'){

        Trim(&fileAddress, 0);
        Trim(&fileAddress, fileAddress.length()-1);
    }
    ifstream myFile;
    myFile.open(fileAddress);
    if(myFile.is_open() != 1){
        cout << "Something went wrong with opening the file" << endl;
        OpenFile();
    }

    if(myFile.is_open()){
        string line;
        int lineNumber = 1;
        while (getline(myFile, line))
        {
            cout << lineNumber++ << ". " << line << endl;
        }
        
    }
    myFile.close();
}

int main(){
    OpenFile();
    return 0;
}
