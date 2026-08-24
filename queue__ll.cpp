#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
    Node* head;
    Node* tail;

public:
    Queue() {
        head = tail = NULL;
    }

    // Insert at tail
    void push(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = tail = newNode;
        } 
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Remove from head
    void pop() {
        if (head == NULL) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;

        // If queue becomes empty
        if (head == NULL) {
            tail = NULL;
        }
    }

    // Return front element
    int front() {
        if (head == NULL) {
            cout << "Queue is empty\n";
            return -1;
        }

        return head->data;
    }

    // Check empty
    bool empty() {
        return head == NULL;
    }
};

int main() {
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;

    return 0;
}