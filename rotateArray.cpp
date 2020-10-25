//question link: https://leetcode.com/problems/rotate-array/
//code:

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        while(k > nums.size()) {
            k -= nums.size();
        }
        //reverse first part
        reverse(nums.begin(), nums.begin()+nums.size()-k);
        //reverse 2nd part
        reverse(nums.begin()+(nums.size()-k), nums.end());
        //reverse whole array
        reverse(nums.begin(), nums.end());
    }
};