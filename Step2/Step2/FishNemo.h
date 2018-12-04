/**
 * \file FishNemo.h
 *
 * \author Charles B. Owen
 *
 * Class the implements a Nemo fish
 */

#pragma once

#include <memory>
#include "XmlNode.h"
#include "Item.h"
#include "Fish.h"
using namespace xmlnode;



 /**
  * Implements a Nemo fish
  */
class CFishNemo : public CFish
{
public:
	CFishNemo(CAquarium *aquarium);

	/// Default constructor (disabled)
	CFishNemo() = delete;

	/// Copy constructor (disabled)
	CFishNemo(const CFishNemo &) = delete;

	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

	virtual ~CFishNemo();

};
