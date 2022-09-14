#include <bits/stdc++.h>
using namespace std;

int main()
{
    string temp;
    while(cin>>temp)
    {
       istringstream iss(temp);
       string temp2;
       while(getline(iss,temp2,',')) cout<< temp2 <<endl;
       if (cin.get() == '\n') break;
    }

    return 0;
}