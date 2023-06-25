#include <filesystem>
#include <iostream>
#include "filefunctions.hpp"
#include <string>
using namespace std;
void getfile(){
    std::string path = "C:\\Program Files (x86)\\";
    for (const auto & entry : filesystem::directory_iterator(path))
        std::cout << entry.path() << std::endl;
}
int main(){
}