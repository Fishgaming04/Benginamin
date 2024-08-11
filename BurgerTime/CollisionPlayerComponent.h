#pragma once
#include "Components.h"
#include "glm/glm.hpp"
namespace dae
{

	class CollisionPlayersComponent final: public ObserverComponent
	{
	public:
		CollisionPlayersComponent(GameObject* obj);

		void Update(double) override;

		virtual ~CollisionPlayersComponent() {};

		virtual void OnNotify(Event event, Subject*, const std::any& args) override;

		bool getCanClimb() const { return m_CanClimbLastFrame; }
		bool getCanWalk() const { return m_CanWalkLastFrame; }

		CollisionPlayersComponent(const CollisionPlayersComponent& other) = delete;
		CollisionPlayersComponent(CollisionPlayersComponent&& other) = delete;
		CollisionPlayersComponent& operator=(const CollisionPlayersComponent& other) = delete;
		CollisionPlayersComponent& operator=(CollisionPlayersComponent&& other) = delete;
	private:
		glm::vec3 m_PreviousViablePosition;
		int m_LadderOverlap;
		bool m_CurrentPositionIsViable;
		bool m_CanClimb;
		bool m_CanWalk;
		bool m_CanClimbLastFrame;
		bool m_CanWalkLastFrame;
	};

}