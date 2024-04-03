#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct{
	int* stack;
	int max_size;
	int top;
} Stack;

Stack* CreateS(int max_stack_size)
{
	Stack *s = (Stack*)malloc(sizeof(Stack));
	s->stack = (int*)malloc(max_stack_size * sizeof(int));
	s->max_size = max_stack_size;
	s->top = -1;
	return s;
}

int top = -1;

bool IsEmptyS(Stack *s)
{
	if(s->top < 0) return true;
	else return false;
}

bool IsFullS(Stack *s)
{
	if(s->top == s->max_size -1) return true;
	else return false;
}

void Push(Stack *s, int e)
{
	if(IsFullS(s))
		cout << "Error" << endl;
	else
		s->stack[++s->top] = e;
}

int Pop(Stack *s)
{
	if(IsEmptyS(s)){
		cout << "Error" << endl;
		return 0;
	}
	else
		return s->stack[s->top--];
}

int main(){
	Stack *s1 = CreateS(10), *s2 = CreateS(10);

	Push(s1, 10);
	Push(s1, 20);
	Push(s1, 30);
	Push(s2, 100);
	Push(s2, 200);
	cout << Pop(s1) << endl;
	cout << Pop(s1) << endl;
	cout << Pop(s2) << endl;
}