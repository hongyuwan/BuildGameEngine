// Add your unit tests somewhere in this file
// Provide sufficient 'coverage' of funtions you have implemented.
#include "TinyMath.hpp"
#include <iostream>

// Add a 1-vector with a 0-vector.
bool unitTest1(){
    puts("Test operator+ of Vec2D");
    Vec2D a(1,1);
    Vec2D b(0,0);
    Vec2D result = a + b;


    if(result.x == 1 && result.y == 1){
        return true;
    }
    // You generally should not be printing out the
    // results here, I'm just showing this function here
    // to help you if you need to debug your vectors.
    PrettyPrint(std::cout, result);

    // Return false whenever a unit test is failing your
    // expected behavior
    return false;
}

// TODO
// Test the dot product of a Vec2D
bool unitTest2(){
    puts("Test the dot product of a Vec2D");
    Vec2D a(1,1);
    Vec2D b(0,0);
    Vec2D result = Dot(a,b);
    if(result.x == 0 && result.y ==0){
        return true;
    }
    return false;
}
// TODO
// Test operator== of Vec2D
bool unitTest3(){
    puts("Test operator== of Vec2D");
    Vec2D a(1, 1);
    Vec2D b(1, 1);
    if((a == b)) {
        return true;
    }
    return false;
}
// TODO
// Test operator * of Vec2D
bool unitTest4(){
    puts("Test operator* of Vec2D");
    float b=3.14;
    Vec2D a(1, 1);
    Vec2D result(3.14, 3.14);
    if(a*b==result) {
        return true;
    }
    return false;
}
// TODO
// Test operator / of Vec2D
bool unitTest5(){
    puts("Test operator* of Vec2D");
    float b=3.41;
    Vec2D a(3.41, 3.41);
    Vec2D result(1, 1);
    if(a/b==result) {
        return true;
    }
    return false;
}
// TODO
// Test operator - of Vec2D to negative
bool unitTest6(){
    puts("Test operator- of Vec2D to negative");
    Vec2D a(3, 3);
    Vec2D result(-3, -3);
    if(-a==result) {
        return true;
    }
    return false;
}
// TODO
// Test Magnitude of Vec2D
bool unitTest7(){
    puts("Test Magnitude of Vec2D");
    Vec2D a(1, 1);
    float result=Magnitude(a);
    if(result==sqrtf(2)){
        return true;
    }
    return false;
}
// TODO
//Test Vector Projection of Vec2D
bool unitTest8(){
    puts("Test Projection of Vec2D");
    Vec2D a(1, 1);
    Vec2D b(2, 2);
    Vec2D result=Project(a,b);
    if(result.x==1&&result.y==1){
        return true;
    }
    return false;
}
// TODO
//Test Vector Normalize of Vec2D
bool unitTest9(){
    puts("Test Normalize of Vec2D");
    Vec2D a(1, 1);
    Vec2D result=Normalize(a);
    if((result.x==sqrtf(2)/2)&&(result.y=sqrtf(2)/2)){
        return true;
    }
    return false;
}
//Test Vector CrossProduct of Vec2D
// TODO
bool unitTest10(){
    puts("Test CrossProduct of Vec2D");
    Vec2D a(1, 1);
    Vec2D b(2, 2);
    float result=CrossProduct(a,b);
    if(result==0){
        return true;
    }
    return false;
}
// Test Matrix3D operator *
// TODO
bool unitTest11(){
    puts("Test operator * of Matrix3D");
    Matrix3D a;
    Matrix3D b(1,1,1,1,1,1,1,1,1);
    Matrix3D c(1,1,0,1,1,0,1,1,0);
    Matrix3D result =a*b;
    for (int i=0;i<3;i++){
        for(int j=0;j<3;j++)
        {
            if(result(i,j)!=c(i,j))
            {
               std::cout<<result(i,j)<<std::endl;
                std::cout<<c(i,j)<<std::endl;
                return false;
            }
        }
    }
    return true;
}
// Test Matrix multiply by a vector
// TODO
bool unitTest12(){
    puts("Test Matrix3D multiply by a vector");
    Matrix3D a;
    Vec2D b(1,1);
    Vec2D result =a*b;
    if(result.x == 1 && result.y == 1){
        return true;
    }
    return false;
}


// TODO: Add more tests here at your discretion
bool (*unitTests[])(void)={
    unitTest1,
    unitTest2,
    unitTest3,
    unitTest4,
    unitTest5,
    unitTest6,
    unitTest7,
    unitTest8,
    unitTest9,
    unitTest10,
    unitTest11,
    unitTest12,	
    nullptr
};


// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
    unsigned int testsPassed = 0;
    // List of Unit Tests to test your data structure
    int counter =0;

    // Iterate through the array of unitTest functions until the
    // nullptr is found indicating the end of the unitTest array.
    while( unitTests[counter] != nullptr ){
        std::cout << "========unitTest " << counter << "========\n";

        if( true == unitTests[counter]() ){
            std::cout << "passed test\n";
            testsPassed++;	
        }else{
            std::cout << "failed test, missing functionality, or incorrect test\n";
        }

        ++counter;
    }

    std::cout << "\n\n" << testsPassed << " of " << counter << " tests passed\n";

    return 0;
}
