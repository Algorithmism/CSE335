/**
 * \file CPictureObserverTest.cpp
 * Testing Implementation
 * \author Mark Maroki
 *
 */


#include "stdafx.h"
#include "CppUnitTest.h"
#include "PictureObserver.h"
#include "Picture.h"
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Gdiplus;
using namespace std;

namespace Testing
{
	class CPictureObserverMock : public CPictureObserver
	{
	public:
		CPictureObserverMock() : CPictureObserver() {}
		bool mUpdated = false;
		virtual void UpdateObserver() override { mUpdated = true; }

	};


	TEST_CLASS(CPictureObserverTest)
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
		TEST_METHOD(TestCPictureObserverConstruct)
		{
			CPictureObserverMock observer;
		}
		TEST_METHOD(TestCPictureSize)
		{
			CPicture picture;

			Size size = picture.GetSize();
			Assert::AreEqual(800, size.Width);
			Assert::AreEqual(600, size.Height);

			picture.SetSize(Size(123, 456));
			size = picture.GetSize();
			Assert::AreEqual(123, size.Width);
			Assert::AreEqual(456, size.Height);
		}
		TEST_METHOD(TestCPictureObserverOneObserver)
		{
			// Allocate a CPicture object
			shared_ptr<CPicture> picture = make_shared<CPicture>();

			// Create a mock observer object
			CPictureObserverMock observer;

			// And set it for the observer:
			observer.SetPicture(picture);
			// actual implementation
			picture->UpdateObservers();
			// tests to see if implementation above works
			Assert::IsTrue(observer.mUpdated);

		}
		TEST_METHOD(TestCPictureObserverGettingObserver)
		{
			shared_ptr<CPicture> picture = make_shared<CPicture>();

			/// Create a mock observer object
			CPictureObserverMock observer;
			///implement the setting of the picture. 
			observer.SetPicture(picture);
			///test implementation of setting picture
			Assert::IsTrue(picture == observer.GetPicture());
		}
		TEST_METHOD(TestCPictureObserverTwoObserver)
		{
		
			// Allocate a CPicture object 1
			shared_ptr<CPicture> pictureOne = make_shared<CPicture>();
			// Allocate a CPicture object 2
			shared_ptr<CPicture> pictureTwo = make_shared<CPicture>();

			// Create a mock observer object
			CPictureObserverMock observerOne;
			// Create a second mock observer object
			CPictureObserverMock observerTwo;

			// And set it for the first observer:
			observerOne.SetPicture(pictureOne);
			// And set it for the second observer:
			observerTwo.SetPicture(pictureTwo);

			// actual implementation for the first picture
			pictureOne->UpdateObservers();
			// actual implementation for the second picture
			pictureTwo->UpdateObservers();

			///test implementation of setting picture
			Assert::IsTrue(observerOne.mUpdated);
			///test implementation of setting picture
			Assert::IsTrue(observerTwo.mUpdated);
		}
		TEST_METHOD(TestCPictureObserverCreateNDestroy)
		{
			///make shared ptr for picture
			shared_ptr<CPicture> picture = make_shared<CPicture>();
			{
				///create Mock observer
				CPictureObserverMock observerTwo;

				//Assumption: spawning objectTwo out of scope would create and\
							  destroy once out of the 'loop', right?

				///set picture for the observer to see if it destroys and creates
				observerTwo.SetPicture(picture);

			}
		
		}

	};
}