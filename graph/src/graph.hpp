#pragma once

#include"vertex.hpp"
#include<map>

namespace TDA {


    //  The 'vertices' map defined is by default as ptr to T key, so do hash is repect to ptr value and comparation operator compare two address memory, 
//  but we want to search value of key throught some T value, not address, and also we want to compare two T values, not address.
    template<typename T2>
    struct PtrValueHash {
        std::size_t operator()(const T2* ptr) const {
            return std::hash<T2>()(*ptr);
        }
    };

    template<typename T2>
    struct PtrValueEqual {
        bool operator()(const T2* a, const T2* b) const {
            return *a == *b;
        }
    };


template<typename T>
struct Graph_t {

    std::shared_ptr<Vertex_t<T>> addVertex(T const& value);
    void addEdge(T const& from, T const& to, double weight, bool undirected = false);
    void printGraph() const;

private:


    std::unordered_map<T const*, std::shared_ptr<Vertex_t<T>>, PtrValueHash<T>, PtrValueEqual<T>> _vertices;

};

} // namespace TDA