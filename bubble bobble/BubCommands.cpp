#include "BubCommands.h"
#include "BubbleManager.h"
dae::BubWalkCommand::BubWalkCommand(GameObject* object)
	: GameObjectCommand(object)
{}


dae::BubWalkCommand::~BubWalkCommand()
{
}

void dae::BubWalkCommand::Execute(float)
{
	auto stateMachine{ GetGameObject()->GetComponent<StateMachine>() };
	if (!dynamic_cast<BubBubbleState*>(stateMachine->GetState()) && !dynamic_cast<BubDeadState*>(stateMachine->GetState()) && !dynamic_cast<BubWalkingState*>(stateMachine->GetState()) && !dynamic_cast<BubJumpingState*>(stateMachine->GetState()))  {
		stateMachine->SetState(new BubWalkingState{});
		
	}
}

dae::BubJumpCommand::BubJumpCommand(GameObject* object)
	: GameObjectCommand(object)
{}


dae::BubJumpCommand::~BubJumpCommand()
{
}

void dae::BubJumpCommand::Execute(float)
{
	auto stateMachine{ GetGameObject()->GetComponent<StateMachine>() };
	if (!dynamic_cast<BubBubbleState*>(stateMachine->GetState()) && !dynamic_cast<BubDeadState*>(stateMachine->GetState()) && !dynamic_cast<BubJumpingState*>(stateMachine->GetState())) {
		stateMachine->SetState(new BubJumpingState{});

	}
}

dae::BubShootCommand::BubShootCommand(GameObject* object)
	: GameObjectCommand(object)
{}

dae::BubShootCommand::~BubShootCommand()
{
}

void dae::BubShootCommand::Execute(float)
{
	auto stateMachine{ GetGameObject()->GetComponent<StateMachine>() };
	if (!dynamic_cast<BubBubbleState*>(stateMachine->GetState()) && !dynamic_cast<BubDeadState*>(stateMachine->GetState())) {
		stateMachine->SetState(new BubShootingState{});
		GetGameObject()->GetComponent<BubbleManager>()->Shoot();
	}
}

dae::BubIdleCommand::BubIdleCommand(GameObject* object)
	: GameObjectCommand(object)
{}

dae::BubIdleCommand::~BubIdleCommand()
{
}

void dae::BubIdleCommand::Execute(float)
{
	auto stateMachine{ GetGameObject()->GetComponent<StateMachine>() };
	if (!dynamic_cast<BubBubbleState*>(stateMachine->GetState()) && !dynamic_cast<BubDeadState*>(stateMachine->GetState()) && !dynamic_cast<BubIdleState*>(stateMachine->GetState()) && !dynamic_cast<BubJumpingState*>(stateMachine->GetState())) {
		//check Velocity if 0
		stateMachine->SetState(new BubIdleState{});
	}
}

dae::BubHitCommand::BubHitCommand(GameObject* object)
	: GameObjectCommand(object)
{}

dae::BubHitCommand::~BubHitCommand()
{
}

void dae::BubHitCommand::Execute(float)
{
	auto stateMachine{ GetGameObject()->GetComponent<StateMachine>() };
	if (!dynamic_cast<BubBubbleState*>(stateMachine->GetState()) && !dynamic_cast<BubDeadState*>(stateMachine->GetState())) {
		stateMachine->SetState(new BubDeadState{});
	}
}
