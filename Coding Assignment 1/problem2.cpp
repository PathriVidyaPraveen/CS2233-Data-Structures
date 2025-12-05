#include <bits/stdc++.h>
using namespace std;

// node of doubly linked list

typedef struct Node {
    int data;
    struct Node* np;
} Node;

// helper function for XOR ing 2 pointers

Node* XOR(Node* a , Node* b) {
    return (Node*)( (uintptr_t)(a) ^ (uintptr_t)(b) );
}

Node* head = NULL;
Node* tail = NULL;

// Operation 1: Search for a value x in the list

void searchElement(int x){
    Node* curr = head;

    Node* prev = NULL;

    Node* next;
    while(curr!= NULL){
        if(curr->data == x){
            cout << "Element is present" << endl;
            return;
        }

        next = XOR(prev,curr->np);
        prev = curr;
        curr=next;

    }
    cout << "Element is not present" << endl;
    return;

}

// Operation 2: Insert the value x into the list at the head or beginning of list

// helper function to print the entire double linked list

void print(){
    Node* curr = head;
    Node* prev = NULL;
    Node* next;

    while(curr != NULL){
        cout << curr->data << " ";

        next = XOR(prev , curr->np);

        prev=curr;
        curr=next;
    }
    cout << endl;
    return;

}

// insert element function

void insertElement(int x){
    Node* newnode = (Node*)malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->np = XOR(NULL,head);

    if(head != NULL){
        Node* next = XOR(NULL,head->np);
        head->np = XOR(newnode,next);
    } else{
        tail = newnode; // first element



    }
    head = newnode;
    print();
}

// Operation 3: Delete the value x from the list

void deleteElement(int x){
    Node* curr = head;
    Node* prev = NULL;
    Node* next;

    while(curr !=NULL){
        if(curr->data == x){
            next = XOR(prev,curr->np);
            //update prev
            if(prev!=NULL){
                prev->np=XOR(XOR(prev->np, curr),next);

            }else{
                head = next; // just delete head
            }
            // update next pointer
            if(next){
                next->np = XOR(prev,XOR(next->np,curr));
            }else{
                tail = prev; // just delete tail
            }


free(curr);
            print();
            
            return;

        }
        next = XOR(prev,curr->np);
        prev=curr;
        curr=next;
    }

    cout << "Element is not present" << endl;
    return;
}

// Operation 4: Reverse the list in O(1)

void reverseList(){
    Node* temp = head;
    head = tail;
    tail = temp;
    print();
    return;
}

// main function to take putputs and perform corresponding operations

int main(){

    int k;
    cin >> k;
    while(k--){
        int op;
        cin >> op;
        int x;
        switch(op){
            case 1:
            
            cin >> x;
            searchElement(x);
            break;
            case 2:
            
            cin >> x;
            insertElement(x);
            break;
            case 3:
            
            cin >> x;
            deleteElement(x);
            break;
            case 4:
            reverseList();
            break;
        }
    }


    return 0;
}