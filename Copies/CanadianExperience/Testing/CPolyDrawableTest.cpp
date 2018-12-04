#include "stdafx.h"
#include "CppUnitTest.h"

#include <string>

#include "PolyDrawable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Gdiplus;

namespace Testing
{
	TEST_CLASS(CPolyDrawableTest)
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
		TEST_METHOD(CPolyDrawableConstructor) 
		{
			CPolyDrawable testPolyDraw(L"testDraw");
			Assert::AreEqual(std::wstring(L"testDraw"), testPolyDraw.GetName());
		
		}

		TEST_METHOD(TestPolyDrawColor) 
		{
			//first create a draw object
			CPolyDrawable testPolyDraw(L"testDraw");
			//then assign same color as was assigned to cullah in PolyDrawable.h
			Gdiplus::Color culluh = Gdiplus::Color::Cyan;
			//then see if getting color for testPolyDraw is same (before setting it)
			Assert::AreEqual(culluh.GetValue(), testPolyDraw.GetColor().GetValue());
			//then assign different color to new variable and set it to mem var
			Gdiplus::Color tempCulluh = Gdiplus::Color::Gold;
			//then set tempCulluh so that we can grab(get) it for testPolyDraw
			testPolyDraw.CPolyDrawable::SetColor(tempCulluh);
			//then test if getting the color fom mem var after setting the color to Gold will cause testPolyDraw to be Gold
			Assert::AreEqual(tempCulluh.GetValue(), testPolyDraw.GetColor().GetValue());



		}

	};
}