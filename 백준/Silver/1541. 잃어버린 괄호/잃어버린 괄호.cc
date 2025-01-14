#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

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
    string commands;
    cin >> commands;

    vector<string> parts = split(commands, '-');

    int result = 0;

    vector<string> first = split(parts[0], '+');
    for (string& num : first) {
        result += stoi(num);
    }

    for (int i = 1; i < parts.size(); i++) {
        vector<string> sub_part = split(parts[i], '+');
        for (string& num : sub_part) {
            result -= stoi(num);
        }
    }

    cout << result << '\n';
    return 0;
}
