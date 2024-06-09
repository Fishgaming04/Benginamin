#pragma once
#include "Components.h"
#include "GameObject.h"
namespace dae {


	class BubbleCompenent : public UpdatingComponent
	{
	public:
		BubbleCompenent(GameObject* obj);
		virtual ~BubbleCompenent() {};
		virtual void Update(double elapsedtime);
		void Shot(bool isLookingLeft, GameObject* shooter);
		void setMaxTimer(float timer) { m_MaxTimer = timer; }
		bool GetIsActive() { return m_IsActive; }
		void setShootingDistance(float distance, float Speed) { m_ShootingDistance = distance; m_Speed = Speed; };
		void setGoingLeft(bool isGoingLeft) { m_IsGoingLeft = isGoingLeft; }
		void setMoveToSide(bool move) { m_MoveToSide = move; }

		//rule of 5
		BubbleCompenent(const BubbleCompenent& other) = delete;
		BubbleCompenent(BubbleCompenent&& other) = delete;
		BubbleCompenent& operator=(const BubbleCompenent& other) = delete;
		BubbleCompenent& operator=(BubbleCompenent&& other) = delete;
	private:
		bool m_IsActive;
		bool m_IsGoingLeft;
		bool m_MoveToSide;
		float m_Timer;
		float m_MaxTimer;
		float m_ShootingDistance;
		float m_Speed;
		float m_DistanceTraveld;
		
	};

}
