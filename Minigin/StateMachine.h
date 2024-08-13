#pragma once
#include "GameObject.h"
#include "Components.h"
namespace dae {

	class State
	{
	public:
		virtual ~State() = default;
		virtual State* update(GameObject& , double deltaTime) = 0;
		virtual void enter(GameObject& ) = 0;
		virtual void exit(GameObject&) = 0;
	};


	class StateMachine : public UpdatingComponent
	{
	public:
		StateMachine(GameObject* GameObj);
		virtual void Update(double deltaTime) override;
		void SetState(State* state);
		State* GetState();
		~StateMachine();
	private:
		State* m_State;
	};
}