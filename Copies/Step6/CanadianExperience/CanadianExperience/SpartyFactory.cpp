/**
 * \file SpartyFactory.cpp
 * Factory
 * \author Mark Maroki
 */

#include "stdafx.h"
#include <memory>
#include "SpartyFactory.h"
#include "PolyDrawable.h"
#include "ImageDrawable.h"
#include "HeadTop.h"

using namespace std;
using namespace Gdiplus;


/**
 * Constructor
 */
CSpartyFactory::CSpartyFactory()
{
}


/**
 * Destructor
 */
CSpartyFactory::~CSpartyFactory()
{
}

/** This is a concrete factory method that creates our Sparty actor.
* \returns Pointer to an actor object.
*/
std::shared_ptr<CActor> CSpartyFactory::Create()
{
	shared_ptr<CActor> actor = make_shared<CActor>(L"Sparty");

	auto shirt = make_shared<CImageDrawable>(L"Shirt", L"images/sparty_torso.png");
	shirt->SetCenter(Point(-435, 83));
	shirt->SetPosition(Point(0, -114));
	actor->SetRoot(shirt);

	auto lleg = make_shared<CImageDrawable>(L"Left Leg", L"images/sparty_lleg.png");
	lleg->SetCenter(Point(-500, -225));
	lleg->SetPosition(Point(0, -114));
	shirt->AddChild(lleg);

	auto rleg = make_shared<CImageDrawable>(L"Right Leg", L"images/sparty_rleg.png");
	rleg->SetCenter(Point(-435, -225));
	rleg->SetPosition(Point(0, -114));
	shirt->AddChild(rleg);

	auto headb = make_shared<CImageDrawable>(L"Head Bottom", L"images/sparty_lhead.png");
	headb->SetCenter(Point(-450, 0));
	headb->SetPosition(Point(0, -100));
	shirt->AddChild(headb);

	auto headt = make_shared<CHeadTop>(L"Head Top", L"images/sparty_head.png");
	headt->SetCenter(Point(-455, 40));
	headt->SetPosition(Point(0, -100));
	headb->AddChild(headt);

	auto larm = make_shared<CImageDrawable>(L"Left Arm", L"images/sparty_larm.png");
	larm->SetCenter(Point(-525, -35));
	larm->SetPosition(Point(0, -114));
	shirt->AddChild(larm);

	auto flag = make_shared<CImageDrawable>(L"Flag", L"images/amflag.png");
	flag->SetCenter(Point(-525, -35));
	flag->SetPosition(Point(100, -150));
	larm->AddChild(flag);

	auto rarm = make_shared<CImageDrawable>(L"Right Arm", L"images/sparty_rarm.png");
	rarm->SetCenter(Point(-370, -35));
	rarm->SetPosition(Point(0, -114));
	shirt->AddChild(rarm);

	auto eyel = make_shared<CImageDrawable>(L"Left Eye", L"images/sparty_leye.png");
	eyel->SetCenter(Point(-510, -177));
	eyel->SetPosition(Point(0, -114));
	headt->AddChild(eyel);

	auto eyer = make_shared<CImageDrawable>(L"Right Eye", L"images/sparty_reye.png");
	eyer->SetCenter(Point(-475, -175));
	eyer->SetPosition(Point(0, -114));
	headt->AddChild(eyer);

	actor->AddDrawable(larm);
	actor->AddDrawable(rarm);
	actor->AddDrawable(rleg);
	actor->AddDrawable(lleg);
	actor->AddDrawable(shirt);
	actor->AddDrawable(headb);
	actor->AddDrawable(headt);
	actor->AddDrawable(eyel);
	actor->AddDrawable(eyer);
	actor->AddDrawable(flag);
	
	return actor;
}