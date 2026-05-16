#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(){

    string fileAddress;
    
    cout << "Type the address of the file you want to re-encode: ";
    getline(cin, fileAddress);
    ifstream myFile;
    myFile.open(fileAddress);
    cout <<"File name: "<< myFile.is_open()<<endl;

    if(myFile.is_open()){
        string line;
        int lineNumber = 1;
        while (getline(myFile, line))
        {
            cout << lineNumber++ << ". " << line << endl;
        }
        
    }
    myFile.close();
    return 0;
}

void Trim(string* address, int index){
    int length = (*address).length();
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