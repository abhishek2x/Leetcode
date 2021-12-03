class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int mx=arr[0];
        int mn=arr[0];
        int far=arr[0];
        
        for(int i=1; i<size(arr); i++) {
            int temp = max({arr[i], arr[i]*mn, arr[i]*mx});
            mn = min({arr[i], arr[i]*mn, arr[i]*mx});
            mx = temp;
            far = max(far, mx);
        }
        return far;
    }
};