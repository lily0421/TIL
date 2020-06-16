/*연결리스트 이용한 큐 선언*/

#include <stdio.h>
#define SIZE 10000
#define INF 99999999

//큐 선언
typedef struct{
	int	data;
	struct Node *next;
}Node;

typedef struct{ //front, rear가 들어감
	Node *front;
	Node *rear;
	int count; //큐에 있는 원소들 카운트
}Queue;


//큐 삽입
void push(Queue *queue, int data){
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	if (queue->count == 0) {//큐가 비어있으면 카운트는 0
		queue->front = node;//front는 노드
	}//초기 세팅
	else {
		queue->rear->next = node;//rear의 다음노드로 새 노드가 들어옴]
	}
	queue->rear = node;//rear가 해당 노드 됨
	queue->count++;
}
//큐 추출
int pop(Queue *queue){
	if (queue->count == 0) {//큐 비어 있음
		printf("큐 언더플로우가 발생했습니다\n");
		return -INF;
	}
	Node *node = queue->front;
	int data = node->data;
	queue->front = node->next;//큐의 front가 다음 노드 값을 가리키도록 만들고
	free(node);
	queue->count--;
	return data;//데이터 뽑아서 반환
}

//큐 전체 출력
void show(Queue *queue){//큐의 앞에서부터 뒤쪽으로
	Node*cur = queue->front;
	printf("---------- 큐의 앞 -----------\n");
	while(cur != NULL){//노드 존재하면 계속 출력
		printf("%d \n", cur->data);
		cur = cur->next;
	}
	printf("---------- 큐의 뒤 -----------\n");
}

//완성된 큐 사용
int main(void) {
	Queue queue;
	queue.front = queue.rear = NULL;
	queue.count = 0;

	push(&queue, 7);
	push(&queue, 5);
	push(&queue, 4);
	pop(&queue);
	push(&queue, 6);
	pop(&queue);
	return 0;
}