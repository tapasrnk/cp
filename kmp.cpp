#include <bits/stdc++.h>
using namespace std;
vector<int> LPS(string &s) {
    vector<int> lps(s.size(), 0);
    int i = 0, j = 1;
    while (j < s.size()) {
        if (s[i] == s[j]) {
            lps[j] = i + 1;
            i++;
            j++;
        } else if (i == 0) {
            lps[j] = 0;
            j++;
        } else {
            i = lps[i - 1];
        }
    }
    return lps;
}
vector<int> Match(string &text, string &pat, vector<int> &lps) {
    vector<int> ans;
    int j = 0;
    for (int i = 0; i < text.size(); ) {
        if (text[i] == pat[j]) {
            i++;
            j++;
            if (j == pat.size()) {
                ans.push_back(i - pat.size());
                j = lps[j - 1];
            }
        } else if (j == 0) {
            i++;
        } else {
            j = lps[j - 1];
        }
    }
    return ans;
}
int main () {
    string text = "aacaabaacaayaacaay";
    string pat = "aacaay";
    vector<int> lps = LPS(pat);
    for (int x : lps) {
        cout << x<< " ";
    }
    cout << "\n";
    vector<int> indexs = Match(text, pat, lps);
    for (int x : indexs) {
        cout << x<< " ";
    }
    cout << "\n";
    return 0;
}