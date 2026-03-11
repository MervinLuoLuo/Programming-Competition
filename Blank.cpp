#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

bool check(int n,int base){
    int maxx = 0;
    if(n % 2 == 1) maxx = (((n + 1) / 2) + (n / 2)) * (n / 2) + ((n + 1) / 2);
    else maxx = (n / 2) * n;
    if(maxx >= base) return 1;
    else return 0;
}

void solve(){
    int a,b;cin >> a >> b;
    int x = max(a,b);
    int l = 1,r = 1e9;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(check(mid,x)) r = mid - 1;
        else l = mid + 1;
        // cerr << l << endl;
    }
    cout << l << endl;
}

signed main(){
    int t;cin >> t;
    while(t--) solve();
    return 0;
}

/*
odd: ((n + 1) / 2 + n / 2) * n / 2 + ((n + 1) / 2)
even: (n / 2) * n
*/