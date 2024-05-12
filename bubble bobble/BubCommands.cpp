#include "BubCommands.h"

dae::BubWalkCommand::~BubWalkCommand()
{
}

void dae::BubWalkCommand::Execute(float)
{
	if (!dynamic_cast<BubBubbleState*>(GetStateMachine()->GetState()) || !dynamic_cast<BubDeadState*>(GetStateMachine()->GetState()) || !dynamic_cast<BubDeadState*>(GetStateMachine()->GetState()))  {
		GetStateMachine()->SetState(GetState(), *GetGameObject());
		
	}
}

dae::BubJumpCommand::~BubJumpCommand()
{
}

void dae::BubJumpCommand::Execute(float)
{
	if (!dynamic_cast<BubBubbleState*>(GetStateMachine()->GetState()) || !dynamic_cast<BubDeadState*>(GetStateMachine()->GetState()) || !dynamic_cast<BubJumpingState*>(GetStateMachine()->GetState())) {
		GetStateMachine()->SetState(GetState(), *GetGameObject());
	}
}

dae::BubShootCommand::~BubShootCommand()
{
}

void dae::BubShootCommand::Execute(float)
{
	if (!dynamic_cast<BubBubbleState*>(GetStateMachine()->GetState()) || !dynamic_cast<BubDeadState*>(GetStateMachine()->GetState()) || !dynamic_cast<BubShootingState*>(GetStateMachine()->GetState())) {
		GetStateMachine()->SetState(GetState(), *GetGameObject());
	}
}

void dae::BubIdleCommand::Execute(float)
{
	if (!dynamic_cast<BubBubbleState*>(GetStateMachine()->GetState()) || !dynamic_cast<BubDeadState*>(GetStateMachine()->GetState()) || !dynamic_cast<BubIdleState*>(GetStateMachine()->GetState())) {
		//check Velocity if 0
		GetStateMachine()->SetState(GetState(), *GetGameObject());
	}
}

dae::BubHitCommand::~BubHitCommand()
{
}

void dae::BubHitCommand::Execute(float)
{
	if (!dynamic_cast<BubBubbleState*>(GetStateMachine()->GetState()) || !dynamic_cast<BubDeadState*>(GetStateMachine()->GetState()) || !dynamic_cast<BubDeadState*>(GetStateMachine()->GetState())) {
		GetStateMachine()->SetState(GetState(), *GetGameObject());
	}
}
