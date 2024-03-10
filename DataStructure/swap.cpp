// swap using reference variale
#include <iostream>
using namespace std;

void swap(int& num1, int& num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

int main(){
    int a = 5;
    int b = 7;

    printf("Before swap: a = %d, b = %d\n",a,b);
    swap(a,b);
    printf("After swap: a = %d, b = %d\n",a,b);
}