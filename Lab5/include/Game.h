#pragma once

#include "Scene.h"
#include "ColourComponent.h"
#include "InputHandler.h"
#include "ModelComponent.h"


using namespace std;

class IEngineCore;
class InputHandler;


class Game
{
public:
	Game();

	IEngineCore* m_engineInterfacePtr;
	InputHandler* m_inputHandler;

	

	void update();
	void render();

			
private:
	GameObject m_playerBackground;
	GameObject m_playerCube;
	Camera m_camera;
	int numCubesToRead;
	int iLevel;
	stringstream ss;
	string s;
	float w, x, y, z;


	
	Scene* m_currentScene = new Scene("assets/Levels/snowLevel.json");
};
