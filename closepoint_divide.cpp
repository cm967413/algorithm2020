#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    class Point_contents
    {
        public:
            int distance;
             vector<int> current_point;

            Point_contents(int distance, vector<int> point)
            {
                this->distance = distance;
                this->current_point = point;
            }
    };
    
    void set_points(vector<vector<int>>& points,vector<Point_contents>& contents)
    {
        for(auto & point : points)
        {
            int distance = point[0]*point[0]+point[1]*point[1];
            Point_contents pc(distance,point);
            contents.push_back(pc);
        }
    }

    int partition(vector<Point_contents>& contents,int begin, int end)
    {
        int pivot = contents[end].distance; //beware
        int i = begin -1;
        for(int j = 0; j <= end-1; j++)
        {
            if(contents[j].distance < pivot)
            {
                i++;
                swap(contents[i],contents[j]);
            }

        }
        i++;
        swap(contents[i],contents[end]);
        return i;
    }
    /*int partition(vector<Point_contents>& contents,int begin,int end)
    {
        int pivot = contents[end].distance;
        int left = begin;
        int right = end;
        right--;
        while(1)
        {
            while(left <= right && contents[left].distance <= pivot)
            {
                left++;
            }
            while(left < right && contents[right].distance > pivot)
            {
                right--;
            }
            if(right <= left)
            {
                break;
            }
            swap(contents[left],contents[right]);
        }
        swap(contents[left],contents[end]);
        return left;
    }*/

    void sort(vector<Point_contents>& contents,int begin, int end,int K)
    {
        if(begin >= end)
        return;
        int middle = partition(contents,begin,end);
        int left_array_size = middle - begin + 1;

        if(left_array_size < K)
        {
            sort(contents,middle + 1, end, K-left_array_size);
        }
        else if(left_array_size >= K)
        {
            sort(contents, begin, middle-1,K);
        }
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> ans;
        vector<Point_contents> contents;
        set_points(points,contents);
        sort(contents,0,contents.size()-1,K);
        for(int i = 0; i < K; i++)
        {
            ans.push_back(contents[i].current_point);
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
