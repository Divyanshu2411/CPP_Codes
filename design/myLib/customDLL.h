#pragma once

#include<bits/stdc++.h>

using namespace::std;

template <typename K, typename V>
class Node {
    public:
    K key;
    V val;
    Node* next;
    Node* prev;

    Node(K key,V val, Node* next, Node* prev){
        this->key= key;
        this->val= val;
        this->next= next;
        this->prev= prev;
    }
};

template <typename K, typename V>
class doublyLL{

    Node<K,V> *listHead =nullptr;
    Node<K,V> *listTail=nullptr;

    Node<K,V> * search(K key){
        Node<K,V> *temp= listHead;
        while(temp){
            if(temp->key==key)
            return temp;
            temp= temp->next;
        }
        return NULL;
    }
    public:
    int size=0;

    void add(K key, V val){
        Node<K,V> *node = new Node<K,V>(key, val, NULL, NULL);
        if(size==0){
            listHead=node;
            listTail=node;
        }
        else{
            listTail->next=node;
            node->prev=listTail;
            listTail=node;
        }
        size++;
    }

    
    void update(K key, V newVal){
        Node<K,V> *node= search(key);
        if(node)
            node->val = newVal;
        else throw runtime_error("The key to be updated is not present");
    }

    void remove(K key){
        Node<K,V> *node = search(key);
        if(!node){
            throw runtime_error("The key to be removed is not present");
        }

        if(node->prev) node->prev->next= node->next;  
        else listHead= node->next;

        if(node->next) node->next->prev = node->prev;
        else listTail = node->prev;
        
        delete(node);
        size--;     
    }

    void print(){
        Node<K,V>* curr= listHead;
        while(curr){
            cout<<curr->key<<" : "<<curr->val<<" -> ";
            curr= curr->next;
        }
        cout<<"NULL\n";
    }

    Node<K,V> * getHead(){
        return listHead;
    }

    Node<K,V>* getTail(){
        return listTail;
    }
    //Destructor, to ensure the memory is freed and no memory leak
    ~doublyLL(){
        Node<K,V> * curr = listHead;
        while(curr){
            Node<K,V> *nextNode= curr->next;
            delete curr;
            curr= nextNode;
        }
        listHead=listTail=nullptr;
        size=0;
    }
};
