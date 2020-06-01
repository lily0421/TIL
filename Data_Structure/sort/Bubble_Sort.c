#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 10

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

void print_all(int x[MAX]){
  for(int i = 0 ; i < MAX ; i++){
    printf("%d  ",x[i]);
  }
  printf("\n");
}


void bubble_sort(int x[MAX]){
  int k;
  int i;

  for(k = 0 ; k < MAX - 1 ;k++){

    for(i = k+1 ; i < MAX ; i++){
      printf("%d : %d\n" , k , i);
      if(x[k] > x[i]){
        swap_array(x,k,i);
      }
    }
    printf("\n");
    print_all(x);
  }
}

int main(){
  int a[MAX];

  Rand(a);

  print_all(a);

  clock_t start,finish;
  double duration;
  start = clock();

  bubble_sort(a);

  finish = clock();
  duration = (double)(finish - start)/CLOCKS_PER_SEC;
  printf("%f초 입니다\n",duration);
  return 0;
}
