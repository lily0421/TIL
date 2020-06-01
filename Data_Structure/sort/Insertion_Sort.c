#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 100000

void Rand(int x[MAX]){
  srand((unsigned int)time(NULL));

  for(int i = 0 ; i < MAX ; i++){
    x[i] = rand()%100+1;
  }

}

void swap_array(int x[MAX], int a , int b){
  int temp;

  temp = x[a];
  x[a] = x[b];
  x[b] = temp;

}

void intsertion_sort(int x[MAX]){

  int i ;
  int key;
  int j;

  for(i = 1 ; i < MAX ; i++){

      key = x[i];
      j = i-1;

      while(j >= 0 && x[j] > key){

        x[j+1] = x[j];
        j = j-1;

      }

      x[j+1] = key;

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

 // print_all(a);

  clock_t start,finish;
  double duration;
  start = clock();

  intsertion_sort(a);

  finish = clock();
  duration = (double)(finish - start)/CLOCKS_PER_SEC;
  printf("%f초 입니다\n",duration);


  return 0;

}
