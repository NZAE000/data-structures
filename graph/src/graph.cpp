#include"graph.hpp"
#include<iostream>

namespace TDA {


template<typename T>
std::shared_ptr<Vertex_t<T>> Graph_t<T>::
addVertex(T const& value) 
{

    std::shared_ptr<Vertex_t<T>> vertex {nullptr};
    auto iterator = _vertices.find(&value); // This internally calls: PtrValueHash<T> to locate the bucket and PtrValueEqual<T> to compare with already stored keys.

    if (iterator == _vertices.end())
    {
        vertex = std::make_shared<Vertex_t<T>>(*const_cast<T*>(&value));
        _vertices[&value] = vertex; // This internally calls: PtrValueHash<T>::operator() to calculate the bucket and PtrValueEqual<T>::operator() to compare if an "equivalent" key already exists.
    }
    else vertex = (*iterator).second;

    return vertex;
}


template<typename T>
void Graph_t<T>::
addEdge(T const& from, T const& to, double weight, bool undirected) 
{
    auto v_from = addVertex(from);
    auto v_to   = addVertex(to);

    v_from->_neighbors.emplace_back(v_to, weight);
    if (undirected) {
        v_to->_neighbors.emplace_back(v_from, weight);
    }
}

template<typename T>
void Graph_t<T>::
printGraph() const 
{
    for (const auto& [key, vertex] : _vertices) {
        std::cout << vertex->_value << " -> ";
        for (const auto& [neighbor, weight] : vertex->_neighbors) {
            std::cout << "(" << neighbor->_value << ", weight=" << weight << ") ";
        }
        std::cout << '\n';
    }
}


}