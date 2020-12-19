#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
 
int top = -1;
char stack[MAX];
 
// function prototypes
void push(char);
void pop();
void find_top();
 
int main()
{
	int i;
	char a[MAX];

    while(1){
    
	    printf("enter expression\n");
	    scanf("%s", a);

	    for (i = 0; a[i] != '\0';i++)
	    {
		    if (a[i] == '(' || a[i] == '{' || a[i] == '[')
		    {
			    push(a[i]);
		    }
		    else if (a[i] == ')' || a[i] == '}' || a[i] == ']')
		    {
			    pop();
		    }
	    }
	   find_top();
    }
}
 
// to push elements in stack
void push(char a)
{
    if(top == (MAX-1)){
        printf("Stack Overflow\n");
        return;
    }
	stack[top] = a;
	top++;
}
 
// to pop elements from stack
void pop()
{
	if (top == -1)
	{
		printf("expression is invalid\n");
		exit(0);
	}	
	else
	{		
		top--;
	}
}
 
// to find top element of stack
void find_top()
{
	if (top == -1)
		printf("-> expression is valid\n\n");
	else
		printf("-> expression is invalid\n\n");
}
