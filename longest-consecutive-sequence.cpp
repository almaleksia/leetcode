class Solution {
public:
    int longestConsecutive(vector<int> &num) {
         if ( num.size() == 0 ) return 0;
         if ( num.size() == 1 ) return 1;
         
         sort(num.begin(), num.end());
         
         int longest = 1;
         int current = 1;
         for ( int i = 1; i < num.size(); i++ ) {
             if ( num[i] - num[i-1] > 1 ) {
                    if ( current > longest ) longest = current;
                    current = 1;
             } else if ( num[i] - num[i-1] == 1 ) {
                 current++;
             }
         }
     
         if ( current > 1 && current > longest ) {
             longest = current;
         }
         
         return longest;
    }
};
