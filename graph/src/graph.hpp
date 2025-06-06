#include"vertex.hpp"
#include<unordered_map>

namespace TDA {

template<typename T>
class Graph_t {
    std::unordered_map<T, std::shared_ptr<Vertex<T>>> vertices;

public:
    void addVertex(const T& value);
    void addEdge(const T& from, const T& to, double weight, bool undirected = false);
    void printGraph() const;
};


} // namespace TDA