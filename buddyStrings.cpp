//question link: https://leetcode.com/problems/buddy-strings/
//code:

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.length() != B.length()) {
            return false;
        }
        bool sameCharsPresent = false;
        unordered_map<char, int> freq;
        for(char ch: A) {
            freq[ch]++;
            if(freq[ch] > 1) {
                sameCharsPresent = true;
            }
        }
        // to check if different chars or chars with different freq present
        for(char ch: B) {
            if(freq.count(ch) && freq[ch] > 0) {
                freq[ch]--;
            } else {
                return false;
            }
        }

        int misplacedChars = 0;
        for(int i=0; i<A.length(); i++) {
            if(A[i] != B[i]) {
                misplacedChars++;
            }
        }

        if(misplacedChars == 2) {
            return true;
        } else if(misplacedChars == 0 && sameCharsPresent) {
            return true;
        } else {
            return false;
        }
    }
};