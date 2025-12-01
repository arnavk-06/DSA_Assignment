#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool checkDuplicates(Node* root, bool seen[]) {
    if (root == nullptr) return false;
    if (seen[root->data] == true) {
        return true;
    }
    seen[root->data] = true;
    return checkDuplicates(root->left, seen) || checkDuplicates(root->right, seen);
}

int main() {
    int n, val;
    cout << "Enter number of nodes in the binary tree: ";
    cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        Node* newNode = new Node(val);
        if (root == nullptr) {
            root = newNode;
        } else {
            // Simple insertion logic for demonstration (not a balanced tree)
            Node* temp = root;
            while (true) {
                if (val < temp->data) {
                    if (temp->left == nullptr) {
                        temp->left = newNode;
                        break;
                    } else {
                        temp = temp->left;
                    }
                } else {
                    if (temp->right == nullptr) {
                        temp->right = newNode;
                        break;
                    } else {
                        temp = temp->right;
                    }
                }
            }
        }
    }
    
    bool seen[10000] = { false };

    if (checkDuplicates(root, seen))
        cout << "Duplicates Found";
    else
        cout << "No Duplicates";

    return 0;
}
