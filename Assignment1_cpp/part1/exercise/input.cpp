// Compile with:
// g++ -std=c++17 input.cpp -o prog
#include <iostream>
#include <fstream>
#include <string> // new library!

int main(int argc, char** argv){


    std::ifstream inFile;

    if (argc != 2){
        std::cout << "Oops, exactly two arguments needed.\n";
        std::cout << "ProgramName file_path.\n";
        return 0;
    }

    inFile.open(argv[1]);
    if(inFile.is_open()){
        std::string line;   // A string object.
        while(getline(inFile,line)){
            std::cout << line << std::endl;
        }
    }

    // Closes the file we are reading from
    inFile.close();

    return 0;
}