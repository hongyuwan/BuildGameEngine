// Compile with:
// g++ -std=c++17 io.cpp -o prog
#include <iostream>
using namespace std;
int main(){
    std::cout << "Hello" << endl;
    std::cout << "How old are you?" << endl;



    int age;

    // Now we want to get c++ input (i.e. cin)
    cin >> age;

    cout << "That is great you are " << age << endl;
    cerr<< "That is great you are " << age << endl;
    clog<< "That is great you are " << age << endl;
    return 0;
}
