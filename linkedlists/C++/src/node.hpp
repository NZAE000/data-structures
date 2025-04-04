#pragma once
#include<cstdint>


template<typename TYPE>
struct Node_t {

    TYPE           _value{0};
    Node_t<TYPE>*  _next{nullptr};
};