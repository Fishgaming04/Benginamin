#include "PlayerObserver.h"
#include "EnemyComponent.h"

namespace dae {
	PlayerObserver::PlayerObserver(GameObject* obj)
		:ObserverComponent(obj)
	{
	}

	void PlayerObserver::OnNotify(Event event, Subject*, const std::any&)
	{
		if (event == Event::PlayerHit) {
			GetGameObject()->GetComponent< EnemyComponent>()->Reset();
		}

	}

}
