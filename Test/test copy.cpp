#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;


signed main(){
    bool flag1 = 0,flag2 = 0;
    int n;cin >> n;
    int cnt  = 0;
    int i = 2;
    vector<int> num;
    while(cnt != n){
        i++;cnt++;
        for(int j = 2; j * j <= 2; j++){
            if(i % j == 0) {flag1 = 1;break;}
        }
        if(flag1){cnt = 0;num.clear();continue;}
        num.push_back(i);
    }
    for(auto p:num){
        cout << p << ' ';
    }
    return 0;
}