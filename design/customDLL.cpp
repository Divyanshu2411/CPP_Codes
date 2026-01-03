#include<bits/stdc++.h>
#include "myLib/customDLL.h"

using namespace::std;

// template <typename K, typename V>
// class Node {
//     public:
//     K key;
//     V val;
//     Node* next;
//     Node* prev;

//     Node(K key,V val, Node* next, Node* prev){
//         this->key= key;
//         this->val= val;
//         this->next= next;
//         this->prev= prev;
//     }
// };

// template <typename K, typename V>
// class doublyLL{

//     Node<K,V> *listHead =nullptr;
//     Node<K,V> *listTail=nullptr;

//     Node<K,V> * search(K key){
//         Node<K,V> *temp= listHead;
//         while(temp){
//             if(temp->key==key)
//             return temp;
//             temp= temp->next;
//         }
//         return NULL;
//     }
//     public:
//     int size=0;

//     void add(K key, V val){
//         Node<K,V> *node = new Node<K,V>(key, val, NULL, NULL);
//         if(size==0){
//             listHead=node;
//             listTail=node;
//         }
//         else{
//             listTail->next=node;
//             node->prev=listTail;
//             listTail=node;
//         }
//         size++;
//     }

    
//     void update(K key, V newVal){
//         Node<K,V> *node= search(key);
//         if(node)
//             node->val = newVal;
//         else throw runtime_error("The key to be updated is not present");
//     }

//     void remove(K key){
//         Node<K,V> *node = search(key);
//         if(!node){
//             throw runtime_error("The key to be removed is not present");
//         }

//         if(node->prev) node->prev->next= node->next;  
//         else listHead= node->next;

//         if(node->next) node->next->prev = node->prev;
//         else listTail = node->prev;
        
//         delete(node);
//         size--;     
//     }

//     void print(){
//         Node<K,V>* curr= listHead;
//         while(curr){
//             cout<<curr->key<<" : "<<curr->val<<" -> ";
//             curr= curr->next;
//         }
//         cout<<"NULL\n";
//     }

//     //Destructor, to ensure the memory is freed and no memory leak
//     ~doublyLL(){
//         Node<K,V> * curr = listHead;
//         while(curr){
//             Node<K,V> *nextNode= curr->next;
//             delete curr;
//             curr= nextNode;
//         }
//         listHead=listTail=nullptr;
//         size=0;
//     }
// };

int main() {
    try {
        doublyLL<int, string> list;

        // 1. Test Add
        cout << "Adding elements..." << endl;
        list.add(1, "Apple");
        list.add(2, "Banana");
        list.add(3, "Cherry");
        cout << "Size after adding 3 elements: " << list.size << endl;
        list.print();

        // 2. Test Update
        cout << "Updating key 2..." << endl;
        list.update(2, "Blueberry");
        list.print();
        // 3. Test Remove (Middle)
        cout << "Removing key 2 (middle)..." << endl;
        list.remove(2);
        cout << "Size: " << list.size << endl;
        list.print();


        // 4. Test Remove (Head)
        cout << "Removing key 1 (head)..." << endl;
        list.remove(1);
        list.print();

        // 5. Test Remove (Tail/Last remaining)
        cout << "Removing key 3 (tail)..." << endl;
        list.remove(3);
        cout << "Final Size: " << list.size << endl;
        list.print();

        // 6. Test Error Handling
        cout << "Testing invalid remove..." << endl;
        list.remove(99); 

    } catch (const runtime_error& e) {
        cout << "Caught expected error: " << e.what() << endl;
    }

    return 0;
}