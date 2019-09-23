
/*

Problem states that:
Given a 2 x N grid of integer, A, choose numbers such that the sum of the numbers is maximum and no two chosen numbers are adjacent horizontally, vertically or diagonally, and return it.

 A = [   [1, 2, 3, 4]
         [2, 3, 4, 5]    ]
       
 In simple term if you choose 3 from 2nd row
 
 you can choose any of (1, 2, 3, 3, 4) which are adjacents to it.
 
 
 Solution:
  Idea is to use the DP, But before that lets have a keen observation.
  Can you think of any test case where the chosen element from the column is minimum of two.
  For example at any point if column 2 is chosen (1-based indexing) then there is no way we will go for the number 2 ever.
  
  Hence we just have to reduce the problem to standard robber problem where robbery was not allowed among two adjacents houses.
  
  At any position we can choose to Rob current place and add the val of N-2 place or use the val of N-1 place only, whichever is maximum.
  
  See following code for better understanding.
  
  
  
  

            
 */
 

int Solution::adjacent(vector<vector<int> > &A) {
    vector<int> V, U;
    for(int i=0;i<A[0].size();i++)
    {
        V.push_back(max(A[0][i], A[1][i]));
        //cout<<V[i]<<" ";
    }
    
    int N = V.size();
    
    U.push_back(V[0]);
    U.push_back(max(V[1], V[0]));
    
    for(int i=2;i<N;i++)
    {
        U.push_back(max(V[i] + U[i-2], U[i-1]));
    }
    
    return max(U[N-1],U[N-2]);
}
