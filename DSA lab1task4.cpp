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
    List() : head(nullptr) {}

    ~List() {
        Node<T>* current = head;
        Node<T>* next;

        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }

    void addElement(T data) {
        Node<T>* newNode = new Node<T>{data, nullptr};
        
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

};

int main() {
    // Example usage of the List class
    List<int> intList;
    intList.addElement(1);
    intList.addElement(2);
    intList.addElement(3);

    return 0;
}
