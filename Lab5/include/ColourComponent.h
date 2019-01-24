/*! \file ColourComponent.h
* Class controls the game engines colour components
*/

#pragma once
#include "Component.h"

#define COLOUR_ADJUSTMENT_VALUE 0.001f //! The value to adjust the background colour by (No longer used)

class ColourComponent : public Component//! ColourComponent class handles all of the background colour and is a component of Component
{
public:
	ColourComponent() : m_colourValue(0) {}; //! Colour component constructor

	void OnUpdate(float dt) override//! Updates the colour component
	{

	}

	void OnMessage(const std::string m) override //! Checks form messages to the colour component
		/*!
		\param m m is the string that stores the message
		*/
	{
		if (m == "increase")
		{
			m_colourValue += COLOUR_ADJUSTMENT_VALUE;
		}
		else if (m == "decrease")
		{
			m_colourValue -= COLOUR_ADJUSTMENT_VALUE;
		}
	}

	float m_colourValue; //! m_colourValue is the float that stores the current colour value
};

class RedComponent : public ColourComponent {}; //! Red Component is the class that stores the red colour value
class GreenComponent : public ColourComponent {};//! Green Component is the class that stores the green colour value
class BlueComponent : public ColourComponent {};//! Blue Component is the class that stores the blue colour value