#pragma once

#include <cstddef>  // Include to use NULL, otherwise use nullptr
#include <iostream>
#include <cstdlib>
#include <istream>
#include "node.hpp"

template<class T>
class PQ{
private:
    Node<T> *head;          // the pointer to the front of the list
    Node<T> *tail;          // the pointer to the back of the list
    int count;

public:
    // desc: Inializes a new, empty queue
	PQ();

    // desc:    Adds new data to the queue
    // param:   data The data to add to the list
    // param:   priority The priority assigned to this node
    // returns: void
	void enqueue(T &data, int priority);

    // desc:    Removes the front element form the queue
    // returns: void
	void dequeue(void);   

    // desc:    Removes the value found at the front of the queue
    // returns: The data found at the front of the queue
    T get_front(void); 

    // desc:    Checks if the queue is empty or not
    // returns: true is the queue is empty, false if not
    bool isEmpty(void);

    // desc:    Clears the queue
    // returns: void
    void clear(void);

    // desc:    Returns the number of elements in the queue
    // returns: The number of elements in the queue
    int get_count(void);

    void Add1();
    void Minus();
    bool compare2(int prio1, int prio2);

};




template<class T>
bool PQ<T>::compare2(int prio1, int prio2)
{
    if (prio2 < prio1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class T>
PQ<T>::PQ()
{
	head = NULL;
    tail = NULL;
    count = 0;

}

template<class T>
void PQ<T>::Add1()
{
    count += 1;
    return;
}

template<class T>
void PQ<T>::Minus()
{
    count -= 1;
    return;
}

template<class T>
void PQ<T>::enqueue(T &data, int priority)
{
    Node<T> *new_node = new Node<T>(data, priority);
    if (count == 0)
    {
        head = new_node;
        tail = new_node;
        Add1();
        return;
    }
    else if (count == 1)
    {
        if (new_node->get_prio() < head->get_prio())
        {
            tail = head;
            head = new_node;
            new_node->set_next(head);
            Add1();
            return;
        }
        else
        {
            head->set_next(new_node);
            tail = new_node;
            Add1();
            return;
        }    
    }
    else
    {
        Node<T> *prevnode = head;
        Node<T> *curnode = head->get_next();
        while (true)
        {
            if (new_node->get_prio() < prevnode->get_prio())
            {
                new_node->set_next(prevnode);
                head = new_node;
                Add1();
                return;
            }
            else if (curnode == tail and new_node->get_prio() >= tail->get_prio())
            {
                curnode->set_next(new_node);
                tail = new_node;
                Add1();
                return;
            }
            if (prevnode->get_prio() < new_node->get_prio() < curnode->get_prio())
            {
                prevnode->set_next(new_node);
                new_node->set_next(curnode);
                Add1();
                return;
            }
            else if (prevnode->get_prio() < new_node->get_prio() >= curnode->get_prio())
            {
                new_node->set_next(curnode->get_next());
                curnode->set_next(new_node);
                Add1();
                return;
            }
            else
            {
                prevnode = curnode;
                curnode = curnode->get_next();
            }
        }
    }
}


template<class T>
void PQ<T>::dequeue(void)
{
    if (count == 0)
    {
        return;
    }
    else if (count == 1)   
    {
        Node<T> *node2rm = head;        
        head = NULL;
        tail = NULL;
        Minus();
        delete node2rm;
    }
    else if (count == 2)
    {
        Node<T> *node2rm = head;
        head = tail;
        delete node2rm;
        Minus();
    }
    else
    {
        Node<T> *node2rm = head;
        head = head->get_next();
        delete node2rm;
        Minus();
    }
    return;
}

template<class T>
T  PQ<T>::get_front()
{
    if (count == 0)
    {
        return -1;
    }
    else
    {
        T data = head->get_data();
        return data;
    }
}

template<class T>
bool PQ<T>::isEmpty()
{
    if (count == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

template<class T>
void PQ<T>::clear(void)
{
    while (isEmpty() == false)
    {
        if (count == 0)
        {
            break;
        }
        else
        {
            dequeue();
        }
    }
}


template<class T>
int PQ<T>::get_count(void)
{
    return count;
}

