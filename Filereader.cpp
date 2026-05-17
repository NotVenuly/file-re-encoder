#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void Trim(string* address){
    int length = (*address).length()-1;
    cout << "length is: " << length << endl;
    for (int i=0; i<length; i++){
        (*address)[i] = (*address)[i+1];
        cout << (*address) << endl;
        cout << "i is: " << i << endl;
    }
    address->pop_back();
    address->pop_back();
    
}


string OpenFile(){
    string fileAddress;
    
    cout << "Type the address of the file you want to re-encode: ";
    getline(cin, fileAddress);
    if(fileAddress[0] == '"'){
        Trim(&fileAddress);
    }
    ifstream myFile;
    myFile.open(fileAddress);
    
    if(myFile.is_open()){
        stringstream ss;
        string line;
        while (getline(myFile, line))
        {
            ss << line << endl;
        }
        string result = ss.str();
        return result;
    }
    cout << "Something went wrong with opening the file" << endl;
    myFile.close();
    return "";
}

int main(){
    string file = OpenFile();
    return 0;
}
