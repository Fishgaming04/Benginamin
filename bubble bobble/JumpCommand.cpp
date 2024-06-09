#include "JumpCommand.h"
#include "GameObject.h"
#include "GravityComponent.h"
#include "StateMachine.h"
#include <iostream>
#include "BubStates.h"
namespace dae
{

dae::JumpCommand::JumpCommand(GameObject* object, float jumpheight)
	:StateCommand(object)
	, m_JumpHeight(jumpheight)
{
}

void JumpCommand::Execute(float)
{
	double momentum{ GetGameObject()->GetComponent<GravityComponent>()->GetMomentum() };
	if (dynamic_cast<BubJumpingState*>(GetGameObject()->GetComponent<StateMachine>()->GetState()))
	{
		return;
	}
	else if (momentum < m_maxMomentum && momentum >= 0 || momentum > -m_maxMomentum && momentum <= 0)
	{
		GetGameObject()->GetComponent< GravityComponent>()->SetMomentum(-m_JumpHeight);	
		GetGameObject()->GetComponent<StateMachine>()->SetState(new BubJumpingState{});
		std::cout << "Jumping\n";
	}
}

dae::JumpCommand::~JumpCommand()
{
}

}
