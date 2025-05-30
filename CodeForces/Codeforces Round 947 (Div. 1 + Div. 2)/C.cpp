/*https://codeforces.com/contest/1975/problem/C*/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int mid(int a, int b, int c){
    int z = max(a,max(b,c));
    int x = min(a,min(b,c));
    return a+b+c-x-z;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n;cin >> n;
        vector<int> a(n +5);
        for(int i = 0; i < n; i++){cin >> a[i];}
        int ans = -1;
        for(int i = 0; i < n - 1; i++){
            ans = max(ans, min(a[i], a[i+1]));
        }
        for(int i = 1; i < n -1; i++){
            ans = max(ans,mid(a[i-1],a[i],a[i+1]));
        }
        cout << ans<< endl;
    }
    return 0;
}
/*

*/
/*
长度为 n 的数组 a
有这样的操作: 
    选择 l and r
    令 a[l] to a[r] 全换成 a[((r-l) + 1) / 2]
问 a 全部变为相同数字时 这个数字最大能是多少?
Input: 
n
a[i](1e9)
Output: 
ans
*/