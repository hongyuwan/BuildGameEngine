// Compile with:
// g++ -std=c++17 output.cpp -o prog
#include <iostream>
#include <fstream>
int main(int argc, char** argv){


    // Opens a file to output
    std::ofstream outFile;
    // Write to a new file called 'temp.txt'
    // This overwrites a previous file, or otherwise
    // creates a new file if it does not exist.
    outFile.open("temp.txt");

    // We can work with files similar to how we
    // work with cout and cin.
    outFile << "# Some image data" << std::endl;
    outFile << "P3" << std::endl;

    // Closes the file we are streaming data to
    outFile.close();

    return 0;
}
