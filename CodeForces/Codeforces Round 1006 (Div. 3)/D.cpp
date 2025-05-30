#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int L = n - 1, R = n - 1, N = 0;
    for(int i = n - 2; i >= 0; i--){
        int maxx = 0,minx = 0, fin = 0;
        for(int j = i + 1; j < n; j++){
            if(a[j] > a[i]) maxx++;
            if(a[j] < a[i]) minx++;
            fin = minx - maxx;
            if(fin > N){L = i; R = j; N =fin;}
        }
    }
    cout << L + 1 << ' ' << R + 1 << endl;
}
int main(){
    int t;cin >>t;
    while(t--){
        solve();
    }
    return 0;
}