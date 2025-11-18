#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

ll MOD = 1000000007;

matrix multiply(const matrix& a, const matrix& b) {
    matrix c(2, vector<ll>(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return c;
}

matrix power(matrix a, ll n) {
    matrix res(2, vector<ll>(2));
    res[0][0] = res[1][1] = 1;

    while (n > 0) {
        if (n % 2 == 1) {
            res = multiply(res, a);
        }
        a = multiply(a, a);
        n /= 2;
    }
    return res;
}

int main() {
    ll n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    matrix base = {{1, 1}, {1, 0}};
    
    matrix result_matrix = power(base, n - 1);

    cout << result_matrix[0][0] << endl;

    return 0;
}