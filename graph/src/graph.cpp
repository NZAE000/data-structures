#include"graph.hpp"
#include<cassert>

namespace TDA {


template<typename T>
Graph_t<T>::Graph_t(std::vector<T> const& values, std::vector<std::vector<double>> const& adjacency_matrix)
{   
    auto size { values.size() };
    double weight {0};

    for (uint32_t i=0; i<size; ++i) {
        for (uint32_t j=0; j<size; ++j)
        {
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


template<typename T>
template<typename T1>
void Graph_t<T>::
DFS(T1&& b, T1&& t)
{   
    T begin  { std::forward<T1>(b) };
    T tarjet { std::forward<T1>(t) };

    auto it_begin  = _vertices.find(&begin);
    auto it_tarjet = _vertices.find(&tarjet);
    assert(it_begin  != end(_vertices) && "[DFS]: begin value not found.");
    assert(it_tarjet != end(_vertices) && "[DFS]: tarjet value not found.");

    Vertex_t& v_begin  = *(*it_begin).second.get();
    Vertex_t& v_target = *(*it_tarjet).second.get();
    //std::cout<< "begin: "<< v_begin << " tarjet: "<< v_target<<"\n";
    Stack_t<Vertex_t*> stack;

    DFS_impl(v_begin, v_target, stack);
}

template<typename T>
void Graph_t<T>::
DFS_impl(Vertex_t& v_begin, Vertex_t& v_target, Stack_t<Vertex_t*>& stack)
{

    v_begin._visited = 1;
    std::cout<<v_begin._value<<" ";
    if (v_begin._value == v_target._value) { std::cout<<"!"; }

    //stack.push(&v_begin);
    //stack.show();

    for (auto const& neighbor : v_begin._neighbors){
        Vertex_t* v_neighbor  = neighbor.first.get();
        if (!v_neighbor->_visited){
            //std::cout<<v_begin._value<<"-"<<v_neighbor->_value <<'\n';
            DFS_impl(*v_neighbor, v_target, stack);
        }
    }
    //_stack_visited.pop();
}


template<typename T>
template<typename T1>
void Graph_t<T>::
BFS(T1&& b, T1&& t)
{  
    T begin  { std::forward<T1>(b) };
    T tarjet { std::forward<T1>(t) };

    auto it_begin  = _vertices.find(&begin);
    auto it_tarjet = _vertices.find(&tarjet);
    assert(it_begin  != end(_vertices) && "[DFS]: begin value not found.");
    assert(it_tarjet != end(_vertices) && "[DFS]: tarjet value not found.");

    Vertex_t& v_begin  = *(*it_begin).second.get();
    Vertex_t& v_target = *(*it_tarjet).second.get();

    Queue_t<Vertex_t*> queque;
    BFS_impl(v_begin, v_target, queque);
}

template<typename T>
void Graph_t<T>::
BFS_impl(Vertex_t& v_begin, Vertex_t& v_target, Queue_t<Vertex_t*>& queque)
{
    v_begin._visited = 1;
    std::cout<<v_begin._value<<" ";
    if (v_begin._value == v_target._value) { std::cout<<"!"; }

    for (auto const& neighbor : v_begin._neighbors){
        Vertex_t* v_neighbor = neighbor.first.get();
        if (!v_neighbor->_visited) queque.enqueue(v_neighbor);
    }

    Vertex_t** v_first = queque.get();
    if (v_first){
        std::cout<<"aca: "<<(*v_first)->_value;
        queque.dequeue();
        BFS_impl(**v_first, v_target, queque);
    }
}

}