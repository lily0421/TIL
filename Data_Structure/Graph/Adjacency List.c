/*방향가중치 그래프와 인접 리스트 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//연결리스트 구조체 만들기
typedef struct{ //한개의 노드를 만들 것임.
	int	index; //인덱스
	int distance;//가중치(거리)
	struct Node *next;//연결리스트니, 다음 노드에 연결
}Node;

//연결리스트 삽입 함수
void addFront (Node *root, int index, int distance ){//앞에 추가
	Node *node = (Node *)malloc(sizeof(Node));//한개의 노드를 노드 크기만큼 동적할당
	node->index = index;
	node->distance = distance;//초기화
	node->next = root->next;//차례대로 연결
	root->next = node;
}

//연결리스트 출력함수
void showAll( Node *root ){//특정 root가 있을 때 출력
	Node*cur = root->next;//root의 next부터 출발
	while (cur != NULL) {
		printf("%d(거리 : %d) ", cur->index, cur->distance);//어떤 원소, 그 원소까지 가는 거리
		cur = cur->next;//이렇게 연결리스트의 끝까지 간다
	}
}

//연결리스트 사용
int main() {
	int n, m;//노드의 개수, 간선의 개수
	scanf("%d %d", &n,&m);
	Node** a = (Node**)malloc(sizeof(Node*)*(n + 1));//인접리스트로 구현시, 노드의 개수만큼 연결리스트 필요 
													 //노드개수 +1만큼 동적할당 :
													 //각 인덱스가 1부터 시작할 것이라고 할것이기 때문
	for (int i = 1; i <= n; i++) {
		a[i] = (Node*)malloc(sizeof(Node));//각 노드를 동적할당으로 초기화
		a[i]->next = NULL;//root가 전부 NULL값을 가리킬 수 있도록
	}
	for (int i = 0; i < m; i++) {
		int x, y, distance; //각 간선의 정보들을 사용자들이 입력
		scanf("%d %d %d", &x, &y, &distance);
		addFront(a[x], y, distance);// 앞에 더해주는 방식 이용 
									//특정한 인덱스(노드)에 연결되어 있는 노드들을 Y라고 해서 연결하고
									//그 가중치 (distance)를 넣어줌
	}
	for (int i = 1; i < n; i++) {
		printf("원소 [%d]: ",i);//각 원소 출력
		showAll(a[i]);//특정 원소(특정 노드, 정점)에 연결되어 있는 다른 정점들을 전부 출력
		printf("\n");
	}
	system("pause");
	return 0;
}