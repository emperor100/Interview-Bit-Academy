
  
/* A tribute to IBAcademy team and Ram Sir */


*/
    

// Problem states that we are given a string of multiple parenthesis and we have to find the length of longest valid parenthesis
    
/*

    This can be solved using a single stack of pair<char, int> where char will be the opening/closing braces and int will be the index number.
    
    Initially this stack will have a speacial symbol "$". Then for i 0 to A.size()-1 we will encounter all type of open and closing braces.
    
    Lets take an example 
        
        ()[<][()<()>{}]
        
        here the ans is "[()<()>{}]" how can we get this, see below step by step guide
        
        Insert { ($, -1)}
        Then serier of inserts will be like this
        { $ -1, ( 0 } here if we see that the closing braces is similar to current top opening braces we will update the result and pop the similar element from stack.
        
        { $ -1, [ 1, < 2, ] 3, [ 4, ( 5, } now again here ) will pop the top element and update the ans as 2.
        
        { $ -1, [ 1, < 2, ] 3, [ 4, < 6, ( 7 , } again here also result will be 2 only.
       
        { $ -1, [ 1, < 2, ] 3, [ 4, < 6,  } here result will be after popping the first element 8-4 which is 4.
        
        seee below code for better understanding.
    
    
    */


bool openBaces(char ch)
{
    if(ch == '{' or ch == '[' or ch == '<' or ch =='(')
        return true;
    return false;
    
}



bool matching(char c2, char c1)
{
    
    if(c1 == '{' and c2 == '}' or c1 == '[' and c2 == ']' or c1 == '(' and c2 == ')' or c1 == '<' and c2 == '>')
        return true;
    return false;
    
}
int Solution::LBSlength(const string A) {
    
    stack <pair<char, int> > S;
    
    S.push(make_pair('&', -1));
    
    int result=0;
    for(int i=0;i<A.size();i++)
    {
        if(openBaces(A[i]))
        {
            S.push(make_pair(A[i], i));
        }
        
        else 
        {
            if(matching(A[i], S.top().first))
            {
                
                S.pop();
                result = max(result, i - S.top().second);
                //if(S.empty())
                    
                
                
            }
            else 
                S.push(make_pair(A[i], i));
            
            
        }
    }
    
    return result;
    
}
