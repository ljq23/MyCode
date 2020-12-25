#ifndef BH456_H_INCLUDED
#define BH456_H_INCLUDED

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int two = INT_MIN;
        stack<int> st;
        for(int i=nums.size()-1; i>=0; --i){
            if(nums[i]<two) return true;
            while(!st.empty()&&nums[i]>st.top()){
                two = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};

#endif // BH456_H_INCLUDED
