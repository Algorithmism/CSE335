#include "stdafx.h"

#include <memory>

#include "CppUnitTest.h"
#include "Actor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Gdiplus;

namespace Testing
{
	TEST_CLASS(CActorTest)
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
		TEST_METHOD(TestCActorConstructor)
		{
			CActor actor(L"Harold");
			Assert::AreEqual(std::wstring(L"Harold"), actor.GetName());
		}
		TEST_METHOD(TestCActorEnabledDefaultVal) 
		{
			//Thank you TAs for helping me through this! I was thinking too hard about it\
				TY for clearing it up. :) 
			CActor actor(L"Harold");
			//is the value set to true for the IsEnabled member var?
			Assert::AreEqual(true, actor.IsEnabled());
			//if so, then set the member var to false
			actor.SetEnabled(false);
			//then, check to see if it is false. if these all pass then we're good
			Assert::AreEqual(false, actor.IsEnabled());
		}
		TEST_METHOD(TestCActorClickableDefaultVal) 
		{
			//create object
			CActor actor(L"Harold");
			//check if clickable
			Assert::AreEqual(true, actor.IsClickable());
			//if clickable set mem var to false to make it not clickable
			actor.SetClickable(false);
			//Check if clickable (should not be clickable)
			Assert::AreEqual(false, actor.IsClickable());
		}
		TEST_METHOD(TestCActorPositionVal) 
		{
			//create actor object to test with
			CActor actor(L"Harold");
			//Check if initial values are set correctly
			Assert::AreEqual(0, actor.GetPosition().X);
			Assert::AreEqual(0, actor.GetPosition().Y);
			//If so, then set to new position value
			Gdiplus::Point newLocation = Gdiplus::Point(50, 50);
			//Set to that new Location point
			actor.SetPosition(newLocation);
			//test to see if in those set positions from newLoc
			Assert::AreEqual(50, actor.GetPosition().X);
			Assert::AreEqual(50, actor.GetPosition().Y);


		
		}
	};
}