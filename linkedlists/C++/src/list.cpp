#include "list.hpp"
#include <stdexcept>

template<typename TYPE>
template<typename TYPE2>
Node_t<TYPE>& List_t<TYPE>::
createNode(TYPE2&& val)
{
    Node_t<TYPE>* node { new Node_t<TYPE>{static_cast<TYPE>(val)} };
    return *node;
}

template<typename TYPE>
void List_t<TYPE>::
dropNode(Node_t<TYPE>& node)
{
    delete &node;
}

template<typename TYPE>
void List_t<TYPE>::
destroy()
{
    Node_t<TYPE>* to_drop{nullptr};
    while(this->_head){
        to_drop    = this->_head;
        this->_head = this->_head->_next;
        dropNode(*to_drop);
    }
}

template<typename TYPE>
void List_t<TYPE>::
show() const noexcept
{
    Node_t<TYPE>* current_node { this->_head };
    while (current_node)
    {
        std::cout<< current_node->_value << " ";
        current_node = current_node->_next;
    }

    std::cout<<std::endl;
}

// GET /////////////////////////////////////////////////

template<typename TYPE>
const Node_t<TYPE>* List_t<TYPE>::
getNode(std::size_t pos) const
{
    Node_t<TYPE>* current_node {nullptr};

    if (pos < this->_size){
        current_node = this->_head;
        std::size_t index {0};
        while(++index <= pos) current_node = current_node->_next;
    }
    return current_node;
}
template<typename TYPE>
Node_t<TYPE>* List_t<TYPE>::
getNode(std::size_t pos)
{   
    auto const* node = const_cast<const List_t<TYPE>*>(this)->getNode(pos);
    return const_cast<Node_t<TYPE>*>(node);
}

// ADD /////////////////////////////////////////////////

template<typename TYPE>
template<typename TYPE2>
void List_t<TYPE>::
add_begin(TYPE2&& val)
{
    auto& node { createNode(val) };

    if (!this->_head){
        this->_head = &node;
    }
    else{
        node._next = this->_head;
        this->_head = &node;
    }
    ++this->_size;
}

template<typename TYPE>
template<typename TYPE2>
void List_t<TYPE>::
add_end(TYPE2&& val)
{
    auto& node { createNode(val) };

    if (!this->_head) this->_head = &node;
    else{
        Node_t<TYPE>* last_node = getNode(this->_size-1);
        last_node->_next = &node;
    }
    ++this->_size;
}

template<typename TYPE>
template<typename TYPE2>
void List_t<TYPE>:: 
add(TYPE2&& val, std::size_t pos)
{
    if (pos == 0) add_begin(val);
    else if (pos < this->_size)
    {
        Node_t<TYPE>& node { createNode(val) };
        Node_t<TYPE>* previous_node = getNode(pos-1);
        node._next = previous_node->_next;
        previous_node->_next = &node;
        ++this->_size;
    }
}

// DROP /////////////////////////////////////////////////
template<typename TYPE>
void List_t<TYPE>::
erase_begin()
{
    if (!this->_head) return;
    else
    {
        Node_t<TYPE>& to_drop { *this->_head };
        this->_head = this->_head->_next;
        dropNode(to_drop);
        --this->_size;
    }
}
template<typename TYPE>
void List_t<TYPE>::
erase_end()
{
    if (!this->_head) return;
    else if (!this->_head->_next) dropNode(*this->_head);
    else
    {
        Node_t<TYPE>* penultimate_node = getNode(this->_size-2);
        dropNode(*penultimate_node->_next);
        penultimate_node->_next = nullptr;
    }
}

template<typename TYPE>
void List_t<TYPE>::
erase(std::size_t pos)
{
    if (pos == 0) erase_begin();
    if (pos < this->_size)
    {
        Node_t<TYPE>* previus_node = getNode(pos-1);
        Node_t<TYPE>& to_drop      = *previus_node->_next;
        previus_node->_next  =  previus_node->_next->_next;
        dropNode(to_drop);
    }
}

// OVERLOADING OPERATORS /////////////////////////

template<typename TYPE>
TYPE const& List_t<TYPE>::
operator[](std::size_t pos) const
{
    auto const* node = getNode(pos);
    if (!node) throw std::runtime_error("access out of range");
    return node->_value;
}

template<typename TYPE>
TYPE& List_t<TYPE>::
operator[](std::size_t pos)
{
    auto& elem = const_cast<List_t<TYPE> const*>(this)->operator[](pos);
    return const_cast<TYPE&>(elem);
}