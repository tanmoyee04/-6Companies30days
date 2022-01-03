/* Given two rectangles, find if the given two rectangles overlap or not. A rectangle is denoted by providing the x and y coordinates of two points: the left top corner and the 
right bottom corner of the rectangle. Two rectangles sharing a side are considered overlapping. (L1 and R1 are the extreme points of the first rectangle and L2 and R2 are the 
extreme points of the second rectangle). */

class Solution {
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        // If one rectangle is on the left side of other
        if(L1[0]>R2[0] || L2[0] > R1[0]) return 0;
        // If one triangle is above another
        if(R1[1]>L2[1] || R2[1] > L1[1]) return 0;
        return 1;
    }
};
