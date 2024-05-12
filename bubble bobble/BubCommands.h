#pragma once
#include "Command.h"
#include "GameObject.h"
#include "BubStates.h"
#include "StateMachine.h"


namespace dae {

	class BubWalkCommand : public Command
	{
	public:
		virtual ~BubWalkCommand() override;
		virtual void Execute(float) override;

	};
}
