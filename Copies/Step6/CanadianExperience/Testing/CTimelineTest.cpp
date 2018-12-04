/**
 * \file CTimelineTest.cpp
 * Testing CTimeline
 * \author Mark Maroki
 */


#include "stdafx.h"
#include "CppUnitTest.h"
#include "Timeline.h"
#include "AnimChannelAngle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CTimelineTest)
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
		TEST_METHOD(CTimelineTester)
		{

			CTimeline timeline;
			//check initial, set new time and see if it matches
			Assert::AreEqual(0.0, timeline.GetCurrentTime());
			timeline.SetCurrentTime(55.5);
			Assert::AreEqual(55.5, timeline.GetCurrentTime());
			
			//check initial is set then change and see if it matches
			Assert::AreEqual(30, timeline.GetFrameRate());
			timeline.SetFrameRate(40);
			Assert::AreEqual(40, timeline.GetFrameRate());

			//check initial is set then change and see if it matches
			Assert::AreEqual(300, timeline.GetNumFrames());
			timeline.SetNumFrames(400);
			Assert::AreEqual(400, timeline.GetNumFrames());

		}


		TEST_METHOD(TestCTimelineGetDuration)
		{
			CTimeline timeline;

			// Default value
			Assert::AreEqual(10, timeline.GetDuration(), 0.0001);

			// Changed duration
			timeline.SetFrameRate(375);
			Assert::AreEqual(300.0 / 375.0, timeline.GetDuration(), 0.0001);

			timeline.SetNumFrames(789);
			Assert::AreEqual(789.0 / 375.0, timeline.GetDuration(), 0.0001);
		}

		TEST_METHOD(TestCTimelineGetCurrentFrame)
		{
			CTimeline timeline;

			// Default value
			Assert::AreEqual(0, timeline.GetCurrentFrame());

			// Changed time
			timeline.SetCurrentTime(9.27);
			Assert::AreEqual(278, timeline.GetCurrentFrame());
		}
		TEST_METHOD(TestCTimelineAdd)
		{
			CTimeline timeline;
			CAnimChannelAngle channel;

			timeline.AddChannel(&channel);
			Assert::IsTrue(&timeline == channel.GetTimeline());
		}
	};
}