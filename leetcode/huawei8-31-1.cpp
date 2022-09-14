#include <bits/stdc++.h>
using namespace std;
stack<int> s1;
string match(string word, unordered_map<string,int> map)
{
    string word_bef =word;
    int index = 0;
    for(int i = 0 ; i< word.size();i++)
    {
        if(word[i] >= 'a' && word[i] <= 'z') word[i] = word[i] + 'A' - 'a';
    }
    if (s1.empty())
    {
        auto cur = map.find(word);
        if (cur != map.end())
        {
            index = cur->second;
            return to_string(index) + word_bef.substr(1,word_bef.size());
        }
    }
    return word_bef;
}

int main()
{
    string str_t;
    string str1;
    string str2;
    int i = 0;
    while(i != 2)
    {
        getline(cin,str_t);
        cout<<str_t<<endl;
        if (i==0) str1 = str_t;
        if (i==1) str2 = str_t;
        i++;
    }
    unordered_map<string,int> map;
    istringstream iss(str2);
    string temp;
    int index = 0;
    while(iss>>temp)
    {
        if (map.find(temp) == map.end()) {
            for(int i = 0 ; i< temp.size();i++)
            {
                if(temp[i] >= 'a' && temp[i] <= 'z') temp[i] = temp[i] + 'A' - 'a';
            }
            map[temp] = index; 
            index++;
        }
    }
    int p1 = 0;
    int len1 = str1.size();
    stack<int> s1;
    string temp_word = "";
    string  ret = "";
    while(p1<len1)
    {
        char temp_c = str1[p1];
        if (temp_c == ' ' || temp_c == ',' || temp_c == '.')
        {
            ret+= match(temp_word, map);
            temp_word = "";
        }
        else temp_word += temp_c;
        p1++; 
    }
    cout<<ret<<endl;
    return 0;
}