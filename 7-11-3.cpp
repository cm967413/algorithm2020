#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct store
{
    int x;
    int y;
    int idx;
};
struct record
{
    pair<store,store> par;
    int distance;
};
bool cmp(record a,record b)
{
    if(a.distance < b.distance)
    return 1;
    else if (a.distance == b.distance)
    {
     return a.par.first.idx < a.par.second.idx;
    }
    else
    return 0;
}
int destroy(vector<record>&);

int N;

int main()
{
    cin >> N;
    store stores[N];
    for(int i = 0; i < N; i++)
    {
        cin >> stores[i].x;
        cin >> stores[i].y;
        stores[i].idx=i;
    }
    vector <record> rec;
    for(int i = 0; i < N-1; i++)
    {
        for(int j = i+1; j < N; j++)
        {
            if( ((stores[i].x - stores[j].x)*(stores[i].x - stores[j].x)) +
                ((stores[i].y - stores[j].y)*(stores[i].y - stores[j].y)) < 40000 )
             {
                 record tmp;
                 tmp.par.first = stores[i];
                 tmp.par.second = stores[j];
                 /*cout <<"^^^^^^^^^^^^^^^^^^^^^^"<<endl;
                 cout << tmp.par.first.x<<" ";
                 cout << tmp.par.first.y<<endl;
                cout << tmp.par.second.x<<" ";
                 cout << tmp.par.second.y<<endl;*/
                 
                 tmp.distance = ((stores[i].x - stores[j].x)*(stores[i].x - stores[j].x)) +
                                ((stores[i].y - stores[j].y)*(stores[i].y - stores[j].y));
                
                rec.push_back(tmp);
                
             }
        }
    }
    for(int i = 0; i < rec.size();i++)
    {
    	cout << rec[i].par.first.idx<<" ";
        cout << rec[i].par.second.idx<<endl;
	}
	cout << "---------------------------"<<endl;
    sort(rec.begin(),rec.end(),cmp);
    //存好要刪除的vector了 接下來要按照distance進行sort
    //store紀錄index
    for(int i = 0; i < rec.size();i++)
    {
    	cout << rec[i].par.first.idx<<" ";
        cout << rec[i].par.second.idx<<endl;
	}
    
    int ans = destroy(rec);

    cout << "Number of removed 7-11 stores: "<< ans << endl;
   /* for(auto & it : rec )
    {
        cout << it.par.first.idx<<" ";
        cout << it.par.second.idx<<"  1: ";
        cout << it.par.first.center_distance;
        cout << "  2: "<<it.par.second.center_distance<<endl;
        cout << it.par.first.is_destroyed<<" "<<it.par.second.is_destroyed<<endl;
    }*/

    
    
    return 0;
}
int destroy(vector<record> &rec)
{
    int num_of_destoryed_stores = 0;
    
    bool is_destroyed[N]={0};
    for( auto& it : rec)
    {
        //cout <<"before: "<< is_destroyed[it.par.first.idx]<<" "<<is_destroyed[it.par.second.idx]<<endl;
        if(is_destroyed[it.par.first.idx] == 1 || is_destroyed[it.par.second.idx] == 1)
        {
       //     cout << "cone"<<endl;
            continue;
        }
        else
        {
            int x1 = it.par.first.x;
            int y1 = it.par.first.y;
            int x2 = it.par.second.x;
            int y2 = it.par.second.y;
            
            if(((x1-20000)*(x1-20000)+(y1-20000)*(y1-20000)) < ((x2-20000)*(x2-20000)+(y2-20000)*(y2-20000)))
            {
                is_destroyed[it.par.first.idx] = 1;
                num_of_destoryed_stores++;
            }
            else if(((x1-20000)*(x1-20000)+(y1-20000)*(y1-20000)) > ((x2-20000)*(x2-20000)+(y2-20000)*(y2-20000)))
            {
                is_destroyed[it.par.second.idx] = 1;
                num_of_destoryed_stores++;
            }
            else if(((x1-20000)*(x1-20000)+(y1-20000)*(y1-20000)) == ((x2-20000)*(x2-20000)+(y2-20000)*(y2-20000)))
            {
                if(it.par.first.idx < it.par.second.idx)
                {
                    is_destroyed[it.par.first.idx]=1;
                    num_of_destoryed_stores++;
                }
                else
                {
                    is_destroyed[it.par.second.idx]=1;
                    num_of_destoryed_stores++;
                }
                
            }
        }
        //cout <<"after: "<< is_destroyed[it.par.first.idx]<<" "<<is_destroyed[it.par.second.idx]<<endl;
        
    }
    return num_of_destoryed_stores;
}