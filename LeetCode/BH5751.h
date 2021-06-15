#ifndef BH5751_H_INCLUDED
#define BH5751_H_INCLUDED

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int size1=nums1.size(),size2=nums2.size();
        int a=0,b=0;
        int ans = 0;
//        cout << nums1.size() << " " << nums2.size() << endl;
        while(b<size2){
            while(a<size1&&nums1[a]>nums2[b]) ++ a;
            if(a>=size1) return ans;
            ans = max(ans,b-a);
            ++ b;
        }
        return ans;
    }
};


#endif // BH5751_H_INCLUDED
