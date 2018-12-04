#include "stdafx.h"
#include "CppUnitTest.h"

#include "Aquarium.h"
#include "FishNemo.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CFishNemoTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestCFishNemoConstruct)
		{
			CAquarium aquarium;
			CFishNemo fish(&aquarium);
		}
	};
}