#include <stdio.h>

void changePointer(int* ptr) {
    int x = 10;
    ptr = &x; // 포인터를 다른 변수 x를 가리키도록 변경
}

int main() {
    int num = 5;
    int* ptr = &num;

    printf("Before function call %d\n",*ptr); // 출력: 5
    changePointer(ptr);
    printf("After function call %d\n",*ptr); // 여전히 num의 주소를 가리키므로 출력: 5

    return 0;
}

// 포인터 변수가 가리키는 주소를 다른 주소로 바꿀 경우
// 함수 안에서만 작동 (함수 바깥까지 영향 주지 않음)