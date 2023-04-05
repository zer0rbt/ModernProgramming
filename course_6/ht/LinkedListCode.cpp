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
    Node<type> *first = nullptr;
    Node<type> *last = nullptr;

    void append(type data) {
        Node<type> *pnode = new Node<type>();
        pnode->elem = data;
        if (last != nullptr) {
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

        for (int i = 0; ((i < ins_at) and (elemAfter != nullptr)); i++)
            elemAfter = elemAfter->next;

        if (elemAfter != nullptr) {
            pNode->next = elemAfter;
            if (elemAfter->prev != nullptr)
                elemAfter->prev->next = pNode;
            elemAfter->prev = pNode;
            pNode->next = elemAfter;
        } else if (last != nullptr) {
            pNode->prev = last;
            last->next = pNode;
            last = pNode;
        } else if (last == nullptr) last = pNode;

        if (ins_at <= 0) {
            if (first != nullptr) {
                first->prev = pNode;
                pNode->next = first;
            }
            first = pNode;
        }
    }

    void remove(int start_on, int end_before) {
        start_on = max(start_on, 0);
        Node<type> *currentPointer = first;
        Node<type> *pNode;
        for (int i = 1; (i <= end_before) and (currentPointer != nullptr); i++) {
            if (i == start_on) pNode = currentPointer;
            currentPointer = currentPointer->next;
        }
        (currentPointer != nullptr) ? (currentPointer->prev = pNode) : (last = pNode);
        (start_on != 0) ? (pNode->next = currentPointer) : (first = currentPointer);
    }


    void clear() {
        first = NULL;
        last = NULL;
    }

};

//
// Created by zer-oRBT on 01.03.2023.
//

//
// Created by zer-oRBT on 25.03.2023.
//
