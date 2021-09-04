#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bSearch(vector<int> &nums, int target) {
        
        int low = 0, high = nums.size()-1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) high = mid-1;
            else low = mid + 1;
        }
        return low;
    }
    
    vector<int> searchRange(vector<int> &nums, int target) {
        
        int p2 = bSearch(nums, target);
        int p1 = bSearch(nums, target - 1);

        if (p1 == p2 )// That means element is not present hence return [-1,-1]
            return {-1, -1};
        
        return {p1, p2-1}; //element is present 
    }
};