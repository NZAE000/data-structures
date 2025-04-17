#pragma once
#include<cstdint>


/*  template<typename TYPE>
    struct Node_t { ... };

    To generate types as:
    
        - Node that contains a int type                  => Node_t<int>
        - Node that contains a float type                => Node_t<float>
        - Node that contains a char type                 => Node_t<char>
        - Node that contains a string type               => Node_t<std::string>
        - Node that contains a struct Order {...}; type: => Node_t<Order>

*/
template<typename TYPE>
struct Node_t {

    TYPE           _value{0};
    Node_t<TYPE>*  _next{nullptr};
};