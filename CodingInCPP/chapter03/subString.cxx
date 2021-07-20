#include <iostream>
#include <unordered_set>

int lengthOfLongestSubstring(string s) {
	int ans = 0, rk = -1;
	std::unordered_set<char> chSet;
	
	for (int i = 0; i < s.length(); ++i) {
		if (i != 0) {
			chSet.erase(s[i - 1]);
		}
		
		// 不存在就加入set, rk不需要重置
		while( rk + 1 < s.length() && !chSet.count(s[rk + 1])) {
			chSet.insert(s[rk + 1]);
			++rk;
		}

		ans = rk - i + 1 > ans ? rk - i + 1 : ans;	
	}

	return ans;
}

int main() {

	std::unordered_set<int>  nums;

	for (int i = 1; i <= 4; ++i) {
		nums.insert(i * 2);
	}

	for (int i = 1; i < 10; ++i) {
		if (!nums.count(i)) {
			std::cout << i << " not in set" << std::endl;
		} else {
			std::cout << i << " is in set" << std::endl;
		}
	}
	return 0;
}