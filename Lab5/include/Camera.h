/*! \file Camera.h
* Class controls the game engine cameras
*/

#pragma once
#include "Component.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>

class Camera : public Component //! Camera handles all of the cameras in the game and is a component of Component
{
public:
	glm::vec3 m_position;//!< m_position is a vector storing the camera position
	glm::quat m_orientation;//!< m_orientation is a quaternion storing the cameras orientation 
	float m_fov;//!< m_fov stores the games field of view

	Camera() : m_position(0.f, 0.f, -10.f), m_orientation(1, 0, 0, 0), m_fov(45) {}
	Camera(const glm::vec3& pos) : m_position(pos), m_orientation(1, 0, 0, 0), m_fov(90) {}
	Camera(const glm::vec3& pos, const glm::quat& orient) : m_position(pos), m_orientation(orient), m_fov(90) {}

	void lookAt(const glm::vec3& target) { m_orientation = (glm::toQuat(glm::lookAt(m_position, target, glm::vec3(0, 1, 0)))); }//!Sets the direction of the camera
	/*!
		\param target target is the vecotr containing the position the camera should be looking at
	*/
	const glm::vec3& position() const { return m_position; } //! Gets the position of the camera

	const glm::quat& orientation() const { return m_orientation; } //!Gets the orientation if the camera

	glm::mat4 getViewMatrix() const { return glm::translate(glm::mat4_cast(m_orientation), m_position); }//! Gets the current view matrix

	void translate(const glm::vec3 &v) { m_position += v * m_orientation; } //!Translates the camera using a Vector
	/*!
	\param v v is the vector that stores the movement
	*/
	void translate(float x, float y, float z) { m_position += glm::vec3(x, y, z) * m_orientation; } //!Translates the camera using 3 floats
	/*!
	\param x x is the x value of the movement
	\param y y is the x value of the movement
	\param z z is the x value of the movement
	*/
	void rotate(float angle, const glm::vec3 &axis) { m_orientation *= glm::angleAxis(angle, axis * m_orientation); }//!Rotates the camera using a Vector
																													 /*!
																													 \param angle angle is the angle that stores the rotation
																													 \param axis axis is the axis on which this rotation should take place
																													 */
	void rotate(float angle, float x, float y, float z) { m_orientation *= glm::angleAxis(angle, glm::vec3(x, y, z) * m_orientation); }//!Rotates the camera using 3 floats
																																	   /*!
																																	   \param angle angle is the angle that stores the rotation
																																	   \param x x is the x value of the rotation
	\param y y is the x value of the rotation
	\param z z is the x value of the rotation
																																	   */

	void yaw(float angle) { rotate(angle, 0.0f, 1.0f, 0.0f); } //! Handles the yaw of the camera (Y axis)
															   /*!
															   \param angle angle is the angle that stores the rotates
															   */
	void pitch(float angle) { rotate(angle, 1.0f, 0.0f, 0.0f); }//! Handles the pitch of the camera (X axis)
																/*!
																\param angle angle is the angle that stores the rotates
																*/
	void roll(float angle) { rotate(angle, 0.0f, 0.0f, 1.0f); }//! Handles the roll of the camera (Z axis)
															   /*!
															   \param angle angle is the angle that stores the rotates
															   */

	void setFOV(float fov) { m_fov = fov; }//! Sets the fov of the camera
										   /*!
										   \param fov fov stores the fov set by m_fov
										   */

	void OnUpdate(float dt) override//! Updates the camera
	{
	}
	void OnMessage(const std::string m) override //! Checks form messages to the camera
	{
	}
};
