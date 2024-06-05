#pragma once
#include "GameObject.h"
#include "Components.h"
namespace dae {

	class State
	{
	public:
		virtual ~State() = default;
		//virtual State* handleInput(GameObject& gameObject) {};
		virtual State* update(GameObject& ) = 0;
		virtual void enter(GameObject& ) = 0;
		virtual void exit(GameObject&) = 0;
	};


	class StateMachine : public UpdatingComponent
	{
	public:
		//virtual void handleInput(GameObject& gameObject);
		StateMachine(GameObject* GameObj);
		virtual void Update(double) override;
		void SetState(State* state);
		State* GetState();
		~StateMachine();
	private:
		State* m_State;
	};
}