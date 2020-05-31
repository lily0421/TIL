#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10000 //전체 stack크기 정해줌
#define INF 99999999 


int stack[SIZE];
int top = -1;//stack의 최상단 의미

void push(int data) {
	if (top == SIZE - 1) {
		printf("스택 오버플로우가 발생했습니다.\n");
		return;
	}
	//그렇지 않다면 top에 1을 더한 값의 index에 data를 넣어줌
	stack[++top] = data;

}
void pop() {
	if (top==-1) {//원소가 하나도 들어있지 않다면
		printf("스택 언더플로우가 발생했습니다.\n");
		return -INF;//무한을 return해주어 문제 발생 알려줌
	}
	//오류가 없다면 현재 top이 가리키고 있는 그 원소의 값을 반환하면서 
	//원소가 줄었음을 알림 
	return stack[top--];
}

void show() {//출력	
	printf("--스택의 최상단--\n");
	for(int i=top; i>=0; i--){
		printf("%d\n", stack[i]); //최상단부터 출력
	}
	printf("--스택의 최하단--\n");
}
int main() {
	//stack에 값 넣기
	push(7);//스택에 메모리 주소를 보내야 하기 때문에 &를 붙임
	push(5);
	push(4);
	pop();
	push(6);
	pop();
	show();
	system("pause");
	return 0;
}