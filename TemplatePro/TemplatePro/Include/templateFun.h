#pragma once

#ifndef FUNTEMPLATE_H
#define FUNTEMPLATE_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

namespace Test {

	namespace Template {

		namespace Fun {

			template<class T>
			T Max(T a, T b)
			{
				return b < a ? a : b;
			}

			bool test();
		}
	}
}


#endif