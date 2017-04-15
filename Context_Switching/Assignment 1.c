#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 1024*1024

typedef struct thread

{
unsigned char *stack_pointer;
void (*initial_function)(void*);
void *initial_argument;

}thread;


void thread_switch(struct thread * old, struct thread * new);
void thread_start(struct thread * old, struct thread * new);

thread *current_thread;
thread *inactive_thread;



int factorial(int n) 
{
    return n == 0 ? 1 : n * factorial(n-1);
}

  
void fun_with_threads(void * arg) 
{
    int n = *(int*) arg;
    printf("%d! = %d\n", n, factorial(n));
 
}

void thread_wrap() 
{
    current_thread->initial_function(current_thread->initial_argument);
    yield();
    
}


void yield() {
    struct thread * temp = current_thread;
    current_thread = inactive_thread;
    inactive_thread = temp;
    thread_switch(inactive_thread, current_thread);
}



int main()
{
 

int * p = malloc(sizeof(int));
*p = 5;


current_thread = malloc(sizeof(thread));
inactive_thread = malloc(sizeof(thread)); 


current_thread->initial_argument = p;
current_thread->initial_function = fun_with_threads;
current_thread->stack_pointer = malloc(STACK_SIZE) + STACK_SIZE;

thread_start(inactive_thread, current_thread);


} 


