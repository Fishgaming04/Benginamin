#include "CollisionBubbleComponent.h"
#include "GameObject.h"
#include "StateMachine.h"
#include "BubbleCompenent.h"
namespace dae {

	dae::CollisioBubbleComponent::CollisioBubbleComponent(GameObject* obj)
		:ObserverComponent(obj)
	{
	}

	void dae::CollisioBubbleComponent::OnNotify(Event event, Subject*, const std::any& args)
	{
		if (event == Event::collision) {
			CollisionInfo info = std::any_cast<CollisionInfo>(args);
			if (info.CollisionObject == GetGameObject()) {
				HandleCollision(info.MovingSubject, info);
				
			}	
			else if (info.MovingSubject == GetGameObject()) {
				HandleCollision(info.CollisionObject, info);
			}
		}
	}
	void CollisioBubbleComponent::HandleCollision(GameObject* HitByBubble, CollisionInfo info)
	{
		if (HitByBubble->getTag() == "Player") {

		}
		else if (HitByBubble->getTag() == "Envirement") {
			if (info.CollisionDirection.y == -1)
			{
				auto pos = GetGameObject()->GetTransform()->getLocalposition();

				pos.y += info.overlapPercentage.y * GetGameObject()->GetTransform()->getSize().y;
				GetGameObject()->setLocalPosition(pos);

				GetGameObject()->GetComponent<BubbleCompenent>()->setMoveToSide(true);
			}
		}
		else if (HitByBubble->getTag() == "Enemy") {

		}
	}
}
