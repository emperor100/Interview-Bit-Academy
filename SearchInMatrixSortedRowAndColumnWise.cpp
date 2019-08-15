/* A tribute to IBAcademy and Ram Sir */

/*
Question:
Search in a row wise and column wise sorted matrix
Given a matrix of integers A of size N x M and an integer B. In the given matrix every row and column is sorted in increasing order. Find and return the position of B in the matrix in the given form:
If A[i][j] = B then return (i * 1009 + j)
And if B is not present return -1 instead. Note: Rows are numbered from top to bottom and columns are numbered from left to right. 

*/

/* 
Solution:

Approach_1: One basic intuition is just check for the element inside the matrix and return. **{ Time - O(n*m) : Space - O(1) }**
Approach_2: If in above approach problem is there for handling large number of queries Q. 
            Traverse once in the matrix and store each element in the hashMap.              **{ Time - O(n*m + log(n*m)) : Space - O(n*m) }**
Approach_3: Since we know that the elements row and column wise are already sorted.
            Lets use this to find out our ans.
            
            Start from the 1st row and last column. Just check whether the given element is less than the element present.
            i) If yes, Go left;
            ii) If no, Go down.
            
            **{ Time - O(n+m) : Space - O(1) }**     
            
*/


int Solution::solve(vector<vector<int> > &A, int B) {
    
    
    int n = A.size(); //number of rows
    int m = A[0].size();  // number of columns
    
    int i=0, j=m-1;  // Starting from 1st row and Last column
    
    while(i<n && j>=0)
    {
        if(A[i][j] == B)
        {
            /* This is when element found. It can be customized as required*/
            return (i+1)*1009 + (j+1);
        }
        else if(A[i][j] > B)
        j--;
        else i++;
    }
    /* If element not Found*/
    return -1;   
    
}    
       
