#include <iostream>
using namespace std;

class Tree {
public:
    int value;
    int height;
    int subtreeSum;
    Tree* left;
    Tree* right;
    Tree* parent;

    Tree(int val) : value(val), height(1), subtreeSum(val), left(nullptr), right(nullptr), parent(nullptr) {}

    int getHeight(Tree* node) {
        return node ? node->height : 0;
    }

    void updateNode() {
        height = max(getHeight(left), getHeight(right)) + 1;
        subtreeSum = value + (left ? left->subtreeSum : 0) + (right ? right->subtreeSum : 0);
    }
    
    int balanceFactor() {
        return getHeight(left) - getHeight(right);
    }

    Tree* rotateRight() {
        Tree* newRoot = left;
        left = newRoot->right;
        if (left) left->parent = this;
        newRoot->right = this;
        newRoot->parent = parent;
        parent = newRoot;
        updateNode();
        newRoot->updateNode();
        return newRoot;
    }

    Tree* rotateLeft() {
        Tree* newRoot = right;
        right = newRoot->left;
        if (right) right->parent = this;
        newRoot->left = this;
        newRoot->parent = parent;
        parent = newRoot;
        updateNode();
        newRoot->updateNode();
        return newRoot;
    }

    Tree* balance() {
        updateNode();
        int bal = balanceFactor();

        if (bal > 1) {
            if (left && left->balanceFactor() < 0)
                left = left->rotateLeft();
            return rotateRight();
        }
        if (bal < -1) {
            if (right && right->balanceFactor() > 0)
                right = right->rotateRight();
            return rotateLeft();
        }
        return this;
    }

    Tree* insert(int val) {
        if (val < value) {
            if (left) left = left->insert(val);
            else left = new Tree(val), left->parent = this;
        }
        else if (val > value) {
            if (right) right = right->insert(val);
            else right = new Tree(val), right->parent = this;
        }
        return balance();
    }

    Tree* findMin() {
        return left ? left->findMin() : this;
    }

    Tree* removeMin() {
        if (!left) return right;
        left = left->removeMin();
        return balance();
    }

    Tree* remove(int val) {
        if (val < value) {
            if (left) left = left->remove(val);
        }
        else if (val > value) {
            if (right) right = right->remove(val);
        }
        else {
            Tree* leftChild = left;
            Tree* rightChild = right;
            delete this;
            if (!rightChild) return leftChild;
            Tree* min = rightChild->findMin();
            min->right = rightChild->removeMin();
            min->left = leftChild;
            return min->balance();
        }
        return balance();
    }

    int rangeSum(int L, int R) {
        if (value < L) return right ? right->rangeSum(L, R) : 0;
        if (value > R) return left ? left->rangeSum(L, R) : 0;

        int sum = value;
        if (left) sum += left->rangeSum(L, R);
        if (right) sum += right->rangeSum(L, R);

        return sum;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Tree* root = nullptr;

    cout << "Введите количество элементов, затем сами элементы" << '\n';
    int kol, el;
    cin >> kol;
    for (int i = 0; i < kol; i++) {
        cin >> el;
        if (root)
            root = root->insert(el);
        else
            root = new Tree(el);
    }

    cout << "Введите диапазон нахождения суммы" << '\n';
    int L, R;
    cin >> L >> R;
    cout << "Сумма элементов в заданном диапазоне [" << L << ", " << R << "]: " << root->rangeSum(L, R) << '\n';

    cout << "Введите количество элементов для удаления, затем сами элементы" << '\n';
    cin >> kol;
    for (int i = 0; i < kol; i++) {
        cin >> el;
        root = root->remove(el);
    }
    cout << "Сумма после удаления в диапазоне [" << L << ", " << R << "]: " << root->rangeSum(L, R) << '\n';
}
