#pragma once
#include "node.hpp"
#include<iostream>

struct List_t {

    void show()        const noexcept;
    void destroy();
    std::size_t size() const noexcept { return _size; }

// Operators /////////////////////////////

    void add_begin(uint32_t);
    void add_end(uint32_t);
    void add(uint32_t, std::size_t);

    void erase_begin();
    void erase_end();
    void erase(std::size_t);

// Overloading operators

    //void operator[](uint32_t);

private:
    Node_t*     _head{nullptr};
    std::size_t _size{0};

    Node_t& createNode(uint32_t);
    void    dropNode(Node_t&);

    Node_t*       getNode(std::size_t);
    const Node_t* getNode(std::size_t) const;
};