#include <string>
#include <iostream>
#include <fstream>
#include "Filereader.h"

int OpenFileError(){
    char replayAnswer;
    std::cout << "Something went wrong with opening the file" << std::endl;
    std::cout << "Perhaps the address had a typo, or you dont have access to the file" << std::endl;
    std::cout << "would you like to try again?" << std::endl;
    std::cout << "Y/N yes or no:";
    std::cin >> replayAnswer;
    std::cin.ignore();
    if((char)std::tolower(replayAnswer) == 'y'){
        return 1;
    }
    else if((char)std::tolower(replayAnswer) == 'n'){
        return 0;
    }
    else{
        std::cout << "please input a correct commmand";
        return OpenFileError();
    }
}

std::string CheckLastCharacters (std::string str, int charAmount){
    std::string addedCharacters;
    if(charAmount > str.length()){
        return str;
    }
    else{
        int changedLength = str.length()-charAmount;

        for(int i = 0; i<charAmount; i++){
            addedCharacters = addedCharacters+str[changedLength+i];
        }

    }
    return addedCharacters;
}

int WriteFile(std::string filePath, std::string fileName, std::string fileContent){
    std::ofstream newFile;
    if(fileName.empty()){
        std::cout<<"Please write a new name" << std::endl;
        return 2;
    }
    std::string lastCharacters = CheckLastCharacters(fileName, 5);
    if (filePath[0] == '"' && filePath.length() > 2) {
        TrimEdges(&filePath);
    }
    if(lastCharacters == ".json"){
        filePath = filePath + "\\" + fileName;
    }
    else{

        filePath = filePath + "\\" + fileName + ".json";
    }

    newFile.open(filePath);
    if (newFile.is_open()){
        newFile << fileContent;
        newFile.close();
        return 1;
    }
    return OpenFileError();
    
}