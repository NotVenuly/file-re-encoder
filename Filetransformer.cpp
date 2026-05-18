#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

string TransformFile(string fileContent) {

  cout << "STARTED TRANSFORM" << endl;
  vector<int> lineEnd;
  string currString;
  string output;
  vector<string> allLines;
  string strAllLines;
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
  if (currString != ""){
    allLines.push_back(currString);
    currString = "";
    lineCount ++;
  }

  for (int i = 0; i < allLines.size(); i++) {
    cout << "SECOND FOR LOOP" << endl;
    cout << "LINE: " << allLines[i] << endl;

    if (i < allLines.size()-1) {

      strAllLines = strAllLines + "\"" + allLines[i] + "\",";
    } else {
      strAllLines = strAllLines + "\"" + allLines[i] + "\"";
    }
  }
  cout << "SETTING OUTPUT" << endl;
  output =
      "\"line_count\":" + to_string(lineCount) + ", \"lines\":[" + strAllLines;
    cout << "RETURNING OUTPUT" << endl;
  return output;
}