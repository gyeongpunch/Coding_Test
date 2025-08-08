#include <iostream>
#include <cstring>
using namespace std;

static int N, K;
static int dp[31][31][31][436];

bool go(int pos, int a, int b, int k) {
    if (k > K) return false;
    if (pos == N) return k == K;
    int &memo = dp[pos][a][b][k];
    if (memo != -1) return memo;

    if (go(pos+1, a+1, b, k)) { memo = 1; return true; }
	if (go(pos+1, a, b+1, k + a)) { memo = 1; return true; }
	if (go(pos+1, a, b, k + a + b)) { memo = 1; return true; }
	
	memo = 0;
	return false;
}

bool reconstruct(int pos, int a, int b, int k, string &out) {
    if (pos == N) return k == K;
    if (go(pos+1, a+1, b, k)) {
        out.push_back('A');
        return reconstruct(pos+1, a+1, b, k, out);
    }
    if (k + a <= K && go(pos+1, a, b+1, k + a)) {
        out.push_back('B');
        return reconstruct(pos+1, a, b+1, k + a, out);
    }
    if (k + a + b <= K && go(pos+1, a, b, k + a + b)) {
        out.push_back('C');
        return reconstruct(pos+1, a, b, k + a + b, out);
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    if (K < 0 || K > N*(N-1)/2) {
        cout << -1 << '\n';
        return 0;
    }

    memset(dp, -1, sizeof(dp));
    if (!go(0, 0, 0, 0)) {
        cout << -1 << '\n';
        return 0;
    }

    string ans;
    ans.reserve(N);
    reconstruct(0, 0, 0, 0, ans);
    cout << ans << '\n';
    return 0;
}
