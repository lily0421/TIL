#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001
typedef struct {
	int	index;
	struct	Node *next;
}Node;

Node**a; //연결리스트 여러개
int n, m, c[MAX_SIZE]; //n-정점, m-간선,c- 방문 했는지 확인

/*스택(stack)연결처럼 구현*/
void addFront(Node *root, int index) {//연결리스트 삽입함수
	Node *node = (Node*)malloc(sizeof(Node)); //동적할당-
	node->index = index;
	node->next = root->next;//root에 있는 next자체를 node의 next로 삼음.
	root->next = node; // 연결리스트 앞쪽에 붙일 수 있도록
}

/*깊이 우선 탐색*/
void dfs(int x) {//특정 x, 인덱스의 노드에서 깊이우선 탐색
	if (c[x]) { return; }//해당노드를 방문한 적있으면 return
	c[x] = 1;//이후에 해당 노드를 방문했다고, 방문 처리함
	printf("%d ",x);// 해당 노드 출력
	Node *cur = a[x]->next;//해당노드에 연결되어 있는 노드들 확인
	while (cur != NULL) {//NULL값이 아닐 때까지 반복 모든 노드 방문 가능
		int next = cur->index;//연결되어 있는 노드를 확인해서
		dfs(next);//노드에 dfs를 수행=>재귀적으로 함수 호출되어 ~
		cur = cur->next;//반복적으로 방문 가능.
	}
}

/*깊이 우선 탐색 이용*/
int main() {
	scanf("%d %d",&n,&m);
	a = (Node**)malloc(sizeof(Node*)*(MAX_SIZE));//정점의 개수만큼 사이즈 할당
	for (int i = 1; i <= n; i++) {//n개까지만 초기화
		a[i] = (Node*)malloc(sizeof(Node));
		a[i]->next = NULL;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		addFront(a[x], y); //x에서 y로 갈 수 있음
		addFront(a[y], x); //y에서 x로 갈 수 있음	
	}
	dfs(1);//1부터 깊이우선탐색 실행
	system("pause");
	return	0;
}
//방문 순서는 명시되어 있지 않음