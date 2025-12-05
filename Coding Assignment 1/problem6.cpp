#include<bits/stdc++.h>
using namespace std;

// node for doubly linked list

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// stack definition with keeping track of middle node

typedef struct Stack {
    Node* head;
    Node* top;
    Node* middle;
    int num_elements;

} Stack;

// helper fucntion to initialize a stack

void initializeStack(Stack* s){
    s->head = NULL;
    s->top = NULL;
    s->middle = NULL;

    s->num_elements = 0;
    return;
}

// function to push an element onto the top of the stack in O(1)

void push(Stack* s,int data){
    Node* new_node = (Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if(s->num_elements == 0){
        s->head = new_node;
        s->top = new_node;
        s->middle = new_node;
        s->num_elements++;
        return;
    }

    s->top->next = new_node;
    new_node->prev = s->top;
    s->top = new_node;
    s->num_elements++;

    if(s->num_elements % 2 == 1){
        s->middle = s->middle->next;
    }

}

// function to pop the top element of the stack in O(1)

void pop(Stack* s){
    if(s->num_elements == 0){
        cout << "Stack Underflow" << endl;
        return;
    }
    cout << s->top->data << endl;
    Node* temp = s->top;
    s->top = s->top->prev;
    if(s->top){
        s->top->next = NULL;
    }
    s->num_elements--;

    // update the middle pointer

    if(s->num_elements == 0){
        s->head = NULL;
       
        s->middle = NULL;
    }else if(s->num_elements % 2 == 0){
        s->middle = s->middle->prev;
    }

    free(temp);
    return;

}

// function to find the middle element in O(1)

void findMiddle(Stack* s ){
    if(s->num_elements == 0){
        cout << "Stack Empty" << endl;
        return;
    }
    cout << s->middle->data << endl;
}

// function to remove the middle element of the stack in O(1)

void deleteMiddle(Stack* s){
    if(s->num_elements == 0){
        cout << "Stack Empty" << endl;
        return;
    }
    cout << s->middle->data << endl;
    Node* temp = s->middle;
    if(s->middle->prev){
        s->middle->prev->next = s->middle->next;
    }
    if(s->middle->next){
        s->middle->next->prev = s->middle->prev;
    }
    if(s->middle == s->head){
        s->head = s->middle->next;
    }
    if(s->middle == s->top){
        s->top = s->middle->prev;
    }
    s->num_elements--;

    // update middle pointer

    if(s->num_elements == 0){
        s->head = NULL;
        s->top = NULL;
        s->middle = NULL;
    }else if(s->num_elements % 2 == 0  ){
        s->middle = temp->prev; // move left when number of elements is even
    }else{
        s->middle = temp->next; // move right when number of elementts is odd
    }

    free(temp);
}

// main functions to take inputs and perform according operations



int main(){

    int q;
    cin >> q;
    Stack stack_input;
    initializeStack(&stack_input);
    while(q--){
        int op;
        cin >> op;
        switch(op){
            case 1:
            int x;
            cin >> x;
            push(&stack_input,x);
            break;
            case 2:
            pop(&stack_input);
            break;
            case 3:
            findMiddle(&stack_input);
            break;
            case 4:
            deleteMiddle(&stack_input);
            break;

        }
    }


    return 0;
}