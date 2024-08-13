#include "PlayerComponent.h"
#include "PeterStates.h"
#include "Observers.h"
namespace dae {


	PlayerComponent::PlayerComponent(GameObject* obj)
		: UpdatingComponent(obj)
		, m_HitTimer(0.0)
		, m_HitDuration(1.0)
		, m_Subject(std::make_shared<Subject>())
	{
	}

	void PlayerComponent::Update(double elapsedTime)
	{
		if (dynamic_cast<PeterHitState*>(GetGameObject()->GetComponent<StateMachine>()->GetState()))
		{
			m_HitTimer += elapsedTime;
			m_Subject->Notify(Event::PlayerHit, m_Subject.get(), m_lives > 0 );
			if (m_HitTimer > m_HitDuration)
			{
				m_HitTimer = 0;
				if (m_lives <= 0)
				{
					m_Subject->Notify(Event::PlayerDied, m_Subject.get(), m_lives > 0);
				}
				else
				{
					GetGameObject()->GetComponent<StateMachine>()->SetState(new PeterIdleState());
					--m_lives;
					SetSpawnPosition(m_SpawnPosition);
				}
			}
		}
	}

	void PlayerComponent::SetSpawnPosition(const glm::vec3& position)
	{
		m_SpawnPosition = position;
		GetGameObject()->setLocalPosition(m_SpawnPosition);
	}
}
