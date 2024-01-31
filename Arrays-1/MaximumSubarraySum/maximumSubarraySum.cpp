/*
   Using Kadane's Algo to print Max Subarray Sum

*/




class Solution {
public:

    int maximum(int a,int b){
        return ( (a>b)?a:b );
    }
    int maxSubArray(vector<int>& nums) {
      
      int maxSum =-1e9;
      
      int curr =0;

      for(int i=0;i<nums.size();i++){
          
          curr+= nums[i];

          maxSum = maximum(maxSum,curr);

          if(curr<0)
          curr=0;
      }
        
      return maxSum;
    }
};