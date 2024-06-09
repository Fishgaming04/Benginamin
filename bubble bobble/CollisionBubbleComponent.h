#pragma once
#include "Components.h"
#include "CollisionSubject.h"
namespace dae {

	class CollisioBubbleComponent : public ObserverComponent
	{
	public:
		CollisioBubbleComponent(GameObject* obj);

		virtual void OnNotify(Event event, Subject*, const std::any& args) override;

		virtual ~CollisioBubbleComponent() = default;
		CollisioBubbleComponent(const CollisioBubbleComponent& other) = delete;
		CollisioBubbleComponent(CollisioBubbleComponent&& other) = delete;
		CollisioBubbleComponent& operator=(const CollisioBubbleComponent& other) = delete;
		CollisioBubbleComponent& operator=(CollisioBubbleComponent&& other) = delete;

	private:
		void HandleCollision(GameObject* HitByBubble, CollisionInfo info);
		
	};

}
