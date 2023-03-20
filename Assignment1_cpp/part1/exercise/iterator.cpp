// Compile with:
// g++ -std=c++17 iterator.cpp -o prog
#include <iostream>
#include <vector>
int main(){

  	// Wow you are learning so much already by typing out these examples.
	//
	// Folks in the C++ world 'swear' by iterators.
	// (And I sort of agree). But in this course, it's enough to just know they exist
	// and you can start building a habit out of using them now.
    // g++ -std=c++17 iterator.cpp -o prog


        std::vector<unsigned char> myData;

        // Add data into our vector.
        for(unsigned int i = 65; i < 91; ++i){
            myData.push_back(i);
        }


        std::vector<unsigned char>::iterator it = myData.begin();
        std::vector<unsigned char>::iterator end = myData.end();
        for(; it != end; it++){
            std::cout << *it;
        }

        return 0;
    }

