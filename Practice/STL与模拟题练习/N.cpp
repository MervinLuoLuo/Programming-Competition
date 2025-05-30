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
    int n;cin >> n;
    vector<int> a;
    for(int i = 1; i <= n; i++){
        a.push_back(i);
    }
    do{
        for(int i :a){
            cout << setw(5) << i;
        }
        cout << endl;
    }while(next_permutation(a.begin(),a.end()));
    return 0;
}