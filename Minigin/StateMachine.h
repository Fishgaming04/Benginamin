#pragma once
#include "GameObject.h"
namespace dae {

	class State
	{
	public:
		virtual ~State() {}
		virtual State* handleInput(GameObject& gameObject) {};
		virtual State* update(GameObject& gameObject) {};
		virtual void enter(GameObject& gameObject) {};
	};

	class StateMachine
	{
	public:
		virtual void handleInput(GameObject& gameObject);
		virtual void update(GameObject& gameObject);
		void SetState(State* state, GameObject& gameObject);
		State* GetState();
		~StateMachine();
	private:
		State* m_State;
	};
}