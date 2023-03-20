// Compile with:
// g++ -std=c++17 pointers.cpp -o prog
#include <iostream>

int main(){

  // Pointers can be tricky.
  // 
  // Feel free to use tools like valgrind and gdb to help you debug.
    // Here we create a pointer.
    // It points to nothing.
    int* px= nullptr;
    // Let's create another variable so we can point to it.
    int x = 7;
    // Now we use the 'assignment operator' to point to
    // the variable x. Our pointers 'point' to things remember.
    px = &x; // The 'ampersand gives us the 'address of' a varaible.
    // Remember, pointers store addresses.

    // Let's now dereference 'px' to get the value of the 'thing'
    // that px points to.
    std::cout << "px dereferenced is = " << *px << "\n";


    return 0;
}

// Pointers can be 'Tricksy' sometimes--so practice now!
// https://www.asciiart.eu/books/lord-of-the-rings
//         .';:;'.
//        /_' _' /\   __
//        ;a/ e= J/-'"  '.
//        \ ~_   (  -'  ( ;_ ,.
//         L~"'_.    -.  \ ./  )
//         ,'-' '-._  _;  )'   (
//       .' .'   _.'")  \  \(  |
//      /  (  .-'   __\{`', \  |
//     / .'  /  _.-'   "  ; /  |
//    / /    '-._'-,     / / \ (
// __/ (_    ,;' .-'    / /  /_'-._
// `"-'` ~`  ccc.'   __.','     \j\L\
//                 .='/|\7      
//     snd           ' `
