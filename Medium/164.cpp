class Solution {
public:
    
    int isPresent(vector<int> &arr, int target) {
        int l=0, h = arr.size()-1;
        while(l<=h) {
            int m = (l+h)/2;
            if(arr[m] == target) return m;
            if(arr[m] < target) l = m+1;
            else h = m-1;
        }
        return -1;
    }
    
    vector<int> twoSum(vector<int>& arr, int target) {        
        for(int index1 = 0; index1 < arr.size(); index1++) {
            int search = target-arr[index1];
            int index2 = isPresent(arr, search);
            if(index2 != -1 and index1 != index2) {
                cout << arr[index1] << " " << arr[index2] << "\n";
                return {min(index1+1, index2+1), max(index1+1, index2+1)};
            }
        }
        return {};
    }
};


// [2,7,11,15]
// 9
// [2,3,4]
// 6
// [-1,0]
// -1
// [1,2,3,4,4,9,56,90]
// 8