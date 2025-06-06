#pragma once
#include<cstdint>
#include<vector>


template<typename T>
struct Vertex {
    T value;
    std::vector<std::pair<std::shared_ptr<Vertex<T>>, double>> neighbors;

    Vertex(T val) : value(val) {}
};
