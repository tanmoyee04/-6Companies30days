/* You may recall that an array arr is a mountain array if and only if:

* arr.length >= 3
* There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
⋅⋅* arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
⋅⋅* arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray. */

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans=0,i=1,start,end,n=arr.size();
        while(i<n){
            start=0; //Each time after traversing one mountain or not,
            end=0; //we have to set upper & lower to 0
            while(i<n && arr[i-1]<arr[i]){ //Increasing part of mountain
                start++;
                i++;
            }
            while(i<n && arr[i-1]>arr[i]){ //Decreasing part of mountain
                end++;
                i++;
            }
            while(i<n && arr[i-1]==arr[i]){ //   for flat array,where elements are equal
                i++;
            }
            if(start && end){ //Mountain only exists if we have both incresing part and decreasing part adjacently
                ans=max(ans,start+end+1);
            }
        }
        return ans;
    }
};
