#include"graph.cpp"



int main() {
    TDA::Graph_t<std::string> g;

    g.addEdge("A", "B", 1.5);
    g.addEdge("A", "C", 2.0);
    g.addEdge("B", "C", 2.5, true); // undirected edge

    g.printGraph();
}