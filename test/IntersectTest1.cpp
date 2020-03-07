#include "pch.h"
#include "CppUnitTest.h"
#include "../count number of point/count number of point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntersectTest
{
	TEST_CLASS(IntersectTest)
	{
	public:
		TEST_METHOD(caculate_line_line)
		{
			Calculate cal;
			Line l1(0, 0, 1, 1);
			Line l2(0, 0, 0, 1);
			int ret = cal.caculate_line_line(l1, l2);
			Assert::AreEqual(ret,(int)1);
			Line l3(0, 0, 1, 1);
			Line l4(1, 0, 2, 1);
			ret = cal.caculate_line_line(l3, l4);
			Assert::AreEqual(ret, (int)0);
		}
	};
}
