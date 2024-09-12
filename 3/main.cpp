#include <iostream>
#include <unordered_set>

using namespace std;

int is_unique(const std::string& s) {
    std::unordered_set<char> char_set;

    for (char c : s) {
        if (char_set.find(c) != char_set.end()) {
            return 0;
        }
        char_set.insert(c);
    }

	cout << s << endl;

    return s.size();
}

int min(int a, int b) {
    if (a < b)
        return (a);
    return (b);
}

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result;

        for (int end = min(int(96), int(s.size())); end > 0; end--)  {
            for (int start = 0; start < s.size() - (end - 1); start++) {
                result = is_unique(s.substr(start, end));
                if (result)
                    return (result);
            }
        }
        return(0);
    }
};

int main(int argc, char** argv) {
	Solution solution;

	if (argc == 2)
		cout << solution.lengthOfLongestSubstring(argv[1]) << endl;
	else
		cout << "are you dumb ?" << endl;
}
