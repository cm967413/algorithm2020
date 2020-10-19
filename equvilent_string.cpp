#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
string cut_half(string str)
{
    if(str.size() %2!=0)  //str.size() & 1
    {
        return str;
    }
    string part1,part2;
    part1 = cut_half(str.substr(0,str.length()/2));
    part2 = cut_half(str.substr(str.size()/2));
    return min(part1+part2,part2+part1);
}

bool cmp(string a, string b)
{
    cout <<cut_half(a)<<"  Hello"<<endl;
    return (cut_half(a) == cut_half(b));
}
int main()
{
    int cas;
    string a,b;
    cin >>cas;
    while(cas--)
    {
        cin >> a;
        cin >> b;
        if(cmp(a, b))
        {
            cout <<"Yes"<<endl;
        }
        else
        {
            cout <<"No"<<endl;
        }
        
    }   
        
    
    return 0;
}