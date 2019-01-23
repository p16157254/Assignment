#include "ModelComponent.h"

ModelComponent::ModelComponent(Model * p_model)
{
	model = p_model;
}

Model* ModelComponent::getModel()
{
	return model;
}


