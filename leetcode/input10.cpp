#include <bits/stdc++.h>

using namespace std;

int main()
{
    istringstream iss;
    string str;
    while(getline(cin,str))
    {
        if (str.empty()) break;
        iss.str(str);
        string temp;
        while(getline(iss,temp,','))
        {
            cout<<temp<<endl;
        }
    }
    return 0;
}