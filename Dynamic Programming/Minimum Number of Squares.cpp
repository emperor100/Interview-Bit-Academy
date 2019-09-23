/*
  
  Problem :
  Minimum Number of Squares
  Given an integer N. Return count of minimum numbers, sum of whose squares is equal to N. Example: N=6 Possible combinations are :
  (1^2 + 1^2 + 1^2 + 1^2 + 1^2 + 1^2)
  (1^2 + 1^2 + 2^2)
  So, minimum count of numbers is 3 (i.e. 1,1,2). Note: 1 ≤ N ≤ 105


  Solution:
  
  This problem is similar to Coin Change problem.
  In this problem instead of finding number of ways we need to find the minimum number of coins required to get the number.
  
  Now the question is where are the coins?
  
  We can obeserve that the number of coins are all the number from 1 to SQRT(N), why? because these will add up to give the number N.
  
  Hence we will maintain the array of numbers from 1 to SQRT(N) and consider these as our coins.
  
  Now just see below implementation on a variant on Coin Change problem to find the result for this problem.
  
*/



int Solution::countMinSquares(int A) {
    
    vector<int> V;
    vector<int> res(A+10, 1e8);
    for(int i=1;i<=sqrt(A);i++)
        V.push_back(i);
    
    res[0]=0;
    res[1]=1;
    res[2]=2;
    
    for(int i=0;i<V.size();i++)
    {
        
        for(int j=V[i]*V[i];j<=A;j++)
        {
            if(res[j] > res[j-V[i]*V[i]]+1)
                res[j]=res[j-V[i]*V[i]]+1;
        }
        
        
    }
    
    return res[A];

    
    
}
