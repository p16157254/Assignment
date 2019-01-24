/*! \file InputHandler.h
* Class controls the game engines inputs
*/

#pragma once

#include <map>
#include "GameObject.h"
#include "TransformComponent.h"
#include <vector>



class InputCommand //! InputCommand class handles all of the player inputs
{
public:
	virtual ~InputCommand() {} //! Destructor for InputCommand
	virtual void execute(GameObject& playerBackground) = 0; //! Executes a command
	int iLevel = 1; //! Stores the current level loaded
};


//e.g. class RotateLeftCommand : public InputCommand


class RotateCubeCW : public InputCommand //! Rotates the view clockwise
{
public:
	void execute(GameObject& m_playerCube) override
	{
		if (m_playerCube.getComponent<TransformComponent>())
			m_playerCube.getComponent<TransformComponent>()->rotate(m_playerCube.getComponent<TransformComponent>()->getRotateValue(true), glm::vec3(0.f, 1.f, 0.0f)); 
	};
	
};


class RotateCubeCCW : public InputCommand //! Rotates the view counter clockwise
{
public:
	void execute(GameObject& m_playerCube) override
	{
		if (m_playerCube.getComponent<TransformComponent>())
			m_playerCube.getComponent<TransformComponent>()->rotate(m_playerCube.getComponent<TransformComponent>()->getRotateValue(false), glm::vec3(0.f, 1.f, 0.f));
	};
};

class RotateUp : public InputCommand //! Rotates the view up
{
public:
	void execute(GameObject& m_playerCube) override
	{
		if (m_playerCube.getComponent<TransformComponent>())
			m_playerCube.getComponent<TransformComponent>()->rotate(m_playerCube.getComponent<TransformComponent>()->getRotateValue(true), glm::vec3(1.f, 0.f, 0.0f));
	};
};


class RotateDown : public InputCommand //! Rotates the view down
{
public:
	void execute(GameObject& m_playerCube) override
	{
		if (m_playerCube.getComponent<TransformComponent>())
			m_playerCube.getComponent<TransformComponent>()->rotate(m_playerCube.getComponent<TransformComponent>()->getRotateValue(false), glm::vec3(1.f, 0.f, 0.f));
	};
};



class TranslateRight : public InputCommand //! Moves the player right
{
public:
	void execute(GameObject& m_playerCube) override
	{
		if (m_playerCube.getComponent<TransformComponent>())
			m_playerCube.getComponent<TransformComponent>()->translate(m_playerCube.getComponent<TransformComponent>()->getTranslateValue(true),0.f,0.f);
	};
};

class TranslateLeft : public InputCommand //! Moves the player left
{
public:
	void execute(GameObject& m_playerCube) override
	{
		if (m_playerCube.getComponent<TransformComponent>())
			m_playerCube.getComponent<TransformComponent>()->translate(m_playerCube.getComponent<TransformComponent>()->getTranslateValue(false),0.f,0.f);
	};
};


class ScaleCubeUp : public InputCommand //! Scales the cube up in the x axis
{
public:
	void execute(GameObject& m_playerCube) override
	{
		if (m_playerCube.getComponent<TransformComponent>())
			m_playerCube.getComponent<TransformComponent>()->scaleUp(m_playerCube.getComponent<TransformComponent>()->getScaleValue(true), 0.f, 0.f);
	};
};

class ScaleCubeDown : public InputCommand //! Scales the cube up in the x axis
{
public:
	void execute(GameObject& m_playerCube) override
	{
		if (m_playerCube.getComponent<TransformComponent>())
			m_playerCube.getComponent<TransformComponent>()->scaleUp(m_playerCube.getComponent<TransformComponent>()->getScaleValue(false), 0.f, 0.f);
	};
};

class TranslateForward : public InputCommand //! Moves the player forward
{
public:
	void execute(GameObject& m_playerCube) override
	{
		if (m_playerCube.getComponent<TransformComponent>())
			m_playerCube.getComponent<TransformComponent>()->translate(0.f,0.f, m_playerCube.getComponent<TransformComponent>()->getTranslateValue(true));
	};
};

class TranslateBack : public InputCommand //! Moves the player back
{
public:
	void execute(GameObject& m_playerCube) override
	{
		if (m_playerCube.getComponent<TransformComponent>())
			m_playerCube.getComponent<TransformComponent>()->translate(0.f,0.f, m_playerCube.getComponent<TransformComponent>()->getTranslateValue(false));
	};
};

class TranslateUp : public InputCommand //! Moves the player up
{
public:
	void execute(GameObject& m_playerCube) override
	{
		if (m_playerCube.getComponent<TransformComponent>())
			m_playerCube.getComponent<TransformComponent>()->translate(0.f, m_playerCube.getComponent<TransformComponent>()->getTranslateValue(true), 0.f);
	};
};

class TranslateDown : public InputCommand //! Moves the player down
{
public:
	void execute(GameObject& m_playerCube) override
	{
		if (m_playerCube.getComponent<TransformComponent>())
			m_playerCube.getComponent<TransformComponent>()->translate(0.f, m_playerCube.getComponent<TransformComponent>()->getTranslateValue(false), 0.f);
		
	};
};

class SwitchScene : public InputCommand //! Switches the scene
{
public:
	void execute(GameObject& m_playerCube) override
	{
		if (m_playerCube.getComponent<TransformComponent>())
			if (iLevel == 1) {
				m_playerCube.getComponent<TransformComponent>()->translate(100.f, 0.f, 0.f);
				iLevel++;
			}
			else if (iLevel == 2)
			{
				m_playerCube.getComponent<TransformComponent>()->translate(-200.f, 0.f, 0.f);
				iLevel++;
			}
			else if (iLevel == 3)
			{
				m_playerCube.getComponent<TransformComponent>()->translate(100.f, 0.f, 0.f);
				iLevel = 1;
			}

	};
};




struct InputHandler //! InputHandler struct 
{
	std::vector<GameObject>* m_playerCube; //! Pointer to the m_playerCube vector of game objects

	std::map<int, InputCommand*> m_controlMapping; //! m_controlMapping is a map containing an integer and the InputCommand pointer

	InputHandler(std::vector<GameObject>* p_playerCubes) : m_playerCube(p_playerCubes) //! InputHandler is a component of m_playerCubes
		/*!
			It contains all of the control mapping for each of the execute commands
		*/
	{
		// the idea will be to map the keys directly from a config file that can be loaded in
		// and changed on the fly
		
		m_controlMapping[76] = new RotateCubeCW; 
		m_controlMapping[74] = new RotateCubeCCW;
		m_controlMapping[75] = new RotateUp;
		m_controlMapping[73] = new RotateDown;
		m_controlMapping[65] = new TranslateRight;
		m_controlMapping[68] = new TranslateLeft;
		m_controlMapping[87] = new TranslateForward;
		m_controlMapping[83] = new TranslateBack;
		m_controlMapping[70] = new TranslateUp;
		m_controlMapping[82] = new TranslateDown;
		m_controlMapping[67] = new ScaleCubeUp;
		m_controlMapping[90] = new ScaleCubeDown;
		m_controlMapping[49] = new SwitchScene;
		
	}

	void handleInputs(const std::vector<bool>& keyBuffer) //! Handles the input for the game engine
	
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
