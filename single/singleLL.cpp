#include<bits/stdc++.h>
using namespace std;

class Node{
    public :
    int val;
    Node* next;

    Node(int data){
        val = data;
        next = NULL;
    }
};
Node* head = NULL;
void insertAthead(Node* &head,int val){
    Node* new_node = new Node(val);
    new_node -> next = head;
    head = new_node;
}

void insertAttail(Node* &head,int val){
    Node* temp=head;
    Node* new_node = new Node(val);
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = new_node;
}

void insertAtposition(Node* &head,int val,int pos){

    if(pos == 0){
        insertAthead(head,val);
        return;
    }
    Node* new_node=new Node(val);
    int cnt=1;
    Node* temp = head;
    while(cnt < pos-1){
        temp = temp -> next;
        cnt++;
    }
    new_node -> next = temp -> next;
    temp -> next = new_node;
}
// 0 based indexing
void deleteAtposition(Node* &head,int pos){
    if(pos == 0){
        head = head -> next;
        return;
    }
    int cnt = 1;
    Node* temp = head;
    Node* temp2 = NULL;
    while(cnt <= pos ){
        temp2 = temp;
        temp = temp -> next;
        // temp2 = temp;
        cnt++;
    }
    temp2 -> next = temp -> next;
    temp -> next= NULL;
}

void display(Node* &head){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->val << "->";
            temp = temp -> next;
        }
        cout << "NULL" << endl;
}

int main(){
    insertAthead(head,10);
    display(head);
    insertAthead(head,9);
    display(head);
    insertAttail(head,5);
    display(head);
    insertAtposition(head,2,2);
    display(head);
    deleteAtposition(head,1);
    display(head);
    deleteAtposition(head,2);
    display(head);
    return 0;
}
