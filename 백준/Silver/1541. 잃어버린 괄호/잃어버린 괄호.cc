#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// 문자열을 특정 구분자로 나누는 함수
vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    string expression;
    cin >> expression;

    // '-'로 나누기
    vector<string> parts = split(expression, '-');

    int result = 0;

    // 첫 번째 부분은 더하기
    vector<string> firstPart = split(parts[0], '+');
    for (const string& num : firstPart) {
        result += stoi(num); // 숫자 더하기
    }

    // 나머지 부분은 빼기
    for (size_t i = 1; i < parts.size(); i++) {
        vector<string> subPart = split(parts[i], '+');
        for (const string& num : subPart) {
            result -= stoi(num); // 숫자 빼기
        }
    }

    cout << result << '\n';
    return 0;
}
