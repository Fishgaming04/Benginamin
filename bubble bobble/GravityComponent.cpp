#include "GravityComponent.h"
#include "GameObject.h"
#include "Transform.h"
#include <iostream>
namespace dae
{

	GravityComponent::GravityComponent(GameObject* obj)
		:UpdatingComponent(obj)
		, m_Momentum(0)
		, m_MaxMomentum(100)
		, m_MomentumScaler(1)
	{
	}

	void GravityComponent::Update(double elapsed)
	{
		if (m_Momentum + 9.81 * elapsed * m_MomentumScaler > m_MaxMomentum) {
			m_Momentum = +m_MaxMomentum;
		}
		else {
			m_Momentum += 9.81 * m_MomentumScaler * elapsed;
		}
		float x = GetGameObject()->GetTransform()->getWorldposition().x;
		float y = GetGameObject()->GetTransform()->getWorldposition().y + static_cast<float>(m_Momentum);
		float z = GetGameObject()->GetTransform()->getWorldposition().z;
		GetGameObject()->setLocalPosition(x, y, z);
	}

	double GravityComponent::GetMomentum()
	{
		return m_Momentum;
	}

	void GravityComponent::addMomentum(double momentum)
	{
		m_Momentum += momentum;
	}

	void GravityComponent::SetMomentum(double scaler)
	{
		m_Momentum = scaler;
		//std::cout << m_Momentum << "\n";
	}

}