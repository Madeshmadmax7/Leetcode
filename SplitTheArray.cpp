#include <bits/stdc++.h>
using namespace std;

bool canSplit(vector<int>& arr) {
    unordered_map<int, int> freq;
    
    for (int i : arr) {
        freq[i]++;
        if (freq[i] > 2) {
            return false;
        }
    }
    int singleCount = 0;
    for (auto it : freq) {
        if (it.second == 1) {
            singleCount++;
        }
    }
    return (singleCount % 2 == 0);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << (canSplit(arr) ? "true" : "false") << endl;
    return 0;
}
