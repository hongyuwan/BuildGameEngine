// Files that end in the .cpp extension are 'C++' files

// Bring in libraries here
#include <iostream> // input and output 'stream' library
#include <vector>   // std::vector data structure.

using namespace std;
void printVector(const vector<int>& v)
{
    cout << v.at(1) << endl;
    cout << v.at(2) << endl;
}

void printRawArray(int array[], int size)
{
    cout << "PrintRawArray" << endl;
    for (int i = 0; i < size; i++) {
        cout << array[i] << endl;
    }
}
int main(){

    // Source code here
    cout << "Hi! My name is Wan" << endl;

    // Raw array
    int array[5]={1,2,3,4,5};

    // Vector
    vector<int> myVector;
    myVector.push_back(0);
    myVector.push_back(1);
    myVector.emplace_back(2);

    printVector(myVector);
    printRawArray(myVector.data(),myVector.size());


    return 0;
}
