

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
