/*우선순위 큐-완전 이진 트리 형태의 힙을 이용해 구현 가능*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 10000

//정의
void swap(int *a, int *b){
	int temp = *a;
	*a = b;
	*b = temp;
}//두개 위치 바꿈

typedef struct{
	int	heap[MAX_SIZE];// 한개의 힙이 배열형태로 만들어져 있음
	int count;//현재 힙에 들어있는 원소 개수
}priorityQueue; 

//삽입
void push(priorityQueue *pq, int data){//특정한 우선순위 큐에 data를 넣음
	if (pq->count >= MAX_SIZE) return;
	pq->heap[pq->count] = data; //data를 q에 담겨있는 원소의 개수에 해당하는 인덱스에 넣어줌
								//이러면 항상 완전한 이진트리의 마지막 원소로써 들어감
	int now = pq->count;//삽입된 data에 해당하는 인덱스
	int parent = (pq-> count - 1) / 2;
	//새 원소를 삽입한 이후에 상향식으로 힙을 구성합니다
	while (now > 0 && pq->heap[now] > pq->heap[parent]) {//부모보다 값이 더 크다면 
		swap(&pq->heap[now], &pq->heap[parent]);//위치를 서로 바꿔줌
		now = parent;
		parent = (parent - 1) / 2;//부모의 위치에서 힙 구성을 반복할 수 있도록
	}
	pq->count++;//삽입 후 count증가
}

//큐 추출
int pop(priorityQueue *pq){//특정 큐를 매개변수로 입력 받음
	if (pq-> count <= 0) return -9999;//더 이상 추출할 원소 없으면 오류
	int res = pq->heap[0];//추출할 원소. root노드의 값
	pq->count--;//count-1 
	pq->heap[0] = pq->heap[pq->count];//count에 해당하는 원소(마지막 원소)를 첫번째 root노드에 넣어줌
	//즉, root노드를 빼고 해당 root노드에 마지막 원소 넣음
	int	now = 0, leftChild = 1, rightChild = 2;
	int target = now;//target은 자기자신을 가리킴.후에는 바꾸고자하는 자식노드가 됨
	//새 원소를 추출한 이후에 하향식으로 힙을 구성합니다.
	while(leftChild < pq->count){//leftChild가 count보다 작을때만.즉 원소가 존재할때까지만
		if (pq->heap[target] < pq->heap[leftChild]) target = leftChild;//target ,leftChild바꿈
		if (pq->heap[target] < pq->heap[rightChild] && rightChild < pq->count) target = rightChild;//target에 rightChild넣어줌
																								   //rightChild < pq->count는 인덱스 벗어남을 방지
		if(target == now) break; //두 자식보다 본인이 더 크다면
								 //더 이상 내려가지 않아도 될 때 종료
		else {
			swap(&pq->heap[now], &pq->heap[target]);//자식 중에서 큰 값과 자신의 값 바꿈
			now = target;//아래로 내려가야 함
			leftChild = now * 2 + 1;
			rightChild = now * 2 + 2;
		}
	}
	return res;
}

//사용
int main(void){
	int n, data;
	scanf("%d", &n);
	priorityQueue	pq;
	pq.count = 0;

	for(int i = 0; i < n; i++) {
		scanf("%d", &data);
		push(&pq, data);
	}
	for(int i = 0; i < n; i++) {
		int	data = pop(&pq);
		printf("%d ", data);
	}
	return	0;
}