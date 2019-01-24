/*! \file Game.h
* Class controls the game engines game loop and actions
*/

#pragma once

#include "Scene.h"
#include "ColourComponent.h"
#include "InputHandler.h"
#include "ModelComponent.h"


using namespace std;

class IEngineCore;//! IEngineCore Class handles the Engine Core
class InputHandler;//! InputHandler Class handles player inputs


class Game
{
public:
	Game();//!< Game Constructior

	IEngineCore* m_engineInterfacePtr;//!< Engine Core pointer
	InputHandler* m_inputHandler;//!< Input Handler Pointer

	

	void update();//<! Update function
	void render();//<! Render function 

			
private:
	GameObject m_playerBackground;//! The Game Object playerBackground
	GameObject m_playerCube;//! The Game Object playerCube
	Camera m_camera; //! The Camera camera
	int numCubesToRead; //! Integer holding the number of objects needing to be loaded
	stringstream ss; //! The String Stream ss, used for reading in JSON files
	string s;//! The String s, used for reading in JSON files
	float w, x, y, z;//! Floats w, x, y and z hold the position of loaded objects


	
	Scene* m_currentScene = new Scene("assets/Levels/LevelFile.json"); //! The Scene pointer currentScene, it holds the path to the LevelFile.json
};
