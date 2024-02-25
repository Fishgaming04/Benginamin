#include "Components.h"

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

}
