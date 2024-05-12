#pragma once
#include "GameObject.h"
#include "Components.h"
namespace dae {

	class State
	{
	public:
		virtual ~State() {}
		//virtual State* handleInput(GameObject& gameObject) {};
		virtual State* update(GameObject& ) {};
		virtual void enter(GameObject& ) {};
		virtual void exit(GameObject& ) {}
	};



	class StateMachine : public UpdatingComponent
	{
	public:
		//virtual void handleInput(GameObject& gameObject);
		virtual void update();
		void SetState(State* state);
		State* GetState();
		~StateMachine();
	private:
		State* m_State;
	};
}