1. In C++ what are two instances where you would use the keyword const?

(1) Mark a variable as read-only, specifies that a variable's value is constant and tells the compiler to prevent the programmer from modifying it.
(2) Indicate that no member variables in a class will be mutated.

2. What does 'inline' do? Why might a programmer use it? Why might a programmer choose not to use inline?

The "inline" keyword in C++ is used to suggest the compiler to insert the code of a function directly into the code calling it, rather than generating a function call. This can improve the performance of the program by reducing the overhead of a function call. If a function is called frequently, a programmer might want to use it. But if this function is big and not called frequently, the programmer might not want to use it.

3. Why do you think [TinyMath.hpp](./TinyMath.hpp) is implemented as a header only library? 

I think [TinyMath.hpp] is implemented as a header only library. Because the functions and structs are only present in the header file, there is no same name implementation file like TinyMath.cpp.

4. What is the difference between a shared_ptr and a unique_ptr?

shared_ptr allows multiple objects to share the same dynamically allocated object. However, the unique_ptr can't be used to share allocated object.

5. Do you think you should ever use absolute file paths in a project you distribute to others? 

No, the absolute file paths usually don't work on different computer. Instead, it is better to use relative file paths or allow the user to specify the required file paths in a project you distribute to others.

6. What is the difference between static and dynamic linking?

The main difference is, the statuc linking embedding all required libraries and object files directly into the final binary executable file. But the dynamic linkin the libraries and object files at runtime.  The binary executable file will be linked when they are needed.

7. If I get an 'undefined reference' or 'unresolved external symbol', do you think that is a compiler error (something wrong in your code) or a linker error (some missing external dependency)? 

I think these errors are all the linker error. Usually, the linker is unable to find a definition for a symbol (some missing external dependency) that was declared in the code. 
