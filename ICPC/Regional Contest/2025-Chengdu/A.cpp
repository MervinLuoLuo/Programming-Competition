#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N=2e5+10;
const int mod=998244353; 
void solve()
{
    int n; cin >> n;
    vector<int> d(n);
    for(auto& x : d) cin >> x;
    vector<int> L(n), R(n);
    for(int m = 1; m <= 1e3; m++)
    {
        int sumL = 0, sumR = 0;
        bool flag = 1;
        for(int i = 0; i < n; i++)
        {
            L[i] = max(0, (int)ceil(m * (d[i] / 100.0 - 0.005) - 1e-9));
            R[i] = min(m, (int)floor(m * (d[i] / 100.0 + 0.005) - 1e-9));
            if(L[i] > R[i])
            {
                flag = 0;
                break;
            }
            sumL += L[i];
            sumR += R[i];
        }
        if(!flag) continue;
        if(sumL <= m && m <= sumR)
        {
            vector<int> b = L;
            int las = m - sumL;
            for(int i = 0; i < n; i++)
            {
                if(las == 0) break;
                int add = min(R[i] - L[i], las);
                b[i] += add;
                las -= add;
            }
            cout << "Yes" << endl;
            for(auto x : b) cout << x << " ";
            cout << endl;
            return;
        }
    }
    cout << "No" << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;
    while(t--)
        solve();
}
/*
3
4
25 25 25 25
5
25 25 25 26 0
3
0 0 1
 */