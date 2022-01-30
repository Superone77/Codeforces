//
// Created by Superone77 on 2022/1/30.
//
#include <iostream>
#include <string>

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
    int n; cin>>n;
    string str; cin>>str;
    if(n == 1) cout<<"YES"<<endl;
    else if(n == 2){
        if(str == "10" || str == "01")
            cout<<"YES"<<endl;
        else{
            cout<<"NO"<<endl;
        }
    }else{
        cout<<"NO"<<endl;
    }
    return;

}