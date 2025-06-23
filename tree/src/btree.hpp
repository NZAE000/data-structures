#pragma once
#include"node.hpp"

namespace TDA {


template<typename T>
struct BTree_t {

    ~BTree_t();

    template<typename T2>
    void insert(T2&& value);

    template<typename T2>
    void DSF_preorder(T2&& value);
    template<typename T2>
    void DSF_postorder(T2&& value);
    template<typename T2>
    void DSF_inorder(T2&& value);

private:
    Node_t<T>* _root {nullptr};

// Helpers
    void destructor_impl(Node_t<T>** node);

    template<typename T2>
    [[nodiscard]] Node_t<T>& createNode(T2&& value);
    void dropNode(Node_t<T>* node);

    template<typename T2>
    void insert_impl(Node_t<T>** father_node, T2&& value);

    template<typename T2>
    void DSF_pre_impl(Node_t<T>** father_node, T2&& value);
    template<typename T2>
    void DSF_post_impl(Node_t<T>** father_node, T2&& value);
    template<typename T2>
    void DSF_in_impl(Node_t<T>** father_node, T2&& value);

};


} // namespace  TDA