//
// Created by hussien on ٤/١٨/٢٠٢٠.
//

#ifndef SSECTION_1_LIST_H
#define SSECTION_1_LIST_H
#include "Node.h"
#include <bits/stdc++.h>


template<class type>

class List {

private:
    node<type> *tail;
    node<type> *Head;
    int siz;

public:
    void clear();

    List();

    void push_back(type item);

    List(type item, int siz);

    List(const List<type> &);

    int size();

    ~List();

    class iterator {
        /*this class hold a pointer of type node "nodepoiner" "kaslt a3dlo le "nodepointer"
         *  friend class with list class to can reach to the private attributes
         * */
        friend class List<type>;
    public:
        node<type> *nodepoiner;
// paramterize consrtuctor take a pointer of type node and
//and make nodepoiner equal to
        iterator(node<type> *p) {
            nodepoiner = p;
        }
        //default constructor
        iterator() {
            nodepoiner = nullptr;
        }

        //return true if nodepointer not equal to the itr otherwise return true
        bool operator!=(const iterator &itr) const {
            return nodepoiner != itr.nodepoiner;
        }
        //return true if nodepointer equal to the itr otherwise return true
        bool operator==(const iterator &itr) const {
            return nodepoiner == itr.nodepoiner;
        }
        //overloading the "*"
        // return tha value or the item of the nodepoiner
        type &operator*() const {
            return nodepoiner->item;
        }
        //overloading to it++
        //return the current nodepoiner
        //make the nodepoiner equal to next node
        iterator operator++(int) {
            iterator temp = *this;
            nodepoiner = nodepoiner->nextnode;
            return temp;
        }

        //overloading ++it
        // make the nodepoiner equal to next node and then return it
        iterator operator++() {
            nodepoiner = nodepoiner->nextnode;
            return nodepoiner;
        }
        //works as it++
        iterator operator--(int) {
            iterator temp = *this;
            nodepoiner = nodepoiner->prevnode;
            return temp;
        }
        //works as --it
        iterator operator--() {
            //iterator temp = *this;
            nodepoiner = nodepoiner->prevnode;
            return nodepoiner;
        }
    };

    void insert(type value, iterator &position);

    //it return the next node
    // if the position not equal tail
    // otherwise it throw an exception and return the tail*the prev*
    // if the position equal to the head just make the head equal the next node and return it
    iterator erase(iterator &position) {
        try {
            siz--;
            auto temp = position.nodepoiner->nextnode;
            if(position.nodepoiner==Head)
            {
                Head=temp;
                delete position.nodepoiner;
                return Head;

            }
            position.nodepoiner->prevnode->nextnode = position.nodepoiner->nextnode;

            if (position.nodepoiner == tail) {
                tail=position.nodepoiner->prevnode;
                delete position.nodepoiner;
                throw 404;
            }

                position.nodepoiner->nextnode->prevnode = position.nodepoiner->prevnode;
                return temp;
            }
            catch (int ) {

                return this->rend();
            }
        }
            //return null as tail->nextnode is always equal to null
        iterator end() const {
            return iterator(tail->nextnode);
        }
        // return pointer equal to the tail
        iterator rend() const {
            return iterator(tail);
        }
        //return null as head->prevnode is always equal to null

        iterator rbegin() const {
            return iterator(Head->prevnode);
        }
        // return pointer to the head
        iterator begin() const {
            return iterator(Head);
        }


    };


#endif //SSECTION_1_LIST_H
