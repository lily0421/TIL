/*무방향 비가중치 그래프와 인접행렬*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a[1001][1001];//전체노드 정점이 1000개 존재
int n, m;

int main() {
	scanf("%d %d", &n, &m);//노드개수, 간선개수 입력받음
	for (int i = 0; i < m; i++) {//간선의 개수만큼 어떻게 연결되어 있는지
		int x, y;
		//1 2 입력받음 => 1과 2가 열결
		scanf("%d %d", &x, &y);
		a[x][y] = 1;//1번정점에 두번째 인덱스에 1넣고,
		a[y][x] = 1;//2번 정점에 첫번째 인덱스에 1넣음 
					//서로 연결-방향성 없기 때문
	}
	/*전체 연결 된 것 출력*/
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	system("pause");
}
/*공간을 1개 더 줘서 int i가 1부터 시작도록 했다*/
