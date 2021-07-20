#include <iostream>
#include <vector>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
	double ans = 0;
	int flag = nums1.size() + nums2.size();
	int i = 0, j = 0;
	std::vector<int> res;
	
	while(i < nums1.size() && j < nums2.size()) {
		if (nums1[i] <= nums2[j]) {
			res.push_back(nums1[i]);
			++i;
		}else {
			res.push_back(nums2[j]);
			++j;
		}
	}
	
	while(i < nums1.size()) {
		res.push_back(nums1[i++]);
	}
	
	while(j < nums2.size()) {
		res.push_back(nums2[j++]);
	}
	
	if(flag % 2 == 0) {
		ans = (res[flag / 2 - 1] + res[flag / 2]) * 1.0 / 2;
	}else {
		ans = res[flag / 2] * 1.0;
	}
	
	return ans;
}

int reverse(int x) {
	
	int flag = 1;
	if (x < 0) {
		flag *= -1;
	}
	
	std::vector<int> res;
	while(x != 0) {
		res.push_back(x % 10);
		x /= 10;
	}
	
	long long sum = 0;
	for(auto val : res) {
		// 这里需要注意越界问题
		if (sum > INT_MAX / 10 || (sum == INT_MAX && val > 7)) {
			return 0;
		}
		sum = sum * 10 + val;
		
	}       
	
	return sum * flag;
}


int main() {
	std::vector<int> nums1{1,3}, nums2{2,4};
	findMedianSortedArrays(nums1, nums2);

	reverse(-124);
	return 0;
}