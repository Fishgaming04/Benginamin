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
		, m_CanClimbLastFrame(false)
		, m_CanWalkLastFrame(false)
		, m_LadderOverlap(0)
	{
	}

	void CollisionPlayersComponent::Update(double)
	{

		if (!m_CurrentPositionIsViable)
		{
			//auto pos = GetGameObject()->GetTransform()->getLocalposition();
			GetGameObject()->GetTransform()->SetLocalPosition(m_PreviousViablePosition);

			//std::cout << "old: " << pos.x << " " << pos.y << " " << pos.z << "\n";
			//::cout << "new: " << m_PreviousViablePosition.x << " " << m_PreviousViablePosition.y << " " << m_PreviousViablePosition.z << "\n";
		}
		else
		{
			m_CanClimbLastFrame = m_CanClimb;
			m_CanWalkLastFrame = m_CanWalk;
		}

		m_CurrentPositionIsViable = false;
		m_CanClimb = false;
		m_CanWalk = false;
		m_LadderOverlap = 0;
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
					
					//std::cout << "\n\n Platform \n";
					//std::cout << info.CollisionDirection.x << " " << info.CollisionDirection.y << "\n";
					//std::cout << info.overlapPercentage.x << " " << info.overlapPercentage.y << " " << info.overlapPercentage.Total << "\n";

					if (info.CollisionDirection.x == 0) {
						if (info.overlapPercentage.y <= 0.5f && info.overlapPercentage.y > 0.1f) {
							m_CurrentPositionIsViable = true;
							m_PreviousViablePosition = GetGameObject()->GetTransform()->getLocalposition();
							m_CanWalk = true;
						}
					}
				}
				else if (info.CollisionObject->getTag() == "Ladder")
				{
					//std::cout << "\n\nLadder\n";
					//std::cout << info.CollisionDirection.x << " " << info.CollisionDirection.y << "\n";
					//std::cout << info.overlapPercentage.x << " " << info.overlapPercentage.y << " " << info.overlapPercentage.Total << "\n";

					if (info.CollisionDirection.x == 0){
						m_CanClimb = true;
						if (info.CollisionDirection.y == 1) {

							m_CurrentPositionIsViable = true;
							m_PreviousViablePosition = GetGameObject()->GetTransform()->getLocalposition();
							
							m_LadderOverlap = 1;
						}
						else if (info.CollisionDirection.y == -1) {
							if (m_LadderOverlap != 1)
							{
								m_CurrentPositionIsViable = false;
							}
							m_LadderOverlap = -1;
						}
						else
						{
							m_CurrentPositionIsViable = true;
							m_PreviousViablePosition = GetGameObject()->GetTransform()->getLocalposition();

						}
					}
				}
			}
		}
	}
}