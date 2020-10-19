#include<bits/stdc++.h>
using namespace std;
int cut_half(string a,string b)
{
    if(a == b)
    return 1;
    else if (a.size()%2!=0)
    {
        return 0;
    }
    else if (cut_half(a.substr(0, a.size() / 2), b.substr(0, b.size() / 2)) && cut_half(a.substr(a.size() / 2, a.size() / 2), b.substr(b.size() / 2, b.size() / 2)))
        return 1;
    else if (cut_half(a.substr(0, a.size() / 2), b.substr(b.size() / 2, b.size() / 2)) && cut_half(a.substr(a.size() / 2, a.size() / 2), b.substr(0, b.size() / 2)))
        return 1;
    

    return 0;
}
int main()
{
    string first,second;
    int cas;
    cin >> cas;
    while(cas--)
    {
        cin >> first;
        cin >> second;
        if(cut_half(first,second))
        {
            cout << "Yes"<<endl;
        }
        else
        {
            cout << "No"<<endl;
        }
        

    }
    return 0;
}