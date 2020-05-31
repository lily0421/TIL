#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

typedef struct {
	int data;
	struct Node *next;
} Node;

typedef struct {
	Node *top;
} Stack;

void push(Stack *stack, int data) {
	Node *node = (Node*)malloc(sizeof(Node));//하나의 노드가 들어갈 수 있는 공간 할당
	node->data = data; //node의 데이터는 넣고자 하는 데이터를 집어넣고
	node->next = stack->top;//node의 next는 현재의 top이 들어갈 수 있음
	stack->top = node;//stack의 top은 현재node로 바꿔줌. 마지막에 들어온 최상단 node가 top 
}
void pop(Stack *stack) {//특정한 stack이 매개변수로 들어옴
	if (stack->top == NULL) {//현재 stack이 비어있다면 
		printf("스택 언더플로우가 발생했습니다.\n");
		return -INF;//무한을 return해주어문제 발생 알려줌
	}
	Node *node = stack->top; //기존의 node에 최상단 node를 담아놓았다가
	int data = node->data; //data를 추출할 것임
	stack->top = node->next;//이후 stack의 top은 node의 next(두번째 node)가 될 수 있도록
	free(node);//기존의 node는 할당해제
	return data;
}
void show(Stack *stack) {//출력
	Node *cur = stack->top;
	printf("--스택의 최상단--\n");
	while (cur != NULL) {
		printf("%d\n", cur->data); //top에서 부터 출발
		cur = cur->next;
	}
	printf("--스택의 최하단--\n");
}
int main() {
	Stack s;
	s.top = NULL;//반드시 NULL값을 넣어야 언더플로우나 show함수에서 체크 가능
	//stack에 값 넣기
	push(&s, 7);//스택에 메모리 주소를 보내야 하기 때문에 &를 붙임
	push(&s, 5);
	push(&s, 4);
	pop(&s);
	push(&s, 6);
	pop(&s);
	show(&s);
	system("pause");
	return 0;
}