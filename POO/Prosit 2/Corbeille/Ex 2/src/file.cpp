#include "file.hpp"
#include <fstream>
#include <iostream>

File::File(const string& name,const string& path) {
    this->name = name;
    this->path = path.empty() ? name : path ;
}

File::~File() {}

void File::setName(string name) {
    this->name = name;
}
void File::setPath(string path) {
    this->path = path;
}
string File::getName() {
    return this->name;
}
string File::getPath() {
    return this->path;
}

string File::readBin() const {}
void File::writeBin() const {}

