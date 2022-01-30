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

//非常蒙蔽的题，和标题一样觉得很神奇。结论是，只进行操作 1 或者 操作 2，直到进行一次操作 3就可以使得 a = b。

//int main (){
//    IOS
//    int t; cin >> t;
//    while (t --){
//        int a, b, ans1 = 0, ans2 = 0; cin >> a >> b;
//        int ta = a, tb = b;
//        while ((ta | tb) != tb){
//            ta ++;
//            ans1 ++;
//        }
//        ta = a, tb = b;
//        int tempb = b * 2 + 100;
//        while (((ta | tb) != tb) && tb < tempb){
//            tb ++;
//            ans2 ++;
//        }
//        cout << min (min (ans1 + 1, ans2 + 1), b - a) << endl;
//    }
//    return 0;
//}
