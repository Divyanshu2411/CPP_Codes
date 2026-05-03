#include<bits/stdc++.h>
#include "myLib/customDLL.h"
using namespace::std;

template<typename K, typename V>
class CustomHashMap{

    int capacity=10;
    
    vector<doublyLL<K,V>> mapData(10);
    int maxLF =0.75; //load balancing factor

    int findHash(K key){
        hash<K> hasher;
        return hasher(key);
    }

    int findHashIndex(K key){
        return (findHash(key) % capacity);
    }
 
    void rebalance(){
        int nCapacity= 2*capacity;
        vector<doublyLL<K,V>> newData(nCapacity);

        for(int i=0; i<capacity; i++){
            Node<K,V>* curr= mapData[i].getHead();
            while(curr){
                int newInd = findHash(curr->key) % nCapacity;
                newData[newInd].add(curr->key, curr->val);
                curr= curr->next;
            }
        }
        mapData= move(newData);
        capacity= nCapacity;
    }


    public:
    int size=0;
    void put(K key, V val){
        putInMap(key, val, mapData);
    }
    void remove(K key){

    }
    void update(K key, newValue){

    }

    void findKey(K key){

    }


};
