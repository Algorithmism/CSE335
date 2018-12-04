#include "stdafx.h"
#include "CppUnitTest.h"
#include "Drawable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;




namespace Testing
{
	//similar to previous tests we must make the abstract possible
	class CDrawableMock : public CDrawable 
	{ 
	//make public only for testing purposes
	public:
		//needed in this format because constructors disabled and this is format needed
		CDrawableMock(const std::wstring &name): CDrawable(name) {}
		//override the draw function for the test
		virtual void Draw(Gdiplus::Graphics *graphic) override {}
		//override for the HitTest function
		virtual bool HitTest(Gdiplus::Point position) override { return false; }
	};
	TEST_CLASS(CDrawableTest)
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
		TEST_METHOD(TestCDrawableConstructor)
		{
			CDrawableMock drawn(L"testDraw");
			Assert::AreEqual(std::wstring(L"testDraw"), drawn.GetName());
		}
		TEST_METHOD(TestCDrawableDefaultPositionVal) 
		{
			//create new name		
			CDrawableMock drawn(L"testDraw");
			//check to see if it defaults to 0,0
			Assert::AreEqual(0, drawn.GetPosition().X);
			Assert::AreEqual(0, drawn.GetPosition().Y);
			//create newLocation posiiton
			Gdiplus::Point newLoc = Gdiplus::Point(50, 50);
			//set position
			drawn.SetPosition(newLoc);
			//check if at 50,50
			Assert::AreEqual(50, drawn.GetPosition().X);
			Assert::AreEqual(50, drawn.GetPosition().Y);
		
		}
		TEST_METHOD(TestCDrawableDefaultRotationVal)
		{
			CDrawableMock drawn(L"testDraw");
			//check for default rotational value
			Assert::AreEqual(0.0, drawn.GetRotation());
			double a = 0.333;
			double b = acos(cos(a));
			//Set the actual intended rotation
			drawn.SetRotation(b);
			//check if rotation worked by getting the rotation 
			Assert::AreEqual(a, drawn.GetRotation(), 0.000000001);

		}
		TEST_METHOD(TestCDrawableAssociation)
		{
			CDrawableMock body(L"Body");
			auto arm = std::make_shared<CDrawableMock>(L"Arm");
			auto leg = std::make_shared<CDrawableMock>(L"Leg");

			Assert::IsNull(arm->GetParent());
			Assert::IsNull(leg->GetParent());

			body.AddChild(arm);
			body.AddChild(leg);

			Assert::IsTrue(arm->GetParent() == &body);
			Assert::IsTrue(leg->GetParent() == &body);
		}
	};
}