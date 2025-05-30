/*
https://www.luogu.com.cn/problem/P5736
*/
#include<bits/stdc++.h>
#define endl '\n'
#define int  long long
using namespace std;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    vector<int> num;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        num.push_back(x);
    }
    for(int i = 0; i < num.size();i++){
        if(num[i] <= 1)num.erase(num.begin() + i);
        for(int j = 2; j * j <= num[i]; j++){
            if(num[i] % j == 0) num.erase(num.begin() + i);
        }
    }
    for(auto p : num){
        cout << p << ' ';
    }
    return 0;
}
