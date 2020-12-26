#include "pch.h"
#include "CppUnitTest.h"
#include "../Project 6.4-2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest642
{
	TEST_CLASS(UnitTest642)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t[10] = { -5, -4, 0, 10, 25, -25, 1, 4, -1, 0 };

			int M = SearchMin(t, 10,-5,1);
			int First = SearchFirst(t, 10,-1,0);
			int Last = SearchLast(t,-1,9, First);
			int S = Sum(t, 7,0,4);
			int Zero = SearchZero(t, 10, -1, 0);
			Sort(t, 10,0);


			Assert::AreEqual(M, -25);
			Assert::AreEqual(First, 3);
			Assert::AreEqual(Last, 7);
			Assert::AreEqual(S, 1);
			Assert::AreEqual(Zero, 2);
			Assert::AreEqual(t[0], 0);
		}
	};
}
