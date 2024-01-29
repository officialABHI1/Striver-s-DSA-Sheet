/* 

  Resource : https://www.geeksforgeeks.org/top-50-matrix-grid-coding-problems-for-interviews/
  Brute force( Better Approach) 

 >>  Instead of a set, using two vectors to hash whether the ith/jth row/col has a 0 in it or not
 >>  Re-iterating the hash table for both rows and columns and if 0 exists in the respective row/col --> Make that col and row = 0 accordingly 

 Time complexity  = O(m*n) 
 Space Complexity = O(m+n) 

*/

class Solution {
public:

    void makeColumnZero(vector<vector<int>>& matrix, int col,int row){
       
       for(int i=0;i<row;i++)
        matrix[i][col]=0;
    }

    void makeRowZero(vector<vector<int>>& matrix, int row,int col){
       
       for(int i=0;i<col;i++)
        matrix[row][i]=0;
    }

    void setZeroes(vector<vector<int>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> zerothCol(col, 0);
        vector<int> zerothRow(row, 0);

        //hashing the column and row in which 0 is present

        for(int i=0;i<col;i++){
            for(int j=0;j<row;j++){
                if(matrix[j][i]==0){ // Corrected here
                    zerothCol[i]=1;
                    zerothRow[j]=1;
                   // break;   
                }
            }
        }

        // now making the given col = 0 where 0 is present

        for(int i=0;i<col;i++){
            if(zerothCol[i]){
                makeColumnZero(matrix,i,row);
            }
        }
        
        // now making the given row = 0 where 0 is present
        for(int i=0;i<row;i++){
            if(zerothRow[i]){
                makeRowZero(matrix,i,col);
            }
        }
    }
};
