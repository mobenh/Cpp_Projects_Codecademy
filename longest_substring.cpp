#include <iostream>
#include <vector>
using namespace std;

    int longestSubstring(string s) {
        vector<int> chars(128, -1);

        int l = 0; int r = 0; int ans = 0;

        while (r < s.length()) {
            
           
            if (chars[s[r]] != -1 && 
                chars[s[r]] >= l && 
                chars[s[r]] < r) {
                l = chars[s[r]] + 1;
            }
            
            ans = max(ans, r - l + 1);
            chars[s[r]] = r;
            r++;
        }
        return ans;
    }


int main() {
    string str; cin >> str;
    cout << longestSubstring(str) << "\n";
}

