#pragma once
#include<cstdint>


template<typename TYPE>
struct Node_t {

    TYPE           _value{};
    Node_t<TYPE>*  _next{nullptr};
};