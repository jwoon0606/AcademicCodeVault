#include <iostream>

void changeValue(int *ptr)
{
    *ptr = 10; // ptr이 가리키는 변수의 값 변경
}

int main()
{
    int num = 5;
    int *ptr = &num;

    std::cout << "Before function call: " << *ptr << std::endl; // 출력: 5
    changeValue(ptr);
    std::cout << "After function call: " << *ptr << std::endl; // ptr이 가리키는 변수의 값을 직접 바꿨으므로 출력: 10

    return 0;
}

// 함수의 값을 직접 바꾼 경우
// 함수 밖까지 영향을 준다