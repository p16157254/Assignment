#include "Scene.h"

Scene::Scene(std::string p_sLevel)
{
	p_sLevel;
	m_sLevel = p_sLevel;

}

void Scene::update()
{
}

void Scene::render(IEngineCore* p_engineInterfacePtr)
{
	for (int i = 0; i < v_playerObjects->size(); i++)
	{
		Model* l_mTemp = v_playerObjects->at(i).getComponent<ModelComponent>()->getModel();
		glm::mat4 l_m4Temp = v_playerObjects->at(i).getComponent<TransformComponent>()->getModelMatrix();
		p_engineInterfacePtr->drawModel(l_mTemp, l_m4Temp);
	}
}

bool Scene::loadLevelJSON(std::string levelJSONFile)
{

	std::fstream jsonData;
	Json::Value root;
	Json::Reader reader;

	jsonData.open(levelJSONFile.c_str());

	if (!reader.parse(jsonData, root))
	{
		std::cout << "Failed to parse data from: "
			<< levelJSONFile << reader.getFormattedErrorMessages();
		return false;
	}
	const Json::Value gameObjects = root["GameObjects"];

	for (int i = 0; i < gameObjects.size(); i++)
	{
		std::cout << gameObjects[i]["name"].asString() << "loaded\n";
		string objectName = gameObjects[i]["name"].asString();
		float x, y, z;

		Model* object = new Model("assets/models/" + objectName + ".obj");
		const Json::Value posNode = gameObjects[i]["position"];
		const Json::Value orientNode = gameObjects[i]["orientation"];
		const Json::Value scaleNode = gameObjects[i]["scale"];


		x = posNode[0].asFloat();
		y = posNode[1].asFloat();
		z = posNode[2].asFloat();

		glm::vec3 pos(x, y, z);

		GameObject go_temp;

		go_temp.addComponent(new TransformComponent(pos));
		go_temp.addComponent(new ModelComponent(object));

		getCubes()->push_back(go_temp);

	}

	return true;
}

std::vector<GameObject>* Scene::getCubes()
{
	return v_playerObjects;
}

std::string Scene::getLevel()
{
	return m_sLevel;

}
