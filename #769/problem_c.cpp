//
// Created by Superone77 on 2022/1/30.
//

#include <iostream>
#include <queue>


using namespace std;

void solve();
int main() {
    int repeats = 0;
    cin>>repeats;
    for(int i = 0;i<repeats;++i){
        solve();
    }
}
void solve(){
    int a,b; cin>>a>>b;
    int depth = 0;
    queue<pair<int,int> > queue;
    queue.push(make_pair(a,b));
    int sum = 1;
    int count =0;
    while(!queue.empty()){
        pair<int,int> num = queue.front();queue.pop();sum--;
        if(num.first == num.second) {
            cout << depth << endl;
            return;
        }
        if(num.first>num.second){
            queue.push(make_pair(num.first,num.second+1)); count++;
            queue.push(make_pair(num.first|num.second, num.second));count++;
            queue.push(make_pair(num.first+1, num.second));count++;
        }else if(num.second - num.first<10){
            queue.push(make_pair(num.first+1, num.second));count++;
            queue.push(make_pair(num.first|num.second, num.second));count++;
            queue.push(make_pair(num.first,num.second+1)); count++;
        }else{
            queue.push(make_pair(num.first|num.second, num.second));count++;
            queue.push(make_pair(num.first+1, num.second));count++;
            queue.push(make_pair(num.first,num.second+1)); count++;
        }

        if(sum == 0){
            sum = count;
            count = 0;
            depth++;
        }
    }
    cout<<depth<<endl;
}