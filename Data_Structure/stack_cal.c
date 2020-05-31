#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 99999999

typedef struct Node {
	char data[100]; // 숫자 혹은 문자열로 다양한데, 숫자의 경우 길이가 길수 있어 문자열로 처리
	struct Node *next;//다음 node로 갈 수 있도록
}Node;

typedef struct Stack {
	Node *top;
}Stack;

void push(Stack *stack, char *data) { //기존의 stack과 동일함. 									 
	Node *node = (Node*)malloc(sizeof(Node));
	strcpy(node->data, data); //각 node들은 데이터를 포함하고 있어, 매개변수로 넘어온 문자열 데이터를 노드 안에 담을 수 있도록
	node->next = stack->top;//현재 stack의 top을 해당 node의 다음을 가리키도록
	stack->top = node; //stack의 top을 해당 node로 바꿈
}

char* getTop(Stack *stack) {//stack의 상단 node인 top을 반환
	Node *top = stack->top;
	return top->data;
}

char* pop(Stack *stack) {
	if (stack->top == NULL) {
		printf("스택 언더플로우가 발생했습니다.\n");
		return -INF;
	}
	Node *node = stack->top;
	char *data = (char*)malloc(sizeof(char) * 100);
	strcpy(data, node->data);
	stack->top = node->next;
	free(node);
	return data;
}
//후위 표기법으로 변환 - 우선순위 함수 만들기
int getPriority(char *i) {
	if (!strcmp(i, "(")) return 0;//우선선위 낮음
	if (!strcmp(i, "+") || !strcmp(i, "-")) return 1;
	if (!strcmp(i, "*") || !strcmp(i, "/")) return 2;
	return 3;
}

//후위 표기법 계산
//나뉘어 들어오는 문자열 s, 문자열의 개수 size //각 문자열을 검사
char* transition(Stack *stack, char **s, int size) {
	char res[1000] = "";
	for (int i = 0; i < size; i++) {//각 문자열을 하나씩 살펴보면서
		if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/")) {//해당문자열이 연산자이면
			while (stack->top != NULL && getPriority(getTop(stack)) >= getPriority(s[i])) {//자신보다 높은 연산자는
				strcat(res, pop(stack)); strcat(res, " ");//stack에서 뽑은 후
				//res는 후위표기법으로 바뀐 결과값이 담길 것 따라서 띄어쓰기로 구분
			}
			push(stack, s[i]);//자신의 stack에 넣는다
			
		}
		else if (!strcmp(s[i], "(")) push(stack, s[i]);//여는괄호 일 경우 바로 스택에 넣기
		else if (!strcmp(s[i], ")")) {//닫는 괄호 일 경우
			while (strcmp(getTop(stack), "(")) {//여는 괄호가 나올때까지
				strcat(res, pop(stack)); strcat(res, " ");//stack에서 뽑아서 결과에 담는다.
			}
			pop(stack);//여는 괄호 또한 나올 수 있게 함.
		}
		else strcat(res, s[i]);	strcat(res, " ");//일반 숫자인 경우
	}
	while (stack->top != NULL) {//이후 stack에 남아 있는 원소가 있을 경우 다 꺼내줌
		strcat(res, pop(stack)); strcat(res, " ");
	}
	return res;//후위표기법 뽑아냄
}


void calculate(Stack *stack, char **s, int size) {
	int x, y, z;
	for (int i = 0; i < size; i++) {
		if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || strcmp(s[i], "/")) {//연산자라면
			//스택에서 2개를 뽑아서
			x = atoi(pop(stack)); 
			y = atoi(pop(stack));
			//그것을 계산
			//y가 먼저 들어갔기 때문에 x보다 먼저 더해줌

			if (!strcmp(s[i], "+")) z = y + x;
			if (!strcmp(s[i], "-")) z = y - x;
			if (!strcmp(s[i], "*")) z = y * x;
			if (!strcmp(s[i], "/")) z = y / x;
			char buffer[100];
			sprintf(buffer, "%d", z);
			push(stack, buffer);//계산 결과를 다시 stack에 넣음
		}
		else {
			push(stack, s[i]);
		}
	}
	printf("%s ", pop(stack));
}

//후위계산기 사용
int main(void) {
	Stack stack; 
	stack.top = NULL; //스택 초기화
	char a[100] = "( ( 3 + 4 ) * 5 ) - 5 * 7 * 5 - 5 * 10"; //계산 수식
	int size = 1; //size는 각각의 문자열들의 개수 
	for (int i = 0; i < strlen(a); i++) {//문자를 살펴보면서
		if (a[i] == ' ') size++; //띄어쓰기가 나올때마다 1씩 더해줌
	}
	//string token이라는 라이브러리를 이용해서,
	//각각의 문자열을 띄어쓰기를 이용해서 분리할 것
	char **ptr = strtok(a, " ");
	char **input = (char**)malloc(sizeof(char*) * size);//후위 표기법 계산기에 넣고자 하는 입력값을 마련해줌
	for (int i = 0; i < size; i++) {
		input[i] = (char*)malloc(sizeof(char) * 100);//각 문자열은 최대 100까지크기
	}
	//토큰으로 분리된 각 문자열들을 input에 넣음
	for (int i = 0; i < size; i++) {
		strcpy(input[i], ptr);
		ptr = strtok(NULL, " ");//다음 토큰을 확인할 때는 string token함수를 또 불러옴.
	}
	//띄어쓰리고 분리된 토큰 값이 input에 넣어짐

	char b[1000] = "";
	strcpy(b, transition(&stack, input, size));
	printf("후위 표기법 : %s\n", b);
	size = 1;
	for (int i = 0; i < strlen(b) - 1; i++) { // 마지막은 항상 공백이 들어가므로 1 을 빼기
		if (b[i] == ' ') size++;
	}
	char *ptr2 = strtok(b, " ");
	for (int i = 0; i < size; i++) {
		strcpy(input[i], ptr2);
		ptr2 = strtok(NULL, " ");
	}
	calculate(&stack, input, size);
	system("pause");
	return 0;
}

