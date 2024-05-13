#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <set>
#include <cctype>
#include <utility>
#include <cmath>
#include <array>

using namespace std;

typedef long long ll;
typedef long double ld;

// Pairs
typedef pair<int, int> pi;

// Vectors
typedef vector<int> vi;

//Macros
#define F first
#define S second
#define E end
#define PB push_back
#define FOR(i, a, b) for (int i = a, i < b; ++i)

// Constants
const ld PI = acos((ld)-1);
const ll BIG = 1e18;

/**
 * Sieve of Eratosthenes 
 * Time Complexity: O(n log log n)
 * Memory: O(n)
*/
vector<bool> sieve(int n) {
    vector<bool> primes(n+1, true);
    primes[0] = primes[1] = false;

    for (int i = 2; i*i <= n; ++i) {
        if (primes[i] && (long long)i*i <= n) {
            for (int j = i*i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }
    return primes;
}

void solve() {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Read the Problem!!!!

    solve();

    return 0;
}

/**
 * READ QUESTION STATEMENTS THOROUGHLY
 * Remember edge cases
 * Think simple (sometimes hardcode scenarios)
 * Look at Input and Output bounds (integer overflow, array bounds)
*/
