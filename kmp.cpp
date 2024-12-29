#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to compute the LPS (Longest Prefix Suffix) array
void computeLPSArray(const string& pattern, vector<int>& lps) {
    int len = 0;  // length of the previous longest prefix suffix
    lps[0] = 0;   // LPS[0] is always 0
    int i = 1;
    
    while (i < pattern.length()) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];  // Use the previous LPS value
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP algorithm to search the pattern in the text
void KMPSearch(const string& text, const string& pattern) {
    int m = pattern.length();
    int n = text.length();
    
    // Create an array to hold the longest prefix suffix values
    vector<int> lps(m);
    
    // Preprocess the pattern to get the LPS array
    computeLPSArray(pattern, lps);
    
    int i = 0;  // index for text
    int j = 0;  // index for pattern
    
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        
        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text = "ABC ABCDAB ABCDABCDABDE";
    string pattern = "ABCDABD";
    
    KMPSearch(text, pattern);
    
    return 0;
}
