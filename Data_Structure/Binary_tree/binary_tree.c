#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct Node *leftC;
	struct Node *rightC;
} Node;

Node* initNode(int data, Node *leftC, Node *rightC) { //초기화
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->leftC = leftC;
	node->rightC = rightC;
	return node; //노드의 포인터 반환
}

/*전위 순회*/
void preorder(Node* root) { //특정한 root node가 주어졌을 때
	if (root) {//node의 값이 null값이 아니라면
		printf("%d ", root->data); //자기자신을 출력후
		preorder(root->leftC); // 왼쪽으로
		preorder(root->rightC); //그 후 오른쪽으로
	}
}

/*후위 순회*/
void postorder(Node* root) {
	if (root) {//node의 값이 null값이 아니라면		
		preorder(root->leftC); //왼쪽으로
		preorder(root->rightC); //오른쪽으로
		printf("%d ", root->data); //자기자신 출력
	}
}

int main(void){
	Node* n7 = initNode(50, NULL, NULL);
	Node* n6 = initNode(37, NULL, NULL);
	Node* n5 = initNode(23, NULL, NULL);
	Node* n4 = initNode(5, NULL, NULL);
	Node* n3 = initNode(48, n6, n7);
	Node* n2 = initNode(17, n4, n5);
	Node* n1 = initNode(30, n2, n3);
	preorder(n1);
	printf("\n");
	postorder(n1);
	system("pause");
	return 0;
}