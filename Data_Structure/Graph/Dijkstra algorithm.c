/*다익스트라 알고리즘-프림 알고리즘과 비슷*/

//간선 구조체 정의 [최대 노드 : 20,000개 / 최대 간선 : 300,000개]
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define NODE_MAX 20001
#define EDGE_MAX 600001 // 양방향 간선이므로 300,000 개

typedef struct {
	int cost;
	int node;
}Edge;
//우선 순위 큐안에서 Edge끼리 서로 위치를 바꾸야 하는 일이 발생할 수 있어 swap함수 만듦
void swap(Edge *a, Edge *b) {
	Edge temp;
	temp.cost = a->cost;
	temp.node = a->node;
	a->cost = b->cost;
	a->node = b->node;
	b->cost = temp.cost;
	b->node = temp.node;
}
//우선순위 큐 정의 및 삽입함수 구현
typedef struct {
	Edge *heap[EDGE_MAX];
	int count;
} priorityQueue;

void push(priorityQueue *pq, Edge *edge) {
	if (pq->count >= EDGE_MAX) return;
	pq->heap[pq->count] = edge;
	int now = pq->count;
	int parent = (pq->count - 1) / 2;
	//새 원소를 삽입 후 상향식으로 힙 구성
	while (now > 0 && pq->heap[now]->cost < pq->heap[parent]->cost) {
		swap(pq->heap[now], pq->heap[parent]);
		now = parent;
		parent = (parent - 1) / 2;
	}
	pq->count++;
}

//우선순위 큐 추출 함수 구현
Edge* pop(priorityQueue *pq) {
	if (pq->count <= 0) return NULL;
	Edge *res = pq->heap[0];
	pq->count--;
	pq->heap[0] = pq->heap[pq->count];
	int now = 0, leftChild = 1, rightChild = 2;
	int target = now;
	//새 원소를 추출한 이후에 하향식으로 힙을 구성합니다.
	while (leftChild < pq->count) {
		if (pq->heap[target]->cost > pq->heap[leftChild]->cost) target = leftChild;
		if (pq->heap[target]->cost > pq->heap[rightChild]->cost && rightChild < pq->count) target = rightChild;
		if (target == now) break; //더 이상 내려가지 않아도 될 때 종료
		else {
			swap(pq->heap[now], pq->heap[target]);
			now = target;
			leftChild = now * 2 + 1;
			rightChild = now * 2 + 2;
		}
	}
	return res;
}

//간선 연결 리스트 구현
typedef struct Node {
	Edge *data;
	struct Node *next;
}Node;
Node** adj;
int ans[NODE_MAX];//특정한 노드까지의 최단 거리값 의미

void addNode(Node** target, int index, Edge* edge) {
	if(target[index] == NULL) {
		target[index] = (Node*)malloc(sizeof(Node));
		target[index]->data = edge;
		target[index]->next = NULL;
	}
	else {
		Node* node = (Node*)malloc(sizeof(Node));
		node->data = edge;
		node->next = target[index];
		target[index] = node;
	}
}

//다익스트라 사용
int main() {
	int n, m, k; //k는 출발하는 노드
	scanf("%d %d %d", &n, &m, &k);
	adj = (Node**)malloc(sizeof(Node*)*(n + 1)); //노드의 개수만큼 연결리스트 만듦
	for (int i = 1; i <= n; i++) {
		adj[i] = NULL;//연결리스트 초기화 
		ans[i] = INT_MAX;//맨처음 모든 노드로 갈 수 있는 비용은 무한으로 가정
	}
	priorityQueue *pq;//우선순위 큐를 만든 후
	pq = (priorityQueue*)malloc(sizeof(priorityQueue));
	pq->count = 0;
	for (int i = 0; i < m; i++) {//방향그래프 인 것 처럼 만듦
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);//a에서 b로 가는 비용이 c라고 하자고 입력받으면
		Edge *edge = (Edge*)malloc(sizeof(Edge));
		edge->node = b;//a번째 인덱스에 원소 b를 추가
		edge->cost = c;
		addNode(adj, a, edge);
	}//간선의 정보가 우선순위 큐에 담김

	//다익스트라 알고리즘을 시작합니다.
	ans[k] = 0;//출발하고자 하는 노드를 k라고 함
	Edge *start = (Edge*)malloc(sizeof(Edge));
	start->cost = 0; start->node = k; push(pq, start);//출발 노드에 대한 간선정보를 큐애 넣고
	while (1) {//큐에서 pop하면서 알고리즘 수행
			   //모든 간선에 대한 정보를 큐에 담았다가 빼게 됨
		Edge* now = pop(pq);//큐에 있는 원소를 하나 꺼내서
		if (now == NULL)break;//원소가 바닥날때까지 pop
		int curNode = now->node;//원소(노드)와 비용 정보를 담는다
		int curCost = now->cost;
		if (ans[curNode] < curCost)continue;//현재 보고 있는 비용이, 현재까지 테이블에 담은 비용보다 크다면 무시
		Node* cur = adj[curNode];//아니라면 특정 노드가 추가 됨을 의미

		//추가된 노드에 연결된 모든 노드를  확인하면서 적은 비용으로 테이블 갱신
		while (cur != NULL) {//특정 노드를 확인했을 때,
			Edge* temp = cur->data;
			temp->cost += curCost;//건너가는 비용을 담을 것
			if (temp->cost < ans[temp->node]) {//현재 테이블에 담겨있던 해당 노드에 대한 최단거리 비용이
											   //현재 보고 있는 비용보다 크다면
				ans[temp->node] = temp->cost;//작은 값으로 갱신
				push(pq, temp);//해당 간선을 큐에 담아서 다시 간선데이터를 확인할 수 있도록 함
			}
			cur = cur->next;
		}
	}
	//테이블 형태로 출력
	for (int i = 1; i <= n; i++) {
		if (ans[i] == INT_MAX)printf("INF\n"); //초기화 값인 INT_MAX와 같아면 해당 노드로는 도착할 수 없다는 의미
		else printf("%d\n", ans[i]);
	}
	system("pause");
}