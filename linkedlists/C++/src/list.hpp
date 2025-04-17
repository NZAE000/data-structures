#pragma once
#include "node.hpp"
#include<iostream>

template<typename TYPE>
struct List_t {

    void show()        const noexcept;
    void destroy();
    std::size_t size() const noexcept { return _size; }

// Operators /////////////////////////////

    /*  template<typename TYPE2> <====

        Template to enable universal references (&&), 
        know whether it is used as an l-value or r-value, 
        depending on whether the argument is passed 
        as an lvalue or r-value. 
        (https://isocpp.org/blog/2012/11/universal-references-in-c11-scott-meyers)
    */

    template<typename TYPE2>
    void add_begin(TYPE2&&);

    template<typename TYPE2>
    void add_end(TYPE2&&);

    template<typename TYPE2>
    void add(TYPE2&&, std::size_t);

    void erase_begin();
    void erase_end();
    void erase(std::size_t);


// Overloading operators: sugar syntax for applying operators 
// (Let "this" be an instance of the class. It is possible to call this operator as this.operator[](3), but calling it "this[3]" also looks good in that.)
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