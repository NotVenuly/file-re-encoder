#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>



void Trim(std::string *address, size_t startPos, size_t count);
void TrimEdges(std::string *address);
std::string OpenFile();

#endif