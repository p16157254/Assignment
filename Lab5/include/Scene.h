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
	Scene(std::string p_sLevel);


	void update();
	void render(IEngineCore* p_engineInterfacePtr);

	bool loadLevelJSON(std::string levelJSONFile);


	std::vector<GameObject>* getCubes();

	std::string getLevel();

private:

	std::string m_sLevel;


protected:
	std::vector<GameObject> *v_playerObjects = new std::vector<GameObject>();

};