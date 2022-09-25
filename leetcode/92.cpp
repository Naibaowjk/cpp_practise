#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}
};

class Solution
{
public: 
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if (head == nullptr) return head;
        if (right == left) return head;
        int index = 1;
        ListNode* cur = head;
        ListNode* l = left >= 1? nullptr : head;
        ListNode* r = nullptr;
        ListNode* rev_l = nullptr;
        ListNode* rev_r = nullptr;
        ListNode* rev_end = nullptr;
        while(cur != nullptr)
        {
            if (index == left - 1) {l = cur; cur = cur->next; }
            else if (index == left ) {rev_end = cur; rev_l = cur; cur = cur->next;}
            else if (index >  left && index <= right)
            {
                
                rev_r = cur->next;
                cur->next = rev_l;
                rev_l = cur;
                cur = rev_r;
            }
            // else if (index == right) rev_r = cur;
            else if (index == right + 1 ) {r = cur; cur = cur->next;}
            else cur = cur->next;
            index++;
        }
        if (l == nullptr) head = rev_l;
        else l->next = rev_l;
        rev_end->next = r;
        return head;
    }
};

ListNode* build_list(vector<int> v_val)
{
    ListNode *head = (ListNode*) malloc(sizeof(ListNode) * v_val.size() );
    ListNode* cur = head;
    for (int i = 0; i < v_val.size(); i++)
    {
        cur->val = v_val[i];
        if (i != v_val.size() -1 ) cur->next = cur + 1;
        else cur->next = nullptr;
        cur = cur->next;
    }
    return head;
}

int main()
{
    vector<int> v_val{1,2,3,4,5};
    int left = 1;
    int right = 2;
    ListNode* head = nullptr;
    head = build_list(v_val);
    Solution s;
    head = s.reverseBetween(head, left, right);
    return 0;
}