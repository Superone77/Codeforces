//
// Created by Superone77 on 2022/1/27.
//
#include <iostream>
#include <vector>


using namespace std;

vector<pair<int,int>> compute(int &size, int &target, vector<int> &flags, int count){
    if(count == 1){
        for(int i = 0;i<size;i++){
            if(flags[i]==1){
                continue;
            }
            for(int j = i+1; j<size;j++){
                if(flags[j] == 1) {
                    continue;
                }
                if(i&j == target){
                    pair<int,int> temp = {i,j};
                    vector<pair<int,int>> res;
                    res.push_back(temp);
                    return res;
                }
            }
        }
        return NULL;
    }
    for(int i = 0;i<size;i++){
        if(flags[i]==1){
            continue;
        }
        flags[i] = 1;
        for(int j = i+1; j<size;j++){
            if(flags[j] == 1){
                continue;
            }
            flags[j]= 1;
            int temp = i&j;
            vector<pair<int,int>> res = compute(size,target-temp flags, count-1);
            flags[j]=0;

        }
        flags[i]=0;
    }
}


int main() {
    int repeats = 0;
    cin>>repeats;
    for(int i = 0;i<repeats;++i){
        int size;
        int target;
        cin>>size;
        cin>>target;
        vector<int> flags;
        for(int i = 0;i<size;i++){
            flags.push_back(0);
        }
        vector<pair<int,int>> res = compute(size,target, flags, size/2);
    }

}
