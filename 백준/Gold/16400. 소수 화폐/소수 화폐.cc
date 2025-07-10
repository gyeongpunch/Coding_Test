#include <iostream>
#include <queue>
#include <string>
#include <climits>
#include <unordered_set>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

const int MOD = 123456789;

bool is_prime(int num){
    for(int i=2; i*i<=num; i++){
        if(num % i == 0) return false;
    }
    return true;
}

const int MX = 40001;

int N;
vector<int> primes;
int dp[MX];

int main(void) {
    fastio;

    cin >> N;

    for(int i=2; i<=N; i++){
        if(is_prime(i)){
            primes.push_back(i);
        }
    }
    dp[0]=1;

    for(int p : primes){
        for(int i=p; i<=N; i++){
            dp[i] = (dp[i] + dp[i - p]) % MOD;
        }
    }
    
    cout << dp[N] << '\n';
    
    return 0; 
}
