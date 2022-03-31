class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        bool flag = true;
        int res=0;
        
        while(flag) {
            for(int i=0; i<tickets.size(); i++) {
                if(tickets[i]) tickets[i]--, res++;
                if(i == k) {
                    if(tickets[i] == 0) {
                        flag=false;
                        break;
                    }
                }
            }
        }
        
        return res;
    }
};