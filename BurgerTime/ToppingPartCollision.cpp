#include "ToppingPartCollision.h"
#include "GameObject.h"
#include "CollisionSubject.h"
#include <iostream>

namespace dae {



	ToppingPartCollision::ToppingPartCollision(GameObject* obj)
		:ObserverComponent(obj)
		,m_IsPressed{ false }
	{
	}

	void ToppingPartCollision::OnNotify(Event event, Subject*, const std::any& args)
	{
		if (event == Event::collision)
		{
			GameObject* HitObject = nullptr;
			CollisionInfo info = std::any_cast<CollisionInfo>(args);
			if (info.MovingSubject == GetGameObject())
			{
				HitObject = info.CollisionObject;
			}
			else if (info.CollisionObject == GetGameObject())
			{
				HitObject = info.MovingSubject;
			}
			else
			{
				return;
			}

			if (HitObject->getTag() == "Player")
			{
				if (info.overlapPercentage.x > 0.5f) {
					m_IsPressed = true;
				}
			}
		}
	}


}