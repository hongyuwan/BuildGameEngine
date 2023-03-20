//
// Created by hongy on 2023/1/20.
//
// Compile with:
// g++ -std=c++17 input.cpp -o prog
#include <iostream>
#include <fstream>
#include <string> // new library!
#include <vector>
using namespace std;
struct Story{
    int operation=99;
    std::vector<string> myVector;
    Story(std::vector<string> vector) : myVector(vector) {}
    int line=0;
    string renderPrint=myVector[0];;
    Story(){}//constructor
    ~Story(){}//Destructor
    int cal=0;

    void input(){
    if(cal!=0){
        cin>> operation;
    }

    }
    void update(){
       if(line<myVector.size()&&cal!=0){
           if(operation==1){
               line+=1;
           }
           else if(operation==2){
               line-=1;
           }
       }
        renderPrint=myVector[line];


    }
    void render(){
        cout<<renderPrint<<endl;
        cout<<"1. Advance Story"<<endl;
        cout<<"2. Go Back in Story"<<endl;
        cal+=1;
        if(cal==myVector.size()){
            cout<<"******story is over*********"<<endl;
        }
    }
    void loop(){
        while(true){
            input();
            update();
            render();
        }
    }
};
int main(int argc, char** argv){
    std::vector<string> myData;

    std::ifstream inFile;

    if (argc != 2){
        std::cout << "Oops, exactly two arguments needed.\n";
        std::cout << "ProgramName file_path.\n";
        return 0;
    }
    inFile.open(argv[1]);
    if(inFile.is_open()){
        std::string line;   // A string object.
        while(getline(inFile,line)){
            myData.push_back(line);
        }
    }
    // Closes the file we are reading from
    inFile.close();

    Story GameStory(myData);
    GameStory.loop();
    return 0;
}
