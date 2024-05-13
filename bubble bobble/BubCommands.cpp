#include "BubCommands.h"

dae::BubWalkCommand::BubWalkCommand(GameObject* object)
	: StateCommand(object)
{}


dae::BubWalkCommand::~BubWalkCommand()
{
}

void dae::BubWalkCommand::Execute(float)
{
	auto stateMachine{ GetGameObject()->GetComponent<StateMachine>() };
	if (!dynamic_cast<BubBubbleState*>(stateMachine->GetState()) || !dynamic_cast<BubDeadState*>(stateMachine->GetState()) || !dynamic_cast<BubWalkingState*>(stateMachine->GetState()))  {
		stateMachine->SetState(new BubWalkingState{});
		
	}
}

dae::BubJumpCommand::BubJumpCommand(GameObject* object)
	: StateCommand(object)
{}


dae::BubJumpCommand::~BubJumpCommand()
{
}

void dae::BubJumpCommand::Execute(float)
{
	auto stateMachine{ GetGameObject()->GetComponent<StateMachine>() };
	if (!dynamic_cast<BubBubbleState*>(stateMachine->GetState()) || !dynamic_cast<BubDeadState*>(stateMachine->GetState()) || !dynamic_cast<BubJumpingState*>(stateMachine->GetState())) {
		stateMachine->SetState(new BubJumpingState{});
	}
}

dae::BubShootCommand::BubShootCommand(GameObject* object)
	: StateCommand(object)
{}

dae::BubShootCommand::~BubShootCommand()
{
}

void dae::BubShootCommand::Execute(float)
{
	auto stateMachine{ GetGameObject()->GetComponent<StateMachine>() };
	if (!dynamic_cast<BubBubbleState*>(stateMachine->GetState()) || !dynamic_cast<BubDeadState*>(stateMachine->GetState()) || !dynamic_cast<BubShootingState*>(stateMachine->GetState())) {
		stateMachine->SetState(new BubShootingState{});
	}
}

dae::BubIdleCommand::BubIdleCommand(GameObject* object)
	: StateCommand(object)
{}

dae::BubIdleCommand::~BubIdleCommand()
{
}

void dae::BubIdleCommand::Execute(float)
{
	auto stateMachine{ GetGameObject()->GetComponent<StateMachine>() };
	if (!dynamic_cast<BubBubbleState*>(stateMachine->GetState()) || !dynamic_cast<BubDeadState*>(stateMachine->GetState()) || !dynamic_cast<BubIdleState*>(stateMachine->GetState())) {
		//check Velocity if 0
		stateMachine->SetState(new BubIdleState{});
	}
}

dae::BubHitCommand::BubHitCommand(GameObject* object)
	: StateCommand(object)
{}

dae::BubHitCommand::~BubHitCommand()
{
}

void dae::BubHitCommand::Execute(float)
{
	auto stateMachine{ GetGameObject()->GetComponent<StateMachine>() };
	if (!dynamic_cast<BubBubbleState*>(stateMachine->GetState()) || !dynamic_cast<BubDeadState*>(stateMachine->GetState())) {
		stateMachine->SetState(new BubDeadState{});
	}
}
