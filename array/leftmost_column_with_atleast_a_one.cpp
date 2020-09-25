//LC problem : 1428. Leftmost Column with at Least a One
//Link : https://leetcode.com/problems/leftmost-column-with-at-least-a-one/
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        
        vector<int> dim = binaryMatrix.dimensions();
        int nr = dim[0],nc = dim[1];
        int idx = nc;
        for (int r = 0;r < nr;r++) {
            int hiIdx = -1;
            
            int i =0, j = idx-1;
            if (binaryMatrix.get(r,j) == 1) {
                
                while(i < j) {
                    int m = i+ (j-i)/2;
                    if (binaryMatrix.get(r,m) == 0) {
                        i = m+1;
                    }else {
                        j = m;
                    }
                }
                hiIdx = j;
            }
            
            if (hiIdx!=-1 && hiIdx < idx) {
                idx =hiIdx;
            }
            if (idx == 0)
                break;
        }
        return idx<nc?idx:-1;
    }
};
