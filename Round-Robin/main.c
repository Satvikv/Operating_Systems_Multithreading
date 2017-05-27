#include <stdio.h>
#include <stdlib.h>
#include "schedule.h"
//unsigned long int arr[100000]={0};

unsigned long int find_nth_fibonacci(int n){
 
   if(n==1)
	    return 1;
	if(n==0)
		return 0;
	/*if(arr[n]!=0){
	   return arr[n];
	}
	arr[n-1]=find_nth_fibonacci(n-1);
	arr[n-2]=find_nth_fibonacci(n-2);*/
   return find_nth_fibonacci(n-1)+find_nth_fibonacci(n-2);
}
void thread_function(void *ptr){

   printf("New Thread Started\n");
   //int *n=(int *)malloc(sizeof(int *));
   printf("%d\n",*(int*)ptr);
   printf("Result %li\n",find_nth_fibonacci((*(int* )ptr)));
   yield();
   printf("New Thread Still running\n");
}


int main(){

  scheduler_begin();
  int n1=1,n2=3,n3=4;
  
  
  printf("the number is %li\n",find_nth_fibonacci(n2));
  
  thread_fork(thread_function,&n1);
  
  thread_fork(thread_function,&n2);
  
  thread_fork(thread_function,&n3);
  printf("Back to Main\n");
  scheduler_end();
}