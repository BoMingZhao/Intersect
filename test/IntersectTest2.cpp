#include "pch.h"
#include "CppUnitTest.h"
#include "../count number of point/count number of point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntersectTest
{
	TEST_CLASS(IntersectTest)
	{
	public:
		TEST_METHOD(caculate_line_circle)
		{
			Calculate cal;
			Line l1(0, 0, 1, 1);
			Circle c1(0, 1, 1);
			int ret = cal.caculate_line_circle(l1, c1);
			Assert::AreEqual(ret, (int)2);
			Line l2(0, 0, 0, 1);
			Circle c2(1, 0, 1);
			ret = cal.caculate_line_circle(l2, c2);
			Assert::AreEqual(ret, (int)1);
			Line l3(0, 0, 1, 0);
			Circle c3(0, 2, 1);
			ret = cal.caculate_line_circle(l3, c3);
			Assert::AreEqual(ret, (int)0);
		}
	};
}
