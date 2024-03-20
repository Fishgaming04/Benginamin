#include "HealthComponent.h"


namespace dae
{


	HealthComponent::HealthComponent(GameObject* obj)
		:UpdatingComponent(obj)
		,m_Health(100)
	{
	}

	void HealthComponent::Update(double elapsedTime)
	{
		elapsedTime;
	}

	int HealthComponent::GetHealth()
	{
		return m_Health;
	}

	void HealthComponent::SetHealth(int health)
	{
		m_Health = health;
	}

}