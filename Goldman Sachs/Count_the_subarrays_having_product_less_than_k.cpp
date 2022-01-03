/* Given an array of positive numbers, the task is to find the number of possible contiguous subarrays having product less than a given number k. */

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        // The approach will be to use sliding window. We will use two pointers named start and end both pointing to the starting index initially
        if(k<=1) return 0;
        int ans=0, left=0;
        long long product=1;
        
        for(int right=0; right<n; right++){
            product *= a[right];   //Multiply the product with the current number
            
            while(product>=k){
                product = product/a[left]; /*If the product comes out to be >= k, slide the window and divide the product by nums[l] (Since, we only want product of a contiguous subarray)*/
                left++;
            }  
            ans += right - left + 1; /*Each time add to ans the element itself(Each element is a subarray) and extra (right-left) subarrays. */
        }
        return ans;
    }
};
