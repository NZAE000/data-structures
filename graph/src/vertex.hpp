#pragma once
#include<cstdint>
#include<vector>
#include<memory>

template<typename T>
struct Vertex_t {

    Vertex_t(T& val) : _value{val} {}

    T _value;
    std::vector<std::pair<std::shared_ptr<Vertex_t<T>>, double>> _neighbors;
};
