#include "BubbleCompenent.h"


namespace dae
{
	BubbleCompenent::BubbleCompenent(GameObject* obj)
		:UpdatingComponent(obj)
		, m_IsActive(false)
		, m_Timer(0)
		, m_MaxTimer(0)
		, m_ShootingDistance(0)
		, m_Speed(0)
	{
	}
	void BubbleCompenent::Update(double elapsedtime)
	{
		if (m_IsActive)
		{
			m_Timer += static_cast<float>(elapsedtime);
			if (m_Timer >= m_MaxTimer)
			{
				m_IsActive = false;
				m_Timer = 0;
				GetGameObject()->setLocalPosition(-50, -50, 0);
				return;
			}
		
			if (m_DistanceTraveld < m_ShootingDistance)
			{
				if (m_IsGoingLeft)
				{
					GetGameObject()->setLocalPosition(GetGameObject()->GetTransform()->getWorldposition().x - m_Speed * static_cast<float>(elapsedtime), GetGameObject()->GetTransform()->getWorldposition().y, GetGameObject()->GetTransform()->getWorldposition().z);
					m_DistanceTraveld += m_Speed * static_cast<float>(elapsedtime);
				}
				else
				{
					GetGameObject()->setLocalPosition(GetGameObject()->GetTransform()->getWorldposition().x + m_Speed * static_cast<float>(elapsedtime), GetGameObject()->GetTransform()->getWorldposition().y, GetGameObject()->GetTransform()->getWorldposition().z);
					m_DistanceTraveld += m_Speed * static_cast<float>(elapsedtime);
				}
			}
			else if (m_MoveToSide)
			{
				if (m_IsGoingLeft) {
					GetGameObject()->setLocalPosition(GetGameObject()->GetTransform()->getWorldposition().x - m_Speed / 2 * static_cast<float>(elapsedtime), GetGameObject()->GetTransform()->getWorldposition().y , GetGameObject()->GetTransform()->getWorldposition().z);

				}
				else
				{
					GetGameObject()->setLocalPosition(GetGameObject()->GetTransform()->getWorldposition().x + m_Speed / 2 * static_cast<float>(elapsedtime), GetGameObject()->GetTransform()->getWorldposition().y , GetGameObject()->GetTransform()->getWorldposition().z);
					
				}
				m_MoveToSide = false;
			}
			else
			{

				GetGameObject()->setLocalPosition(GetGameObject()->GetTransform()->getWorldposition().x, GetGameObject()->GetTransform()->getWorldposition().y - m_Speed/2 * static_cast<float>(elapsedtime), GetGameObject()->GetTransform()->getWorldposition().z);
			}
		}



	}

	void BubbleCompenent::Shot(bool isLookingLeft, GameObject* shooter)
	{
		m_IsActive = true;
		if (isLookingLeft)
		{
			m_DistanceTraveld = 0;
			m_IsGoingLeft = true;
			GetGameObject()->setLocalPosition(shooter->GetTransform()->getWorldposition().x - 10, shooter->GetTransform()->getWorldposition().y, shooter->GetTransform()->getWorldposition().z);
		}
		else
		{
			m_DistanceTraveld = 0;
			m_IsGoingLeft = false;
			GetGameObject()->setLocalPosition(shooter->GetTransform()->getWorldposition().x + 10, shooter->GetTransform()->getWorldposition().y, shooter->GetTransform()->getWorldposition().z);
		}
	}
}
