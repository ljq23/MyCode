#ifndef BH5698_H_INCLUDED
#define BH5698_H_INCLUDED

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        int sum = 0;
        for(int i=0; i<nums.size(); ++i){
            sum += nums[i];
        }
        goal -= sum;
        goal = goal>0?goal:-goal;
        goal += (limit-1);
        return goal/limit;
    }
};


#endif // BH5698_H_INCLUDED
