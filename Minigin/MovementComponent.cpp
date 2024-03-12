#include "MovementComponent.h"
#include "InputManager.h"
//#include "Singleton.h"


namespace dae {
	

	MovementComponent::MovementComponent(GameObject* obj)
		:UpdatingComponent(obj)
	{
	}

	void MovementComponent::Update(double elapsedTime)
	{
		InputManager cat;
		cat.GetInstance();
	}

}