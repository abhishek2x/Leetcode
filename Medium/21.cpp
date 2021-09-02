#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
           
        while(low <= high){
            int mid = (low+high) /2;

            if(nums[mid] == target) return mid;
            
            // means nums at lo to mid is sorted
            else if (nums[low] <= nums[mid]){
                if(target>= nums[low] && target < nums[mid]) high = mid-1;
                else low = mid+1;
            }
            
            //means nums at mid to high is sorted
            else if(nums[mid]< nums[high]) {
                if(nums[mid] < target && nums[high] >= target) low = mid+1;
                else high = mid -1;
            }
        }
        return -1;
    }
};


// [4,5,6,7,0,1,2]
// 0
// [4,5,6,7,0,1,2]
// 3
// [1]
// 0
// [3,1]
// 1
// [1, 3]
// 3
// [3,5,1]
// 1
