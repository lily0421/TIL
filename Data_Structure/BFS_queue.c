#include <stdio.h>
#include <stdlib.h>
#define INF 99999999
#define MAX_SIZE 1001

/*연결리스트 정의-노드가 연결된 형태*/
typedef struct {
	int index;
	struct Node *next;
}Node;

/*큐 생성*/
typedef struct {
	Node *front;
	Node *rear;
	int count;
}Queue;

Node **a; //각각의 정점들이 연결리스트 형태로 인접한 정점들의 정보를 담고있음 - 이차원포인트 이용
int n, m, c[MAX_SIZE];//정점, 간섭, 방문한 정보

/*연결리스트 삽입 함수*/
void addFront(Node *root, int index) {
	Node *node = (Node*)malloc(sizeof(Node));//하나의 노드가 새롭게 넣어질 때
	node->index = index;//노드의 인덱스에는 넣고자하는 값이 들어감-연결되어 있는 해당 정점
	node->next = root->next;//연결리스트 추가
	root->next = node;
}

/*큐 삽입 함수*/
void queuePush(Queue *queue, int index) {
	Node *node = (Node*)malloc(sizeof(Node));//노드 할당
	node->index = index;
	node->next = NULL;
	if (queue->count == 0) { //큐가 비어있다면 
		queue->front = node;//큐의 front에 노드 넣기
	}
	else {//큐가 비어 있지 않다면
		queue->rear->next = node;//큐의 rear에 넣기
	}
	queue->rear = node;//코리에는 노드추가
	queue->count++;//큐의 count증가
}

/*큐 추출 함수*/
int	queuePop(Queue *queue) {
	if (queue->count == 0) {//큐가 비어있다면
		printf("큐 언더플로우가 발생했습니다.\n");
		return -INF;
	}
	Node* node = queue->front;//front에서 노드 한개 꺼냄
	int index = node->index;//해당 인덱스 데이터 값
	queue->front = node->next;
	free(node);//메모리 해제
	queue->count--;//하나 빠졌으니 count감소
	return index;//해당 데이터 출력
}

/*너비 우선 탐색 함수*/
void bfs(int start) {//특정 위치에서 너비우선 탐색 사용
	Queue q;
	q.front = q.rear = NULL;//큐 초기화
	q.count = 0;
	queuePush(&q, start);//큐에 시작하는 인덱스 넣기
	c[start] = 1;//해당 노드를 방문처리
	while (q.count != 0) {//큐가 빌 때 까지 반복
		int x = queuePop(&q); //큐에 있는 원소 하나 뽑기
		printf("%d ", x);//방문 한 것 출력
		Node *cur = a[x]->next;//원소에 연결되어 있는 노드 하나씩 확인
		/*인접한 노드들이 방문되어 있는지 여부에 따라 큐에 넣을지를 결정*/
		while (cur != NULL) {
			int next = cur->index;//인접 노드 확인
			if (!c[next]) {//방문하지 않았다면
				queuePush(&q, next);//큐에 넣고
				c[next] = 1;	//방문처리
			}
			cur = cur->next;//모든 노드 확인 하기
		}
	}
}

/*너비 우선 탐색 이용*/
int main(void) {
	scanf("%d %d", &n, &m);//정점개수, 간선 개수 입력 받기
	a = (Node **)malloc(sizeof(Node *) * (MAX_SIZE)); //동적할당
	for (int i = 1; i <= n; i++) {
		a[i] = (Node *)malloc(sizeof(Node));//연결리스트 초기화
		a[i]->next = NULL;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		addFront(a[x], y);
		addFront(a[y], x);
	}
	bfs(1);//노드 1을 기준으로 너비우선탐색
	system("pause");
	return	0;
}
