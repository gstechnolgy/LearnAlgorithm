#include<stdio.h>
/*
 Program to perfom the insertion sort
 A [5,4,3,2,1] => [1,2,3,4,5]
 Time Complexity: O(n^2)
 Space Complexity: O(1) 
 for(i=1 to n-1)
    j=i
    while(j>0 and A[j]<A[j-1])
       swap(A[j], A[j-1])
       j=j-1
*/
void swap(int *a, int* b) {
   int temp;
   temp=*a;
   *a=*b;
   *b=temp;
}
void insertion_sort(int input[],int n) {
  int i,j;
  for(i=1; i<n; i++) {
     j=i;
     while((j>0) && (input[j]<input[j-1])) {
        swap(&input[j], &input[j-1]);
        j=j-1;  
     }
  }
}

int main() {
  int input[5]={5,4,3,2,1};
  insertion_sort(input,5);
  int i=0;
  for(i=0; i<5; i++) {
    printf("\t %d",input[i]);
  }
  printf("\n");
  return 0;
}
