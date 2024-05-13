#include<iostream>
using namespace std;

typedef struct node{
    int data;
    struct node* next;
}node;

node* head = NULL;

void insertAtBegin(int val){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
        newnode->next = head;
    } else{
        node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }

    cout << "\nNode Inserted at begin with value : " << val << endl;
}

void insertEnd(int val){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;

    if(head == NULL){
        head=newnode;
        newnode->next = head;
    } else{
        node* temp = head;

        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next=head;
    }
    cout << "\nNode Inserted at end with value : " << val << endl;
}

void deleteBegin(){
    node* delnode = head;

    if(head==NULL){
        cout << "Queue is empty : " << endl;
        return;
    } else{
        node* temp=head;
        while(temp->next != head){
            temp=temp->next;
        }

        temp->next = head->next;
        head= head->next;
    }
    cout << "\nNode deleted with data : " << delnode->data << endl;
    free(delnode);
}

void deleteEnd(){
    node* delnode = head;
    while(delnode->next != head){
        delnode = delnode->next;
    }

    if(head==NULL){
        cout << "Queue is empty : " << endl;
        return;
    } else{
        node* temp=head;
        while((temp->next)->next != head){
            temp=temp->next;
        }

        temp->next = head;
    }

    cout << "\nNode deleted with data : " << delnode->data << endl;
    free(delnode);
}

void displayQueue(){
    if(head == NULL){
        cout << "Empty Queue : ";
        return;
    } else{
        cout << "\nQueue Nodes : \n";

        node* temp = head;
        do{
            cout << temp->data << " ";
            temp = temp->next;
        }while(temp != head);
    }
}

int main(){
    insertAtBegin(46);
    insertAtBegin(45);
    displayQueue();
    // insertAtBegin(47);
    insertEnd(66);
    insertEnd(69);
    displayQueue();

    deleteBegin();
    displayQueue();

    deleteEnd();
    displayQueue();

    return 0;
}