#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> &nums) {
	int l = 0, r = nums.size() - 1, ans = 0;
	while (l < r) {
		int area = abs(l - r) * min(nums[l], nums[r]);
		ans = max(ans, area);
		if (nums[l] < nums[r]) { l++; }
		else if (nums[l] > nums[r]) { r--; }
		else { r--; }
	}
	return ans;
}

int main() {
	vector<int> nums = { 1,8,6,2,5,4,8,3,7 };
	cout << maxArea(nums) << endl;

}