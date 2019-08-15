/* A tribute to great IBAcademy team and Ram Sir */


/* 

Question
Repeat and Missing Number Array

You are given a read only array of n integers from 1 to n.  Each integer appears exactly once except A which appears twice and B which is missing. Return A and B.  Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? Note that in your output A should precede B.  Example:
Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4

*/

/* Solution Approach:
This can be solved using extra space of O(n) and time complexity O(nlogn) 

Here we will try to solve it in O(1) extra space and O(n) time complexity.

O(n)
Make two equations as follows and lets assume that number X is repeated and Y is missing.

1 + 2 + X + 4 + Y + 6 = n*(n+1)/2; = x2
1 + 2 + X + 4 + X + 6 = x1 

Here we will have two cases 
      i) x1 - x2 > 0
      ii) x1- x2 < 0
We can handle each case separately.

We got our first equation (i.e, x1-x2);

Now make second equation as follows:

1^2 + 2^2 + X^2 + 4^2 + Y^2 + 6^2 = (n*(n+1)*(2n+1))/6 = y2
1^2 + 2^2 + X^2 + 4^2 + X^2 + 6^2 = y1

Here we will also get two cases. 
Why are we getting two cases ? Simple! Either X can be repeated 2wice or Y. Which means Sum of terms either will rise or fall.


Try to find out the equation yourself.
*/




vector<int> Solution::repeatedNumber(const vector<int> &A) {
    
    long  S1=0;
    long  S2=0;
    long  n = A.size();
    vector<int> res(2);
    
    
    S1  = (long long)((n*(n+1))/2);
    
    for(long i=1;i<=n;i++)
        S2+=(long)(i*i);
    
    for(int i=0;i<n;i++)
    {
        S1-= (long)(A[i]);
        long ai=A[i];
        S2-= (long)(ai*ai);
    }

    /* Handling both cases with single if-else */
    
    
    if(S1 < 0)
    {
        res[1] = (long)((S2 - S1*S1)/(2*S1));
        res[0] = res[1] + S1;
    
        res[0] = abs(res[0]);
        res[1] = abs(res[1]);
        
    }
    
    else {
    
    res[1] = (long)((S2 + S1*S1)/(2*S1));
    res[0] = res[1] - S1;
    
    res[0] = abs(res[0]);
    res[1] = abs(res[1]);
    
    }
    /* A simple check to place the numbers in the order */
    for(int i=0;i<n;i++)if(res[1] == A[i]){
        swap(res[0], res[1]);
        break;
    }
    
    
    return res;
}
