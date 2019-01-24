/*! \file Scene.h
* Class controls the game engines scenes
*/

#pragma once
#include "ModelComponent.h"
#include "GameObject.h"
#include "IEngineCore.h"
#include "json/json.h"
#include "TransformComponent.h"
#include <fstream>
#include <sstream>




class Scene
{
public:
	Scene(std::string p_sLevel); //! Scene constructor


	void update(); //! Update function
	void render(IEngineCore* p_engineInterfacePtr); //! Render function
	/*!
		\param p_engineInterfacePtr p_engineInterfacePtr is the pointer for the engine interface
	*/

	bool loadLevelJSON(std::string levelJSONFile); //! Function to load a JSON file as a level
	/*! 
	\param levelJSONFile levelJSONFile is the string that stores the level path and name
	*/
	
	std::vector<GameObject>* getCubes(); //! Puts the objects in the level into a vector of Game Objects

	std::string getLevel(); //! Gets the path and name of the level

private:

	std::string m_sLevel; //! Stores the path and name of the level


protected:
	std::vector<GameObject> *v_playerObjects = new std::vector<GameObject>(); //! A pointer to a vector of game objects

};