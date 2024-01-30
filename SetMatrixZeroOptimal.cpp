/*
   Most Optimal Approach :

  >> As we saw in the previous approach, we were taking an extra space of size n & m to hash the col/row where 0 is present and we were using the makeColumnZero and RowZero functions to make
      that respective row and column zero according to the hash table WHERE 1 is present.
  >> Now In this approach to avoid the extra space we will do this hashing in the row and column itself which will act as our hash tables.
     Rest we will call the same **makeColumnZero** and **makeRowZero** functions to make that respective row and column zero according to the hash table WHERE 1 is present but only from the second row/column.
  Note: As an edge case we need to handle the scenario if the first row has a zero but not but first column so we make only the first row 0 but not 1st column and vice versa
        FOR THIS WE HAVE USED FLAG VARIABLES TO PRE-REMEMBER THAT WHILE HASHING 
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

        // vector<int> zerothCol(col, 0);
        // vector<int> zerothRow(row, 0);

        //hashing the column and row in which 0 is present

        int flag1 =0, flag2=0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){ // Corrected here
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                    
                    if(i==0 & j!=0) // to check if the first row has any 0 in it 
                    {
                     flag2++;
                    }
                    else if(j==0 & i!=0) // to check if the first col has any 0 in it 
                    {
                     flag1++;
                    }
                    else if(i==0 && j==0){ // unneccessary still to avoid any issues
                    flag1++;flag2++;
                    }
                }
            }
        }

        // now making the given col = 0 where 0 is present

        for(int i=1;i<col;i++){
            if(matrix[0][i]==0){
                makeColumnZero(matrix,i,row);
            }
        }
        
        // now making the given row = 0 where 0 is present
        for(int i=1;i<row;i++){
            if(matrix[i][0]==0){
                makeRowZero(matrix,i,col);
            }
        }

        if(flag1>=1 & flag2==0){
           makeColumnZero(matrix,0,row);
        }
        else if(flag1==0 && flag2>=1)
        {
           makeRowZero(matrix,0,col);
        }
        else if(flag1>=1 && flag2>=1)
        {
            makeColumnZero(matrix,0,row);
            makeRowZero(matrix,0,col);
        }

    }
};
