#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e7 + 10;

int prime[maxn];
bool in[maxn];
int cnt = 0;
void get(int n)
{
    in[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!in[i])
        {
            cnt++;
            prime[cnt] = i;
        }
        for (int j = 1; j <= cnt && i * prime[j] <= n; j++)
        {
            in[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

void solve(){
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        int d = n / i;
        int c = 0;
        for (int j = 1; j <= cnt; j++)
        {
            if (prime[j] <= d)
                c++;
            else
                break;
        }
        ans += c;
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    get(maxn - 5);
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}