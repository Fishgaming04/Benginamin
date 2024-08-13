#pragma once
#include "Components.h"
#include "Observers.h"
#include <memory>
#include <any>
namespace dae {
	class BurgerPartsFallingCollisionComponent final : public ObserverComponent
	{
	public:
		BurgerPartsFallingCollisionComponent(GameObject* obj);

		void Update(double) override;

		virtual ~BurgerPartsFallingCollisionComponent() {};

		virtual void OnNotify(Event event, Subject*, const std::any& args) override;
		void setSubject(std::shared_ptr<Subject> subject) { m_Subject = subject; }


		BurgerPartsFallingCollisionComponent(const BurgerPartsFallingCollisionComponent& other) = delete;
		BurgerPartsFallingCollisionComponent(BurgerPartsFallingCollisionComponent&& other) = delete;
		BurgerPartsFallingCollisionComponent& operator=(const BurgerPartsFallingCollisionComponent& other) = delete;
		BurgerPartsFallingCollisionComponent& operator=(BurgerPartsFallingCollisionComponent&& other) = delete;

	private:

		int m_FallPlatformCounter;
		int m_FallEnemyCounter;

		bool m_TouchingPlatform;
		bool m_TouchingPlatformLastFrame;

		std::shared_ptr<Subject> m_Subject;
	};
}



