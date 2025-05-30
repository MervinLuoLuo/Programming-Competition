/*https://codeforces.com/contest/1975/problem/B*/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n;cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){cin >> a[i];}
        sort(a.begin(),a.end());
        int x = a[0], y;
        bool flag = 1;
        for(int i = 1; i < n; i++){
            if(a[i] % x != 0){y = a[i];break;}
        }
        for(int i = 1; i < n; i++){
            if(a[i] % x != 0 and a[i] % y != 0){
                flag = 0;
                break;
            }
        }
        if(flag) yes;
        else no;
    }
    return 0;
}
/*
长度为 n 的数组 a 
if 所有 a[k] 都能被 a 中 a[i] or a[k]整除  -> 美丽数组
判断 a 美丽吗
Inpuit: 
n
a[i]
1e9
Output: 
yes or no
*/