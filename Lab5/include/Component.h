/*! \file Component.h
* Class controls the game enginescomponents
*/

#pragma once

#include <string>

class Component //! Component class handles all of the engines components
{
public:
	virtual void OnUpdate(float dt) = 0;//! Updates the component
	virtual void OnMessage(const std::string m) = 0;//! Checks form messages to the component
													/*!
													\param m m is the string that stores the message
													*/

};

