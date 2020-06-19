
#include "List.h"
#include "node.h"
#include <bits/stdc++.h>

using namespace std;

template<class type>
List<type>::List()
{
    Head = tail = NULL;
    siz=0;

}

template<class type>
int List<type>::size()
{
    return siz;
}

template<class type>
void List<type>::push_back(type value) {
    auto *NODE = new node<type>;
    NODE->item = value;
    NODE->nextnode = NULL;
    NODE->prevnode = tail;
    if (this->siz == 0)
    {

        Head = tail = NODE;
        Head->prevnode = NULL;
    }
    else
        {
        tail->nextnode = NODE;
        tail = NODE;
        }
    this->siz++;
}

template<class type>
List<type>::List(type item, int size)
{
    this->siz = 0;
    for (int i = 0; i < size; i++) {
        this->push_back(item);
    }
}

template<class type>
List<type>::~List() {
    clear();
}


template<class type>
void List<type>::clear() {

    node<type> *cur = Head;

    while (cur != NULL) {
        node<type> *temp = cur->nextnode;
        delete cur;
        cur = temp;

    }

    Head = NULL;
    this->siz=0;

}

template<class type>
List<type>::List(const List<type> &list2) {


    this->clear();
    this->siz = 0;
    for (auto it :list2) {
        this->push_back(it);
    }
}


template<class type>
void List<type>::insert(type value, List::iterator &position) {
    auto *NODE = new node<type>;
    NODE->item = value;
    NODE->nextnode = position.nodepoiner;
    NODE->prevnode = position.nodepoiner->prevnode;
    NODE->prevnode->nextnode = NODE;
    NODE->nextnode->prevnode = NODE;
    position.nodepoiner = NODE;
    siz++;
}







