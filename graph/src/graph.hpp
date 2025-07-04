#pragma once
#include<iostream>
#include<cstdint>
#include<vector>
#include<memory>
#include<map>
#include "../../stack/src/stack.cpp"
#include "../../queue/src/queue.cpp"
/*

Implementación de grafo eficiente:

    -> Hacer que cada Vertex_t sea dueño de su propio valor (T _value).
    -> Usar punteros como claves en el unordered_map, lo cual evita duplicar objetos de tipo T.
    -> Implementar PtrValueHash y PtrValueEqual para que el mapa compare y ubique claves por contenido, no por dirección.

El diseño resuelve perfectamente el problema de:

    -> Evitar duplicación de T.
    -> Permitir modificar los atributos internos de T.
    -> Mantener unicidad de vértices por valor.
    -> Soportar tanto lvalues como rvalues con perfect forwarding.
*/

namespace TDA {

    //  The 'vertices' map defined is by default as ptr to T key, so do hash is repect to ptr value and comparation operator compare two address memory, 
    //  but we want to search value of key throught some T value, not address, and also we want to compare two T values, not address.
    template<typename T2>
    struct PtrValueHash {
        std::size_t operator()(T2 const* ptr) const {
            return std::hash<T2>()(*ptr);
        }
    };

    template<typename T2>
    struct PtrValueEqual {
        bool operator()(T2 const* a, T2 const* b) const {
            return *a == *b;
        }
    };


template<typename T>
struct Graph_t {

    /// @brief /////////////////////////////////////////////////////////////////
    struct Vertex_t {

        Vertex_t(T&& val)      : _value{std::move(val)} {}
        Vertex_t(const T& val) : _value{val} {}

        T _value;
        uint8_t _visited {0};
        std::vector<std::pair<std::shared_ptr<Vertex_t>, double>> _neighbors;
        
        friend std::ostream& operator<<(std::ostream& os, Vertex_t const& v) {
            os << v._value;
            return os;
        }
    };
    ///////////////////////////////////////////////////////////////////////////

    explicit Graph_t() = default;
    explicit Graph_t(std::vector<T> const&, std::vector<std::vector<double>> const&);


    template<typename T1>
    void addEdge(T1&& from, T1&& to, double weight, bool undirected = false);

    template<typename T1>
    void DFS(T1&& begin, T1&& target);

    template<typename T1>
    void BFS(T1&& begin, T1&& target);

    friend std::ostream& operator<<(std::ostream& os, Graph_t<T> const& g)
    {
        for (const auto& [key, vertex] : g._vertices) {
            os << *vertex.get() << " -> ";
            for (const auto& [neighbor, weight] : vertex->_neighbors) {
                os << "(" << *neighbor.get() << ", weight=" << weight << ") ";
            }
            os << '\n';
        }
        return os;
    }

private:

    std::unordered_map<T*, std::shared_ptr<Vertex_t>, PtrValueHash<T>, PtrValueEqual<T>> _vertices;

    template<typename T1>
    std::shared_ptr<Vertex_t> addVertex(T1&& value); // User don't access.
    void DFS_impl(Vertex_t& begin, Vertex_t& target, Stack_t<Vertex_t*>&);
    void BFS_impl(Vertex_t& begin, Vertex_t& target, Queue_t<Vertex_t*>&);
};

} // namespace TDA