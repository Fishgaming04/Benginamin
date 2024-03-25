#include "Components.h"
#include "GameObject.h"
namespace dae {

	Component::Component(GameObject* obj)
	:m_ObjectPtr(obj)
	{	
	}

	GraphicalComponent::GraphicalComponent(GameObject* obj) 
	:Component(obj)
	{
	}
	
	UpdatingComponent::UpdatingComponent(GameObject* obj)
	:Component(obj)
	{
	}

	ObserverComponent::ObserverComponent(GameObject* obj)
		:Component(obj)
		,m_TheWatched{}
	{
	}

	ObserverComponent::~ObserverComponent()
	{
		for (auto obj : m_TheWatched)
		{
			obj->RemoveObserver(this);
		}
	}

	void ObserverComponent::removeWatched(GameObject* actor)
	{
		if (actor) {
			auto it = std::find(m_TheWatched.begin(), m_TheWatched.end(), actor);
			if (it != m_TheWatched.end())
			{
				m_TheWatched.erase(it);
			}
		}
	}

	void ObserverComponent::AddIsWatching(GameObject* object)
	{
		if (object) {
			m_TheWatched.push_back(object);
			object->AddObserver(this);
		}
	}
}
