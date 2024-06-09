#pragma once
#include "Components.h"
#include "GameObject.h"
#include "CollisionSubject.h"
namespace dae
{

	class EnemyCollisionObserver : public ObserverComponent
	{
	public:
		EnemyCollisionObserver(GameObject* obj);
		virtual ~EnemyCollisionObserver() {};

		virtual void OnNotify(Event event, Subject*, const std::any& args) override;

		EnemyCollisionObserver(const EnemyCollisionObserver& other) = delete;
		EnemyCollisionObserver(EnemyCollisionObserver&& other) = delete;
		EnemyCollisionObserver& operator=(const EnemyCollisionObserver& other) = delete;
		EnemyCollisionObserver& operator=(EnemyCollisionObserver&& other) = delete;
	private:
		void HandleCollision(GameObject* HitByBubble, CollisionInfo info);

	};

}
