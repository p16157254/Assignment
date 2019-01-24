/*! \file GLFW_EngineCore.h
* Class controls the game engines core functions
*/

#pragma once
#include "IEngineCore.h"
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <glm/mat4x4.hpp>
#include "Camera.h"

class Game;

class GLFW_EngineCore : public IEngineCore//! GLFW_EngineCore class handles the games engine core and is a component of IEngineCore
{
public:
	~GLFW_EngineCore() override;//!< Engine Core Constructor

	bool initWindow(int width, int height, std::string windowName) override;
	/*!
		\param width width of the game window
		\param height height of the game window
		\param windowName the name of the game window
	*/
	bool runEngine(Game& game) override;
	/*!
		\param Game Game is the actual game engine
	*/
	void renderColouredBackground(float r, float g, float b) override;
	/*!
		\param r r is the Red value in RGB
		\param g g is the Green value in RGB
		\param b b is the Blue value in RGB
	*/
	void setCamera(const Camera* cam) override;
	/*!
		\param cam cam is the game camera
	*/
	void drawCube(const glm::mat4& modelMatrix) override;
	/*!
		\param modelMatrix modelMatrix is a glm matrix that holds the model for rendering
	*/
	void drawModel(Model * model, glm::mat4 & modelMatrix);
	/*!
		\param model model is the actual game model
		\param modelMatrix modelMatrix is a glm matrix that holds the model for rendering
	*/

private:
	GLFWwindow* m_window; //!< m_window is the game window
	GLuint m_defaultShaderProgram; //!< m_defaultShaderProgram is the shader that is automatically applied if none is set
	
	static int m_screenWidth; //!< m_screenWidth is the width of the screen
	static int m_screenHeight; //!< m_screenHeight is the height of the screen
	static std::vector<bool> m_keyBuffer;  //!< m_keyBuffer is where the keyboard presses are stored
	static const int m_keyBufferSize = 400; //!< m_keyBufferSize is where the size of the key buffer is set
	static void mouseMoveCallbackEvent(GLFWwindow* window, double xPos, double yPos);//! Checks for mouse updates
	/*!
		\param window window is the game window
		\param xPos xPos is the X position of the mouse in the game window
		\param yPos yPos is is the Y position of the mouse in the game window
	*/
	static void keyCallbackEvent(GLFWwindow* window, int key, int scancode, int action, int mods);//!Checks for keyboard interaction
	/*!
	\param window window is the game window
	\param key key is the integer relating to the key previously pressed
	\param scancode scancode is the integer that stores a keys scancode
	\param action action is the integer that stores the action applied to a key e.g. key down
	\param mods mods is the integer that stores and modification applied to a key e.g. holding shift
	*/
	static void windowResizeCallbackEvent(GLFWwindow* window, int width, int height);//!Resizes the game window
	/*!
	\param window window is the game window
	\param width width is the width of the game window
	\param height height is is the height of the game window
	*/
	
	void setDefaultShaders();//! Sets the default shader
	void initCubeModel();//! Sets the vertices for a cube (not in use)
	static void cursorEnterCallback(GLFWwindow* window, int entered);//! Checks for mouse entry or exit
	/*!
		\param window window is the game window
		\param entered entered is the integer that stores whether the mouse has entered or exited the screen space
	*/

};

