#include "CollisionPlayerComponent.h"
#include "GameObject.h"
#include "CollisionSubject.h"
#include <iostream>

namespace dae {

	CollisionPlayersComponent::CollisionPlayersComponent(GameObject* obj)
		:ObserverComponent(obj)
		, m_CurrentPositionIsViable(false)
		, m_CanClimb(false)
		, m_CanWalk(false)
	{
	}

	void CollisionPlayersComponent::Update(double)
	{
		if (!m_CurrentPositionIsViable)
		{
			GetGameObject()->GetTransform()->SetLocalPosition(m_PreviousViablePosition);
		}
		else
		{
			m_PreviousViablePosition = GetGameObject()->GetTransform()->getLocalposition();
		}
		m_CurrentPositionIsViable = false;
		m_CanClimb = false;
		m_CanWalk = false;
	}

	void CollisionPlayersComponent::OnNotify(Event event, Subject*, const std::any& args)
	{

		if (event == Event::collision)
		{
			CollisionInfo info = std::any_cast<CollisionInfo>(args);
			if (info.MovingSubject == GetGameObject())
			{
				//std::cout << "Collision with " << info.CollisionObject->getTag() << "\n";
				if (info.CollisionObject->getTag() == "Platform")
				{
					
					std::cout << "\n\n Platform \n";
					std::cout << info.CollisionDirection.x << " " << info.CollisionDirection.y << "\n";
					std::cout << info.overlapPercentage.x << " " << info.overlapPercentage.y << " " << info.overlapPercentage.Total << "\n";


					if (info.CollisionDirection.x == 0) {
						m_CurrentPositionIsViable = true;
						if (info.CollisionDirection.x <= 0.2) {
							std::cout << "Collision with platform\n";
							m_CanWalk = true;
						}
					}

					//const float overlappingX{ 0.2f }, overlappingY{ 0.5f };
				}
				else if (info.CollisionObject->getTag() == "Ladder")
				{
					std::cout << "\n\nLadder\n";
					std::cout << info.CollisionDirection.x << " " << info.CollisionDirection.y << "\n";
					std::cout << info.overlapPercentage.x << " " << info.overlapPercentage.y << " " << info.overlapPercentage.Total << "\n";
					if (info.overlapPercentage.Total == 1.0f)
					{
						m_CurrentPositionIsViable = true;
						m_CanClimb = true;
					}
				}

			}
		}



	}
}