#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

string TransformFile(string fileContent) {
  string currString;
  string output;
  vector<string> allLines;
  string strAllLines;
  int lineCount;

  for (int i = 0; i < fileContent.length() - 1; i++) {
    if (fileContent[i] == '\n') {
      allLines.push_back(currString);
      currString = "";
      lineCount++;
      continue;
    }
    currString = currString + fileContent[i];

  }
  if (currString != ""){
    allLines.push_back(currString);
    currString = "";
    lineCount ++;
  }

  for (int i = 0; i < allLines.size(); i++) {

    if (i < allLines.size()-1) {

      strAllLines = strAllLines + "\"" + allLines[i] + "\", \n";
    } else {
      strAllLines = strAllLines + "\"" + allLines[i] + "\"";
    }
  }
  output =
      "{\"line_count\":" + to_string(lineCount) + ", \"lines\":[" + strAllLines+ "]}";
    cout << "RETURNING OUTPUT" << endl;
  return output;
}