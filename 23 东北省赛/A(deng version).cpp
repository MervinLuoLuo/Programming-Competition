#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef long long ll;
typedef pair<int,int> PII;
#define x first
#define y second
const int N = 1e5 + 10;
void solve()
{	
	ll x ,k;ll ans=0;
	cin>>x>>k;
	ans=k + 1;
	ll t=x;
	if(x==1){
		cout<<1<<'\n';
		return;
	}

	for(int i=1;i<=k;i++){
		x=t;
		t=(ll)sqrt(t);
		if(t*t==x){
			ans++;
			continue;
		}
		else{
			if(t!=1)
				ans+=1+k-i;
			else
				ans++;
		}
		if(t==1)
			break;
	}
	cout<<ans<<'\n';
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	//cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}