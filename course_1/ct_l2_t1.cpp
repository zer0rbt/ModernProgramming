#include <iostream>
#include <vector>

using namespace std;

template<class var>
void minmax(var arr, int len) {
    var min, max;
    min = arr;
    max = arr;
    for (int i = 1; i <= len; i++) {
        if (*(arr + i) < *min) min = (arr + i);
        if (*(arr + i) > *max) max = (arr + i);
    }
    cout << *min << endl;
    cout << *max;
}

template<class type>
struct Node {
    type elem;
    Node *next;
    Node *prev;
};

template<class type>
struct TWLL {
    Node<type> *first;
    Node<type> *last;

    void append(type data) {
        Node<type> *pnode = new Node<type>();
        pnode->elem = data;
        if (last != NULL) {
            pnode->prev = last;
            pnode->prev->next = pnode;
        } else first = pnode;
        last = pnode;
    };

    void pprint() {
        for (Node<type> *cp = first; cp != nullptr; cp = cp->next)
            cout << cp->elem << " ";
        cout << endl;
    };

    void insertAt(int ins_at, type value) {
        Node<type> *pNode = new Node<type>();
        pNode->elem = value;
        Node<type> *elemAfter = first;

        for (int i = 0; ((i < ins_at) and (elemAfter != NULL)); i++)
            elemAfter = elemAfter->next;

        if (elemAfter != NULL) {
            pNode->next = elemAfter;
            if (elemAfter->prev != NULL)
                elemAfter->prev->next = pNode;
            elemAfter->prev = pNode;
            pNode->next = elemAfter;
        } else if (last != NULL) {
            pNode->prev = last;
            last->next = pNode;
            last = pNode;
        }

        if (ins_at <= 0) first = pNode;
    }

    void remove(int start_on, int end_before) {
        start_on = max(start_on, 0);
        Node<type> *currentPointer = first;
        Node<type> *pNode;
        for (int i = 1; (i <= end_before) and (currentPointer != NULL); i++) {
            if (i == start_on) pNode = currentPointer;
            currentPointer = currentPointer->next;
        }
        (currentPointer != NULL) ? (currentPointer->prev = pNode) : (last = pNode);
        (start_on != 0) ? (pNode->next = currentPointer) : (first = currentPointer);
    }


    void clear() {
        first = NULL;
        last = NULL;
    }

};


int main() {
    vector<int> a = {1, 2, 3, 0, 1, 6, -1};
    TWLL<int> B, C;
    for (int i = 0; i < a.size(); i++)
        B.append(a[i]);
    B.pprint();
    B.insertAt(1, 9);
    B.pprint();
    B.remove(0, 7);
    B.pprint();
    return 0;
}
//
// Created by zer-oRBT on 01.03.2023.
//
