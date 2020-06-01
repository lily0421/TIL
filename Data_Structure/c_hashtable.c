#include <stdio.h>
#include <stdlib.h>

struct bucket* hashTable = NULL;
int SIZE = 10;

struct node {
  int key;
  int value;
  struct node* next;
};

struct bucket {
  struct node* head;
  int count;
};

struct node* createNode(int key, int value) {
  struct node* newNode;
  newNode = (struct node*)malloc(sizeof(struct node));

  newNode->key = key;
  newNode->value = value;
  newNode->next = NULL;

  return newNode;
}

int hashFunction(int key) { return key % SIZE; }

void insert(int key, int value) {
  int hashIndex = hashFunction(key);
  struct node* newNode = createNode(key, value);

  // 아무 노드가 없는 경우
  if (hashTable[hashIndex].count == 0) {
    hashTable[hashIndex].head = newNode;
    hashTable[hashIndex].count = 1;
  }
  // 내가 넣고자 하는 인덱스에 이미 값이 있는 경우
  else {
    newNode->next = hashTable[hashIndex].head;
    hashTable[hashIndex].head = newNode;
    hashTable[hashIndex].count++;
  }

  return;
}

void removeNode(int key) {
  int hashIndex = hashFunction(key);
  struct node* node;
  struct node* trace;
  node = hashTable[hashIndex].head;

  // 아무 노드가 없는 경우
  if (node == NULL) {
    printf("\nno key found\n");
    return;
  }
  // 있으면
  while (node != NULL) {
    // 찾으면
    if (node->key == key) {
      // 포인터 바꾸기
      if (node == hashTable[hashIndex].head) {
        hashTable[hashIndex].head = node->next;
      } else {
        trace->next = node->next;
      }

      hashTable[hashIndex].count--;
      free(node);
      return;
    }

    trace = node;
    node = node->next;
  }

  printf("\nnot key found\n");
  return;
}

void search(int key) {
  int hashIndex = hashFunction(key);
  struct node* node = hashTable[hashIndex].head;

  if (node == NULL) {
    printf("\nno key found\n");
    return;
  }

  while (node != NULL) {
    // 찾았다
    if (node->key == key) {
      printf("key found key = [%d] value = [%d] ", node->key, node->value);
      return;
    }
    node = node->next;
  }
  printf("\nno key found\n");
  return;
}

void display() {
  struct node* horse;

  for (int i = 0; i < SIZE; i++) {
    horse = hashTable[i].head;
    printf("Bucket[%d] : ", i);
    while (horse != NULL) {
      printf("(key: %d, val: %d) -> ", horse->key, horse->value);
      horse = horse->next;
    }
    printf("\n");
  }

  printf("\n------------- end of display -------------\n");
  return;
}

int main() {
  hashTable = (struct bucket*)malloc(SIZE * sizeof(struct bucket));
  insert(0, 1);
  insert(1, 10);
  insert(11, 10);
  insert(21, 10);
  insert(31, 10);
  insert(6, 25);
  insert(97, 4);

  display();

  removeNode(31);
  removeNode(11);

  display();

  search(6);
  search(85);
}