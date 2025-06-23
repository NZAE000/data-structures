#include<iostream>
//#include<string>
#include"btree.cpp"


int 
main(void)
{
    TDA::BTree_t<int32_t> btree{};
    int n = 5;

    btree.insert(n);
    btree.insert(10);
    btree.insert(4);
    btree.insert(9);
    btree.insert(15);

    //btree.DSF_preorder(11);
    //btree.DSF_inorder(9);
    btree.DSF_postorder(9);

    return 0;
}