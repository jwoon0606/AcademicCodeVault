#include <stdio.h>

int main(){
    int a = 0, b = 0;

    printf("Input two integers: ");
    scanf("%d %d",&a,&b);

    printf("%d + %d = %d\n",a,b,a+b);
    return 0;   
}