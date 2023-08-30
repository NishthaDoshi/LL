#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* pre;
    Node* next;
    Node(int data){
        val = data;
        pre = NULL;
        next = NULL;
    }
};
Node* head = NULL;

void insertAthead(Node* &head,int val){
    Node* new_node = new Node(val);
    new_node -> next = head;
    head -> pre = new_node;
    head = new_node; 
}

void insertAttail(Node* &head,int val){
    Node* new_node = new Node(val);
    Node* temp = head;
    while(temp -> next != NULL){
        temp -> pre = temp;
        temp = temp -> next;
    }
    new_node -> pre = temp;
    temp -> next = new_node;
}

void insertAtposition(Node* &head,int val,int pos){
    Node* new_node = new Node(val);
    if(pos == 0){
        insertAthead(head,val);
        return;
    }
    Node* temp = head;
    Node* temp2 = head->next;
    int cnt = 1;
    while(cnt < pos){
        cnt++;
        temp = temp -> next;
    }
    if(temp -> next == NULL){
        new_node -> pre = temp;
        new_node -> next = NULL;
        temp->next = new_node;
        return;
    }
    new_node -> pre = temp;
    new_node -> next = temp -> next;
    temp -> next -> pre = new_node;
    temp -> next = new_node;
}

void deleteAtposition(Node* &head,int pos){
    if(pos == 0){
        head -> next -> pre = NULL;
        head = head -> next;
        return;
    }
    int cnt = 1;
    Node* temp = head;
    while(cnt < pos){
        cnt++;
        temp = temp -> next;
    }
    if(temp -> next -> next == NULL){
        temp -> next -> pre = NULL;
        temp -> next = NULL;
        return;
    }

    Node* temp2 = temp -> next;
    temp -> next = temp2 -> next;
    temp2 -> next -> pre = temp;
}
void display(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> val << "->";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}
int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    display(head);
    insertAthead(head,55);
    display(head);
    insertAttail(head,99);
    display(head);
    insertAtposition(head,3,3);
    display(head);
    insertAtposition(head,5,4);
    display(head);
    insertAtposition(head,5,2);
    display(head);
    deleteAtposition(head,5);
    display(head);
    return 0;
}
