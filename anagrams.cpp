class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> groups;
        for ( int i = 0; i < strs.size(); i++ ) {
            string str = strs[i];
            sort(str.begin(), str.end());
            groups[str].push_back(strs[i]);
        }
        
        vector<string> result;
        for ( auto it = groups.begin(); it != groups.end(); ++it  ) {
            vector<string> item = it->second;
            if ( item.size() > 1 ) {
                for ( auto word = item.begin(); word != item.end(); ++word ) {
                    result.push_back(*word);
                }
            }
        }
        
        return result;
    }
};
