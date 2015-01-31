class Solution {
private:
    int max_len;
    int min_len;
    unordered_map<int, bool> cache;
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        max_len = INT_MIN;
        min_len = INT_MAX;
        for ( auto it = dict.begin(); it != dict.end(); ++it ) {
            int len = (*it).length();
            if ( max_len < len ) max_len = len;
            if ( min_len > len ) min_len = len;
        }
        
        return canBreak(s, dict, 0);
    }
    
    bool canBreak( string s, unordered_set<string> &dict, int pos ) {
        if ( s.size() == 0 ) { return true; }
        if ( dict.find(s) != dict.end() ) { return true; }
        
        for (  int i = 0; i < max_len; i++ ) {
               string new_str = s.substr(0, min_len+i);
               if ( dict.find(new_str) != dict.end() ) {
                   pos = pos+min_len+i; 
                   if ( cache.find(pos) == cache.end() )
                        cache[pos] = canBreak(s.substr(min_len+i), dict, pos);
                   bool can = cache[pos];
                   if ( can == true ) return true;
               }
        }
        
        return false;
    }
};
