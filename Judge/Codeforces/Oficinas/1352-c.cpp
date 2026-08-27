#include <iostream>
using namespace std;

int main() {
    int t;  // casos teste
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        // formula
        long long result = k + (k - 1) / (n - 1);
        cout << result << endl;
    }

    return 0;
}
