#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int INF = 1e17;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> x(n + 5);
        for(int i = 2; i <= n ; i++){
            cin >> x[i];
        }
        vector<int> a(n + 5);
        a[1] = 314159;
        for(int i = 2 ; i <= n; i++){
            a[i] = a[i -1] + x[i];
            if(a[i] > maxn) a[i] = x[i];
        }
        for(int i = 1; i <= n; i ++){
            cout << a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
/*
给定一个数组 xi n - 1 个元素
要找一个数组 xi = ai % ai-1 ( 1 <= ai <= 1e9)
如果 a 有多个 输出 x一个就行
Input:
t cases
n 1e5
xi
Output: 
ai
*/