#ifndef BH1011_H_INCLUDED
#define BH1011_H_INCLUDED

class Solution {
public:
    int check(vector<int>& weights,int mid){
        int ans=0,tp=0;
        for(auto x : weights){
            if(x>mid) return -1;
            tp += x;
            if(tp>mid){
                ++ ans;
                tp = x;
            }
        }
        if(tp<=mid) ++ ans;
        else return -1;
        return ans;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int left=0,right=0;
        for(auto v : weights) right += v;
        while(left<right){
            int mid = (left+right)/2;
            int nu = check(weights,mid);
            if(nu>D||nu==-1){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};

#endif // BH1011_H_INCLUDED
