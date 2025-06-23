#pragma once


template<typename T>
struct Node_t {

    T _value;
    Node_t* left{nullptr};
    Node_t* right{nullptr};
};