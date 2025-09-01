#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX 100

char stack[MAX];
int top = -1;
//push function
void push(char c)
{
	if (top < MAX-1)
	{
		stack[++top]=c;
	}
}
//pop function
char pop()
{
	if(top >= 0)
	{
		return stack[top--];
	}
	return -1;
}
//peek function
char peek()
{
	if(top >= 0)
	{
		return stack[top];
	}
	return -1;
}
// function todefine operator precedence
int precedence(char op)
{
	switch(op)
	{
		case'*':
		case'/':
		case'%':return 2;	
		case'+':
		case'-':return 1;
		default : return 0; 
	}
}
//function to check if character is operator 
int isoperator(char c)
{
	return(c=='+'||c=='-'||c=='*'||c=='/'||c=='%');
}
//infix to postfix conversion
void infixToPostfix (char infix[],char postfix[])
{
	int i,k=0;
	char symbol;
	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];
		//operand ? drectly add to postfix
		if(isalnum(symbol))
		{
			postfix[k++]=symbol;
		}
		// left pranthesis ? push to stack
		else if (symbol=='c')
		{
			push(symbol);
		}
		// right paranthesis ? pop until '('
		else if(symbol ==')')
		{
			while(top!=-1 && peek() != '(')
			{
				postfix[k++] = pop();
			}
			pop();
		}
		//operator
		else if(isoperator(symbol))
		{
			while(top!=-1 && precedence(peek()) >= precedence(symbol))
			{
				postfix[k++]=pop();
			}
			push(symbol); 
		}
    }
    while(top!=-1)
    {
    		postfix[k++]=pop();
	}
	postfix[k]='\0' ; //null terminate string
}

int main()
{
	char infix[MAX],postfix[MAX];
	printf("Enter an infix expression: ");
	scanf("%s",infix);
	infixToPostfix(infix,postfix);
	printf("postfix expression: %s\n",postfix);
	return 0;
}

