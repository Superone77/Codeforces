//
// Created by Superone77 on 2022/1/27.
//

// https://zhuanlan.zhihu.com/p/462561849
#include <iostream>
#include <vector>


using namespace std;

int main() {
    int repeats = 0;
    cin>>repeats;
    for(int i = 0;i<repeats;++i){
        solve();
    }
}

void solve(){
    int n,k;cin>>n>>k;
    if(n == 4 && k==3){cout<<-1<<'n';return;}

    vector<pair<int,int>> ans;
    if(k==n-1){
        ans.push_back(make_pair(n-1,n-2));
        ans.push_back(make_pair(0,n-3));
        ans.push_back(make_pair(1,3));
        ans.push_back(make_pair(2.n-4));
        for(int i =4;i<n/2;i++) ans.push_back(make_pair(i,n-1-i));
    }
    else if(k==0)
    {
        for(int i=0;i<n/2;i++) ans.push_back(make_pair(i,n-1-i));
    }
    else
    {
        ans.push_back(make_pair(n-1,k));
        ans.push_back(make_pair(0,n-1-k));
        for(int i = 1;i<n/2;i++) if(i!=k && n-1-i!=k) ans.push_back(make_pair(i,n-i-1));
    }

    for(auto [x,y]:ans) cout<<x<<" "<<y<<'\n';

}
