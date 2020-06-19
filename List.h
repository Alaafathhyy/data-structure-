
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

        friend class List<type>;
    public:
        node<type> *nodepoiner;

        iterator(node<type> *p)
        {
            nodepoiner = p;
        }

        iterator() {nodepoiner = nullptr;}


        bool operator!=(const iterator &itr) const {return nodepoiner != itr.nodepoiner;}

        bool operator==(const iterator &itr) const
        {
            return nodepoiner == itr.nodepoiner;
        }

        type &operator*() const {
            return nodepoiner->item;
        }

        iterator operator++(int) {
            iterator temp = *this;
            nodepoiner = nodepoiner->nextnode;
            return temp;
        }

        iterator operator++() {
            nodepoiner = nodepoiner->nextnode;
            return nodepoiner;
        }

        iterator operator--(int) {
            iterator temp = *this;
            nodepoiner = nodepoiner->prevnode;
            return temp;
        }

        iterator operator--() {
            //iterator temp = *this;
            nodepoiner = nodepoiner->prevnode;
            return nodepoiner;
        }
    };

    void insert(type value, iterator &position);


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

    iterator end() const
    {
        return iterator(tail->nextnode);
    }

    iterator rend() const
    {
        return iterator(tail);
    }

    iterator rbegin() const
    {
        return iterator(Head->prevnode);
    }

    iterator begin() const
    {
        return iterator(Head);
    }


};


#endif //SSECTION_1_LIST_H
