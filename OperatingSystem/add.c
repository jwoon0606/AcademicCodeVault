#include <stdio.h>

int main()
{
    int a = 0, b = 0;

    // Get two integers from user
    printf("Input two integers: ");
    scanf("%d %d", &a, &b);

    // display the result
    printf("%d + %d = %d\n", a, b, a + b);
    return 0;
}