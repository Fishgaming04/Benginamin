#include "EnemyStates.h"
#include "TextComponent.h"


namespace dae {

	State* EnemyWalkingState::update(GameObject& gameObject, double deltaTime)
	{
		if (m_IsDirtyMovement || !m_MoveCommand)
		{
			delete m_MoveCommand;
			if (m_IsGoingLeft)
				m_MoveCommand = new MoveCommand{ &gameObject, glm::vec3{-1.f,0.f,0.f}, m_Speed };
			else
				m_MoveCommand = new MoveCommand{ &gameObject, glm::vec3{1.f,0.f,0.f}, m_Speed };
		}

		if (m_IsDirtyTexture)
		{
			gameObject.GetComponent<TextureComponent>()->SetTexture(m_TextureWalking);
			m_IsDirtyTexture = false;
		}

		m_MoveCommand->Execute(static_cast<float>(deltaTime));

		
		return nullptr;
	}

	void EnemyWalkingState::enter(GameObject& gameObject)
	{
		if (m_TextureWalking) {
			gameObject.GetComponent<TextureComponent>()->SetTexture(m_TextureWalking);
		}
	}

	void EnemyWalkingState::exit(GameObject&)
	{
		delete m_MoveCommand;
		m_MoveCommand = nullptr;
	}

	State* EnemyClimbingState::update(GameObject& gameObject, double deltaTime)
	{
		if (m_IsDirtyMovement || !m_MoveCommand)
		{
			delete m_MoveCommand;
			if (m_IsGoingUp)
				m_MoveCommand = new MoveCommand{ &gameObject, glm::vec3{0.f, -1.0f ,0.f}, m_Speed };
			else
				m_MoveCommand = new MoveCommand{ &gameObject, glm::vec3{0.f,1.0f,0.f}, m_Speed };
		}

		if (m_IsDirtyTexture)
		{
			gameObject.GetComponent<TextureComponent>()->SetTexture(m_TextureClimb);
			m_IsDirtyTexture = false;
		}

		m_MoveCommand->Execute(static_cast<float>(deltaTime));


		return nullptr;
	}

	void EnemyClimbingState::enter(GameObject& gameObject)
	{
		if (m_TextureClimb) {
			gameObject.GetComponent<TextureComponent>()->SetTexture(m_TextureClimb);
		}
	}

	void EnemyClimbingState::exit(GameObject&)
	{
		delete m_MoveCommand;
		m_MoveCommand = nullptr;
	}

	State* EnemyHitState::update(GameObject& gameObject, double)
	{
		if (m_IsDirtyTexture)
		{
			gameObject.GetComponent<TextureComponent>()->SetTexture(m_TextureHit);
			m_IsDirtyTexture = false;
		}

		return nullptr;
	}

	void EnemyHitState::enter(GameObject& gameObject)
	{
		if (m_TextureHit){
			gameObject.GetComponent<TextureComponent>()->SetTexture(m_TextureHit);
		}
	}

	void EnemyHitState::exit(GameObject&)
	{
	}
}