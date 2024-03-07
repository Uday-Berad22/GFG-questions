//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   string longestSubstring(string& S, int N) {
    // Initialize variables to store the maximum length, answer, and pointers
    int max = 0;
    string ans = "-1";
    int i = 0;
    int j = 0;

    // Iterate through the string until one of the pointers reaches the end
    while (i < N && j < N) {
        // Extract the current substring from index i to j
        string subString = S.substr(i, j - i + 1);

        // Check if the current substring occurs again in the remaining part of the string
        if (S.find(subString, j + 1) != string::npos) {
            // Calculate the length of the current substring
            int len = subString.length();

            // If the length is greater than the current maximum, update the answer
            if (len > max) {
                ans = subString;
                // Update the maximum length
                max = len;
            }
        } else {
            // If the current substring is not found again, move the starting pointer i to the next position
            i++;
        }

        // Move the ending pointer j to the next character
        j++;
    }

    // Return the final answer
    return ans;
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends