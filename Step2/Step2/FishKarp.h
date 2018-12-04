/**
 * \file FishKarp.h
 *
 * \author Mark Maroki
 *
 * Class the implements a Karp fish
 */

#pragma once

#include <memory>
#include "XmlNode.h"
#include "Item.h"
#include "Fish.h"
using namespace xmlnode;

 /**
  * Implements a Karp fish
  */
class CFishKarp : public CFish
{
public:
	CFishKarp(CAquarium *aquarium);

	/// Default constructor (disabled)
	CFishKarp() = delete;

	/// Copy constructor (disabled)
	CFishKarp(const CFishKarp &) = delete;

	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

	virtual ~CFishKarp();

	virtual void SetLocation(double x, double y);

};
