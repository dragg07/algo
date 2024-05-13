#include <iostream>
using namespace std;

struct Link {
    int coff;
    int pow;
    struct Link* next;
};

Link* poly1 = nullptr;
Link* poly2 = nullptr;
Link* poly = nullptr;
Link* poly3 = nullptr;

void create(Link* node) {
    do{
        cout << "\nEnter coefficient: ";
        cin >> node->coff;
        cout << "Enter power: ";
        cin >> node->pow;
        char ch;
        cout << "\nContinue (y/n): ";
        cin >> ch;
        if (ch != 'y' && ch != 'Y')
            break;
        
        node->next = new Link;
        node = node->next;
        node->next = nullptr;
    }while(true);
}

void show(Link* node) {
    while (node != nullptr) {
        cout << node->coff << "x^" << node->pow;
        if (node->next != nullptr){
            if((node->next)->coff > 0)
                cout << "+";

            else
                cout << "";
        }
        node = node->next;
    }
}

void polyadd() {
    while (poly1 && poly2) {
        if (poly1->pow > poly2->pow) {
            poly->pow = poly1->pow;
            poly->coff = poly1->coff;
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            poly->pow = poly2->pow;
            poly->coff = poly2->coff;
            poly2 = poly2->next;
        } else {
            poly->pow = poly1->pow;
            poly->coff = poly1->coff + poly2->coff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        if(poly1 || poly2) {
            poly->next = new Link;
            poly = poly->next;
            poly->next = nullptr;
        }
    }
    while (poly1 || poly2) {
        if (poly1) {
            poly->pow = poly1->pow;
            poly->coff = poly1->coff;
            poly1 = poly1->next;
        }
        if (poly2) {
            poly->pow = poly2->pow;
            poly->coff = poly2->coff;
            poly2 = poly2->next;
        }
        if(poly1 || poly2) {
            poly->next = new Link;
            poly = poly->next;
            poly->next = nullptr;
        }
    }
}

int main() {
    poly1 = new Link;
    poly2 = new Link;
    poly = new Link;
    poly3 = poly;
    cout << "\nEnter 1st polynomial:\n";
    create(poly1);
    cout << "\nEnter 2nd polynomial:\n";
    create(poly2);
    cout << "\n1st Polynomial: ";
    show(poly1);
    cout << "\n2nd Polynomial: ";
    show(poly2);
    polyadd();
    cout << "\nAdded Polynomial: ";
    show(poly3);
    cout << endl;
    return 0;
}