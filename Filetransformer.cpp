#include "Filereader.h"
#include <iostream>
#include <list>
#include <string>
#include <vector>


using namespace std;

string TransformFile(string fileContent) {
  vector<int> lineEnd;
  string currString;
  list<string> allLines;
  int lineCount;
  for (int i = 0; i < fileContent.length() - 1; i++) {
    currString = currString + fileContent[i];
    if (fileContent[i] == '\n') {
      allLines.push_back(currString);
      currString = "";
      lineEnd.push_back(i);
      lineCount++;
    }
  }
}