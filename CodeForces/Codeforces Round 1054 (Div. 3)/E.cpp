#include <bits/stdc++.h>
using namespace std;
#define int long long

// 计算: 子数组中 "不同数 <= K 且长度 <= L" 的子数组数量
long long countAtMost(vector<int> &a, int K, int L) {
    if (K < 0 || L <= 0) return 0;
    int n = a.size();
    unordered_map<int,int> freq;
    int left = 0, distinct = 0;
    long long res = 0;
    for (int right = 0; right < n; right++) {
        if (++freq[a[right]] == 1) distinct++;
        while (distinct > K) {
            if (--freq[a[left]] == 0) distinct--;
            left++;
        }
        // 现在窗口 [left, right] 至多有K种不同数
        // 还要满足长度 ≤ L
        int windowLen = right - left + 1;
        if (windowLen > L) {
            // 缩小窗口，保证长度 ≤ L
            left = right - L + 1;
            while (left <= right && freq[a[left]] == 0) left++; 
        }
        res += (right - left + 1);
    }
    return res;
}

void solve() {
    int t; cin >> t;
    while (t--) {
        int n, k, l, r;
        cin >> n >> k >> l >> r;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        long long ans = countAtMost(a, k, r) - countAtMost(a, k, l - 1)
                      - countAtMost(a, k - 1, r) + countAtMost(a, k - 1, l - 1);
        cout << ans << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
