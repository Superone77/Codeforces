//
// Created by Superone77 on 2022/1/30.
//

#include <iostream>
#include <vector>

using namespace std;

void solve();
void backtracking(int n, vector<int> &flag, vector<int> &path,vector<int> &res, int &minCost, int temp);
int main() {
    int repeats = 0;
    cin>>repeats;
    for(int i = 0;i<repeats;++i){
        solve();
    }
}
void solve(){
    vector<int> flag;
    vector<int> path;
    vector<int> res;
    int minCost = INT_MAX;
    int n; cin>>n;
    for(int i = 0;i<n;i++){
        flag.push_back(0);
        res.push_back(0);
    }
    backtracking(n,flag,path,res,minCost,INT_MIN);
    for(int i = 0;i<n;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}

void backtracking(int n, vector<int> &flag, vector<int> &path,vector<int> &res, int &minCost, int temp){
    if(minCost == 1) return;
    if(n == path.size()){
        if(temp<minCost){
            res.assign(path.begin(),path.end());
            minCost = temp;
        }
        return;
    }
    for(int i = 0;i<n;i++){
        if(flag[i] == 1) continue;
        flag[i] = 1;
        int origin = temp;
        if(path.size()>0){
            int cost = i^path[path.size()-1];
            temp = temp>=cost?temp : cost;
        }
        path.push_back(i);
        backtracking(n,flag,path,res,minCost,temp);
        path.pop_back();
        flag[i]=0;
        temp = origin;
    }
    return;
}