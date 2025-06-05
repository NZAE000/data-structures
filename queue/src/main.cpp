#include<iostream>
#include"queue.cpp"


int 
main(void)
{
    TDA::Queue_t<uint32_t> queue{};
    queue.enqueue(0);

    for (uint32_t i=1; i<10; i+=2) queue.enqueue(i);
    queue.show();

    auto const* val = queue.get();
    std::cout<<"First in queue: "<<*val<<"\n";

    queue.dequeue();
    queue.show();
    val = queue.get();
    std::cout<<"First in queue: "<<*val<<"\n";

    while(queue.size())
    {
        queue.dequeue();
        queue.show();
    }

    return 0;
}