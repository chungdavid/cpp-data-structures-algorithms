#include "data_structures/LinkedList.hpp"
#include <iostream>

int main() {
    std::cout<<"hello world\n";
    dsa_cpp::LinkedList<int> list;
    list.insertStart(5);
    list.insertStart(4);
    list.insertStart(1);
    list.insertStart(1);
    list.insertStart(1);
    list.insertEnd(200);
    list.insertEnd(200);
    list.insertEnd(200);
    list.insertEnd(200);
    list.insertEnd(200);
    list.print();
    std::cout<<list.getSize()<<"\n";
    std::cout<<list.getVal(3)<<"\n";
    std::cout<<list.getVal(0)<<"\n";
    std::cout<<list.getVal(9)<<"\n";
    std::cout<<list.getVal(20)<<"\n";
    return 0;
}