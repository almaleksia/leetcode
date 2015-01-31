class Solution {
public:
    string convertToTitle(int n) {
        string excel_code;
      
        while(n!=0) {
            int code = (n-1) % 26;
            char ch = 'A' + code;
            excel_code = ch+excel_code;
            n = (n-1)/26;
        }
        
        return excel_code;
    }
};
