#include <iostream>
#include <vector>

using namespace std;

template<class type>
struct Node {
    type value;
    Node *left = nullptr;
    Node *right = nullptr;
    Node *parent = nullptr;
};

template<class type>
struct BinTree {
    Node<type> *root = nullptr;
    int size = 0;

    void push(type data) {
        Node<type> *pNode = new Node<type>();
        pNode->value = data;
        size++;

        Node<type> *pcur = root;
        Node<type> *pprev = root;
        if (root == nullptr)
            root = pNode;
        else {
            while (true) {

                if (pcur->value <= data) pcur = pcur->right; else pcur = pcur->left;
                if (pcur != nullptr) pprev = pcur; else break;
            }
            if (pprev->value <= data) pprev->right = pNode; else pprev->left = pNode;
            if (pprev->value <= data) pNode->parent = pprev->right; else pNode->parent = pprev->left;
        }
    }

    void print() {
        print(root);
    };

    void pprint() {
        pprint(root, 0);
    }

    int height() {
        return height(root, 1);
    }

private:
    int height(Node<type> *pNode, int curr_height) {
        int heightl = curr_height;
        int heightr = curr_height;
        if (pNode->right) heightr = height(pNode->right, curr_height + 1);
        if (pNode->left) heightl = height(pNode->left, curr_height + 1);
        return max(heightl, heightr);

    }

    void print(Node<type> *pNode) {
        if (pNode->right) subprint(pNode->right);
        cout << pNode->value << " ";
        if (pNode->left) subprint(pNode->left);
    };

    void pprint(Node<type> *pNode, int bsc) {
        for (int i = 0; i < bsc; i++)
            cout << " ";
        cout << pNode->value << endl;
        if (pNode->left) pprint(pNode->left, bsc + 1);
        if (pNode->right) pprint(pNode->right, bsc + 1);

    }
};


int main() {
    BinTree<int> intBT;
    vector<int> a = {6, 4, 2, 6, 8, 1, 9, 2, 10, 0};

    for (int i = 0; i < a.size(); i++)
        intBT.push(a[i]);
    intBT.pprint();
    cout << "---------------" << endl;
    cout << intBT.height() << endl;
    cout << intBT.size;
    return 0;
}
//
// Created by zer-oRBT on 25.03.2023.
//
