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

// checks the last (charAmount) characters of the given name
// example: if charAmount = 2 and file name is hello
// returns lo
std::string CheckLastCharacters (std::string fileName, int charAmount){
    std::string addedCharacters;
    if(charAmount > fileName.length()){
        return fileName;
    }
    else{
        int changedLength = fileName.length()-charAmount;

        for(int i = 0; i<charAmount; i++){
            addedCharacters = addedCharacters+fileName[changedLength+i];
        }

    }
    return addedCharacters;
}

// function returns an int instead of a boolean since there is 3 possible cases
// 1 means something went wrong and it will start the whole process again
// 0 means executed succesfully
// 2 means something went wrong with naming and just try the naming again
int WriteFile(std::string filePath, std::string fileName, std::string fileContent){
    std::ofstream newFile;
    // if the file name is empty return 2 to just try the  file name again
    if(fileName.empty()){
        std::cout<<"Please write a new name" << std::endl;
        return 2;
    }

    // check for the last 5 characters of the file name to see if the user wrote .json themselves for the file name
    std::string lastCharacters = CheckLastCharacters(fileName, 5);
    if (filePath[0] == '"' && filePath.length() > 2) {
        TrimEdges(&filePath);
    }

    // dont add file extension if user wrote it 
    if(lastCharacters == ".json"){
        filePath = filePath + "\\" + fileName;
    }

    // add .json extension if user didn't write it
    else{

        filePath = filePath + "\\" + fileName + ".json";
    }

    // add the formatted file content to the created json file
    newFile.open(filePath);
    if (newFile.is_open()){
        newFile << fileContent;
        newFile.close();
        return 0;
    }
    return OpenFileError();
    
}