class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int k;
        int index1 = 0;
        for(auto i: numbers) {
            k = target-i;
            auto it = find(numbers.begin(), numbers.end(), k);
            int index2 = it-numbers.begin();
            if(it < numbers.end() && index1!=index2){
                if(index1 < index2)
                    return {index1+1, index2+1};
                else 
                    return {index2+1, index1+1};
            }
            index1++;
        }
        return {};
    }
};

// above has TLE


class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        int l=0, r = n.size()-1;
        while(l<r) {
            int mid = n[l] + n[r];
            if(target == mid)
                return {l+1, r+1};
            else if(target < mid)
                r--;
            else l++;
                
        }
        return {l+1, r+1};
    }
};