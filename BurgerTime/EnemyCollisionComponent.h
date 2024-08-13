#pragma once
#include "Components.h"
#include "glm/glm.hpp"
#include "Observers.h"

namespace dae
{
	class CollisionEnemyComponent final : public ObserverComponent
	{
	public:
		CollisionEnemyComponent(GameObject* obj);

		void Update(double) override;

		virtual ~CollisionEnemyComponent() {};

		virtual void OnNotify(Event event, Subject*, const std::any& args) override;

		CollisionEnemyComponent(const CollisionEnemyComponent& other) = delete;
		CollisionEnemyComponent(CollisionEnemyComponent&& other) = delete;
		CollisionEnemyComponent& operator=(const CollisionEnemyComponent& other) = delete;
		CollisionEnemyComponent& operator=(CollisionEnemyComponent&& other) = delete;
	private:
		bool m_OverlappingWithLadder;
		bool m_OverlappingWithLadderLastFrame;
		bool m_TouchingGround;
		bool m_LadderBottom;
		bool m_LadderTop;
		bool m_TouchingGroundLastFrame;
		int m_CanWalk;
	};
}
