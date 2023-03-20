// g++ -std=c++17 vector.cpp -o prog
#include <iostream>
#include <vector>

int main(int argc, char** argv){

    // Create a vector which stores
    // 'unsigned char' data.
    std::vector<unsigned char> myData;

    // Add data into our vector.
    // The push_back member function automatically adds and expands our vector
    for(unsigned int i = 65; i < 91; ++i){
        myData.push_back(i);
    }

    // Iterate through our container structure
    // and print out the data in our vector.
    for(unsigned int i = 0; i < myData.size(); ++i){
        std::cout << myData[i];
        // std::cout << myData.at(i); // This line does the same thing
    }

    return 0;
}
