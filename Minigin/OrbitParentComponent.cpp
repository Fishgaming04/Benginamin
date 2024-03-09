#include "OrbitParentComponent.h"
#include "GameObject.h"
#include "Transform.h"

namespace dae {
	OrbitParentComponent::OrbitParentComponent(GameObject* obj)
		:UpdatingComponent(obj)
		,m_PivotPoint{}
		,m_DistanceFromPivot{15.0f}
		,m_CurrentAngle{}
		,m_RotationSpeed{10}
	{
	}

	void OrbitParentComponent::setDistanceFromPivot(float distance) {
		m_DistanceFromPivot = distance;
	}


	void OrbitParentComponent::Update(double elapsedTime) {
		m_CurrentAngle += (elapsedTime * double(m_RotationSpeed));

		//if (m_CurrentAngle > );
		
		float x{ float(cos(m_CurrentAngle) * m_DistanceFromPivot) };
		float y{ float(sin(m_CurrentAngle) * m_DistanceFromPivot) };
		m_ObjectPtr->setLocalPosition(x, y);
	}

	void OrbitParentComponent::SetRotationSpeed(int speed) {
		m_RotationSpeed = speed;
	}
}