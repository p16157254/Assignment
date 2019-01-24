/*! \file ModelComponent.h
* Class controls the game engines models
*/

#pragma once

#include "Component.h"
#include "Model.h"

class ModelComponent : public Component //! ModelComponent handles all of the models in the engine and is a component of Component
{
public:
	ModelComponent(Model* p_model); 
	

	void OnUpdate(float dt) override //! Updates the model
	{
	}
	void OnMessage(const std::string m) override //! Send messages to the model
	{
	}

	Model* getModel();


private:

	Model * model;
};