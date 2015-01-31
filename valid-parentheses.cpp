
class Solution {
    
public:
    bool isValid(string s) {
        stack<char> pars;
        for ( auto it = s.begin(); it != s.end(); it++ ) {
            if ( *it == '[' || *it == '(' || *it == '{') {
                pars.push(*it);
                continue;
            } 
            
            if ( *it == ']' ) {
                   if ( pars.empty() ) return false;
                if ( pars.top() != '[' )
                    return false;
                else {
                    pars.pop();
                }
            }
            
            if ( *it == ')' ) {
                if ( pars.empty() ) return false;
                if ( pars.top() != '(' )
                    return false;
                else {
                    pars.pop();
                }
            }
            
            if ( *it == '}' ) {
                if ( pars.empty() ) return false;
                if ( pars.top() != '{' )
                    return false;
                else {
                    pars.pop();
                }
            }
        }
        
        if ( !pars.empty() ) return false;
        return true;
    }
};
