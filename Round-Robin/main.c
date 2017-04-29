#include <stdio.h>
#include "schedule.h"


int find_nth_fibonacci(int n){
 
   if(n<2)
	    return 1;
	
   return find_nth_fibonacci(n-1)+find_nth_fibonacci(n-2); 
}
void thread_function(void *ptr){

   printf("New Thread Started\n");
   int n=(int *)ptr;
   
   printf("Result %d\n",find_nth_fibonacci(n));
    
   /*printf("X is %d, shared var is %d \n",x,shared_var);
   yield();
   printf("New Thread Restarted and  shared var %d\n",shared_var);
   printf("New Thread Ended shared var %d\n",shared_var);*/
}


int main(){

  scheduler_begin();
  int n1=12230,n2=13123,n3=12434;
  thread_fork(thread_function,&n1);
  thread_fork(thread_function,&n2);
  thread_fork(thread_function,&n3);
  scheduler_end(); 
}