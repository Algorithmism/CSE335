/**
 * \file FishBeta.cpp
 *
 * \author Mark Maroki
 */

#include "stdafx.h"
#include <string>
#include "FishBeta.h"
#include "Item.h"
#include "XmlNode.h"


using namespace xmlnode;
using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring FishBetaImageName = L"images/beta.png";

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CFishBeta::CFishBeta(CAquarium *aquarium) :
CFish(aquarium, FishBetaImageName)
{
}

/**
 * Destructor
 */
CFishBeta::~CFishBeta()
{
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishBeta::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CFish::XmlSave(node);
	itemNode->SetAttribute(L"type", L"beta");
	return itemNode;
}