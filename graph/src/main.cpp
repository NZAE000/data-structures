#include"graph.cpp"
#include<string>



int 
main(void) 
{
    std::string a {"A"};
    std::string b {"B"};
    std::string c {"C"};

    TDA::Graph_t<std::string> graph1;
    graph1.addEdge("A", "B", 1.5);
    graph1.addEdge("A", "C", 2.0);
    graph1.addEdge(b, c, 2.5, true); // undirected edge
    
    TDA::Graph_t<std::string> graph2 {
        {"A", "B", c},
        {
            {1.0, 1.5, 2.0},
            {0.0, 0.0, 2.5},
            {0.0, 2.5, 0.0}
        }
    };

    std::cout<<graph1<<'\n'<<graph2<<'\n';

    TDA::Graph_t<std::string> graph3 {
        {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L"},
        {
            {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
            {1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
            {0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0},
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1},
            {0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0}
        }
    };

    std::cout<<graph3;
}