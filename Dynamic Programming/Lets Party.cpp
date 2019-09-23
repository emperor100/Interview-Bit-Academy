
/*


Let's Party
In Danceland, one person can party either alone or can pair up with another person. Can you find in how many ways they can party if there are N people in Danceland? Input Format
Given only argument A of type Integer, number of people in Danceland.
Output Format
Return a single integer N mod 10003, i.e number of ways people of Danceland can party.
Constraints
1 <= N <= 1e5 
Example
Input:
    N = 3

Output :
    4

Explanation :
    Let suppose three people are A, B, and C.
    There are only 4 ways to party as,
    (A, B, C) All party alone
    (AB, C) A and B party together and C party alone
    (AC, B) A and C party together and B party alone
    (BC, A) B and C party together and A party alone
    here 4 % 10003 = 4, so answer is 4.
    
   
   
   
Solution:


  Lets solve this problem considering those two possible cases given in the problem statement.
  
  (i) new memeber doesnot want to pair up. 
  (ii) new memeber wants to pair up with someone.
  
  for the case (i).
    Lets suppose the answer till this member wa introduced was V. We can say also say that before this new member was introduced in the 
    party the total number of ways to satify above 2 conditons were V.
    
    If this member doesnot want to team up wit any member then answer will remain same as V.
    
   for the case (ii) 
    here we will have to add one thing more to our thinking that If this personn want to team up, then it can team up to all members which 
    were previously present in the team, and the rest can be paired as previous to previous members were paired after considering the two case.
    
    below is simple recurrence relation 
      
      F[n] = F[n-1] + (n-1) * F[n-2];
      


*/





int Solution::solve(int A) {
    
    long MOD = 1e4+3;
    
    vector<long> res(A+10, 0);
    res[0] = 1;
    res[1] = 1;
    
    
    for(long i=2;i<=A;i++)
    {
        res[i] = res[i-1] + (i-1)*res[i-2];
        res[i]%=MOD;
    }
    
    return res[A];
}


