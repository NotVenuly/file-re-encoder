#include "Filereader.h"
#include "Filetransformer.h"

#include <string> 
#include <iostream>

using namespace std;

int main(){
    string openedFile = OpenFile();
    cout << "opened file: " << openedFile << std::endl;
    string jsonFile = TransformFile(openedFile);
    cout << "JSON file: " << jsonFile << std::endl;
    return 0;
}