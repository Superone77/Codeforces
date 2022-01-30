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

//要使相邻数的亦或值最小，势必要尽可能消去二进制表达中最高位的 1。
//
//我们拿 8 举例：
//
//000 001 010 011 100 101 110 111
//
//要使相邻的异或值最小，最高位是 1 的所有数应该放在一起相互抵消，但是一定有一个数的最高位是是抵消不掉的。要使这个值尽可能小，我们应该使亦或的结果只保留最高位的1。最简单的方法就是让 0 和 状如100000 的数 (此处 1 是最高位其他位均为 0)，相邻摆放，小于100000的数放 0 一侧，大于的放另一侧。这样构造的结果可以保证答案不超过100000.
//
//以 16 为例：
//
//即 1 2 3 4 5 6 7 0 8 9 10 11 12 13 14 15，最大相邻亦或值为 8。

//int main (){
//    IOS
//    int t; cin >> t;
//    while (t --){
//        int n; cin >> n;
//        int m = 1;
//        for (int i = 1 ; i <= n + 3; i *= 2){
//            if (i * 2 > n - 1){
//                m = i;
//                break;
//            }
//        }
//        for(int i = 1 ; i < m ; i ++) cout << i << ' ';
//        cout << 0 << ' ';
//        for (int i = m ; i < n ; i ++) cout << i << ' ';
//        cout << endl;
//    }
//    return 0;
//}
