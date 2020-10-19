#include <bits/stdc++.h>
using namespace std;
class compare
{
    public:
    bool operator() (const vector<int>&m,const vector<int>&n)
    {
        return m[0]*m[0]+m[1]*m[1] < n[0]*n[0]+n[1]*n[1];
    }

};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> ans;
        priority_queue <vector<int>,vector<vector<int>>,compare> sequence;
        for(int i = 0; i < points.size();i++)
        {
            if(sequence.size()<K)
            {
                sequence.push(points[i]);
            }
            else
            {
                //vector<int> biggest_point = sequence.top();
                //int biggest_distance = biggest_point[0]*biggest_point[0]+biggest_point[1]+biggest_point[1];
                int biggest_distance = sequence.top()[0]*sequence.top()[0]+sequence.top()[1]*sequence.top()[1];
                int current_distance = points[i][0]*points[i][0]+points[i][1]*points[i][1];
                if(biggest_distance > current_distance)
                {
                    sequence.pop();
                    sequence.push(points[i]);
                }
            }
        }
        while(sequence.size()!=0)
            {
                ans.push_back(sequence.top());
                sequence.pop();
            }
        return ans;
    }
};

bool sortFunc(const vector<int>& v1, const vector<int>& v2 ){
    if(v1[0]==v2[0]){
        return v1[1] > v2[1];
    }
    else{
        return v1[0] > v2[0]; 
    }
} 


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x, y, k;
    vector<int> tmp;
    vector<vector<int>> points;
    vector<vector<int>> ans;
    cin >> n >> k;
    while(n--){
        cin >> x >> y;
        tmp.push_back(x);
        tmp.push_back(y);
        points.push_back(tmp); 
        tmp.clear();
    }

    Solution sol;
    ans = sol.kClosest(points,k);
    sort(ans.begin(), ans.end(),sortFunc); 
    for(auto it = ans.begin();it!=ans.end();it++){
        for (auto it2 = it->begin(); it2 != it->end(); it2++) {
            cout << *it2 << " ";
        }
        cout << endl;
    }
    return 0;
}