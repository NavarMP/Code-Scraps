// 11. 12.Addition of 2 polynomials using array

#include <stdio.h>

// Function to add two polynomials
void addPolynomials(int poly1[], int poly2[], int degree1, int degree2, int result[]) {
    int i, maxDegree;
    maxDegree = (degree1 > degree2) ? degree1 : degree2;
    for (i = 0; i <= maxDegree; i++) {
        result[i] = (i <= degree1 ? poly1[i] : 0) + (i <= degree2 ? poly2[i] : 0);
    }
}

// Function to print a polynomial
void printPolynomial(int poly[], int degree) {
    int i;
    for (i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            if (i > 1) {
                printf("%dx^%d + ", poly[i], i);
            } else if (i == 1) {
                printf("%dx + ", poly[i]);
            } else {
                printf("%d", poly[i]);
            }
        }
    }
    printf("\n");
}

int main() {
    printf ("Addition of 2 polynomials using array\n");
    
    int degree1, degree2;
    printf("Enter the degree of polynomial 1: ");
    scanf("%d", &degree1);
    int poly1[degree1 + 1];
    for (int i = degree1; i >= 0; i--) {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &poly1[i]);
    }

    printf("Enter the degree of polynomial 2: ");
    scanf("%d", &degree2);
    int poly2[degree2 + 1];
    for (int i = degree2; i >= 0; i--) {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &poly2[i]);
    }

    int result[degree1 > degree2 ? degree1 + 1 : degree2 + 1];
    addPolynomials(poly1, poly2, degree1, degree2, result);

    printf("Polynomial 1: ");
    printPolynomial(poly1, degree1);
    printf("Polynomial 2: ");
    printPolynomial(poly2, degree2);
    printf("Result: ");
    printPolynomial(result, degree1 > degree2 ? degree1 : degree2);

    return 0;
}