#pragma once

// include this library to use NULL, otherwise use nullptr instead
#include <cstddef>
#include <iostream>
#include "node.hpp"

template<class T>
class BST{
public:
    // Constructor for the BST class, creates an empty tree
    BST(void);
    // Destructor for the BST class, destroys the tree
    ~BST(void);
    // Inserts data into the tree
    // param: The data to be inserted into the tree
    void insert(T);
    // Removes data from the tree
    // param: The data to be removed from the tree
    void remove(T);
    // Performs an inorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *inorder(void);
    
    
    // Performs an postorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *postorder(void);
    // Performs an preorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *preorder(void);
    // Searches the tree for a given value
    // param: the data to search for
    // returns: a pointer to the node containing the data or NULL if the data
    //          was not found
    Node<T> *search(T);
    // Gets the current number of nodes in the tree
    // returns: the number of nodes in the tree
    int get_size(void);
private:
    // the root node of the tree
    Node<T> *root;
    // the number of nodes in the tree
    int node_count;
    int traverse_count;
    std::vector<T> *postordertraverse(Node<T> *givennode, std::vector<T> *givenvec);
    std::vector<T> *preordertraverse(Node<T> *givennode, std::vector<T> *givenvec);
    std::vector<T> *inordertraverse(Node<T> *givennode, std::vector<T> *givenvec);
    void insertception(Node<T> *node2insert, Node<T> *node2compare);
    Node<T> *searchception(Node<T> *node2search, Node<T> *node2compare);
    Node<T> *findparent(Node<T> *possparent, Node<T> *child);

    // bool removeception(Node<T> *node, T val);
   // Node<T> *findnewroot(void);
};

template<class T>
BST<T>::BST()
{
    root = NULL;
    node_count = 0;
}

template<class T>
BST<T>::~BST()
{
    root = NULL;
    while(root != NULL)
    {
        remove(root->get_data());
    }
}

template<class T>
 std::vector<T> * BST<T>::inorder()
{
    std::vector<T> *vec = new std::vector<T>;    
    inordertraverse(root, vec);
    return vec;
}

template<class T>
std::vector<T> * BST<T>::inordertraverse(Node<T> *givennode,std::vector<T> *givenvec)
{
    if (givennode == NULL)
    {
        return givenvec;
    }
    traverse_count++;    
    givenvec = inordertraverse(givennode->get_left(), givenvec);
    givenvec->push_back(givennode->get_data());
    givenvec = inordertraverse(givennode->get_right(), givenvec);
    return givenvec;
}


template<class T>
 std::vector<T> * BST<T>::preorder()
{
    std::vector<T> *vec = new std::vector<T>;
    preordertraverse(root, vec);
    return vec;
}

template<class T>
std::vector<T> * BST<T>::preordertraverse(Node<T> *givennode,std::vector<T> *givenvec)
{
    if (givennode == NULL)
    {
        return givenvec;
    }
    traverse_count++;    
    givenvec->push_back(givennode->get_data());
    givenvec = preordertraverse(givennode->get_left(), givenvec);
    givenvec = preordertraverse(givennode->get_right(), givenvec);
    return givenvec;
}


template<class T>
 std::vector<T> * BST<T>::postorder()
{    
    std::vector<T> *vec = new std::vector<T>;
    postordertraverse(root, vec);
    return vec;
}

template<class T>
std::vector<T> * BST<T>::postordertraverse(Node<T> *givennode,std::vector<T> *givenvec)
{
    if (givennode == NULL)
    {
        return givenvec;
    }
    traverse_count++;
    givenvec = postordertraverse(givennode->get_left(), givenvec);
    givenvec = postordertraverse(givennode->get_right(), givenvec);
    givenvec->push_back(givennode->get_data());
    return givenvec;
}



template<class T>
void BST<T>::insert(T new_data)
{
    Node<T> *node2insert = new Node<T>;
    node2insert->set_data(new_data);
    if (root == NULL)
    {
        root = node2insert;
    }
    else
    {
        insertception(node2insert, root);
        // root = findnewroot();
    }
    return;
}

template<class T>
void BST<T>::insertception(Node<T> *node2insert, Node<T> *node2compare)
{
    if (node2insert->get_data() < node2compare->get_data())
    {
        if (node2compare->get_left() != NULL)
        {
            insertception(node2insert, node2compare->get_left());
        }
        else
        {
            node2compare->set_left(node2insert);
            node_count++;
            return;
        }
    }
    else
    {
        if (node2compare->get_right() != NULL)
        {
            insertception(node2insert, node2compare->get_right());
        }
        else
        {
            node2compare->set_right(node2insert);
            node_count++;
            return;
        }
        
    }
}


template<class T>
Node<T> *BST<T>::search(T val)
{
    if (val == 0)
    {
        return NULL;
    }
    Node<T> *node2search = new Node<T>;
    node2search->set_data(val);
    Node<T> *foundnode = new Node<T>;
    if (node2search->get_data() == root->get_data())
    {
        foundnode = root;
    }
    else
    {
        foundnode = searchception(node2search, root);
    }
    if (foundnode == NULL)
    {
        delete node2search;
        delete foundnode;
        return NULL;
    }
    else
    {
        delete node2search;
        return foundnode;
    }
}

template<class T>
Node<T> *BST<T>::searchception(Node<T> *node2search, Node<T> *node2compare)
{
    if (node2search->get_data() == node2compare->get_data())
    {
        return node2compare;
    }
    else if (node2search->get_data() < node2compare->get_data())
    {
        node2compare = searchception(node2search, node2compare->get_left());
        return node2compare;
    }
    else
    {
        node2compare = searchception(node2search, node2compare->get_right());
        return node2compare;
    }
}

template<class T>
void BST<T>::remove(T val)
{
    if (val == 0)
    {
        return;
    }
    else if (val == root->get_data())
    {
        return;
    }
    else
    {
        Node<T> *child = search(val);
        Node<T> *parent = findparent(root, child);
    }
       
}

template<class T>
Node<T> *BST<T>::findparent(Node<T> *possparent, Node<T> *child)
{
    if (possparent->get_left()->get_data() == child->get_data())
    {
        return possparent;
    }
    else if (possparent->get_right()->get_data() == child->get_data())
    {
        return possparent;
    }
    else if (possparent->get_left()->get_data() > child->get_data())
    {
        possparent = possparent->get_right();
        possparent = findparent(possparent, child);
    }
    else
    {
        possparent = possparent->get_left();
        possparent = findparent(possparent, child);
    }
    return possparent;
}

/*
template<class T>
bool BST<T>::removeception(Node<T> *node2look, T val)
{
    bool flag = new bool;
    flag = false;
    if (node2look->get_data() == val)
    {
        if(node2look->get_left() != NULL)
        {
            Node<T> *yeetnode = node2look;
            Node<T> *node2move = node2look->get_left();
            node2move->set_right(node2look->get_right());
            node2look = node2move;
            delete node2move;
            delete yeetnode;
            return true;
        }
        else if(node2look->get_right() != NULL)
        {
            Node<T> *yeetnode = node2look;
            Node<T> *node2move = node2look->get_right();
            node2move->set_left(node2look->get_left());
            node2look = node2move;
            delete node2move;
            delete yeetnode;
            flag = true;
            return flag;
        }
        else
        {
            delete node2look;
            flag = true;
            return flag;
        }
        
    }
    else
    {
        flag = removeception(node2look->get_left(), val);
        if (flag != true)
        {
            flag = removeception(node2look->get_right(), val);
        }
        return flag;
    }
    return flag;
}
*/
/*
template<class T>
Node<T> *BST<T>::findnewroot()
{
    Node<T> *newroot = new Node<T>;
    int num_to_root = node_count / 2;
    std::vector<T> *vec2reorder = inorder();
    newroot = search(vec2reorder->at(num_to_root));
    if (newroot->get_data() < root->get_data())
    {
        newroot->set_right(root->get_right());
    }
    else
    {
        newroot->set_left(root->get_left());
    }
    return newroot;
}
*/

template<class T>
int BST<T>::get_size()
{
    return node_count;
}