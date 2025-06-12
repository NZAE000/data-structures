#include"graph.hpp"

namespace TDA {


template<typename T>
Graph_t<T>::Graph_t(std::vector<T> const& values, std::vector<std::vector<double>> const& adjacency_matrix)
{   
    auto size { values.size() };
    double weight {0};
    //std::shared_ptr<typename Graph_t<T>::Vertex_t> v_from {nullptr};
    //std::shared_ptr<typename Graph_t<T>::Vertex_t> v_to   {nullptr};

    for (uint32_t i=0; i<size; ++i) {
        //v_from = addVertex(values[i]);
        for (uint32_t j=0; j<size; ++j)
        {
            //if (i == j) v_to = v_from; 
            //else        v_to = addVertex(values[j]);
            weight = adjacency_matrix[i][j];
            if (weight) addEdge(values[i], values[j], weight);
        }
    }
}


// AddVertex is smart in temporarily constructing a T to search for and then moving it to the vertex if it doesn't exist. 
template<typename T>
template<typename T1>
std::shared_ptr<typename Graph_t<T>::Vertex_t> Graph_t<T>::
addVertex(T1&& value) 
{
    std::shared_ptr<Graph_t<T>::Vertex_t> vertex {nullptr};
    T val {std::forward<T1>(value)};

    auto iterator = _vertices.find(&val); // This internally calls: PtrValueHash<T> to locate the bucket and PtrValueEqual<T> to compare with already stored keys.
    if (iterator == _vertices.end())
    {
        vertex = std::make_shared<Graph_t<T>::Vertex_t>(std::move(val));
        _vertices[&(vertex->_value)] = vertex; // This internally calls: PtrValueHash<T>::operator() to calculate the bucket and PtrValueEqual<T>::operator() to compare if an "equivalent" key already exists.
    }
    else vertex = (*iterator).second;

    return vertex;
}


template<typename T>
template<typename T1>
void Graph_t<T>::
addEdge(T1&& from, T1&& to, double weight, bool undirected) 
{
    auto v_from = addVertex(from);
    auto v_to   = addVertex(to);

    v_from->_neighbors.emplace_back(v_to, weight);
    if (undirected) {
        v_to->_neighbors.emplace_back(v_from, weight);
    }
}

}