#include "BubStates.h"
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

	State* BubDeadState::update(GameObject& )
	{

		//check amount of lives
		//if lives > 0, return new BubbleIdleState

		return nullptr;
	}

	void BubDeadState::enter(GameObject& gameObject)
	{
		auto& recourceManager = dae::ResourceManager::GetInstance();
		gameObject.GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("BubHit.png"));
	}

	void BubDeadState::exit(GameObject& )
	{
	}
}