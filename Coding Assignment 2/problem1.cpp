#include<bits/stdc++.h>
using namespace std;
#define MAX 10000

// inorder traversal
void inorder(string tr[] , int n){
    int st[MAX];
    int top = -1;
    int curr = 1;

    while(curr <=n || top!= -1){
        while(curr <= n && tr[curr] != "NULL"){
            top++;
            st[top] = curr;
            curr = 2 * curr;
            /// goes left;
        }
        if(top != -1){
            curr = st[top];
            top--;
            cout << tr[curr] << " ";
            curr = 2 * curr + 1;
            // goes right
        }else{
            break;
        }
    }

    cout << endl;
}

// pre order traversal

void preorder(string tr[] , int n){
    int st[MAX];
    int top = -1;

    if(n == 0 || tr[1] == "NULL"){
        cout << endl;
        return;
    }

    top++;
    st[top] = 1;

    while(top != -1){
        int curr = st[top];
        top--;



        if(curr > n || tr[curr] == "NULL"){
            continue;
        }


        cout << tr[curr] << " ";

        // left

        if(2*curr +1 <= n){
            top++;
            st[top] = 2* curr +1;

        }

        if(2*curr <= n){
            top++;
            st[top] = 2*curr;
        }
    }

    cout << endl;
}

//  postorder traversal

void postorder(string tr[] , int n){
    int st1[MAX] ;
    int st2[MAX];

    int top1 = -1;
    int top2 = -1;

    if(n==0 || tr[1] == "NULL"){
        cout << endl;
        return;
    }
    top1++;
    st1[top1] = 1;
    while(top1 != -1){
        int curr = st1[top1];
        top1--;
        if(curr > n || tr[curr] == "NULL"){
            continue;
        }
        top2++;

        st2[top2] = curr;




        if(2*curr <= n){
            top1++;
            st1[top1] = 2*curr;
        }

        if(2*curr + 1 <= n){
            top1++;
            st1[top1] = 2*curr+1;
        }
    }

    while(top2 != -1){
        cout << tr[st2[top2]] << " ";
        top2--;
    }

    cout << endl;
}

// main function

int main(){

    int k;
    cin >> k;
    while(k--){
        string tr[MAX]; // this stores numbers or NULL string
        int n=0;

        // reads one line until newline found

        string token;
        while(cin >> token){
            n++;
            tr[n] = token;
            if(cin.peek() == '\n'){
                break;
            }
        }
        inorder(tr,n);
        preorder(tr,n);
        postorder(tr,n);


    }
}