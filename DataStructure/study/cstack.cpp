#include <iostream>
#define max 25

char name[max];
int top = -1;

void push(char item){
    name[++top] = item;
}

char pop(){
    return name[top--];
}

int main(){
    push('H');
    push('a');
    push('n');
    printf("%c",pop());
    printf("%c",pop());
    printf("%c\n",pop());

    return 0;
}