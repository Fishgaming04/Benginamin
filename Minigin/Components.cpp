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
		,m_IsWatching{nullptr}
	{
	}
	ObserverComponent::~ObserverComponent()
	{
	}

	void ObserverComponent::SetIsWatching(GameObject* object)
	{
		if (m_IsWatching) {
			m_IsWatching->RemoveObserver(this);
		}
		m_IsWatching = object; 
		if (m_IsWatching) {
			m_IsWatching->AddObserver(this); 
		}
	}
}
