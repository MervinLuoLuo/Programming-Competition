/*https://codeforces.com/contest/2055/problem/B*/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n;cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        bool same = 1;
        for(int i = 0; i < n; i++){
            if(a[i] < b[i]){
                same = 0;break;
            }
        }
        if(same){yes;continue;}
        int x = -1;
        int idx = 0;
        for(int i = 0; i < n; i++){
            if(b[i] - a[i] > 0){
                x = b[i] - a[i];
                idx = i;
                break;
            }
        }
        bool check = 1;
        int count = 0,min = maxn;
        for(int i = 0; i < n; i++){
            if(i == idx) continue;
            if(a[i] - b[i] <= 0) {check = 0;break;}
            if(a[i] - b[i] < min) min = a[i] - b[i];
        }
        if(!check){no;continue;}
        if(x > min){no;continue;}
        else yes;
    }
    return 0;
}
/*

*/
/*
n 个魔法原件 从 1 ~ n编号
有 i 个模块 i 模块有 a[i] 个原件
操作: 
    选编号为 i 模块
    a[i]++;
    其他模块 a[j]--
要求所有 a[i] >= b[i] 个原件
问是否有可能通过 n(n >= 0) 次操作操作使得 a[i] 都 >= b[i]
Input: 
n 1e5
a[i] 1e9
b[i] 1e9
Output: 
yes or no
*/