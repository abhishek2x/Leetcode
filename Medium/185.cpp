class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> result(searchWord.size());
        
        for(int i=1; i <= searchWord.size(); i++) {
            string str = searchWord.substr(0, i);
            
            int count = 0;
            for(int j=0; j < products.size() and count < 3; j++) {
                if(products[j].substr(0, i) == str) {
                    result[i-1].push_back(products[j]);
                    count++;
                }
            }
         }

        return result;
    }
};