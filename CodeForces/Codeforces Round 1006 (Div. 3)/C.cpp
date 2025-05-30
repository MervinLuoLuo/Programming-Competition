#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int t;cin >> t;
    while(t--){
        int n,x;cin >> n >> x;
        vector<int> ans(n);
        int cur = 0;
        for(int i = 1; i < n; i++){
            if((x | i) == x) {ans[i] = i;cur |= i;}
        }
        if(cur != x) ans[n - 1] = x;
        for(auto it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}