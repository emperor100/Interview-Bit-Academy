/* A tribute to IBAcademy and Ram Sir */

/* 
Question:
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
Input Format
The only argument given is integer array A.
Output Format
Return the total water it is able to trap after raining..
For Example
Input 1:
    A = [0,1,0,2,1,0,1,3,2,1,2,1]
Output 1:
    6
                | |
       | |      | | |
..| |..| | |..| | | | |

*/


/*

Solution:

  Stay at one place look left find the highest building, same with right side.
  Answer would be the minimum of them and subtraction of the size of building you're standing on.
  Maintain prefixMax and suffixMax.
  
  { Time : O(n), Space : O(n) }
*/


int Solution::trap(const vector<int> &A) {
    
    const int n = A.size();
    int left[100000+100]={};
    int right[100000+100]={};
    
    left[0]=A[0];
    right[n-1]=A[n-1];
    
    for(int i=1;i<n;i++)left[i] = max(left[i-1], A[i]);
    for(int i=n-2;i>=0;i--)right[i] = max(right[i+1],A[i]);
    
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans += (min(left[i], right[i]));
        ans-=A[i];
    }
    
    return ans;
    
    
}

  
