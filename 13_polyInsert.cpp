#include<iostream>
using namespace std;

typedef struct polynomial{
    int coeff;
    int expo;
    polynomial* next;
}poly;

poly* head = NULL;
poly* p1 = nullptr;
poly* p2 = nullptr;
poly* p3 = nullptr;

void create(poly* p){
    do{
        cout << "\nEnter coefficient: ";
        cin >> p->coeff;
        cout << "Enter expoer: ";
        cin >> p->expo;
        char ch;
        cout << "\nContinue (y/n): ";
        cin >> ch;
        if (ch != 'y' && ch != 'Y')
            break;
        
        p->next = new poly;
        p = p->next;
        p->next = nullptr;
    }while(true);
}

void show(poly* p){
    while(p != nullptr){
        cout << p->coeff << "X^" << p->expo;
        if(p->next != nullptr){
            if((p->next)->coeff < 0)
                cout << "";

            else
                cout << "+";
        }
        p = p->next;
    }
}

int main(){
    p1 = new poly;
    p2 = new poly;
    p3 = new poly;

    create(p1);
    show(p1);

    return 0;
}