#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        std::sort(nums1.begin(), nums1.end());

        if (nums1.size() % 2) {
            return nums1[nums1.size() / 2];
        } else {
            return (static_cast<float>(nums1[nums1.size() / 2 - 1]) + static_cast<float>(nums1[nums1.size() / 2])) / 2;
        }
    }
};

int main() {
	vector<int> nums1 = {1,2,5};
	vector<int> nums2 = {6};

	Solution solution;

	std::cout << solution.findMedianSortedArrays(nums1, nums2) << std::endl;
}
