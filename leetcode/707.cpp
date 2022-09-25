#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node():val(0),prev(nullptr),next(nullptr){}
    Node(int val):val(val),prev(nullptr),next(nullptr){}
};

class MyLinkedList {
public:
    Node* node;
    int len;
    MyLinkedList() {
       node = new Node(); 
       len = 0;
       node->next = node;
       node->prev = node;
    }
    
    int get(int index) {
        if (index < 0 ) return -1;
        if (index >= len) return -1;
        Node* index_node = node->next;
        for (int i = 0; i < index; i++)
        {
            index_node = index_node->next;
        }
        return index_node->val;
    }
    
    void addAtHead(int val) {
        Node* cur_next = node->next;
        Node* new_node = new Node(val);
        node->next = new_node;
        new_node->next = cur_next;    
        new_node->prev = node;
        cur_next->prev = new_node;
        len++;
    }
    
    void addAtTail(int val) {
        if (len == 0)
        {
            addAtHead(val);
            return;
        }
        Node* cur_prev = node->prev;
        Node* new_node = new Node(val);
        node->prev = new_node;
        cur_prev->next = new_node;
        new_node->prev = cur_prev;
        new_node->next = node;
        len++;
    }
    
    void addAtIndex(int index, int val) {
        Node* index_node = node;
        if (index <= 0) {addAtHead(val); return;}
        if (index == len) {addAtTail(val); return;}
        if (index > len) return;
        for (int i = 0; i < index; i++)
        {
            index_node = index_node->next;
        }
        Node* cur_next = index_node->next;
        Node* new_node = new Node(val);
        index_node->next = new_node;
        cur_next->prev = new_node;
        new_node->next = cur_next;
        new_node->prev = index_node;
        len++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 ) return;
        if (index >= len) return;
        Node* index_node = node->next;
        for (int i = 0; i < index; i++)
        {
            index_node = index_node->next;
        }
        Node *index_node_prev = index_node->prev;
        Node *index_node_next = index_node->next;
        index_node_prev->next = index_node_next;
        index_node_next->prev = index_node_prev;
        delete(index_node);
        len--;
    }
};

int main()
{
    MyLinkedList linkedList;
    linkedList.addAtHead(7);
    linkedList.addAtHead(2);
    linkedList.addAtHead(1);
    linkedList.addAtIndex(3,0);
    linkedList.deleteAtIndex(2);
    linkedList.addAtHead(4);
    linkedList.addAtTail(4);
    return 0;
}