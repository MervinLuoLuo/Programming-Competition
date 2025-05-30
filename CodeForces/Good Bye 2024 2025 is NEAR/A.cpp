/*https://codeforces.com/contest/2053/problem/A*/
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
        vector<int> a(n);
        for(int i = 0; i  < n; i++){
            cin >> a[i];
        }
        bool flag = 0;
        for(int i = 0; i <n - 1; i++){
            int x = a[i], y = a[i + 1];
            if(x > y) swap(x, y);
            if(x * 2 > y) {flag = 1;break;}
        }
        if(flag) yes;
        else no;
    }
    return 0;
}
/*
长度为 n 的数组 a
S stable:
    集合 S 中任意三个(可以相同) 的长度
    两边之和大于第三边
问能否将 a 用两种不同的方式分割成 n 个三角形
Input: 
n 200
a[i] 1e5
Output: 
yes or no
*/