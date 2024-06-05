#include "Transform.h"


void dae::Transform::SetLocalPosition(const float x, const float y, const float z){
	SetLocalPosition(glm::vec3(x, y, z));
}
void dae::Transform::SetWorldPosition(const float x, const float y, const float z){
	SetWorldPosition(glm::vec3(x, y, z));
}

void dae::Transform::SetLocalPosition(glm::vec3 Localposition) {
	m_Localposition = Localposition;
}
void dae::Transform::SetWorldPosition(glm::vec3 Worldposition) {
	m_Worldposition = Worldposition;
}
void dae::Transform::SetSize(float width, float height)
{
	m_Size = glm::vec2(width, height);
}
