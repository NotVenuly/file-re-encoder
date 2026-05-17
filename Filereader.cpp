#include "filereader.h"

#include <fstream>
#include <iostream>
#include <iterator>


using namespace std;

void Trim(string *address, size_t startPos, size_t count) {
  address->erase(startPos, count);
}

void TrimEdges(string *address) {
  address->erase(0, 1);
  address->erase((*address).length() - 1, 1);
}

string OpenFile() {
  string fileAddress;

  cout << "Type the address of the file you want to re-encode: ";
  getline(cin, fileAddress);
  if (fileAddress[0] == '"' && fileAddress.length() > 2) {
    TrimEdges(&fileAddress);
  }
  ifstream myFile;
  myFile.open(fileAddress);

  if (myFile.is_open()) {
    string result((istreambuf_iterator<char>(myFile)),
                  istreambuf_iterator<char>());
    myFile.close();
    return result;
  }
  cout << "Something went wrong with opening the file" << endl;
  return "";
}

int main() {
  string file = OpenFile();
  return 0;
}
