#ifndef OFFER-29_H_INCLUDED
#define OFFER-29_H_INCLUDED

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.empty()) return ans;
        int left=0,right=matrix[0].size()-1;
        int top=0,down=matrix.size()-1;
        while(left<=right&&top<=down){
            for(int i=left; i<=right; ++i) ans.push_back(matrix[top][i]);
            for(int i=top+1; i<=down; ++i)  ans.push_back(matrix[i][right]);
            if(left>=right||top>=down) break;
            for(int i=right-1; i>=left; --i) ans.push_back(matrix[down][i]);
            for(int i=down-1; i>top; --i) ans.push_back(matrix[i][left]);
            ++top,--down,++left,--right;
        }
        return ans;
    }
};

#endif // OFFER-29_H_INCLUDED
