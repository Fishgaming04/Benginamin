#include "EnemyComponent.h"
#include "EnemyStates.h"
#include <iostream>
#include "CounterIncreaseObserver.h"
namespace dae
{
	EnemyComponent::EnemyComponent(GameObject* obj)
		:UpdatingComponent(obj)
		, m_Points(0)
		, m_IsGoingLeft(true)
		, m_IsHit(false)
		, m_HitTimer(0)
		, m_HitDuration(0)
		, m_Speed(0)
		, m_Player(nullptr)
		, m_TextureClimb(nullptr)
		, m_TextureWalking(nullptr)
		, m_TextureHit(nullptr)
		, m_SpawnPosition(0, 0, 0)
		, m_StateMachine(nullptr)
	{
		if (!GetGameObject()->GetComponent<StateMachine>())
		{
			GetGameObject()->AddComponent<StateMachine>();
		}
		m_StateMachine = GetGameObject()->GetComponent<StateMachine>();
	}

	void EnemyComponent::Update(double elapsedTime)
	{
		if (m_IsHit) {
			if (m_HitTimer > m_HitDuration)
			{
				m_IsHit = false;
				if (m_SpawnPosition.x <= 0) {
					m_IsGoingLeft = false;
				}
				else {
					m_IsGoingLeft = true;
				}
				m_StateMachine->SetState(new EnemyWalkingState());
				auto state{ dynamic_cast<EnemyWalkingState*>(m_StateMachine->GetState()) };

				state->SetTexture(m_TextureWalking);
				state->SetSpeed(m_Speed);
				state->SetTexture(m_TextureWalking);
				GetGameObject()->setLocalPosition(m_SpawnPosition);
				m_Subject->Notify(Event::UpdateCounter, m_Subject, UpdateCounterEvent{ "Points", m_Points });
				m_HitTimer = 0;
			}
			else if(!GetGameObject()->GetParent() || GetGameObject()->GetParent()->getTag() != "ParentTopping")
			{
				m_HitTimer += elapsedTime;
			}
		}
		//std::cout << "Global: " << GetGameObject()->GetTransform()->getWorldposition().x << " " << GetGameObject()->GetTransform()->getWorldposition().y << " " << GetGameObject()->GetTransform()->getWorldposition().z << std::endl;
		//std::cout << "Local: " << GetGameObject()->GetTransform()->getLocalposition().x << " " << GetGameObject()->GetTransform()->getLocalposition().y << " " << GetGameObject()->GetTransform()->getLocalposition().z << std::endl;
	}

	void dae::EnemyComponent::TurnAround()
	{
		m_IsGoingLeft = !m_IsGoingLeft;
		//std::cout << "Enemy direction left: " << m_IsGoingLeft << "\n";
		if (dynamic_cast<EnemyWalkingState*>(m_StateMachine->GetState())) {
			//std::cout << "Enemy walking state \n";
			auto state{ dynamic_cast<EnemyWalkingState*>(m_StateMachine->GetState()) };
			state->SetIsGoingLeft(m_IsGoingLeft);
			state->SetTexture(m_TextureWalking);
			state->SetSpeed(m_Speed);
		}
	}

	void EnemyComponent::Hit()
	{
		if (m_IsHit) return;
		m_IsHit = true;
		m_HitTimer = 0;
		m_StateMachine->SetState(new EnemyHitState());
		if (!GetGameObject()->GetParent() || GetGameObject()->GetParent()->getTag() != "ParentTopping") {
			GetGameObject()->setLocalPosition(m_SpawnPosition);
		}
		dynamic_cast<EnemyHitState*>(m_StateMachine->GetState())->SetTexture(m_TextureHit);
	}

	void EnemyComponent::TouchingGround()
	{
		if (!dynamic_cast<EnemyWalkingState*>(m_StateMachine->GetState())) {

			m_StateMachine->SetState(new EnemyWalkingState());
			auto state{ dynamic_cast<EnemyWalkingState*>(m_StateMachine->GetState()) };
			
			state->SetTexture(m_TextureWalking);
			state->SetSpeed(m_Speed);
			state->SetTexture(m_TextureWalking);
			glm::vec3 posEnemy{ GetGameObject()->GetTransform()->getWorldposition() };
			glm::vec3 posPlayer{ m_Player->GetTransform()->getWorldposition() };
			if (posEnemy.x < posPlayer.x) {
				m_IsGoingLeft = false;
			}
			else {
				m_IsGoingLeft = true;
			}
			state->SetIsGoingLeft(m_IsGoingLeft);
			//std::cout << "Enemy direction left: " << m_IsGoingLeft << " Walkstate\n";
		}
	}

	void EnemyComponent::IsOverlappingWithLadder(int LadderDirections)
	{
		if (!dynamic_cast<EnemyClimbingState*>(m_StateMachine->GetState())) {

			m_StateMachine->SetState(new EnemyClimbingState());
			auto state{ dynamic_cast<EnemyClimbingState*>(m_StateMachine->GetState()) };
			state->SetTexture(m_TextureClimb);
			state->SetSpeed(m_Speed);

			glm::vec3 posEnemy{ GetGameObject()->GetTransform()->getWorldposition() };
			glm::vec3 posPlayer{ m_Player->GetTransform()->getWorldposition() };
			if (LadderDirections == 1) {
				state->SetIsGoingUp(true);
			}
			else if (LadderDirections == 2) {
				state->SetIsGoingUp(false);
			}
			else if (LadderDirections == 3) {
				if (posEnemy.y > posPlayer.y) {
					state->SetIsGoingUp(true);
				}
				else {
					state->SetIsGoingUp(false);
				}
			}
			else
			{
				std::cout << "Invalid ladder direction \n";
			}
		}
	}
	
	void EnemyComponent::SetTextureClimb(const std::shared_ptr<Texture2D>& texture)
	{
		m_TextureClimb = texture;
	}

	void EnemyComponent::SetTextureWalking(const std::shared_ptr<Texture2D>& texture)
	{
		m_TextureWalking = texture;
	}

	void EnemyComponent::SetTextureHit(const std::shared_ptr<Texture2D>& texture)
	{
		m_TextureHit = texture;
	}

	void EnemyComponent::SetSpawnPosition(const glm::vec3& position)
	{
		m_SpawnPosition = position;
		GetGameObject()->setLocalPosition(m_SpawnPosition);
		if (m_SpawnPosition.x <= 0) {
			m_IsGoingLeft = false;
		}
		else {
			m_IsGoingLeft = true;
		}
	}
}