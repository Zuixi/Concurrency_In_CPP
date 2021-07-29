#include <iostream>
#include <vector>
#include <string>

std::string restoreString(std::string s, std::vector<int>& p) {
    std::string ans(s);
    
    for (int i = 0; i < s.length(); ++i){
        ans[p[i]] == s[i];
    }
    
    return ans;
}

int main() {
    std::vector<int>  pos{4,5,6,7,0,2,1,3};

    restoreString("codeleet", pos);

    return 0;
}