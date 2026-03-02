#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int power;
    Node* next;

    Node(int c, int p) {
        coeff = c;
        power = p;
        next = NULL;
    }
};

void insertTerm(Node*& head, int coeff, int power);
void display(Node* head);
Node* addPolynomial(Node* p1, Node* p2);

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    insertTerm(poly1, 5, 2);
    insertTerm(poly1, 4, 1);
    insertTerm(poly1, 2, 0);

    insertTerm(poly2, 5, 1);
    insertTerm(poly2, 5, 0);

    cout << "Polynomial 1: ";
    display(poly1);

    cout << "Polynomial 2: ";
    display(poly2);

    Node* result = addPolynomial(poly1, poly2);

    cout << "Sum: ";
    display(result);

    return 0;
}
