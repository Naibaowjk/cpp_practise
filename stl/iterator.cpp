#include <iostream>
using namespace std;


template<typename T>
struct ListNode
{
    ListNode<T> *prev;
    ListNode<T> *next;
    T val;
};

template<typename T>
struct Iterator
{
    typedef Iterator<T> iterator;
    typedef T val;
    typedef T& ref;
    ListNode<T> *node;

    Iterator(ListNode<T> *node):node(node){}
    Iterator():node(nullptr){}

    iterator& operator++()
    {
        node = node->next;
        return *this;
    }

    iterator& operator++(int)
    {
        node = node->next;
        return *this;
    }

    iterator& operator--()
    {
        node = node->prev;
        return *this;
    }

    iterator& operator--(int)
    {
        iterator temp = *this;
        node = node->prev;
        return temp;
    }

    bool operator==(iterator& other) {return this->node == other->node;}
    bool operator!=(iterator& other) {return this->node != other->node;}
    iterator* operator->(){return this;}
    ref operator*(){return node->val;}
};

template<typename T>
struct NaibaoList
{
    typedef ListNode<T>* p;
    typedef Iterator<T> iterator;

    NaibaoList()
    { 
        node = new ListNode<T>;
        node->next = node;
        node->prev = node;
    }

    iterator begin()
    {
        // iterator temp(node->next);
        return node->next;
    }

    iterator end()
    {
        return node;
    }

    void insert(iterator posi, T val)
    {
        p tmp = new ListNode<T>;
        tmp->val = val;
        tmp->next = posi.node->next;
        tmp->prev = posi.node;
        posi.node->next->prev = tmp;
        posi.node->next = tmp;

    }

    void erase(iterator posi)
    {
        posi.node->next->prev = posi.node->prev;
        posi.node->prev->next = posi.node->next;
    }

    void push_back(T val)
    {
        insert(--end(), val);
    }

    void pop_back()
    {
        erase(--end());
    }
private:
    p node;
};

template<typename T>
void print_container(T begin, T end)
{
    while(begin != end)
    {
        cout<<*begin<<endl;
        begin++;
    }
}


int main()
{
    int v[5] = {1,2,3,4,5};
    NaibaoList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.pop_back();
    print_container(list.begin(),list.end());
    return 0;
}