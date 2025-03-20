#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Memory Allocation 
// malloc
// free
// malloc : void * malloc(size)
// void이기에 어떤 형이 와도 가능함.

// int* a = (int*)malloc(10 * sizeof(int));
// a = 할당된 Memory의 시작주소!

// free : void free(포인터 주소) a

//int *a, int *b , a = malloc...
// a = b;로 정의하면 a는 b를 지목하기에 메모리 누수가 발생하게됌.
// malloc으로 만든 공간에 누수가 생김.


//int main() {
//
//	int* a = (int*)malloc(10 * sizeof(int));
//	for (int i = 0; i < 10; i++) {
//		*(a + i) = i + 1;
//		printf("%d ", *(a + i));
//	}
//
//	free(a);
//
//	return 0;
//}

// Stack 
// 가장 나중에 저장된 데이터를 가장 먼저 꺼낼 수 있는 자료구조.
// 항아리라고 생각하면 됌.
// 가장 먼저 저장된 데이터를 가장 늦게 꺼낼 수 있는 자료구조.
// Eng : LIFO - Last In, First Out.

// 함수로 표현(Stack)
/*
void fun_3() { // 3번째
	printf("this is function 3\n"); // 1번째
}

void fun_2() { // 2번째
	fun_3();
	printf("this is function 2\n"); // 2번째
}

void fun_1() { // 1번째
	fun_2();
	printf("this is function 1\n"); // 3번째
}

int main() {
	fun_1();
}
*/

// Stack operation
// 1. 데이터를 넣는 것. - Push
// 2. 데이터를 꺼내는 것. - Pop	

// 수식계산(Stack의 응용예제)
// 중위표기법 수식 : ex) 3 + 4, 3 - 1
// 연산자가 숫자 사이에 표기되는 것
// 후위표기법 수식 : ex) 3 4 +, 3 1 -
// 연산자가 숫자 뒤에 표기되는 것
// 후위표기법 수식은 항상 왼쪽에서 오른쪽으로 계산해 나간다.
// 괄호가 필요없음. ex) 3 + 4 * 5 = 23 -> 3 4 + 5 * = 23
// 컴퓨터가 쉽게 계산할 수 있다. -> Stack를 사용해서 계산.

// Stack 구현

#define MAXIMUM_STACK_SIZE 10
#define INVALID_VALUE -999

typedef int boolean;

int stack[MAXIMUM_STACK_SIZE];
int top = -1; // 초기값.

// 스택이 비어있는지
boolean isEmpty(void) {

	if (top == -1) {
		return true;
	}
	
	return false;

}

// 스택이 꽉 찼는지
boolean isFULL(void) {

	if (top == MAXIMUM_STACK_SIZE - 1) {
		return true;
	}
	
	return false;

}

boolean push(int _v) {

	if (isFULL() == true) {
		//stack is full, so it cannot push v
		return false;
	}
	else {
		top++;
		stack[top] = _v;
		return true;
	}
}

int pop(void) {
	// 1. check whether the stack is empty
	if (isEmpty() == true) {
		return INVALID_VALUE;
	}
	else {
		int temp = stack[top];
		top--;
		return temp;
	}
}

int main() {

	push(1);
	push(2);
	push(3);
	push(4);
	push(5);

	for (int i = 0; i < 5; i++) {
		printf("%d \n", pop());
	}

	// 5, 4, 3, 2 ,1

}