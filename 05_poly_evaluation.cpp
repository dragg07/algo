//Polynomial Evaluation
#include <iostream>
#include<cmath>
using namespace std;

struct Node
{
    int coeff;
    int expo;
    Node* Link;
};

Node* Insert(Node* head, int co, int ex){
    Node* temp;
    Node* newP = new Node;
    newP->coeff = co;
    newP->expo = ex;
    newP->Link = nullptr;

    if (head == nullptr || ex > head->expo){
        newP->Link = head;
        head = newP;
    }
    else{
        temp = head;
        while (temp->Link != nullptr && temp->Link->expo >= ex)
            temp = temp->Link;
        
        newP->Link = temp->Link;
        temp->Link = newP;
    }
    return head;
}

Node* Create(Node* head){
    int n, i;
    int coeff, expo;

    cout << "Enter the number of terms: ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cout << "Enter the coefficient for term " << i + 1 << ": ";
        cin >> coeff;
        cout << "Enter the exponent for term " << i + 1 << ": ";
        cin >> expo;
        head = Insert(head, coeff, expo);
    }
    return head;
}

void Print(Node* head)
{
    if (head == nullptr)
    {
        cout << "No Polynomial.";
    }
    else
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->coeff << "x^" << temp->expo;
            temp = temp->Link;
            if (temp != nullptr)
                cout << " + ";
            else
                cout << endl;
        }
    }
}

int evaluatePoly(Node* head, int x){
    int result = 0;
    Node* temp = head;

    while(temp != nullptr){
        result += temp->coeff * pow(x, temp->expo);
        temp = temp->Link;
    }
    return result;
}

int main(){
    Node* head = nullptr;
    cout << "Enter the polynomial\n";
    head = Create(head);
    Print(head);
    int x;
    cout << "\nEnter the value of x for evaluation: ";
    cin >> x;
    int result = evaluatePoly(head, x);
    cout << "\nResult of polynomial evaluation at x = " << x << " is: " << result << endl;
    return 0;
}