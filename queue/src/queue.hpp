#pragma once
#include "node.hpp"

namespace TDA {


template<typename TYPE>
struct Queue_t {

    template<typename TYPE2>
    void enqueue(TYPE2&&);

    void dequeue();

    TYPE const* get() const noexcept;
    TYPE* get()             noexcept;
    uint32_t size()   const noexcept { return _size; }
    void show()       const noexcept;

    ~Queue_t();

private:

    template<typename TYPE2>
    Node_t<TYPE>& createNode(TYPE2&&);
    void dropNode(Node_t<TYPE>&);

    Node_t<TYPE>* _head{nullptr};
    Node_t<TYPE>* _end{nullptr};
    uint32_t _size {0};
};

} // namespace TDA