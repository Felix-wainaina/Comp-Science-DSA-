#include <iostream>

// Node representing an element in the list
template <typename T>
struct Node {
    T data;
    Node* next;
};

// List class representing an Abstract Data Type (ADT) List
template <typename T>
class List {
private:
    Node<T>* head;

public:
    // Constructor
    List() : head(nullptr) {}

    // Destructor
    ~List() {
        Node<T>* current = head;
        Node<T>* next;

        // Delete all nodes
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }

    // Add an element to the list
    void addElement(T data) {
        Node<T>* newNode = new Node<T>{data, nullptr};

        // If the list is empty, set the new node as the head
        if (head == nullptr) {
            head = newNode;
        } else {
            // Otherwise, add the new node at the end
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Other operations such as remove, search, etc. can be added as needed
};

int main() {
    // Example usage of the List class
    List<int> intList;
    intList.addElement(1);
    intList.addElement(2);
    intList.addElement(3);

    // Perform operations on the list...

    return 0;
}
