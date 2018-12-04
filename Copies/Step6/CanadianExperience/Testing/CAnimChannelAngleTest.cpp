/**
 * \file CAnimChannelAngleTest.cpp
 *
 * \author Mark Maroki
 */

#include "stdafx.h"
#include "CppUnitTest.h"
#include "AnimChannelAngle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CAnimChannelAngleTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestNothing)
		{
			// This is an empty test just to ensure the system is working
		}
		TEST_METHOD(CAnimChannelAngleTestt) 
		{
			CAnimChannelAngle angle;
			angle.SetName(L"Mark");
			Assert::IsTrue(angle.GetName() == (L"Mark"));
			angle.SetName(L"Shumaker");
			Assert::IsTrue(angle.GetName() == (L"Shumaker"));
		}
	};
}