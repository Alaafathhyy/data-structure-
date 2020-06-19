//
// Created by ALAA on ٤/١٤/٢٠٢٠.
//

#include "List.h"
#include "node.h"
#include <bits/stdc++.h>

using namespace std;
//default constructor
template<class type>
List<type>::List() {
    Head = tail = NULL;
    siz=0;
    //Head->prevnode=NULL;

}
// return the current size
template<class type>
int List<type>::size() {
    return siz;
}
//tail is always pointing to the last element
//add a node and make it's prev equal to the tail and the next equal null
//then make the tail point to this node
template<class type>
void List<type>::push_back(type value) {
    auto *NODE = new node<type>;
    NODE->item = value;
    NODE->nextnode = NULL;
    NODE->prevnode = tail;
    if (this->siz == 0) {

        Head = tail = NODE;
        Head->prevnode = NULL;
    } else {
        tail->nextnode = NODE;
        tail = NODE;
    }
    this->siz++;
}
// create linked list with a fixed size and all the element equal to a fixed value
template<class type>
List<type>::List(type item, int size) {
    this->siz = 0;
    for (int i = 0; i < size; i++) {
        this->push_back(item);
    }
}

template<class type>
List<type>::~List() {
    clear();
}

// make pointer cur equal to the head
// make pointer temp is always equal to the next of cur
// delete  the cur the make
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
//Create a cpy constructor instead of assign operator
//as the assign operator by defult use the cpy constructor
template<class type>
List<type>::List(const List<type> &list2) {


    this->clear();
    this->siz = 0;
    for (auto it :list2) {
        this->push_back(it);
    }
}

//insert a node X at specific location where it held a node Y
// make the next of X is equal Y  ,and the prev of X is equal to the prev of Y
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







