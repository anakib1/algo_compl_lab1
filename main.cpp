#include <chrono>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<int, int> counts;
unordered_set<int> set;

string operation;
string operand;

constexpr long long PRIME = 37;
constexpr long long MOD = 1000000009;

int hash_str(const string &s) {
    long long ret = 0;
    long long pwr = 1;
    for (const char c: s) {
        (ret += (long long) (c - 'a') * pwr) %= MOD;
        (pwr *= PRIME) %= MOD;
    }
    return ret;
}


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    const chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    while (cin >> operation >> operand) {
        const long operand_hash = hash_str(operand);
        if (operation == "+") {
            set.insert(operand_hash);
        } else if (operation == "-") {
            set.erase(operand_hash);
        } else if (operation == "?") {
            cout << (!set.contains(operand_hash) ? "no" : "yes") << '\n';
        } else if (operation == "#") {
            break;
        }
    }
    const chrono::steady_clock::time_point end = chrono::steady_clock::now();

    cerr << static_cast<std::chrono::duration<double>>(end - begin) << '\n';
}
