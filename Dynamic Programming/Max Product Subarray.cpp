
/*

Max Product Subarray
Find the contiguous subarray within an array (containing at least one number) which has the largest product. Return an integer corresponding to the maximum product possible. Example :
Input : [2, 3, -2, 4]
Return : 6 

Possible with [2, 3]

Solution :

  This is similar to Max sub array sum.
  
  Here is the smartest approach.
  We maintain the minVal and maxVal, because when we take any num < 0 into consideration then it is also possible that somwhere num < is
  also present hence it will eventually maximize out result.
  
  See below simple code for better understanding.
  

*/
int Solution::maxProduct(const vector<int> &A) {
    
   
    int maxVal=A[0];
    int minVal=A[0];
    int ans=maxVal;

    
    for(int i=1;i<A.size();i++)
    {
        
        if(A[i] < 0)    
            swap(maxVal, minVal);
        
        
        maxVal = max(A[i], A[i]*maxVal);
        minVal = min(A[i], A[i]*minVal);
        
        ans = max(ans, maxVal);
        
        
    }
    
        
    return ans;
     
}
