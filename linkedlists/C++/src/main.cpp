#include<iostream>
#include "list.hpp"

int 
main(void)
{
    List_t list{};
    constexpr std::size_t n_nodes {10};

    for (uint32_t i=0; i<n_nodes; ++i){
        list.add_begin(i+1);
        list.add_end(i+1);
    }
    list.show();

    list.add(1, 0);
    list.show();
    list.add(1, 20);
    list.show();
    list.add(0, 15);
    list.show();

    list.erase_begin();
    list.show();
    list.erase_end();
    list.show();
    list.erase(4);
    list.show();

    list.destroy();
    list.show();

    return 0;
}