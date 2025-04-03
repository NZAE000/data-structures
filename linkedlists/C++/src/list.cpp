#include "list.hpp"


Node_t& List_t::
createNode(uint32_t val)
{
    Node_t* node { new Node_t{val} };
    return *node;
}

void List_t::
dropNode(Node_t& node)
{
    delete &node;
}

void List_t::
destroy()
{
    Node_t* to_drop{nullptr};
    while(this->_head){
        to_drop    = this->_head;
        this->_head = this->_head->_next;
        dropNode(*to_drop);
    }
}

void List_t::
show() const noexcept
{
    Node_t* current_node { this->_head };
    while (current_node)
    {
        std::cout<< current_node->_value << " ";
        current_node = current_node->_next;
    }

    std::cout<<std::endl;
}

// GET /////////////////////////////////////////////////

const Node_t* List_t::
getNode(std::size_t pos) const
{
    Node_t* current_node {nullptr};

    if (pos < this->_size){
        current_node = this->_head;
        std::size_t index {0};
        while(++index <= pos) current_node = current_node->_next;
    }
    return current_node;
}
Node_t* List_t::
getNode(std::size_t pos)
{   
    auto const* node = const_cast<const List_t*>(this)->getNode(pos);
    return const_cast<Node_t*>(node);
}

// ADD /////////////////////////////////////////////////

void List_t::
add_begin(uint32_t val)
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

void List_t::
add_end(uint32_t val)
{
    auto& node { createNode(val) };

    if (!this->_head) this->_head = &node;
    else{
        Node_t* last_node = getNode(this->_size-1);
        last_node->_next = &node;
    }
    ++this->_size;
}
void List_t:: 
add(uint32_t val, std::size_t pos)
{
    if (pos == 0) add_begin(val);
    else if (pos < this->_size)
    {
        Node_t& node { createNode(val) };
        Node_t* previous_node = getNode(pos-1);
        node._next = previous_node->_next;
        previous_node->_next = &node;
        ++this->_size;
    }
}

// DROP /////////////////////////////////////////////////

void List_t::
erase_begin()
{
    if (!this->_head) return;
    else
    {
        Node_t& to_drop { *this->_head };
        this->_head = this->_head->_next;
        dropNode(to_drop);
        --this->_size;
    }
}

void List_t::
erase_end()
{
    if (!this->_head) return;
    else if (!this->_head->_next) dropNode(*this->_head);
    else
    {
        Node_t* penultimate_node = getNode(this->_size-2);
        dropNode(*penultimate_node->_next);
        penultimate_node->_next = nullptr;
    }
}

void List_t::
erase(std::size_t pos)
{
    if (pos == 0) erase_begin();
    if (pos < this->_size)
    {
        Node_t* previus_node = getNode(pos-1);
        Node_t& to_drop      = *previus_node->_next;
        previus_node->_next  =  previus_node->_next->_next;
        dropNode(to_drop);
    }
}

// OVERLOADING OPERATORS /////////////////////////

//void List_t::
//operator[](uint32_t pos)
//{
//    
//}

