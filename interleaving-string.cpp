class Solution {
private:
    unordered_map<int, bool> cache;
public:
    bool isInterleave(string s1, string s2, string s3) {
        if ( s3.length() != s1.length() + s2.length() ) return false;
        if ( s3.length() == 0 && s1.length() == 0 && s2.length() == 0 ) return true;
        return is_interleave(s1,s2,s3,0,0,0);
    }
    
    bool is_interleave(string s1, string s2, string s3, int x, int y, int ord) {
    
        if ( s1.length() > x && s1.substr(x, 1).compare(s3.substr(ord,1)) == 0 ) {
            if ( x + 1 == s1.length() && ord+1 == s3.length() && y == s2.length() ) return true;
                int new_key = ckey(x+1, y, s1.length());
                if ( cache.find(new_key) == cache.end() ) {
                    cache[new_key] = is_interleave(s1,s2,s3,x+1,y,ord+1);
                }
            
                if ( cache[new_key] == true ) return true;
        }
        
        if ( s2.length() > y && s2.substr(y, 1).compare(s3.substr(ord,1)) == 0 ) {
            if ( x == s1.length() && ord+1 == s3.length() && y + 1 == s2.length() ) return true;
            int new_key = ckey(x, y+1, s1.length());
            if ( cache.find(new_key) == cache.end() ) {
                cache[new_key] = is_interleave(s1,s2,s3,x,y+1,ord+1);
            }
            
            return cache[new_key];
        }
        
        return false;
    }
    
    int ckey(int x, int y, int length) {
        if ( length == 0 ) return y;
        return y*length + x;
    }
    
    vector<int> coord(int key, int length) {
        if ( length == 0 ) {
            vector<int> crd = { 0, key };
            return crd;
        }
        
        int x = key % length;
        int y = key / length;
        
        vector<int> crd = { x, y };
        return crd;
    }
};
