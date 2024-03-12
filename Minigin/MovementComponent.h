#pragma once
#include "Components.h"
#include "InputManager.h"


namespace dae {


	class MovementComponent: public UpdatingComponent
	{
	public:
        MovementComponent(GameObject* obj);
        virtual ~MovementComponent() {}

        virtual void Update(double elapsedTime) override;

        MovementComponent(const MovementComponent& other) = delete;
        MovementComponent(MovementComponent&& other) = delete;
        MovementComponent& operator=(const MovementComponent& other) = delete;
        MovementComponent& operator=(MovementComponent&& other) = delete;

	private:
        InputManager m_InputManager;


	};


}