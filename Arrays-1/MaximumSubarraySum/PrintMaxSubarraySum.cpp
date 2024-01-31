class Solution {
public:

    int maximum(int a,int b){
        return ( (a>b)?a:b );
    }
    int maxSubArray(vector<int>& nums) {
      
      int maxSum =-1e9 ,start,ansStart,ansEnd;
      
      int curr =0;

      for(int i=0;i<nums.size();i++){
          
          if(curr==0){
              start =i;
          }
          curr+= nums[i];

          if(curr>maxSum)
          {
              maxSum=curr;

              ansStart=start,ansEnd=i;
          }

          if(curr<0)
          curr=0;
      }

      for(int i=ansStart;i<=ansEnd;i++)
      {
          cout<<nums[i]<<" ";
      }
      cout<<endl;
        
      return maxSum;
    }
};