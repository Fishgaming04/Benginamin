#include "Transform.h"

void dae::Transform::SetLocalPosition(const float x, const float y, const float z)
{
	m_Localposition.x = x;
	m_Localposition.y = y;
	m_Localposition.z = z;
}
void dae::Transform::SetWorldPosition(const float x, const float y, const float z)
{
	m_Localposition.x = x;
	m_Localposition.y = y;
	m_Localposition.z = z;
}
