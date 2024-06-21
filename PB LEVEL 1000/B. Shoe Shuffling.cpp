#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) mp[a[i]].push_back(i + 1);

    for (auto& p : mp) {
        if (p.second.size() == 1) {
            cout << -1 << endl;
            return;
        }
    }

    vi ans(n + 1, 0); // +1 to make it 1-indexed
    for (auto& p : mp) {
        vector<int>& indices = p.second;
        // Rotate the indices to ensure no one gets their own shoes
        rotate(indices.begin(), indices.begin() + 1, indices.end());
        for (size_t i = 0; i < indices.size(); ++i) {
            ans[indices[i]] = indices[(i + 1) % indices.size()];
        }
    }

    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}