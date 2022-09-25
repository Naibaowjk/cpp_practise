#include <bits/stdc++.h>
using namespace std;

void quicksort (vector<int> &nums, int left, int right)
{
    if (left < right)
    {
        int i, j,x;
        i = left;
        j = right;
        x = nums[i];
        while(i<j)
        {
            while(i<j && nums[j] > x)
            {
                j--;
            }
            if (i<j) nums[i++] = nums[j];
            while(i<j && nums[i] < x) i++;
            if (i <j) nums[j--] = nums[i];
        }
        nums[i] = x;
        quicksort(nums,left,i-1);
        quicksort(nums,i+1,right);
    }
}

int main()
{
    vector<int> nums{1,4,5,6,7,2,5,3,9};
    cout<<"before:"<<endl;
    for (int i = 0; i < nums.size()-1; i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    
    quicksort(nums,0,nums.size()-1);

    cout<<"after:"<<endl;
    for (int i = 0; i < nums.size()-1; i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}