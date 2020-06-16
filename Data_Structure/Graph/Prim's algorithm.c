/*프림 알고리즘*/

//간선 구조체 정의 [최대 노드 : 1000개 / 최대 간선 : 100,000개]
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define NODE_MAX 1001
#define EDGE_MAX 20001 // 양방향 간선이므로 100,000 개

//간선에 대한 정보 담는 구조체
typedef struct {
	int cost;
	int node;
}Edge;

//두개 간선에 대한 정보를 swap함.우선순위 큐에 정보 담김
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
	Edge *heap[EDGE_MAX];//각 간선이 들어갈 수 있도록 배열을 만듦
	int count;
} priorityQueue;

void push(priorityQueue *pq, Edge *edge) {
	if (pq->count >= EDGE_MAX) return;//데이터를 넣을때, 총 간선을 넘어가면 리턴
	pq->heap[pq->count] = edge;//마지막 인덱스에 새로운 원소를 넣고
	int now = pq->count;
	int parent = (pq->count - 1) / 2;
	//새 원소를 삽입 후 상향식으로 힙 구성
		//root노드까지 올라가면서 힙 구성
	while (now > 0 && pq->heap[now]->cost < pq->heap[parent]->cost) {
		swap(pq->heap[now], pq->heap[parent]);
		now = parent;
		parent = (parent - 1) / 2;
	}
	pq->count++;
}

//우선순위 큐 추출 함수 구현
Edge* pop(priorityQueue *pq) { //원소가 간선(Edge)으로 바뀌었다
	if (pq->count <= 0) return NULL;
	Edge *res = pq->heap[0];
	pq->count--;
	pq->heap[0] = pq->heap[pq->count];//새 원소를 루트노드와 위치를 바꿔서 추출
	int now = 0, leftChild = 1, rightChild = 2;
	int target = now;
	//새 원소를 추출한 이후에 하향식으로 힙을 구성합니다.leaf노드까지 내려가면 전체 힙 구성
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
}Node; // 각 정점은 연결리스트로(인접리스트로 표현)

Node** adj;
int d[NODE_MAX];

void addNode(Node** target, int index, Edge* edge) {//특정 인덱스의 정점에 간선이 추가됨
	if(target[index] == NULL) {
		target[index] = (Node*)malloc(sizeof(Node));
		target[index]->data = edge;
		target[index]->next = NULL;
	}//특정 정점에 연결되어 있는 간선이 없다면, 첫번째 원소로 해당 간선으로 넣어줌
	else {//아니라면 연결리스트에 새롭게 삽입 
		Node* node = (Node*)malloc(sizeof(Node));
		node->data = edge;
		node->next = target[index];
		target[index] = node;
	}
}

//프림 사용
int main() {
	int n, m;//정점, 간선 개수
	scanf("%d %d", &n, &m);
	adj = (Node**)malloc(sizeof(Node*)*(n + 1)); //정점의 개수만큼 동적할당후 연결리스트로 만들어줌
	for (int i = 1; i <= n; i++) {
		adj[i] = NULL;//연결리스트 초기화 		
	}
	priorityQueue *pq;//우선순위 큐를 만든 후
	pq = (priorityQueue*)malloc(sizeof(priorityQueue));
	pq->count = 0;
	for (int i = 0; i < m; i++) {//모든 간선에 대한 정보를 받을 것
		int a, b, c;//c는 가중치(a에서 b까지 가는데 c만큼 소요됨)
		scanf("%d %d %d", &a, &b, &c);
		//무방향 그래프로 생각
		Edge *edge1 = (Edge*)malloc(sizeof(Edge));
		edge1->node = b;
		edge1->cost = c;
		addNode(adj, a, edge1);
		Edge *edge2 = (Edge*)malloc(sizeof(Edge));
		edge2->node = b;
		edge2->cost = c;
		addNode(adj, a, edge2);
	}

	//프림 알고리즘을 시작합니다.
	long long res = 0;
	Edge *start = (Edge*)malloc(sizeof(Edge)); //시작점 입력받음
	start->cost = 0; start->node = 1; push(pq, start);//시작점은 1, 처음비용은 0
	for (int i = 1; i <= n; i++) {//신장트리의 경우 총 n개의 정점이 최종적으로 만들어진 신장트리에 포함되어 n번까지 for문이 돈다
		int nextNode = -1, nextCost = INT_MAX;//다음노드와 비용
		while (1) { //방문하지 않은 노드들 중에서, 가장 비용이 적은 노드를 우선순위 큐에서 꺼냄
					//우선순위 큐에는 비용이 적은 순서로 되어 있음
			Edge* now = pop(pq);
			if (now == NULL)break;
			nextNode = now->node;
			if (!d[nextNode]) { 
				nextCost = now->cost;
				break;
			}
		}
		if (nextCost == INT_MAX) {
			printf("연결 그래프가 아닙니다.\n");//못 찾았다면 연결그래프가 아님
		}
		res += nextCost;//전체 최소 신장 트리를 만드는데 필요한 cost를 다 더해서 
		d[nextNode] = 1;//특정노드(간선의 길이가 작은 노드)를 방문처리
		Node* cur = adj[nextNode];
		while(cur != NULL) {//인접한 노드들을 확인하면서 그 정보를 우선순위 큐에 넣음
			push (pq, cur->data); 
			cur = cur->next;
		}
	}
	printf("%lld\n", res);
	system("pause");
}