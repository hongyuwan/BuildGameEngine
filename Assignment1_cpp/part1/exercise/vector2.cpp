// g++ -std=c++17 vector2.cpp -o prog
#include <iostream>
#include <vector>

int main(int argc, char** argv){

  // You need to understand what is going on with sizeof.
  // This exercise exists because on average, 25% of folks
  // are going to try to use 'sizeof' and expect to get the number
  // of elements in a vector, rather than the size of the underlying data type.
    // Create a vector which stores
    // 'unsigned char' data.
    std::vector<unsigned char> myVector;

    for(unsigned int i = 0; i < 91; ++i){
        myVector.push_back(i);
    }

    // Remember, std::vector is a data structure storing a specific type of element.
    // std::vector is a 'dynamically resizing' array.
    std::cout << "(number of elements) myVector.size()                           = " << myVector.size() << std::endl;
    std::cout << "(size of data structure) sizeof(myVector)                      = " << sizeof(myVector) << std::endl;
    std::cout << "(raw array myVector is built on top of) sizeof(myVector.data())= " << sizeof(myVector.data()) << std::endl;
    std::cout << std::endl;

    // Compare the std::vector to a raw array when using sizeof
    // sizeof can figure out the size of the array, if we are checking the 'sizeof' within the same block scope the raw array was declared.
    int rawArray[100];
    std::cout << "locally allocated, i.e. stack allocated array) sizeof(rawArray)=" << sizeof(rawArray) << std::endl;
    std::cout << std::endl;

    // Compare the raw array to a heap allocated array
    int* heapArray = new int[52];
    // In this case, because heapArray is a pointer, sizeof will only return the size of a pointer type, usually 8 bytes.
    std::cout << "heap allocated array, (i.e. pointer to a chunk of memory) sizeof(heapArray)=" << sizeof(heapArray) << std::endl;
    std::cout << std::endl;

    // Note: We should also delete any heap allocated memory.
    delete[] heapArray;

    return 0;
}
