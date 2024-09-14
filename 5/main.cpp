#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        bool bad_string = false;
        std::string result;

        for (int end = s.size(); end > 0; end--)  {
            for (int start = 0; start < s.size() - (end - 1); start++) {

                for (int index = 0; index < end / 2; index++) {
                    if (s[start + index] != s[start + end - index - 1]) {
                        bad_string = true;
                        break;
                    }
                }
                if (!bad_string)
                    return(s.substr(start, end));
                bad_string = false;
            }
        }
        return(std::string());
    }
};

int main(int argc, char** argv) {
        Solution solution;

        if (argc == 2)
                cout << solution.longestPalindrome(argv[1]) << endl;
        else
                cout << "are you dumb ?" << endl;
}
