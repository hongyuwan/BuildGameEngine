//
// Created by Wan Hongyu on 2023-01-31.
//

void func2(){
    int* px =nullptr;
    *px=7;
}

void func1(){
    func2();
}

int main(){

    func1();
    return 0;
}
