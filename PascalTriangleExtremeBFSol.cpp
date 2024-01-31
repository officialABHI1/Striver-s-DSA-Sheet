/*
   This code will get Integer Overflow error after some test cases 13/30 on leetcode 

   This is calculated with the help of mathematical property of Pascal's triangle which simple states:

   The "rth" number in the "nth" row in P.T can be given as Ncr (N choose r) where   0<=r<=n

   Time complexity: O(n^3)
   Space complexity: O(n^2) 
   
*/

class Solution {
public:

    int fact(int n){

        if(n==0)
        return 1;

        return n*fact(n-1);
    }

    int nthPascalTriangleNum(int n, int r){
      
      int num=1;

      for(int p=0;p<r;p++)
      num*=n-p;

      int deno = fact(r);
      
      return num/deno;

    }

    vector<vector<int>> generate(int numRows) {

    //fixing the size of the answer array
     vector<vector<int>>ans(numRows);

     for(int n=0,sz=1;n<numRows;n++,sz++){

         ans[n].resize(sz);

         for(int r=0;r<=n;r++){
             ans[n][r]=nthPascalTriangleNum(n,r);
         }
     } 
     
      return ans;
        
    }
};
