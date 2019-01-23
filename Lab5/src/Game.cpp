#include "Game.h"


Game::Game()
{
	m_engineInterfacePtr = nullptr;

	


	m_playerBackground.addComponent(new RedComponent);
	m_playerBackground.addComponent(new GreenComponent);
	m_playerBackground.addComponent(new BlueComponent);




	m_currentScene->loadLevelJSON(m_currentScene->getLevel());
	
	
	
	m_inputHandler = new InputHandler(m_currentScene->getCubes());
	

	//saveLevel("assets/levels/saveLevel.txt");
	
}

void Game::update()
{
	
}

void Game::render()
{
	float redValue = 0, greenValue = 0, blueValue = 0;
	if(m_playerBackground.getComponent<RedComponent>())
		redValue = m_playerBackground.getComponent<RedComponent>()->m_colourValue;
	if (m_playerBackground.getComponent<GreenComponent>())
		greenValue = m_playerBackground.getComponent<GreenComponent>()->m_colourValue;
	if (m_playerBackground.getComponent<BlueComponent>())
		blueValue = m_playerBackground.getComponent<BlueComponent>()->m_colourValue;
	
	// e.g. pass object details to the engine to render the next frame
	m_engineInterfacePtr->renderColouredBackground(redValue, greenValue, blueValue);

	// update the camera (probably don't need to do this each frame)
	m_engineInterfacePtr->setCamera(&m_camera);

	// draw the cube

	m_currentScene->render(m_engineInterfacePtr);
	
}

/*void Game::saveLevel(std::string levelFile)
{
	ofstream outputFile;

	outputFile.open(levelFile, ios_base::out);

	if (outputFile.is_open())
	{
		numCubesToRead = m_currentScene->getCubes()->size();
		outputFile << "Number of cubes: " << numCubesToRead << "\n";
		for (int i = 0; i < numCubesToRead; i++)
		{
			outputFile << "Cube " << i << "\n";
			outputFile << m_currentScene->getCubes()->at(i).getComponent<TransformComponent>()->m_position.x
				<< m_currentScene->getCubes()->at(i).getComponent<TransformComponent>()->m_position.y
				<< m_currentScene->getCubes()->at(i).getComponent<TransformComponent>()->m_position.z << "\n";

			outputFile << m_currentScene->getCubes()->at(i).getComponent<TransformComponent>()->m_orientation.w
				<< m_currentScene->getCubes()->at(i).getComponent<TransformComponent>()->m_orientation.x
				<< m_currentScene->getCubes()->at(i).getComponent<TransformComponent>()->m_orientation.y
				<< m_currentScene->getCubes()->at(i).getComponent<TransformComponent>()->m_orientation.z << "\n";

			outputFile << m_currentScene->getCubes()->at(i).getComponent<TransformComponent>()->m_scale.x
				<< m_currentScene->getCubes()->at(i).getComponent<TransformComponent>()->m_scale.y
				<< m_currentScene->getCubes()->at(i).getComponent<TransformComponent>()->m_scale.z << "\n";
		}

		outputFile.close();
	}

}

void Game::loadLevel(std::string levelFile)
{
		ifstream inputFile;
		inputFile.open(levelFile, ios_base::in);

		if (inputFile.is_open())
		{
			std::getline(inputFile, s);
			ss.str(s);
			ss.ignore(17);0
			ss >> numCubesToRead;

			m_currentScene->getCubes()->resize(numCubesToRead);
			ss.clear();

			for (int i = 0; i < numCubesToRead; i++)
			{
				//skip first line
				std::getline(inputFile, s);

				// read in pos
				std::getline(inputFile, s);
				ss.clear();
				ss.str(s);
				ss >> x >> y >> z;
				glm::vec3 pos(x, y, z);

				// read in orient
				std::getline(inputFile, s);
				ss.clear();
				ss.str(s);
				ss >> w >> x >> y >> z;
				glm::quat orient(w, x, y, z);

				//read in scale
				std::getline(inputFile, s);
				ss.clear();
				ss.str(s);
				ss >> x >> y >> z;
				glm::vec3 scale(x, y, z);


				m_currentScene->getCubes()->at(i).addComponent(new TransformComponent(pos, orient, scale));

			}
		}
}*/

