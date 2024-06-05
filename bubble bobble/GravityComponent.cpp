#include "GravityComponent.h"
#include "GameObject.h"
#include "Transform.h"
namespace dae
{

	MomentumComponent::MomentumComponent(GameObject* obj)
		:UpdatingComponent(obj)
		, m_Momentum(0)
		, m_MaxMomentum(100)
		, m_MomentumScaler(1)
	{
	}

	void MomentumComponent::Update(double)
	{
		if (m_Momentum - 9.81 * m_MomentumScaler < -m_MaxMomentum) {
			m_Momentum = -m_MaxMomentum;
		}
		else {
			m_Momentum - 9.81 * m_MomentumScaler;
		}
		float x = GetGameObject()->GetTransform()->getWorldposition().x;
		float y = GetGameObject()->GetTransform()->getWorldposition().y + m_Momentum;
		float z = GetGameObject()->GetTransform()->getWorldposition().z;
		GetGameObject()->GetTransform()->SetWorldPosition(x, y, z);
	}

	double MomentumComponent::GetMomentum()
	{
		return m_Momentum;
	}

	void MomentumComponent::addMomentum(double momentum)
	{
		m_Momentum += momentum;
	}

}