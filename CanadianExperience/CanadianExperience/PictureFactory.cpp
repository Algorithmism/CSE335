/**
 * \file PictureFactory.cpp
 *
 * \author Charles B. Owen
 */

#include "stdafx.h"
#include "PictureFactory.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "ImageDrawable.h"
#include "MachineAdapter.h"

using namespace std;
using namespace Gdiplus;

/**
 * COnstructor
 */
CPictureFactory::CPictureFactory()
{
}


/**
 * Destructor
 */
CPictureFactory::~CPictureFactory()
{
}


/*! \brief Factory method to create a new picture.
* \returns The created picture
*/
std::shared_ptr<CPicture> CPictureFactory::Create()
{
    shared_ptr<CPicture> picture = make_shared<CPicture>();
	picture->GetTimeline()->SetNumFrames(900);


    // Create the background and add it
    auto background = make_shared<CActor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(Point(-100, 0));
    auto backgroundI = make_shared<CImageDrawable>(L"Background", L"images/snow.png");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

	// Create the machine
	auto machine = make_shared<CActor>(L"Machine");
	machine->SetPosition(Point(700, 500));
	auto machineI = make_shared<CMachineAdapter>(L"Machine");
	machine->AddDrawable(machineI);
	machine->SetRoot(machineI);
	picture->AddActor(machine);
	picture->SetMachine(machineI->GetMachine());
	picture->SetMachineAdapter(machineI);

	//create machine 2
	auto machine2 = make_shared<CActor>(L"Machine2");
	machine2->SetPosition(Point(250, 500));
	auto machineII = make_shared<CMachineAdapter>(L"Machine2");
	machine2->AddDrawable(machineII);
	machine2->SetRoot(machineII);
	picture->AddActor(machine2);
	picture->SetMachine2(machineII->GetMachine());
	picture->SetMachineAdapter2(machineII);
    // Create and add Harold
    CHaroldFactory factory;
    auto harold = factory.Create();

    // This is where Harold will start out.
    harold->SetPosition(Point(750, 500));

    picture->AddActor(harold);

    // Create and add Sparty
    CSpartyFactory sfactory;
    auto sparty = sfactory.Create();

    sparty->SetPosition(Point(520, 500));
    picture->AddActor(sparty);



    return picture; ///< return picture
}
