#include "EnemyCollisionComponent.h"
#include "CollisionSubject.h"
#include "EnemyComponent.h"
#include <iostream>

namespace dae {

	dae::CollisionEnemyComponent::CollisionEnemyComponent(GameObject* obj)
		: ObserverComponent(obj)
		, m_OverlappingWithLadder(false)
		, m_TouchingGround(false)
		, m_CanWalk(0)
	{
	}

	void CollisionEnemyComponent::Update(double)
	{

		if (!m_OverlappingWithLadderLastFrame && m_OverlappingWithLadder)
		{
 			int ladders{};
			if (m_LadderBottom) ++++ladders;
			if (m_LadderTop) ++ladders;
			//std::cout << "Ladder overlap: " << ladders << "\n";
			GetGameObject()->GetComponent<EnemyComponent>()->IsOverlappingWithLadder(ladders);
		}
		

		m_LadderBottom = false;
		m_LadderTop = false;
		m_OverlappingWithLadderLastFrame = m_OverlappingWithLadder;
		m_TouchingGroundLastFrame = m_TouchingGround;
		m_OverlappingWithLadder = false;
		m_TouchingGround = false;
		if (m_CanWalk < 0) {
			//GetGameObject()->GetComponent<EnemyComponent>()->TurnAround();
			m_OverlappingWithLadderLastFrame = true;
		}

		m_CanWalk = 0;
	}

	void CollisionEnemyComponent::OnNotify(Event event, Subject*, const std::any& args)
	{
		if (event == Event::collision)
		{
			GameObject* HitObject = nullptr;
			GameObject* EnemyObject = GetGameObject();
			EnemyComponent* enemyComponent = EnemyObject->GetComponent<EnemyComponent>();
			CollisionInfo info = std::any_cast<CollisionInfo>(args);
			if (info.MovingSubject == EnemyObject)
			{
				HitObject = info.CollisionObject;
			}
			else if (info.CollisionObject == EnemyObject)
			{
				HitObject = info.MovingSubject;
			}
			else if (enemyComponent->GetIsHit()) {
				return;
			}
			else
			{
				return;
			}

			if (HitObject->getTag() == "Platform")
			{
				if (info.CollisionDirection.y == 1)
				{
					if (info.overlapPercentage.y <= 0.5f && info.overlapPercentage.y > 0.3f) {

						if (info.CollisionDirection.x != 0)
						{
							//std::cout << "\n\n Platform \n";
							//std::cout << info.overlapPercentage.x << " " << info.overlapPercentage.y << " " << info.overlapPercentage.Total << "\n";
							//std::cout << info.CollisionDirection.x << " " << info.CollisionDirection.y << "\n";
							//std::cout << "Collision direction: " << info.CollisionDirection.x << " Player Going : " << enemyComponent->GetIsGoingLeft() << "\n";
							if (info.CollisionDirection.x == 1 && enemyComponent->GetIsGoingLeft()) {
								++m_CanWalk;
							}
							else if (info.CollisionDirection.x == -1 && !enemyComponent->GetIsGoingLeft()) {
								++m_CanWalk;
							}
							else
							{
								--m_CanWalk;
							}
						}

							//std::cout << " Player Going Left : " << enemyComponent->GetIsGoingLeft() << "\n\n";
						m_TouchingGround = true;
						if (!m_TouchingGroundLastFrame)
						{
							enemyComponent->TouchingGround();
						}
					}
				}
			}
			else if (HitObject->getTag() == "Ladder")
			{
				//std::cout << "\n\n Ladder \n";
				//std::cout << info.overlapPercentage.x << " " << info.overlapPercentage.y << " " << info.overlapPercentage.Total << "\n";
				//std::cout << info.CollisionDirection.x << " " << info.CollisionDirection.y << "\n";

				if (info.CollisionDirection.x == 0) {
					m_OverlappingWithLadder = true;
					if (info.CollisionDirection.y == 1)
					{
						m_LadderBottom = true;
					}
					if (info.CollisionDirection.y == -1)
					{
						m_LadderTop = true;
					}
					 //std::cout << "\n";
				}
			}
			else if (HitObject->getTag() == "Player")
			{
				std::cout << "Player hit\n";
				//player hit
			}

		}
	}

}