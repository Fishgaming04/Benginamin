#include "PeterStates.h"
#include "ResourceManager.h"
#include "TextureComponent.h"

namespace dae {
	//idle
	State* PeterIdleState::update(GameObject&, double)
	{


		return nullptr;
	}

	void PeterIdleState::enter(GameObject& gameObject)
	{
		auto& recourceManager = dae::ResourceManager::GetInstance();
		gameObject.GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("BurgerTime/Sprites/Peter.png"));

		
	}

	void PeterIdleState::exit(GameObject&) 
	{
	}

	//walking
	State* PeterWalkingState::update(GameObject&, double)
	{
		return nullptr;
	}

	void PeterWalkingState::enter(GameObject& gameObject)
	{
		auto& recourceManager = dae::ResourceManager::GetInstance();
		gameObject.GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("BurgerTime/Sprites/PeterWalk.png"));
	}

	void PeterWalkingState::exit(GameObject&)
	{
	}


	//climbing
	State* PeterClimbingState::update(GameObject&, double )
	{
		return nullptr;
	}

	void PeterClimbingState::enter(GameObject& gameObject)
	{
		auto& recourceManager = dae::ResourceManager::GetInstance();
		gameObject.GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("BurgerTime/Sprites/PeterClimb.png"));
	}

	void PeterClimbingState::exit(GameObject&)
	{
	}

	//hit
	State* PeterHitState::update(GameObject&, double)
	{
		return nullptr;
	}

	void PeterHitState::enter(GameObject& gameObject)
	{
		auto& recourceManager = dae::ResourceManager::GetInstance();
		gameObject.GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("BurgerTime/Sprites/Peter.png"));
	}

	void PeterHitState::exit(GameObject&)
	{
	}

}