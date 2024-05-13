#include <iostream>
using namespace std;

struct Node
{
    int coeff;
    int expo;
    Node* Link;
};

Node* Insert(Node* head, int co, int ex)
{
    Node* temp;
    Node* newP = new Node;
    newP->coeff = co;
    newP->expo = ex;
    newP->Link = nullptr;

    if (head == nullptr || ex > head->expo)
    {
        newP->Link = head;
        head = newP;
    }
    else
    {
        temp = head;
        while (temp->Link != nullptr && temp->Link->expo >= ex)
            temp = temp->Link;
        newP->Link = temp->Link;
        temp->Link = newP;
    }
    return head;
}

Node* Create(Node* head)
{
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
        cout << "No Polynomial." << endl;
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

void PolyMult(Node* head1, Node* head2)
{
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* head3 = nullptr;

    if (head1 == nullptr || head2 == nullptr)
    {
        cout << "Zero Polynomial" << endl;
        return;
    }
    while (ptr1 != nullptr)
    {
        while (ptr2 != nullptr)
        {
            head3 = Insert(head3, ptr1->coeff * ptr2->coeff, ptr1->expo + ptr2->expo);
            ptr2 = ptr2->Link;
        }
        ptr1 = ptr1->Link;
        ptr2 = head2;
    }
    Print(head3);
}

int main()
{
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    cout << "Enter the first polynomial" << endl;
    head1 = Create(head1);
    Print(head1);
    cout << endl;
    cout << "Enter the second polynomial" << endl;
    head2 = Create(head2);
    Print(head2);
    cout << endl;
    cout << "The result after multiplication of two polynomial is:-" << endl;
    PolyMult(head1, head2);
    return 0;
}
