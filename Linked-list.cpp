#include <iostream>

// Linked List Node
struct Node {
    int info;
    Node* next;
};

int main() {
    Node *p = nullptr, *head = nullptr, *r = nullptr;
    int v, x = 1;

    // Insertion Operation
    while (x == 1) {
        p = new Node;

        if (p != nullptr) {
            std::cout << "ENTER VALUES YOU WANT TO INSERT : ";
            std::cin >> v;

            p->info = v;
            p->next = nullptr;

            if (head == nullptr && r == nullptr) {
                r = head = p;
            } else {
                r->next = p;
                r = p;
            }

            std::cout << "do you want to continue : ";
            std::cin >> x;

            // Deletion Operation
            if (x == 0) {
                while (p->next != nullptr) {
                    std::cout << "DELETED ELEMENT : " << p->next->info << std::endl;
                    Node* temp = p->next;
                    p->next = p->next->next;
                    delete temp;
                }
            }

            if (x == 0 || x == 1) {
                continue;
            }
        }
    }

    // Display Operation
    r->next = nullptr;
    p = head;

    while (p != nullptr) {
        std::cout << p->info << std::endl;
        p = p->next;
    }

    return 0;
}
