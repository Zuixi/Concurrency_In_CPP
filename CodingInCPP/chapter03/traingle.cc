#include <iostream>
#include <vector>
#include <algorithm>

int triangleNumber1(std::vector<int>& nums) {
	if (nums.size() < 3) {
		return 0;
	}
	
	int count = 0;
	// traverse nums 
	for (int i = 0; i < nums.size() - 2; ++i) {
		int a = nums[i];
		
		for (int j = i+ 1; j < nums.size() - 1; ++j) {
			int b = nums[j];
			
			for (int k = j + 1; k < nums.size(); ++k) {
				int c = nums[k];
				
				if ((a + b > c) && (a + c > b) && (b + c > a) && (a - b < c) && (a - c < b) && (c - b < a)){
					count++;
				}
			}
		}
	}
	
	return count;
}


int triangleNumber2(std::vector<int>& nums) {
	int count = 0;

	// 排序之后， a<= b <= c, 那么一定会有a + b > c, a + c > b;
	// 只需要判断 a + b > c与否，若是a或者b 至少有一个=0，那么这个等式一定不成立
	// 对于c，我们可以使用二分来查找
	for (int i = 0; i < nums.size() - 2; ++i) {
		int k = i + 2;
		for (int j = i + 1; j < nums.size() - 1 && nums[i] != 0; ++j) {
			// 找到合适的c ，a + b > c，找到满足条件的最大的C就行了
			// 范围在[j+1, size - 1]
			int binarySearch(std::vector<int> &nums, int left, int right, int sum);
			k = binarySearch(nums, k, nums.size() - 1, nums[i] + nums[j]);

			count += k - j - 1;
		}
	}

	return count;
}

// 寻找满足条件的最大值，注意返回值
int binarySearch(std::vector<int> &nums, int left, int right, int sum) {
	while (left <= right && right < nums.size()) {
		int mid = (left + right) / 2;

		if (nums[mid] >= sum ) {
			right = mid - 1;
		}
		if (nums[mid] < sum) {
			left = mid + 1;
		}
	}
	return left;
}

int triangleNumber(std::vector<int>& nums) {
	int count = 0;

	// 双指针技法
	for (int i = 0; i < nums.size() - 2; ++i) {
		int k = i + 2;

		for (int j = i + 1; j < nums.size() - 1 && nums[i] != 0; ++j) {
			while (k < nums.size() && nums[j] + nums[i] > nums[k])
			{
				++k;
			}
			count += k - j - 1;
		}
	}

	return count;
}

std::vector<int> shuffle(std::vector<int>& nums, int n) {
	std::vector<int> ans(n * 2);
	
	bool f = false;
	int k = 0;
	for (int i = 0, j = n; i < n; ) {
		// 循环陷阱， f两个都会执行
		// if (!f) {
		// 	ans[k++] == (nums[i]);
		// 	++i;
		// 	f = true;
		// }
		// else {
		// 	ans[k++] = (nums[j]);
		// 	++j;
		// 	f = false;
		// }

		// nums[i] nums[j] j = i + n
		// 间隔插入一个元素i ,j i,j
		ans[k++] = nums[i];
		std::cout << "  " << nums[i];
		ans[k++] = nums[i + n];
		std::cout << "  " << nums[i + n];
		++i;
	}
	
	return ans;
}

int main() {
	std::vector<int> nums = {2,3,2,4};

	// 这种暴力解法很容易超时，需要进行优化
	// triangleNumber1(nums);

	// 先对数组进行排序
	// std::sort(nums.begin(), nums.end());
	// triangleNumber(nums);

	std::vector<int> n= {2,5,1,3,4,7};
	shuffle(n, 3);
	return 0;
}