//determine whether it contains a loop (cycle) using a hash set. A loop exists if some node’s next pointer points to a previous node in the list

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

int main(){
    int n, val, pos;
    cout << "Enter number of nodes: ";
    cin >> n;
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    cout << "Enter position to create loop (0 for no loop): ";
    cin >> pos;
    if (pos > 0) {
        Node* loopNode = head;
        for (int i = 1; i < pos; i++) {
            if (loopNode) {
                loopNode = loopNode->next;
            }
        }
        if (tail) {
            tail->next = loopNode;
        }
    }
    
    Node* slow = head;
    Node* fast = head;
    bool hasLoop = false;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            hasLoop = true;
            break;
        }
    }
    if (hasLoop) {
        cout << "The linked list contains a loop." << endl;
    } else {
        cout << "The linked list does not contain a loop." << endl;
    }
    return 0;
}