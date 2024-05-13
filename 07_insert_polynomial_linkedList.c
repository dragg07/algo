#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coefficient;
    int exponent;
    struct Term *next;
};

typedef struct Term PolynomialTerm;

//Creating a new term
PolynomialTerm *createTerm(int coefficient, int exponent) {
    PolynomialTerm *term = (PolynomialTerm *)malloc(sizeof(PolynomialTerm));
    term->coefficient = coefficient;
    term->exponent = exponent;
    term->next = NULL;
    return term;
}

//For Adding new term in polynomial
void addTerm(PolynomialTerm **polynomial, int coefficient, int exponent) {
    if (coefficient == 0) {
        return;
    }
    PolynomialTerm *newTerm = createTerm(coefficient, exponent);
    if (*polynomial == NULL) {
        *polynomial = newTerm;
        return;
    }
    PolynomialTerm *current = *polynomial;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newTerm;
}

void displayPolynomial(PolynomialTerm *polynomial) {
    PolynomialTerm *current = polynomial;
    int isFirstTerm = 1;
    while (current != NULL) {
        if (current->coefficient < 0 && !isFirstTerm) {
            printf(" - ");
        }
        printf("%dx^%d ", abs(current->coefficient), current->exponent);
        isFirstTerm = 0;
        current = current->next;
    }
    printf("\n");
}

int main() {
    PolynomialTerm *polynomial = NULL;

    printf("Enter the Coefficients of Polynomial expression : \n");
    for(int i=2; i>=0; i--){
        int coff;
        printf("Enter Coefficient of x^%d: ", i);
        scanf("%d", &coff);
        addTerm(&polynomial, coff, i);
    }

    printf("Polynomial: ");
    displayPolynomial(polynomial);

    return 0;
}
