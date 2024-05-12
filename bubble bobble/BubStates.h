#pragma once
#include "StateMachine.h"
namespace dae {

	class BubState : public State
	{
	public:
		virtual ~BubState() override;
		virtual State* handleInput(GameObject& gameObject) override ;
		virtual State* update(GameObject& gameObject) override;
		virtual void enter(GameObject& gameObject) override;
	private:

	};
}
