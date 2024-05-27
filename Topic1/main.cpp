#include <iostream>

void print_hello();

void print_hello(int someNum){
    std::cout << "Hello World!! Input: " << someNum << std::endl;
}

int main(){
    print_hello(123);
    return 0;
}