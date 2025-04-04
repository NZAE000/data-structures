#pragma once
#include "node.hpp"
#include<iostream>

template<typename TYPE>
struct List_t {

    void show()        const noexcept;
    void destroy();
    std::size_t size() const noexcept { return _size; }

// Operators /////////////////////////////

    template<typename TYPE2>
    void add_begin(TYPE2&&);

    template<typename TYPE2>
    void add_end(TYPE2&&);

    template<typename TYPE2>
    void add(TYPE2&&, std::size_t);

    void erase_begin();
    void erase_end();
    void erase(std::size_t);

// Overloading operators

    TYPE&       operator[](std::size_t);
    TYPE const& operator[](std::size_t) const;

private:
    Node_t<TYPE>* _head{nullptr};
    std::size_t   _size{0};

    template<typename TYPE2>
    Node_t<TYPE>& createNode(TYPE2&&);
    void dropNode(Node_t<TYPE>&);

    Node_t<TYPE>*       getNode(std::size_t);
    const Node_t<TYPE>* getNode(std::size_t) const;
};