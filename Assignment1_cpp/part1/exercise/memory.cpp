// g++ -std=c++17 memory.cpp -o prog
#include <iostream>
#include <vector>


int main(int argc, char** argv){

  // We'll have to get comfortable with working with memory.
  //
  // Eventually we'll be passing around memory from the CPU to GPU and back.
  //
  // That's why I am so adament you type out the examples.
  //
  // You can add more to them too--that's the best way to learn!
    uint8_t* contiguous_chunk_of_memory = new uint8_t[80];

    uint8_t* one_item = new uint8_t;

    std::cout << "sizeof(contiugous...) =" << sizeof(contiguous_chunk_of_memory) << std::endl;

    delete one_item;
    delete[] contiguous_chunk_of_memory;

    return 0;

}
