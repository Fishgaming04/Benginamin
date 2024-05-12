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
		virtual void handleInput();
		virtual void update() = 0;
	private:
		State* m_State;
		GameObject* m_GameObject;
	};
}