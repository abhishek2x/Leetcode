class Solution {
public:
    int countStudents(vector<int>& stu, vector<int>& sand) {
        int ones=0, zeros=0;
        
        for(int i: stu) {
            if(i == 1) ones++;
            else zeros++;
        }
        
        while(1) {
                        
            if(sand[0] == 1 && ones==0) break;
            if(sand[0] == 0 && zeros==0) break;
            
            int choice = stu[0];
            stu.erase(stu.begin());
            
            if(choice == sand[0]) {
                sand.erase(sand.begin());
                if(choice == 0) zeros--;
                else ones--;
            }
            else stu.push_back(choice);
        }
        
        return stu.size();
    }
};