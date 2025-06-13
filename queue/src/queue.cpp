#include "queue.hpp"
#include <iostream>

namespace TDA {

template<typename TYPE>
Queue_t<TYPE>::~Queue_t()
{
    while (this->_head) dequeue();
}

template<typename TYPE>
template<typename TYPE2>
Node_t<TYPE>& Queue_t<TYPE>::
createNode(TYPE2&& val)
{
    Node_t<TYPE>* node { new Node_t<TYPE>{std::forward<TYPE2>(val)} };
    return *node;
}

template<typename TYPE>
void Queue_t<TYPE>::
dropNode(Node_t<TYPE>& node)
{
    delete &node;
}


template<typename TYPE>
template<typename TYPE2>
void Queue_t<TYPE>::
enqueue(TYPE2&& val)
{
    Node_t<TYPE>& node { createNode(val) };
    if (!this->_head) { // First node:         ( Node0 )
        this->_head = &node;              //     ^  ^
        this->_end  = &node;             //   head  end
    }
    else {
        this->_end->_next = &node;   //       ( Node0 ) -> (node1)         
        this->_end = &node;          //           ^           ^
    }                               //         head         end

                                    //       ( Node0 ) -> (node1) -> (node2)
                                    //           ^                      ^
                                    //         head                    end
    ++_size;
}                      

template<typename TYPE>
void Queue_t<TYPE>::dequeue()
{
    if (this->_head)
    {
        Node_t<TYPE>* node = this->_head;
        this->_head = this->_head->_next;
        dropNode(*node);
        node = nullptr;
        if (!this->_head) this->_end = nullptr; // Update last to null.
        --_size;
    }
}

template<typename TYPE>
TYPE const* Queue_t<TYPE>::get() const noexcept
{   
    TYPE const* value{nullptr};
    if (this->_head) value = &this->_head->_value;
    return value;
}

template<typename TYPE>
TYPE* Queue_t<TYPE>::get() noexcept
{   
    TYPE const* value = const_cast<Queue_t<TYPE> const*>(this)->get();
    return const_cast<TYPE*>(value);
}


template<typename TYPE>
void Queue_t<TYPE>::
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


} // namespace TDA