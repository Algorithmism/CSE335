/**
 * Base class for a fish
 * This applies to all of the fish, but not the decor
 * items in the aquarium.
 */
#pragma once
#include "Item.h"

class CFish : public CItem
{
public:
	/// Default constructor (disabled)
	CFish() = delete;

	/// Copy constructor (disabled)
	CFish(const CFish &) = delete;
	std::shared_ptr<xmlnode::CXmlNode>XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node);
	void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> &node) override;
	void ChangeSpeed(int SpeedX, int SpeedY);


protected:

	CFish(CAquarium * aquarium, const std::wstring & filename);

	void Update(double elapsed);

private:
	/// Fish speed in the X direction
	double mSpeedX;

	/// Fish speed in the Y direction
	double mSpeedY;
	///Fish Position varible in the X-axis
	double mPositionX;
	///Fish Position variable in the Y-Axis
	double mPositionY;

};

