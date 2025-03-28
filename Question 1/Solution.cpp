
#include <iostream>
#include <unordered_set>
#include <queue>
#include <set>

using namespace std;

// Function to check if a given string has valid parentheses
bool isValid(const string &s) {
    int counter = 0;
    for (char c : s) {
        if (c == '(') {
            counter++;
        } else if (c == ')') {
            if (counter == 0) {
                return false;
            }
            counter--;
        }
    }
    return counter == 0;
}

// Function to remove invalid parentheses using BFS
void InvalidParenthesis(char s[]) {
    unordered_set<string> marked;
    queue<string> q;
    set<string> results;  // Stores valid strings

    bool found = false;
    q.push(string(s));
    marked.insert(string(s));

    while (!q.empty()) {
        int size = q.size();
        unordered_set<string> visited;

        for (int i = 0; i < size; i++) {
            string curr = q.front();
            q.pop();

            if (isValid(curr)) {
                results.insert(curr);  // Add to set to avoid duplicates
                found = true;
            }

            if (found) {
                continue;  // Stop generating new strings once a valid level is found
            }

            for (int j = 0; j < curr.size(); j++) {
                if (curr[j] != '(' && curr[j] != ')') {
                    continue;
                }

                string next = curr.substr(0, j) + curr.substr(j + 1);

                if (marked.find(next) == marked.end()) {
                    q.push(next);
                    visited.insert(next);
                }
            }
        }

        if (found) {
            break;  // Stop BFS once we process all valid strings at this level
        }

        marked.insert(visited.begin(), visited.end());
    }

    // Print unique valid results
    cout << "[";
    for (const string &res : results) {
        cout << res;
    }
    cout << "]" << endl;
}

int main() {
    char s[] = "()())(()";
    InvalidParenthesis(s);
    return 0;
}
