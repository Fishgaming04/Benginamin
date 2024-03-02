#pragma once
#include <glm/glm.hpp>

namespace dae
{
	class Transform final
	{
	public:
		const glm::vec3& getLocalposition() const { return m_Localposition; }
		const glm::vec3& getWorldposition() const { return m_Worldposition; }
		void SetLocalPosition(float x, float y, float z);
		void SetWorldPosition(float x, float y, float z);		\
		void SetLocalPosition(glm::vec3 Localposition);
		void SetWorldPosition(glm::vec3 Worldposition);
	private:	
		glm::vec3 m_Localposition;
		glm::vec3 m_Worldposition;
	};
}
