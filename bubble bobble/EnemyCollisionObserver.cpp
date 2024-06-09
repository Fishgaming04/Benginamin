#include "EnemyCollisionObserver.h"
#include "GameObject.h"
#include "Enemy.h"
#include "StateMachine.h"
#include "BubStates.h"
namespace dae {

	EnemyCollisionObserver::EnemyCollisionObserver(GameObject* obj)
		:ObserverComponent(obj)
	{
	}

	void EnemyCollisionObserver::OnNotify(Event event, Subject*, const std::any& args)
	{

		if (event == Event::collision)
		{
			CollisionInfo info = std::any_cast<CollisionInfo>(args);
			if (info.MovingSubject == GetGameObject())
			{
				HandleCollision(info.CollisionObject, info);
			}
			else if (info.CollisionObject == GetGameObject())
			{
				HandleCollision(info.MovingSubject, info);
			}

		}
	}

	void EnemyCollisionObserver::HandleCollision(GameObject* HitObject, CollisionInfo)
	{
		if (HitObject->getTag() == "Player")
		{
			HitObject->GetComponent<StateMachine>()->SetState(new BubDeadState());
		}
		else if(HitObject->getTag() == "Bubble"){
			GetGameObject()->GetComponent<Enemy>()->SetInBubble(true);
		}
	}
}
