// https://codeforces.com/contest/1631/problem/A

#include <iostream>
#include <vector>

using namespace std;
void swap(vector<int> &x, vector<int> &y, int idx){
    int temp = x[idx];
    x[idx]=y[idx];
    y[idx]=temp;
}

int main() {
    int repeats = 0;
    cin>>repeats;
    for(int i = 0;i<repeats;++i){
        int size = 0;
        cin>>size;
        vector<int> x;
        vector<int> y;
        int max_x = 0;
        int max_y = 0;
        int idx_x = -1;
        int idx_y = -1;
        for(int j = 0;j<size;++j){
            int temp;
            cin>>temp;
            if(temp>max_x) {
                max_x = temp;
                idx_x = j;
            }
            x.push_back(temp);
        }
        for(int j = 0;j<size;++j){
            int temp;
            cin>>temp;
            if(temp>max_y) {
                max_y = temp;
                idx_y = j;
            }
            y.push_back(temp);
        }
        int res;
        int first;
        int second;
        if(max_x == max_y && idx_x == idx_y){
            res = max_x*max_y;
        }
        else if(max_x==max_y){
            first = max_x;
            swap(x,y,idx_y);
            second = 0;
            for(int i = 0;i<size;++i){
                if(i == idx_x || i == idx_y){
                    if(y[i]>second){
                        second = y[i];
                    }
                    continue;
                }
                if(x[i]>y[i]) {
                    if (y[i] > second)
                        second = y[i];
                }
                else{
                    if(x[i]>second)
                        second=x[i];
                }
            }
            res = first*second;
        }else{
            if(max_x>max_y){
                first = max_x;
                second = 0;
                for(int i = 0;i<size;++i){
                    if(i == idx_x){
                        if(y[i]>second){
                            second = y[i];
                        }
                        continue;
                    }
                    if(x[i]>y[i]) {
                        if (y[i] > second)
                            second = y[i];
                    }
                    else {
                        if (x[i] > second)
                            second = x[i];
                    }

                }
                res = first*second;
            }
            else{
                first = max_y;
                second = 0;
                for(int i = 0;i<size;++i){
                    if(i == idx_y){
                        if(x[i]>second){
                            second = x[i];
                        }
                        continue;
                    }
                    if(x[i]>y[i]) {
                        if (y[i] > second)
                            second = y[i];
                    }
                    else{
                        if(x[i]>second)
                            second=x[i];
                    }
                }
                res = first*second;
            }
        }

        cout<<res<<endl;

    }



}
