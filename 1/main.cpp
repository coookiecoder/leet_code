#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    for (int index_one = 0; index_one < nums.size(); index_one++) {
        for (int index_two = 0; index_two < nums.size(); index_two++) {
            if (nums[index_one] + nums[index_two] == target && index_one != index_two)
                return {index_one, index_two};
        }
    }
    return {};
}

int main(int argc, char **argv) {
	vector<int> input;

	for (int iteration = 1; iteration < argc - 1; iteration++) {
		input.push_back(atoi(argv[iteration]));
	}

	vector<int> result = twoSum(input, atoi(argv[argc - 1]));

	if (!result.empty())
		cout << result[0] << " " << result[1] << endl;
	else
		cout << "welp no match was found" << endl;
}
