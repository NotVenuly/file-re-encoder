#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

// use namespace std, since this is a small project
using namespace std;


// use pointers so that we dont have to return anything
void Trim(string *address, size_t startPos, size_t count) {
  address->erase(startPos, count);
}

// this function is to trim the start and end of a string
// in this script it's used for removing quotes which show up when copying path from file manager
void TrimEdges(string *address) {
  address->erase(0, 1);
  address->erase((*address).length() - 1, 1);
}

string OpenFile() {
  string fileAddress;

  cout << "Type the address of the file you want to re-encode: ";
  // get line so we don't have to worry about the end line character
  getline(cin, fileAddress);
  if (fileAddress[0] == '"' && fileAddress.length() > 2) {
    TrimEdges(&fileAddress);
  }
  ifstream myFile;

  // open the file at the given address
  myFile.open(fileAddress);


  if (myFile.is_open()) {
    // go over the whole file with just a couple lines of code using istreambuf
    string result((istreambuf_iterator<char>(myFile)),
                  istreambuf_iterator<char>());
    // close the file for clean code
    myFile.close();
    return result;
  }
  cout << "Something went wrong with opening the file" << endl;
  return "";
}

