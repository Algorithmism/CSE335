
#include <memory>
#include <string>
#include "stdafx.h"
#include "CppUnitTest.h"
#include "Aquarium.h"
#include "FishBeta.h"
#include "FishDory.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	TEST_CLASS(CAquariumTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCAquariumConstruct)
		{
			CAquarium aquarium;
		}
		TEST_METHOD(TestCAquariumHitTest)
		{
			CAquarium aquarium;

			Assert::IsTrue(aquarium.HitTest(100, 200) == nullptr, L"Testing empty aquarium");

			shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(&aquarium);
			fish1->SetLocation(100, 200);
			aquarium.Add(fish1);

			shared_ptr<CFishDory> fish2 = make_shared<CFishDory>(&aquarium);
			fish1->SetLocation(100, 200);
			aquarium.Add(fish2);

			Assert::IsTrue(aquarium.HitTest(100, 200) == fish1, L"Testing fish at 100, 200");
			Assert::IsTrue(aquarium.HitTest(100, 200) == fish2, L"Testing fish at 100, 200");
			Assert::IsTrue(aquarium.HitTest(200, 200) == nullptr, L"Testing empty location");

		}

	};
}