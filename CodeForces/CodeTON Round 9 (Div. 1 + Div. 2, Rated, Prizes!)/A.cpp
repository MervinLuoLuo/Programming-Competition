#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

signed main(){
    int t;cin >> t;
    while(t--){
        int n; cin>> n;
        for(int i = 1; i <= n; i++){
            cout << 2*i - 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}
/*
n个数 
找一个严格递增序列
其中 a[i] mod i != a[j] mod j
i < j
Input: 
t cases
n
Output: 
输出序列
*/