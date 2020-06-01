#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 10

int compare(const void *a, const void *b){
        return *(int *)a - *(int *)b; //크면 양수, 작으면 음수 리턴
}

void Rand(int x[MAX]){
  srand((unsigned int)time(NULL));

  for(int i = 0 ; i < MAX ; i++){
    x[i] = rand()%100+1;
  }
}

void print_all(int x[MAX]){
  for(int i = 0 ; i < MAX ; i++){
    printf("%d  ",x[i]);
  }
  printf("\n");
}

int main(){
  int a[MAX];

  Rand(a);

//  print_all(a);

  clock_t start,finish;
  double duration;
  start = clock();

  qsort(a , MAX , sizeof(int) , compare);

  finish = clock();
  duration = (double)(finish - start)/CLOCKS_PER_SEC;
  printf("%f초 입니다\n",duration);

//  print_all(a);

  return 0;

}
