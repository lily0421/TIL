/*이진 탐색 트리*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int	data;
	struct Node * leftChild;
	struct Node * rightChild;
}Node;

//삽입
Node* insertNode(Node* root, int data){
	if (root == NULL) {//root가 null일 때는 초기화 
		root = (Node *)malloc(sizeof(Node));
		root->leftChild = root->rightChild = NULL;
		root->data = data;
		return root;
	}
	else{
		if (root->data > data) {//루트가 가지고 있는 데이터 보다, 우리가 삽입하고자 하는 노드가 작다면
			root->leftChild = insertNode(root->leftChild, data);//왼쪽으로 이동해서 왼쪽에 삽입
		}
		else{
			root->rightChild = insertNode(root->rightChild, data);
		}
	}
	return root;
}

//탐색
Node* searchNode (Node* root, int data ){
	if (root == NULL) return NULL;
	if (root->data == data) return root;//해당 노드를 발견했다면 리턴
	else if (root->data > data) return searchNode(root->leftChild, data);//우리가 찾고자 하는 데이터가 더 작다면
																		 //왼쪽자식으로 탐색
	else return searchNode(root->rightChild, data);//그렇지 않다면 오른쪽 자식으로 탐색
}//탐색 실패시 null반환

//순회
void preorder(Node * root){//전위 순회 방식
	if (root == NULL) return;
	printf("%d ", root->data);
	preorder(root->leftChild);
	preorder(root->rightChild);
}

//작은 원소 찾기
Node* findMinNode(Node * root ){
	Node* node = root;
	while(node->leftChild != NULL){
		node = node->leftChild;
	}
	return node;
}

//삭제 함수
Node* deleteNode(Node* root, int data ){
	Node* node = NULL;
	if (root == NULL) return NULL;//찾고자 하는 노드를 못찾으면 null
	if (root->data > data) root->leftChild = deleteNode(root->leftChild, data);//찾고자 하는 노드가 더 작으면 왼쪽으로
	else if(root->data < data) root->rightChild = deleteNode(root->rightChild, data);//그렇지 않으면 오른쪽으로
	else {//해당 노드 발견
		if (root->leftChild != NULL && root->rightChild != NULL) {//노드 한개 이상 갖음
			node = findMinNode(root->rightChild);//오른쪽에서 바로 다음으로 큰 값 찾음
			root->data = node->data;//노드의 데이터로 바꿔치기
			root->rightChild = deleteNode(root->rightChild, node->data);//해당 노드는 지워짐
		}
		else {
			node = (root->leftChild != NULL) ? root->leftChild : root->rightChild; 
			//왼쪽 자식이 존재하면 왼쪽 자식을 노드에 담고, 아니라면 오른쪽 자식을 노드에 담음
			free(root);// 현재 노드 할당 해제
			return node;//해당 자식노드를 리턴
		}
	}
	return root;
}

//이용
int main(void) {
	Node* root = NULL;
	root = insertNode(root, 30);
	root = insertNode(root, 17);
	root = insertNode(root, 48);
	root = insertNode(root, 5);
	root = insertNode(root, 23);
	root = insertNode(root, 37);
	root = insertNode(root, 50);
	root = deleteNode(root, 30);
	preorder(root);
	system("pause");
}
