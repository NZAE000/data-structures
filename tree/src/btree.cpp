#include"btree.hpp"
#include<memory>
#include<iostream>

namespace TDA {

template<typename T>
BTree_t<T>::~BTree_t()
{
    destructor_impl(&this->_root);
}

template<typename T>
void BTree_t<T>::
destructor_impl(Node_t<T>** node)
{
    if (*node){
        destructor_impl(&(*node)->left);
        destructor_impl(&(*node)->right);
        dropNode(*node);
        *node = nullptr;
    }
}


template<typename T>
template<typename T2>
Node_t<T>& BTree_t<T>::
createNode(T2&& value)
{
    Node_t<T>* node = new Node_t<T>{std::forward<T2>(value)};
    return *node;
}


template<typename T>
void BTree_t<T>::
dropNode(Node_t<T>* node)
{
    delete node;
}


template<typename T>
template<typename T2>
void BTree_t<T>::
insert(T2&& value)
{
    insert_impl(&this->_root, value);
}


template<typename T>
template<typename T2>
void BTree_t<T>::
insert_impl(Node_t<T>** father_node, T2&& value)
{
    if (!*father_node){
        Node_t<T>& node { createNode(value) };
        *father_node = &node;
    }
    else {
        if (value < (*father_node)->_value){
            insert_impl(&(*father_node)->left, value);
        }
        else {
            insert_impl(&(*father_node)->right, value);
        }
    }
}


// Preorder #################################################
template<typename T>
template<typename T2>
void BTree_t<T>::
DSF_preorder(T2&& value)
{
    DSF_pre_impl(&this->_root, value);
}

template<typename T>
template<typename T2>
void BTree_t<T>::
DSF_pre_impl(Node_t<T>** father_node, T2&& value)
{
    if (!*father_node) std::cout<<" - ";
    else 
    {
        std::cout<<"(";
        std::cout<<' '<<(*father_node)->_value<<' ';
        if ((*father_node)->_value == value) std::cout<<"!";
        DSF_pre_impl(&(*father_node)->left, value);
        DSF_pre_impl(&(*father_node)->right, value);
        std::cout<<")";
    }
}


// Postorder #################################################
template<typename T>
template<typename T2>
void BTree_t<T>::
DSF_postorder(T2&& value)
{
    DSF_post_impl(&this->_root, value);
}

template<typename T>
template<typename T2>
void BTree_t<T>::DSF_post_impl(Node_t<T>** father_node, T2&& value)
{
    if (!*father_node) std::cout<<" - ";
    else 
    {
        std::cout<<"(";
        DSF_post_impl(&(*father_node)->left, value);
        DSF_post_impl(&(*father_node)->right, value);
        std::cout<<' '<<(*father_node)->_value<<' ';
        if ((*father_node)->_value == value) std::cout<<"!";
        std::cout<<")";
    }
}


// Inorder #################################################
template<typename T>
template<typename T2>
void BTree_t<T>::DSF_inorder(T2&& value)
{
    DSF_in_impl(&this->_root, value);
}


template<typename T>
template<typename T2>
void BTree_t<T>::DSF_in_impl(Node_t<T>** father_node, T2&& value)
{
    if (!*father_node) std::cout<<" - ";
    else 
    {
        std::cout<<"(";
        DSF_in_impl(&(*father_node)->left, value);

        std::cout<<' '<<(*father_node)->_value<<' ';
        if ((*father_node)->_value == value) std::cout<<"!";

        DSF_in_impl(&(*father_node)->right, value);
        std::cout<<")";
    }
}

} // namespace TDA 