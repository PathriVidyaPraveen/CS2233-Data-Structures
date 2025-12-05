#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 1000000 // maximum size of the stack to be used

// define a stack structure that stores maximum size of the stack and top element index along with array

typedef struct Stack {
    int max_size;
    char stack_array[MAX_SIZE];
    int top;
} Stack ;

// initialized the stack with given parameters

void initializeStack(Stack* stack,int size){
    stack->max_size = size;
    stack->top = -1;
    return;
}

// push an element to the top of the stack

void push(Stack* stack , char element){
    if(stack->top < stack->max_size-1){
        stack->top++;
        stack->stack_array[stack->top] = element;
    }else{
        cout << "Stack overflow!!" << endl;
    }
}

// pop an element from the top of the stack

char pop(Stack* stack){
    if(stack->top >= 0){
        int top_element = stack->stack_array[stack->top];
        stack->top--;
        return top_element;
    }else{
        cout << "Stack underflow!!" << endl;
        return ' ';
    }
}

// look at the top element of the stack without popping it

char peek(Stack* stack){
    if(stack->top >= 0){
        int top_element = stack->stack_array[stack->top];
        
        return top_element;
    }else{
        cout << "Stack underflow!!" << endl;
        return ' ';
    }
}

// returns true if stack is empty and false otherwise

bool isEmpty(Stack* stack){
    if(stack->top == -1){
        return true;
    }else{
        return false;
    }
}

// find out the precedence of the operation

int getPrecedence(char op){
    
    switch(op){
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '^': return 3;
    }

    return 0;
}

// main function to convert infix expression to postfix expression

string infixToPostfix(string infix){
    if(infix.empty()){
        return "";
    }

    string postfix(infix.length()+1,' ');
    Stack operatorStack; // stack that holds operators during conversion
    initializeStack(&operatorStack,MAX_SIZE);
    int precedence = 0;
    int postfix_index = 0; // keeps track of where we insert into postfix

    for(int i=0;i<infix.length();i++){
        char c = infix[i];
        precedence = getPrecedence(c);
        if(isalnum(c)){
            // if operand then directly add to postfix
            postfix[postfix_index] = c;
            postfix_index++;
        }else if(c == '('){
            // if '(' then push it to stack
            push(&operatorStack,c);
        }else if(c == ')'){
            // if ')', pop until '(' is found
            while(!isEmpty(&operatorStack) && peek(&operatorStack) != '('){
                postfix[postfix_index] = pop(&operatorStack);
                postfix_index++;
            }
            // pop the '(' and discard it
            pop(&operatorStack);
        }else{
            // Case 4: If operator (+, -, *, /, ^ etc.)
            // Pop operators with higher or equal precedence
            while(!isEmpty(&operatorStack)){
                char top_operator = peek(&operatorStack);
                int top_precedence = getPrecedence(top_operator);
                if((c == '^' && precedence < top_precedence) || (c != '^' && precedence <= top_precedence)){
                postfix[postfix_index] = pop(&operatorStack);
                postfix_index++;
                }else{
                    break;
                }

            }
            // Push current operator onto stack
            push(&operatorStack,c);
        }

       

    }

    // After scanning entire infix, pop remaining operators

    while(!isEmpty(&operatorStack)){
        postfix[postfix_index] = pop(&operatorStack);
        postfix_index++;
    }

    postfix[postfix_index] = '\0';

    return postfix;
}

// take inputs and apply function and return outputs

int main(){

    int k;
    cin >> k;
    while(k--){
        string infix;
        cin >> infix;
        string postfix = infixToPostfix(infix);
        cout << postfix << endl;
    }

    return 0;
}