// Compile with:
// g++ -std=c++17 string.cpp -o prog
#include <iostream>

int main(){

  // Type out the example.
  // We'll work with std::strings a lot to parse and manipulate data.
// Create a string
    std::string fullName = "Hongyu Wan";
    // Store a portion of the string
    std::string firstName = fullName.substr(0,6);
    std::string lastName = fullName.substr(7,10);
    // Output our strings
    std::cout << "First: " << firstName << std::endl;
    std::cout << "Last: " << lastName << std::endl;

    // Iterate through our string one
    // character at a time.
    // We break if we find a space.
    // You will also note two ways
    // to access a strings individual
    // characters.
    unsigned int i =0;
    while(i < fullName.length()){
        if(fullName.at(i)!=' '){
            // Terminate from our loop
            std::cout << fullName[i];
        }
        ++i;
    }


    return 0;
}
