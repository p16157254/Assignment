#pragma once

#include <map>
#include "GameObject.h"
#include "TransformComponent.h"
#include <vector>



class InputCommand
{
public:
	virtual ~InputCommand() {}
	virtual void execute(GameObject& playerBackground) = 0;
};


//e.g. class RotateLeftCommand : public InputCommand


class RotateCubeCW : public InputCommand
{
public:
	void execute(GameObject& m_playerCube) override
	{
		if (m_playerCube.getComponent<TransformComponent>())
			m_playerCube.getComponent<TransformComponent>()->rotate(m_playerCube.getComponent<TransformComponent>()->getRotateValue(true), glm::vec3(0.f, 0.f, 1.0f));
	};
};


class RotateCubeCCW : public InputCommand
{
public:
	void execute(GameObject& m_playerCube) override
	{
		if (m_playerCube.getComponent<TransformComponent>())
			m_playerCube.getComponent<TransformComponent>()->rotate(m_playerCube.getComponent<TransformComponent>()->getRotateValue(false), glm::vec3(0.f, 0.f, 1.0f));
	};
};



class TranslateCubeRight : public InputCommand
{
public:
	void execute(GameObject& m_playerCube) override
	{
		if (m_playerCube.getComponent<TransformComponent>())
			m_playerCube.getComponent<TransformComponent>()->translate(m_playerCube.getComponent<TransformComponent>()->getTranslateValue(true),0.f,0.f);
	};
};

class TranslateCubeLeft : public InputCommand
{
public:
	void execute(GameObject& m_playerCube) override
	{
		if (m_playerCube.getComponent<TransformComponent>())
			m_playerCube.getComponent<TransformComponent>()->translate(m_playerCube.getComponent<TransformComponent>()->getTranslateValue(false),0.f,0.f);
	};
};


class ScaleCubeUp : public InputCommand
{
public:
	void execute(GameObject& m_playerCube) override
	{
		if (m_playerCube.getComponent<TransformComponent>())
			m_playerCube.getComponent<TransformComponent>()->scaleUp(m_playerCube.getComponent<TransformComponent>()->getScaleValue(true), 0.f, 0.f);
	};
};

class ScaleCubeDown : public InputCommand
{
public:
	void execute(GameObject& m_playerCube) override
	{
		if (m_playerCube.getComponent<TransformComponent>())
			m_playerCube.getComponent<TransformComponent>()->scaleUp(m_playerCube.getComponent<TransformComponent>()->getScaleValue(false), 0.f, 0.f);
	};
};





struct InputHandler
{
	std::vector<GameObject>* m_playerCube;

	std::map<int, InputCommand*> m_controlMapping;

	InputHandler(std::vector<GameObject>* p_playerCubes) : m_playerCube(p_playerCubes)
	{
		// the idea will be to map the keys directly from a config file that can be loaded in
		// and changed on the fly
		m_controlMapping[69] = new RotateCubeCW;
		m_controlMapping[81] = new RotateCubeCCW;
		m_controlMapping[68] = new TranslateCubeRight;
		m_controlMapping[65] = new TranslateCubeLeft;
		m_controlMapping[67] = new ScaleCubeUp;
		m_controlMapping[90] = new ScaleCubeDown;
	}

	void handleInputs(const std::vector<bool>& keyBuffer)
	{

		for (const auto& mapEntry : m_controlMapping)
		{
			if (keyBuffer[mapEntry.first])
			{
				for (int i = 0; i < m_playerCube->size(); i++)
				{
					mapEntry.second->execute(m_playerCube->at(i));
				}
			}
		}

	}
};
