// Compile with:
// g++ -std=c++17 datasize.cpp -o prog
#include <iostream>

using namespace std;
int main(){
    // Type out the example.
    // Actually type it out--that is how you will learn and
    // build your muscle memory with the language.
    // Do not copy & paste...actually type it out.
    // Change some values, play around, experiment.
    cout<<"Data size of int in bytes = " << sizeof(int) << endl;
    cout << "Data size of char in bytes = " << sizeof(char) <<endl;
    cout << "Data size of uint8_t in bytes = " << sizeof(uint8_t) << endl;
    cout << "Data size of float in bytes = " << sizeof(float) << endl;
    cout << "Data size of double in bytes = " << sizeof(double) << endl;

	return 0;
}
