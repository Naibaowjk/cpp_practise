#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}
};

class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        ListNode* ret=nullptr;
        int size = lists.size();
        if (size == 0) return ret;
        if (size == 1) return lists[0];
        int i=0;
        while(i<size-1){
            merge2Lists(lists,i,i+1);
            i++;
        }
        ret = lists[size-1];
        return ret;
    }
    void merge2Lists(vector<ListNode*> & lists, int i, int j)
    { 
        ListNode* head1 = lists[i];
        ListNode* head2 = lists[j];
        if (head1 == nullptr && head2 == nullptr) {head2 = nullptr; return;}
        if (head1 == nullptr) return ;
        if (head2 == nullptr) {lists[j] = head1; return;}
        ListNode* p1 = head1;
        ListNode* p2 = head2;
        ListNode* cur = nullptr;
        ListNode* head = nullptr;
        while(p1 != nullptr && p2 != nullptr)
        {
            int val1 = p1->val;
            int val2 = p2->val;
            if (val1>val2){
                if (p1 == head1 && p2 == head2) 
                {
                    cur = head2;
                    head = cur;
                    p2 = p2->next;
                    continue;
                }
                else cur->next = p2;

                p2 = p2->next;
            }
            else{
                if (p1 == head1 && p2 == head2)
                {
                    cur = head1;
                    head = cur;
                    p1 = p1->next;
                    continue;
                }
                else cur->next= p1;
                p1 = p1->next;
            }
            cur = cur->next;
        }
        if (p1 == nullptr && p2 != nullptr) cur->next = p2;
        if (p1 != nullptr && p2 == nullptr) cur->next = p1;
        lists[j] = head;
    }
    ListNode* build(vector<int> vec)
    {
        ListNode* head;
        ListNode* cur;
        for(int i = 0; i<vec.size();i++)
        {
            ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
            temp->val = vec[i];
            if (i == 0) {head = temp; cur = temp;}
            else
            {
                cur->next = temp;
                cur = temp;
            }
        }
        return head;
    }
};

int main()
{
    cout<<"Input val for ListNode: like([[1,4,5],[1,3,4],[2,6]])"<<endl;
    int temp;
    vector<ListNode*> lists;
    Solution s;
    cin.get(); //吞掉大括号
    ListNode *head;
    while(cin.get()=='[')
    {
        vector<int> vec_int;
        while(cin>>temp)
        {
            vec_int.push_back(temp);
            char c_temp = cin.get();
            if (c_temp == ',') continue;
            else if (c_temp == ']') break;
        }
        if (vec_int.size() != 0)
        {
            head = s.build(vec_int);
            lists.push_back(head);
        }
        char c_temp = cin.get();
        if (c_temp == ',') continue;
        if (c_temp = ']') break;
    }
    s.merge2Lists(lists, 0, 1);
    return 0;
}