//
// https://codeforces.com/contest/1631/problem/B
//
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int main() {
    int repeats = 0;
    cin >> repeats;
    for (int i = 0; i < repeats; ++i) {
        int size = 0;
        cin >> size;
        vector<int> x;
        for (int j = 0; j < size; ++j) {
            int temp;
            cin >> temp;
            x.push_back(temp);
        }
        int times = 0;
        int res = x[size - 1];
        for (int j = size - 2; j >= 0; --j) {
            if (x[j] != res) {
                times++;
                j -= size-j-2;
            }
        }


        cout << times << endl;
    }
}
