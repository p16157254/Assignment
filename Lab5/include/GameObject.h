/*! \file GameObject.h
* Class controls the game engines game objects
*/

#pragma once
#include "Component.h"
#include "Camera.h"
#include <unordered_map>
#include <typeindex>

class GameObject //< GameObject class handles all of the engines Game Objects
{
public:
	template <typename T> //< T is a template applied to all game objects 
	T* getComponent() 
	{

		auto iter = m_components.find(typeid(T));

		if(iter != std::end(m_components))
		{
			// if found dynamic cast the component pointer and return it
			return dynamic_cast<T*>(iter->second);
		}
		
		// return null if we don't have a component of that type
		return nullptr;
		
	}

	template <typename T>
	void addComponent(T* comp) //! This adds a new component to a Game Object
		/*!
			\param comp comp is the component being added
		*/
	{
		// add the component to unoreder map with hash of its typeid
		m_components[typeid(T)] = comp;
	}
	
private:
	std::unordered_map<std::type_index, Component*> m_components; //< m_components is an unordered map of type indexes and pointeres to components
};

