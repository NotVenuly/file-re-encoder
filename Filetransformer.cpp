#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;


// method for manually formatting the text file into a JSON file
string TransformFile(string fileContent) {
  string currString;
  string output;
  vector<string> allLines;
  string strAllLines;
  int lineCount;

  for (int i = 0; i < fileContent.length() - 1; i++) {

    // if there is a newline character save the string we have gathered so far aside from the new line character
    if (fileContent[i] == '\n') {
      allLines.push_back(currString);
      currString = "";
      lineCount++;
      continue;
    }

    // if there is no newline character keep adding to the current string
    currString = currString + fileContent[i];

  }
  // if currstring is not empty we know that there is a line that hasn't been pushed yet
  // so we push the final line
  if (currString != ""){
    allLines.push_back(currString);
    currString = "";
    lineCount ++;
  }

  for (int i = 0; i < allLines.size(); i++) {

    // add commas and new line characters to each new line to make it more readable
    // unless the line is the last line, in which case we don't add a comma or a newline character
    if (i < allLines.size()-1) {
      strAllLines = strAllLines + "\"" + allLines[i] + "\", \n";
    } else {
      strAllLines = strAllLines + "\"" + allLines[i] + "\"";
    }
  }

  // format it all manually with this variable assign
  // ouput should be something like {"line_count": 5. "lines": ["hello", "everybody", "I am"...]}
  output =
      "{\"line_count\":" + to_string(lineCount) + ", \"lines\":[" + strAllLines+ "]}";
  return output;
}