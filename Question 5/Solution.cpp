#include <iostream>
using namespace std;


/* Given an integer n, return all the numbers in the range
 * [1, n] sorted in lexicographical order.
 * You must write an algorithm that runs in
 * O(n) time and uses O(1) extra space.
 *
* DFS traversal: Generate numbers in lexicographical order using
* Depth-First Search (DFS) starting from 1.
Prefix-based expansion: Expand numbers by appending
digits (e.g., 1 → 10, 11, …) while staying within bounds.
Avoid sorting: Since traversal naturally
follows lexicographical order, avoid extra sorting steps.
Edge cases: Handle cases where n is small (e.g., n = 1),
large (e.g., n = 10⁶), or contains missing middle values.
 */

void DFS(int curr, int n) {
    if (curr > n) {
        return;
    }
    cout << curr << " ";

    for (int i = 0; i < n; i++) {
        int next = curr * 10 + i;

        if (next > n) {
            return;
        }
        DFS(next, n);
    }
}

void lexical(int n) {
    for (int i = 1; i <= 9; i++) {
        DFS(i, n);
    }
}

int main() {
    int n = 13;
    cout << "Output: ";
    lexical(n);


    return 0;
}