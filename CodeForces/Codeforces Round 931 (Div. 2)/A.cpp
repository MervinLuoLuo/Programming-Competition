#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int INF = 1e17;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        vector<int> a(n);
        for(int i = 0;  i< n; i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        int sum = abs(a[0] - a[n - 1]) + abs(a[n-1] - a[1]) + abs(a[1] - a[n - 2]) + abs(a[n - 2] - a[0]);
        cout << sum << endl;
    }
    return 0;
}
/*
一个数组 a 长度为 n 找出下面这个式子的最大值
|a[i] - a[j]| + |a[j] - a[k]| + |a[k] - a[l]|+ |a[l] - a[i]|
|最小 - 最大| + |最大 - 次小| + |次小 - 次大| + |次大 - 最小|
i j k l 均为数组下标且不一定连续
Input: 
t cases
n
a[i]
Output: 
式子最大值
最大的减最小的

*/