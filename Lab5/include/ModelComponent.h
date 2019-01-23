#pragma once

#include "Component.h"
#include "Model.h"

class ModelComponent : public Component
{
public:
	ModelComponent(Model* p_model);
	

	void OnUpdate(float dt) override {


	}
	void OnMessage(const std::string m) override {


	}

	Model* getModel();


private:

	Model * model;
};