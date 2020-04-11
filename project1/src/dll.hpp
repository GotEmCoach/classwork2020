#pragma once

#include <cstddef>  // Include to use NULL, otherwise use NULL
#include <iostream>
#include "node.hpp"
using namespace std;

template<class T>
class DLL{
private:
    Node<T> *head;          // the pointer to the front of the list
    Node<T> *tail;          // the pointer to the back of the list
    int count;
public:
    // desc: Inializes a new, empty list
	DLL();

    // desc:  Adds new data to the end of the list
    // param: data The data to add to the list
	void prepend(T &data);

    // desc:  Adds new data to the front of the list
    // param: data The data to add to the list
	void append(T &data);   

    // desc:    Searches the list for the node that contains data and removes it
    //          from the list
    // param:   data The data to be searched for and removed
    // returns: true if the node was found and removed, false if not
    bool remove(T data); 

    // desc:    Removes the node at the front of the list
    // returns: true if the node was successfully removed, false if not
	bool removeFront(void);

    // desc:    Removes the node at the back of the list
    // returns: true if the node was successfully removed, false if not
	bool removeBack(void);

    // desc:    Searches the list for a node containing the specified data
    // param:   data The data to be searched for
    // returns: A pointer to the node containing the data or NULL if a node
    //          cannot be found
	Node<T> *search(T data);

    // desc::   Returns the data found at the front of the list
    // returns: The data at the front of the list
    T getFront(void);

    // desc::   Returns the data found at the back of the list
    // returns: The data at the back of the list. Return 0 if empty
    T getBack(void);
    
    void iFeelSoLonely(Node<T> *node);

    Node<T> *gibMeNode(T &data);
    
    void yeet(Node<T> *node);
    // desc: Prints the contents of the list from front to back
	void print();
};

template<class T>
Node<T> *DLL<T>::gibMeNode(T &data)
{
    Node<T> *newNode = new Node<T>;
    newNode->set_data(data);
    return newNode;
}


template<class T>
void DLL<T>::iFeelSoLonely(Node<T> *node)
{
    head = node;
    tail = node;
}

template<class T>
void DLL<T>::yeet(Node<T> *node)
{
    delete node;
}

template<class T>
DLL<T>::DLL()
{
    head = NULL;
    tail = NULL;
    count = 0;
}

template<class T>
void DLL<T>::prepend(T &data)
{
    //The code for setting first item in the function is here when list is empty.
    //According to the node.hpp file, NULL is default for prev and next
    Node<T> *newNode;
    newNode = gibMeNode(data);
    
    if (count == 0)
    {
        iFeelSoLonely(newNode);
    }
    else if (count >= 1)
    {
        Node<T> *node2mv;
        node2mv = head;
        newNode->set_next(node2mv);
        node2mv->set_prev(newNode);
        head = newNode;
        
    }
    count = count + 1;
    return;
}


template<class T>
void DLL<T>::append(T &data)
{
    Node<T> *newNode;
    newNode = gibMeNode(data);

    if (count == 0)
    {
        iFeelSoLonely(newNode);
    }
    else if (count > 0)
    {
        Node<T> *noMoveNode;
        noMoveNode = tail;
        noMoveNode->set_next(newNode);
        newNode->set_prev(noMoveNode);
        tail = newNode;
    }
    count = count + 1;
    return;
}
template<class T>
bool DLL<T>::remove(T data)
{
    Node<T> *Node2check;
    Node2check = search(data);
    if (Node2check == NULL)
    {
        return false;
    }
    else if (Node2check->get_data() == data)
    {   
        if (head == NULL)
        {
            return false;
        }
        else if(head == Node2check)
        {
            bool removeFront(Node2check);
            count = count - 1;
            return true;
        }
        else if(tail == Node2check)
        {
            bool removeBack(Node2check);
            count = count - 1;
            return true;
        }
        else
        {
            Node<T> *prev_node = Node2check->get_prev();
            Node<T> *next_node = Node2check->get_next();
            next_node->set_prev(prev_node);
            prev_node->set_next(next_node);
            yeet(Node2check);
            count = count - 1;
            return true;
        }
    
    }
    
    return false;
}

template<class T>
T DLL<T>::getFront()
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        T ooh_data = head->get_data();
        return ooh_data;
    }
    
}

template<class T>
T DLL<T>::getBack()
{
    if (tail == NULL)
    {
        return 0;
    }
    else
    {
        T ooh_data = tail->get_data();
        return ooh_data;
    }
    
}

template<class T>
bool DLL<T>::removeFront()
{
    if (head == NULL)
    {
        return false;
    }
    else
    {
        Node<T> *deleteme = head;
        head = deleteme->get_next();
        yeet(deleteme);
        count = count - 1;
        return true;
    }
}

template<class T>
bool DLL<T>::removeBack()
{
    if (tail == NULL)
    {
        return false;
    }
    else
    {
        Node<T> *deleteme = tail;
        tail = deleteme->get_prev();
        yeet(deleteme);
        count = count - 1;
        return true;
    }
    
}

template<class T>
Node<T> *DLL<T>::search(T target)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        Node<T> *node2find = head;
        if (node2find->get_data() == target)
        {
            return node2find;
        }
        while (node2find != NULL)
        {
            if (node2find->get_data() == target)          
            {
                return node2find;
            }
            else
            {
                node2find = node2find->get_next();
            } 
        }
    }    
    return NULL;
}

template<class T>
void DLL<T>::print()
{
    Node<T> *itr = head;

    std::cout << "Your List: ";
	while (itr != NULL)
	{
        std::cout << itr->get_data() << " -> ";
        itr = itr->get_next();
	}
    std::cout << "NULL" << std::endl;
}


