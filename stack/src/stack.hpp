#pragma once
#include "../../linkedlists/C++/src/node.hpp"

namespace TDA {

template<typename TYPE>
struct Stack_t
{
    template<typename TYPE2>
    void push(TYPE2&&);

    void pop();

    TYPE const* get() const noexcept;
    TYPE* get()             noexcept;
    uint32_t size()   const noexcept { return _size; }
    void show()       const noexcept;

    ~Stack_t();

private:

    template<typename TYPE2>
    Node_t<TYPE>& createNode(TYPE2&&);
    void dropNode(Node_t<TYPE>&);

    Node_t<TYPE>* _head{nullptr};
    Node_t<TYPE>* _top{nullptr};
    uint32_t _size{0};
};

} // namespace TDA 
