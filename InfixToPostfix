#include<stdio.h>
#define MAX 100

int precedence(char op) {
	if(op == '^') return 3;
	if(op == '*' || op == '/') return 2;
	if(op == '+' || op == '-') return 1;
	return 0;
}

int main() {
	char infix[MAX], postfix[MAX], stack[MAX];
	int top = -1, i = 0, j = 0;
	char ch;
	
	printf("Enter the infix expression: ");
	scanf("%s", infix);
	
	while(infix[i] != '\0') {
		ch = infix[i];
		
		if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= 0 && ch <= 9)) {
			postfix[j++] = ch;
		}
		
		else if(ch == '(') {
			stack[++top] = ch;
		}
		
		else if(ch == ')') {
			while(top != -1 && stack[top] != '(') {
				postfix[j++] = stack[top--];
			}
			top--;
		}
		
		else {
			while(top != -1 && precedence(stack[top]) >= precedence(ch)) {
				postfix[j++] = stack[top--];
			}
			stack[++top] = ch;
		}
		
		i++;
	}
	
	while(top != -1) {
		postfix[j++] = stack[top--];
	}
	
	postfix[j] = '\0';
	
	printf("The corresponding postfix expression is: %s \n", postfix);
	
	return 0;
}
