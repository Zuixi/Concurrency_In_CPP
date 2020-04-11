
#include "../Include/templateFun.h"

namespace Test {

    namespace Template {

        namespace Fun {
            
            bool test()
            {
				std::cout << "Test template function beginning------" << std::endl;
				int i = 42;
				std::cout << "max(2,i) = " << Max(2, i) << std::endl;

				double d1 = 2.4;
				double d2 = 23.1;
				std::cout << "max(d1, d2) = " << Max(d1, d2) << '\n';

				std::string s1 = "mathematics";
				std::string s2 = "math";
				std::cout << "max(s1,s2) = " << Max(s1, s2) << std::endl;

				return true;
            }
        }
    }
}