#include"graph.hpp"
#include<iostream>
#include<memory>

namespace TDA {


template<typename T>
void Graph_t<T>::addVertex(const T& value) 
{
    if (vertices.find(value) == vertices.end()) {
        vertices[value] = std::make_shared<Vertex<T>>(value);
    }
}


template<typename T>
void Graph_t<T>::addEdge(const T& from, const T& to, double weight, bool undirected) 
{
    addVertex(from);
    addVertex(to);

    auto fromVertex = vertices[from];
    auto toVertex = vertices[to];

    fromVertex->neighbors.emplace_back(toVertex, weight);
    if (undirected) {
        toVertex->neighbors.emplace_back(fromVertex, weight);
    }
}

template<typename T>
void Graph_t<T>::printGraph() const 
{
    for (const auto& [key, vertex] : vertices) {
        std::cout << vertex->value << " -> ";
        for (const auto& [neighbor, weight] : vertex->neighbors) {
            std::cout << "(" << neighbor->value << ", weight=" << weight << ") ";
        }
        std::cout << '\n';
    }
}


}