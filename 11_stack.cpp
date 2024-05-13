#include<iostream>
using namespace std;

#define MAX_SIZE 10

typedef struct{
    int arr[MAX_SIZE];
    int top;
}stack;

void initialize_stack(stack* s){
    s->top = -1;
}

bool isEmpty(stack* s){
    return s->top == -1;
}

bool isFull(stack* s){
    return s->top >= MAX_SIZE;
}

void push(stack* s, int val){
    if(!isFull(s)){
        s->arr[++s->top] = val;
        cout << val << " Sucessfully pushed into stack : \n";
    } else{
        cout << "\nStack overflow : ";
        return;
    }
}

int pop(stack* s){
    if(!isEmpty(s)){
        return s->arr[s->top--];
    } else{
        cout << "\nStack undeflow : ";
        return -1;
    }
}

void displayStack(stack* s){
    if(!isEmpty(s)){
        cout << "\nStack Elements top to bottom : " << endl;
        for(int i=s->top ; i>=0; i--){
            cout << s->arr[i] << " ";
        }
    } else{
        cout << "stack is empty : " << endl;
        return;
    }
}

int main(){
    stack *s = new stack;
    initialize_stack(s);

    int choice, value;
    while(choice != 5){
        cout << "\nStack operations : \n\n";
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display Stack" << endl;
        cout << "4. Top Position" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice : ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "\nEnter value tobe pushed :";
                cin >> value; 
                push(s, value);
                break;
            
            case 2:
                cout << "Popped Value : " << pop(s) << endl;
                break;
            
            case 3:
                displayStack(s);
                break;

            case 4:
                cout << "\nTop Position : " << s->top << endl;
                break;

            case 5:
                break;

            default: 
                cout << "\n Please choose from the list : \n";
        }

    }
    return 0;
}