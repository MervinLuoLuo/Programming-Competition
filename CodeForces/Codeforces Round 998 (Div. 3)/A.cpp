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
        vector<int> a(5);
        for(int i = 0; i < 5; i++){
            if(i == 2) continue;
            cin >> a[i];
        }
        int ans1 = 1;
        int ans2 = 1;
        a[2] = a[0] + a[1];
        if(a[1] + a[2] == a[3]) ans1++;
        if(a[2] + a[3] == a[4]) ans1++;
        a[2] = a[4] - a[3];
        if(a[0] + a[1] == a[2]) ans2++;
        if(a[1] + a[2] == a[3]) ans2++;
        cout << max(ans1,ans2) << endl;
    }
    return 0;
}
/*
长度为 5 的数组 一开始知道 a[1] [2] [4][5]
 a[i + 2] = a[i] + a[i + 1]
使得数组的斐波那契度数最大
Input: 
a[1][2][4][5]
Output:
数组的斐波那契度数
*/