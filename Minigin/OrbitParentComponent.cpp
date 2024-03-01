#include "OrbitParentComponent.h"
#include "GameObject.h"
#include "Transform.h"

namespace dae {
	OrbitParentComponent::OrbitParentComponent(GameObject* obj)
		:GraphicalComponent(obj)
		,m_PivotPoint{}
		,m_DistanceFromPivot{15}
		,m_CurrentAngle{}
		,m_RotationSpeed{10}
		//,m_TransformPtr{ m_ObjectPtr->GetTransform() }
	{
	}

	void OrbitParentComponent::setDistanceFromPivot(int distance) {
		m_DistanceFromPivot = distance;
	}


	void OrbitParentComponent::Update(double elapsedTime) {
		m_CurrentAngle += (elapsedTime * double(m_RotationSpeed));
		
		float x{};
		float y{};
		x = float(cos(m_CurrentAngle));
		y = float(sin(m_CurrentAngle)); 
		m_TransformPtr->SetLocalPosition(x, y, 1);
	}

	void OrbitParentComponent::SetRotationSpeed(int speed) {
		m_RotationSpeed = speed;
	}
}