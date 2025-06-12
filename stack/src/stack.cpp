#include"stack.hpp"
#include<iostream>


namespace TDA {


template<typename TYPE>
Stack_t<TYPE>::~Stack_t()
{
    while (this->_head) pop();
}

template<typename TYPE>
template<typename TYPE2>
Node_t<TYPE>& Stack_t<TYPE>::
createNode(TYPE2&& val)
{
    Node_t<TYPE>* node { new Node_t<TYPE>{std::forward<TYPE2>(val)} };
    return *node;
}

template<typename TYPE>
void Stack_t<TYPE>::
dropNode(Node_t<TYPE>& node)
{
    delete &node;
}

template<typename TYPE>
template<typename TYPE2>
void Stack_t<TYPE>::
push(TYPE2&& val)
{
    Node_t<TYPE>& node { createNode(val) };     //  (node0) -> null
    node._next = this->_top;                    //     ^
    this->_top  = &node;                        //    top

                                                //  (node1) -> (node0) -> null
                                                //     ^
                                                //    top
    ++_size;
}

template<typename TYPE>
void Stack_t<TYPE>::pop()
{
    if (this->_top){
        Node_t<TYPE>* node = this->_top;
        this->_top = this->_top->_next;
        dropNode(*node);
        --_size;
    }
}


template<typename TYPE>
TYPE const* Stack_t<TYPE>::get() const noexcept
{   
    TYPE const* value{nullptr};
    if (this->_top) value = &this->_top->_value;
    return value;
}

template<typename TYPE>
TYPE* Stack_t<TYPE>::get() noexcept
{   
    TYPE const* value = const_cast<Stack_t<TYPE> const*>(this)->get();
    return const_cast<TYPE*>(value);
}


template<typename TYPE>
void Stack_t<TYPE>::
show() const noexcept
{
    Node_t<TYPE>* current_node { this->_top };
    while (current_node)
    {
        std::cout<< current_node->_value << " ";
        current_node = current_node->_next;
    }

    std::cout<<std::endl;
}



} // namespace TDA 