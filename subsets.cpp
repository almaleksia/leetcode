class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        return powerset(S, S.size()-1);
    }
    
    vector<vector<int> > powerset(vector<int> &S, int end) {
        vector<vector<int> > sets;
        if ( S.size() == 0  ) {
            vector<int> set;
            sets.push_back(set);
            return sets;
        }
        
        if ( end == 0 ) {
            vector<int> set;
            sets.push_back({});
            set.push_back(S[end]);
            sets.push_back(set);
            return sets;
        }
        
        vector<vector<int> > prev_sets = powerset(S, end - 1);
        
        for ( auto it = prev_sets.begin(); it != prev_sets.end(); it++ ) {
            vector<int> set = *it;
            sets.push_back(*it);
            set.push_back(S[end]);
            sets.push_back(set);
        }
        
        return sets;
    }
};
