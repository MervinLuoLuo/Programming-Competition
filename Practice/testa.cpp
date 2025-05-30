#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int i7[] = {7,17,27,37,47,57,67,71,72,73,74,75,76,77,78,79,87,97};
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 1; i <= 100; i++){
		if(i % 7 == 0) {cout << "敲桌子" << endl;continue;}
		bool flag = 0;
		for(int j = 0; j < 18; i++){
			if(i == j){
				flag = 1;
				break;}
		}
		if(flag) cout << "敲桌子" << endl;
		else cout << i << endl;
	}
	return 0;
}