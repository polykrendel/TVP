#include <iostream>
#include <iomanip>
using namespace std;

class NodeTree {
private:
    int value;
    NodeTree* left;
    NodeTree* right;
    NodeTree* parent;

public:
    NodeTree(int val, NodeTree* par = nullptr) : value(val), left(nullptr), right(nullptr), parent(par) {}

    NodeTree* insert(int val) {
        if (val < value) {
            if (left == nullptr)
                left = new NodeTree(val, this);
            else
                left = left->insert(val);
        }
        else if (val > value) {
            if (right == nullptr)
                right = new NodeTree(val, this);
            else
                right = right->insert(val);
        }
        return balance();
    }

    NodeTree* search(int val) {
        if (val == value) return this;
        if (val < value && left != nullptr) return left->search(val);
        if (val > value && right != nullptr) return right->search(val);
        return nullptr;
    }

    NodeTree* remove(int val) {
        if (val < value) {
            if (left != nullptr) left = left->remove(val);
        }
        else if (val > value) {
            if (right != nullptr) right = right->remove(val);
        }
        else {
            if (left == nullptr || right == nullptr) {
                NodeTree* temp = left ? left : right;
                if (temp == nullptr) { 
                    temp = this;
                    return nullptr;
                }
                else {           
                    *this = *temp;
                }
                delete temp;
            }
            else {                  
                NodeTree* temp = minValueNode(right);
                value = temp->value;
                right = right->remove(temp->value);
            }
        }
        return balance();
    }

    NodeTree* rotateLeft() {
        NodeTree* newRoot = right;
        right = newRoot->left;
        if (newRoot->left != nullptr) newRoot->left->parent = this;
        newRoot->parent = parent;
        newRoot->left = this;
        parent = newRoot;
        return newRoot;
    }

    NodeTree* rotateRight() {
        NodeTree* newRoot = left;
        left = newRoot->right;
        if (newRoot->right != nullptr) newRoot->right->parent = this;
        newRoot->parent = parent;
        newRoot->right = this;
        parent = newRoot;
        return newRoot;
    }

    NodeTree* balance() {
        int bal = balanceFactor();
        if (bal > 1) {
            if (left->balanceFactor() < 0)
                left = left->rotateLeft();
            return rotateRight();
        }
        if (bal < -1) {
            if (right->balanceFactor() > 0)
                right = right->rotateRight();
            return rotateLeft();
        }
        return this;
    }

    int height() {
        if (this == nullptr) return 0;
        int leftHeight = left ? left->height() : 0;
        int rightHeight = right ? right->height() : 0;
        return 1 + max(leftHeight, rightHeight);
    }

    int balanceFactor() {
        int leftHeight = left ? left->height() : 0;
        int rightHeight = right ? right->height() : 0;
        return leftHeight - rightHeight;
    }

    NodeTree* minValueNode(NodeTree* node) {
        NodeTree* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    void print(NodeTree* root, string indent = "", bool last = true) {
        if (root != nullptr) {
            cout << indent;
            if (last) {
                cout << "R----"; 
                indent += "   ";
            }
            else {
                cout << "L----";  
                indent += "|  ";
            }
            cout << root->value << endl;

            print(root->left, indent, false); 
            print(root->right, indent, true);  
        }
    }

    void print() {
        print(this);
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    NodeTree* tree = new NodeTree(10);
    tree = tree->insert(5);
    tree = tree->insert(15);
    tree = tree->insert(3);
    tree = tree->insert(8);
    tree = tree->insert(12);
    tree = tree->insert(18);

    cout << "Обход дерева: " << '\n';
    tree->print();
    cout << '\n';

    tree = tree->remove(5);
    tree = tree->insert(-1);

    cout << "После операций: " << '\n';
    tree->print();
    cout << '\n';
}
