#pragma once
#include "Components.h"

namespace dae
{

	class CollisionPlayerComponent : public ObserverComponent
	{
	public:
		CollisionPlayerComponent(GameObject* obj);
		virtual ~CollisionPlayerComponent() {};

		virtual void OnNotify(Event event, Subject*, const std::any& args) override;

		CollisionPlayerComponent(const CollisionPlayerComponent& other) = delete;
		CollisionPlayerComponent(CollisionPlayerComponent&& other) = delete;
		CollisionPlayerComponent& operator=(const CollisionPlayerComponent& other) = delete;
		CollisionPlayerComponent& operator=(CollisionPlayerComponent&& other) = delete;
	private:
	

	};

}
