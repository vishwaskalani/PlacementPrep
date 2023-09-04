#include <iostream>
#include <vector>

using namespace std;

// Compute the longest prefix which is also a suffix for each prefix of the pattern
vector<int> computeLPS(string pattern) {
    int patternLength = pattern.size();
    vector<int> lps(patternLength, 0); // Initialize the LPS array with zeros

    int len = 0; // Length of the previous longest prefix which is also a suffix

    for (int i = 1; i < patternLength; i++) {
        while (len > 0 && pattern[i] != pattern[len]) {
            len = lps[len - 1];
        }

        if (pattern[i] == pattern[len]) {
            len++;
        }

        lps[i] = len;
    }

    return lps;
}

// Find the first occurrence of pattern in text using the KMP algorithm
int KMP(string text, string pattern) {
    int textLength = text.size();
    int patternLength = pattern.size();

    vector<int> lps = computeLPS(pattern);

    int i = 0; // Index for text[]
    int j = 0; // Index for pattern[]

    while (i < textLength) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == patternLength) {
            // Pattern found, return the starting index of the match
            return i - j;
        } else if (i < textLength && pattern[j] != text[i]) {
            if (j != 0) {
                // Update j using the LPS array
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    // Pattern not found in the text
    return -1;
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    
    int result = KMP(text, pattern);
    
    if (result != -1) {
        cout << "Pattern found at index " << result << endl;
    } else {
        cout << "Pattern not found in the text" << endl;
    }

    return 0;
}
