/*https://codeforces.com/contest/1975/problem/A*/
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
        vector<int> a(2 * n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i + n] = a[i];
        }
        bool flag = 0;
        for(int i = 0; i < n; i++){
            int cnt = 1;
            for(int j = 1; j < n; j++){
                if(a[i + j] >= a[i + j - 1]) cnt++;
            }
            if(cnt == n) flag = 1;
        }
        if(flag) yes;
        else no;
    }
    return 0;
}
/*
长度为 n 的正整数数列 a
问经过下列操作能否使得 a 成为一个非严格递增数列(存在操作 0)
    将数列分成两部分 然后交换这两部分的位置
Input: 
n
a[i]
Output: 
yes or no

*/