/**
 * \file MachineFactory1.cpp
 *
 * \author Mark Maroki
 */


#include "stdafx.h"
#include "MachineFactory1.h"
#include "WorkingMachine.h"
#include "Shape.h"
#include "Motor.h"
#include "Pulley.h"
#include "Cam.h"
#include "Roller.h"

using namespace std;
using namespace Gdiplus;
/**
 * Constructor
 */
CMachineFactory1::CMachineFactory1()
{
}

/**
 * Destructor
 */
CMachineFactory1::~CMachineFactory1()
{
}

/**
 * Create a machine object
 * \returns Object of type CMachine
 */
std::shared_ptr<CWorkingMachine> CMachineFactory1::CreateMachine()
{

	// The machine itself
	auto machine = make_shared<CWorkingMachine>(1);

	// The base
	auto base = make_shared<CShape>();
	int wid = 600;
	base->Rectangle(-wid / 2, 0, wid, 40);
	base->SetImage(L"images/base.png");
	//base->SetRotation(3000);
	machine->AddComponent(base);

	// The motor
	auto motor = make_shared<CMotor>();
	machine->AddMotor(motor);
	motor->SetPosition(-150, -38);
	motor->SetSpeed(1.0);

	// Post to hold the first pulley
	// Must be added before the motor pulley so it draws behind the belt
	auto post1 = make_shared<CShape>();
	int wid1 = 20;
	post1->Rectangle(-wid1 / 2, 0, wid1, 90);
	post1->SetPosition(-230, -40);
	post1->SetColor(Gdiplus::Color::Red);
	machine->AddComponent(post1);
	// The shaft
	auto shaft = make_shared<CMotor>();

	// The pulley driven by the motor
	// Radius=15pixels
	auto pulley1 = make_shared<CPulley>(15);
	pulley1->SetImage(L"images/pulley2.png");
	pulley1->SetPosition(-155, -75);
	//pulley1->SetPhase(0.1);	// Rotate it a little bit
	machine->AddComponent(pulley1);
	// This is how I make a connection from a source to a sink.
	// This is the case where they are driven at the same speed.
	motor->GetSource()->AddSink(pulley1->GetSink());

	// The pulley on the first post. Driven by the motor pulley.
	// Radius=40pixels
	auto pulley2 = make_shared<CPulley>(35);
	pulley2->SetImage(L"images/pulley.png");
	pulley2->SetPosition(-230, -120);
	//pulley2->SetPhase(0.1);	// Rotate it a little bit
	machine->AddComponent(pulley2);
	// This is how I make a connection from a pully
	// to another pully using a belt.
	pulley1->Drive(pulley2);


	// Pulley directly driven by that pulley
	// Radius=15px
	auto pulley3 = make_shared<CPulley>(15);
	pulley3->SetImage(L"images/pulley2.png");
	pulley3->SetPosition(-230, -120);
	machine->AddComponent(pulley3);
	pulley2->GetSource()->AddSink(pulley3->GetSink()); ///pulley 2 spins pulley 3 (smaller one)
	
	// The flag
	auto flag = make_shared<CShape>();
	flag->AddPoint(-50, 0);
	flag->AddPoint(-50, -100);
	flag->AddPoint(5, -100);
	flag->AddPoint(5, 0);
	flag->SetImage(L"images/flag.png");
	flag->SetPosition(-230, -120);
	machine->AddComponent(flag);
	pulley3->GetSource()->AddSink(flag->GetSink());


	// The pully that drives this bell
	auto drivePulley = pulley3;

	// X positions of each bell
	int bellX[] = { -100, -30, 40, 110, 190 };

	for (int i = 0; i < 5; i++)
	{
		int x = bellX[i];
		// A post that holds the pulleys and cam
		auto pully2post = make_shared<CShape>();
		pully2post->Rectangle(x, -40, 20, 120);
		pully2post->SetColor(Gdiplus::Color::Red);
		machine->AddComponent(pully2post);

		// A pulley that is driven by the previous stage
		// Radius=35pixels
		auto drivenPulley = make_shared<CPulley>(35);
		drivenPulley->SetImage(L"images/pulley.png");
		drivenPulley->SetPosition(x+10, -150);
		machine->AddComponent(drivenPulley);

		drivePulley->Drive(drivenPulley);

		// A pulley to drive the next stage
		drivePulley = make_shared<CPulley>(35);
		drivePulley->SetImage(L"images/pulley.png");
		drivePulley->SetPosition(x+10, -150);
		drivePulley->SetPhase(0.1);
		machine->AddComponent(drivePulley);

		drivenPulley->GetSource()->AddSink(drivePulley->GetSink());

		// A cam
		auto cam = make_shared<CCam>(20, 16);
		cam->SetImage(L"images/hammered-copper1.png", true);
		cam->SetPhase(-0.25);
		cam->SetPosition(x+10,-150);

		machine->AddComponent(cam);
		drivePulley->GetSource()->AddSink(cam->GetSink());

		// A roller that rides on the cam
		// Radius is 4 pixels.
		// The angle is 0.25, placing it at the top of the cam
		auto roller = make_shared<CRoller>(7, 0.25);
		roller->SetImage(L"images/roller.png");
		cam->AddRoller(roller);
		machine->AddComponent(roller);
		// A bar that represents the bell
		auto bar = make_shared<CShape>();
		bar->Rectangle(-(24 / 2)+10, 0, 24, 108);
		bar->SetPosition(x, -215);
		machine->AddComponent(bar);

		// The mallet that is driven by the roller
		auto mallet = make_shared<CShape>();
		wid = 8;
		mallet->Rectangle(-wid / 2, 0, wid, 100);
		mallet->SetImage(L"images/mallet.png");
		machine->AddComponent(mallet);
		roller->AddPart(mallet);

		shared_ptr<CWavChannel> channel;

		//
		// Specifics for each one of the bells
		//
		switch (i)
		{
		case 0:
		default:
			bar->SetImage(L"images/bar-red.png");
			channel = machine->GetWavPlayer()->CreateChannel(L"audio/bell-c1.wav");

			cam->AddPin(1);
			cam->AddPin(2);
			cam->AddPin(4);
			break;

		case 1:
			bar->SetImage(L"images/bar-grn.png");
			channel = machine->GetWavPlayer()->CreateChannel(L"audio/bell-e1.wav");
			cam->AddPin(3);
			cam->AddPin(5);
			cam->AddPin(9);
			break;

		case 2:
			bar->SetImage(L"images/bar-pur.png");
			channel = machine->GetWavPlayer()->CreateChannel(L"audio/bell-e1.wav");

			cam->AddPin(6);
			cam->AddPin(8);
			cam->AddPin(13);
			break;

		case 3:
			bar->SetImage(L"images/bar-yel.png");
			channel = machine->GetWavPlayer()->CreateChannel(L"audio/bell-g1.wav");
			cam->AddPin(4);
			cam->AddPin(7);
			cam->AddPin(11);
			break;

		case 4:
			bar->SetImage(L"images/bar-cyan.png");
			channel = machine->GetWavPlayer()->CreateChannel(L"audio/bell-a1.wav");
			cam->AddPin(10);
			cam->AddPin(12);
			cam->AddPin(15);
			break;
		}

		roller->SetChannel(channel);

		// The Build function creates the cam after the pins have been added
		cam->Build();
	}

	return machine;
}
