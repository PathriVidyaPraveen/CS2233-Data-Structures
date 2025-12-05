#include<bits/stdc++.h>
using namespace std;

// node of singly linked list of stack
typedef struct Node {
    int data;
    Node* next;
} Node;

// stack data structure defined

typedef struct Stack {
    Node* top;
} Stack;

// helper to initilaize the stack

void initialiseStack(Stack* s){
    s->top = NULL;
    return;
}

// helper to check if stack is empty or not

bool isEmpty(Stack* s){
    if(s->top == NULL){
        return true;
    }
    return false;
}

// function to push an element onto the top of the stack

void push(Stack* s , int data){
    Node* new_node = (Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

// function to pop an element from the top of the stack

int pop(Stack* s){
    if(isEmpty(s)){
        cout << "Stack underflow!" << endl;
        return -1;
    }
    Node* temp = s->top;
    int pop_value = temp->data;
    s->top = s->top->next;
    free(temp);
    return pop_value;
}

// function that helps us to see the top value if stack without popping it

int peek(Stack* s){
    if(isEmpty(s)){
        cout << "Stack underflow!" << endl;
        return -1;
    }
    return s->top->data;
}

// helper function to print the stack elements

void printStack(Stack* s){
    Node* curr = s->top;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
    return;
}

// helper function to insert an element into sorted stack

// recursively find out the position of an element in the sorted stack and push it there and then keep again
// all the popped elements in the recursion calls back into the stack

void insertElementIntoSortedStack(Stack* s, int x){
    if(isEmpty(s) || x >= peek(s)){
        push(s,x);
        return;
    }
    int pop_value_temp = pop(s);
    insertElementIntoSortedStack(s,x);
    push(s,pop_value_temp);
    return;

}

// main function (recursive approach) to sort a stack in descending order


void sortStack(Stack* s){
    if(!isEmpty(s)){
        // take out the top element and sort remaining stack recursively and insert the top element back 
        // into the stack
        int x = pop(s);
        sortStack(s);
        insertElementIntoSortedStack(s,x);
    }

    return;
}
// main function for inputs and outputs and sorting stack using recursion
int main(){

    int n;
    cin >> n;
    Stack stack_input;
    initialiseStack(&stack_input);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        push(&stack_input,x);
    }

    sortStack(&stack_input);




    printStack(&stack_input);



    return 0;
}