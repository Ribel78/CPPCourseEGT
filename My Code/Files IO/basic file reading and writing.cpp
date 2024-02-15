/*
Basic file reading and writing
*/
#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::string line;
    std::ifstream myReadFile;
    myReadFile.open("savefile.txt");
    std::getline(myReadFile, line); 
    std::cout << line << std::endl;
    myReadFile.close();

    std::ofstream myFile;
    myFile.open("savefile.txt"); //ios::app (append), ios::in(read), ios::out(write)-default
    myFile << "Goodbye\n";
    myFile.close();
    return 0;
}