#include<bits/stdc++.h>
using namespace std;

// node of a linked list

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// function for creating a new node with given integer data

Node* createNode(int data){
    Node* new_node = (Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// insert a new node at the end of the linked list

void insert(Node** head, int data){
    Node* newnode = createNode(data);
    if(*head == NULL){
        *head = newnode;
        return;
    }
    Node* current = *head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newnode;
    return;
}

// helper function to print the list as per output criteria

void printList(Node* head){
    if(head == NULL){
        return;
    }
    Node* current = head;
    while(current->next != NULL){
        cout << current->data << ", ";
        current = current->next;
    }
    cout << current->data << endl;
    return;
}

// main logic of the problem

Node* segregate_odd_even_indices(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* odd = head; // track odd indexed nodes
    Node* even = head->next; // track even indexed nodes
    Node* even_head = even; // keep head of even list to attach later



    // traverse until either we run out of even nodes 
    // or there's no next node after the current even node

    while(even != NULL && even->next != NULL){
        // link current odd node to next odd node and current even node to next even node
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    // attched entire even list after odd list
    odd->next = even_head;
    return head;
}

// main function for taking inpuut and printing output along with input parsing for comma separated values

int main(){

    string input;
    getline(cin,input);

    Node* list_input = NULL;

    stringstream ss(input);
    string token;
    while(getline(ss,token,',')){
        int val = stoi(token);
        if(val == -1){
            break;
        }
        insert(&list_input,val);

    }
    Node* list_result = segregate_odd_even_indices(list_input);
    printList(list_result);


    return 0;
}
