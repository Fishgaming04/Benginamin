#include "BubStates.h"
#include "GameObject.h"
#include "TextureComponent.h"
#include "ResourceManager.h"
#include "CounterComponent.h"
#include "StateMachine.h"
#include "GravityComponent.h"
namespace dae{

	State* BubWalkingState::update(GameObject& )
	{
		//check velocity
		//velocity is not 0, return new BubbleJumpState


		return nullptr;
	}

	void BubWalkingState::enter(GameObject& gameObject)
	{
		auto& recourceManager = dae::ResourceManager::GetInstance();
		gameObject.GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("Character1.png"));
	}

	void BubWalkingState::exit(GameObject& )
	{
	}

	State* BubIdleState::update(GameObject& )
	{

		//check velocity
		//velocity is not 0, return new BubbleJumpState
		
		return nullptr;
	}

	void BubIdleState::enter(GameObject& gameObject)
	{
		auto& recourceManager = dae::ResourceManager::GetInstance();
		gameObject.GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("Character1.png"));
	}

	void BubIdleState::exit(GameObject& )
	{
	}

	State* BubJumpingState::update(GameObject& )
	{
		//check velocity
		//velocity is 0, return new BubbleIdleState
		return nullptr;
	}

	void BubJumpingState::enter(GameObject& gameObject)
	{
		auto& recourceManager = dae::ResourceManager::GetInstance();
		gameObject.GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("BubJump.png"));
	}

	void BubJumpingState::exit(GameObject& )
	{
	}

	State* BubBubbleState::update(GameObject& )
	{
		//move bubble towards next level
		return nullptr;
	}

	void BubBubbleState::enter(GameObject& gameObject)
	{
		auto& recourceManager = dae::ResourceManager::GetInstance();
		gameObject.GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("BubBubble.png"));
	}

	void BubBubbleState::exit(GameObject& )
	{
	}

	State* BubShootingState::update(GameObject& )
	{
		//shoot bubble
		return nullptr;
	}

	void BubShootingState::enter(GameObject& gameObject)
	{
		auto& recourceManager = dae::ResourceManager::GetInstance();
		gameObject.GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("BubShooting.png"));

	}

	void BubShootingState::exit(GameObject& )
	{
	}

	State* BubDeadState::update(GameObject& gameObject)
	{

		int count = gameObject.GetComponent<CountingComponent>()->GetCounter("Lives");
		if (count >= 0) {
			gameObject.GetComponent<StateMachine>()->SetState(new BubIdleState());
		}
		else
		{
			gameObject.setLocalPosition(224, 224, 0);
			gameObject.GetComponent<GravityComponent>()->SetMomentum(0);
		}
		//check amount of lives
		//if lives > 0, return new BubbleIdleState

		return nullptr;
	}

	void BubDeadState::enter(GameObject& gameObject)
	{
		auto& recourceManager = dae::ResourceManager::GetInstance();
		gameObject.GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("BubHit.png"));
		int count = gameObject.GetComponent<CountingComponent>()->GetCounter("Lives");
		if (count > 0){
		gameObject.GetComponent<CountingComponent>()->SetCounter("Lives", count - 1);
		gameObject.setLocalPosition(48, 432, 0);
		}
		else
		{
			gameObject.setLocalPosition(224, 224, 0);
		}
	}

	void BubDeadState::exit(GameObject& )
	{
	}
}