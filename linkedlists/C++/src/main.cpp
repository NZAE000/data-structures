#include<iostream>
#include "list.cpp"

int 
main(void)
{
    List_t<uint32_t> list{};
    constexpr std::size_t n_nodes {10};

    for (uint32_t i=0; i<n_nodes; ++i){
        list.add_begin(i);
        list.add_end(i);
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
    std::cout<<"elem 1: "<<list[1]<<"\n";
    list[1] = 0;
    std::cout<<"elem 1: "<<list[1]<<"\n";
    list.show();

    list.destroy();
    list.show();

    return 0;
}