#include "CollisionPlayerComponent.h"
#include "CollisionSubject.h"
#include "GameObject.h"
#include <iostream>
#include "GravityComponent.h"
#include "StateMachine.h"
#include "BubStates.h"

namespace dae
{

	dae::CollisionPlayerComponent::CollisionPlayerComponent(GameObject* obj)
		:ObserverComponent(obj)
	{
	}

	void CollisionPlayerComponent::OnNotify(Event event, Subject* , const std::any& args)
	{

		if (event == Event::collision)
		{
			CollisionInfo info = std::any_cast<CollisionInfo>(args);
			if (info.MovingSubject == GetGameObject())
			{
				//std::cout << "Collision with " << info.CollisionObject->getTag() << "\n";
				if (info.CollisionObject->getTag() == "Envirement")
				{
					//std::cout << info.CollisionDirection.x << " " << info.CollisionDirection.y << "\n";
					//std::cout << info.overlapPercentage.x << " " << info.overlapPercentage.y << " " << info.overlapPercentage.Total << "\n";
					//const float overlappingX{ 0.2f }, overlappingY{ 0.5f };



					if (info.CollisionDirection.y == 1 && GetGameObject()->GetComponent<GravityComponent>()->GetMomentum() >= 0) {
						GetGameObject()->GetComponent<GravityComponent>()->SetMomentum(0);
						auto pos = GetGameObject()->GetTransform()->getLocalposition();

						pos.y -= info.overlapPercentage.y * GetGameObject()->GetTransform()->getSize().y;
						GetGameObject()->setLocalPosition(pos);

						if (info.MovingSubject->getTag() == "Player" && dynamic_cast<BubJumpingState*>(GetGameObject()->GetComponent<StateMachine>()->GetState()))
						{
							GetGameObject()->GetComponent<StateMachine>()->SetState(new BubIdleState());
						}

					}

					//sadly did not get this to work I tried many different things and combinations but was not able to make it work sadly
					//So there are no side of block collisions in the game
					//if (info.CollisionDirection.y == 0 && GetGameObject()->GetComponent<GravityComponent>()->GetMomentum() == 0)
					//{
					//	bool isleft = GetGameObject()->getIsLookingLeft();
					//	isleft;
					//	if (info.CollisionDirection.x == 1 && GetGameObject()->getIsLookingLeft())
					//	{
					//		auto pos = GetGameObject()->GetTransform()->getLocalposition();
					//		pos.x += info.overlapPercentage.x * GetGameObject()->GetTransform()->getSize().x;
					//		GetGameObject()->setLocalPosition(pos);
					//	}
					//	else if (info.CollisionDirection.x == -1 && !GetGameObject()->getIsLookingLeft())
					//	{
					//		auto pos = GetGameObject()->GetTransform()->getLocalposition();
					//		pos.x -= info.overlapPercentage.x * GetGameObject()->GetTransform()->getSize().x;
					//		GetGameObject()->setLocalPosition(pos);
					//	}
					//}
				} 
			}
		}
	}
}