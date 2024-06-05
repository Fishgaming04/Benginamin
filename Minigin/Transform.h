#pragma once
#include <glm/glm.hpp>

namespace dae
{
	struct Rect4f
	{
		float x;
		float y;
		float width;
		float height;
	};

	
	class Transform final
	{
	public:
		const Rect4f GetWorldRect() const { return Rect4f{ m_Worldposition.x, m_Worldposition.y, m_Size.x, m_Size.y }; }
		const Rect4f GetLocalRect() const { return Rect4f{ m_Localposition.x, m_Localposition.y, m_Size.x, m_Size.y }; }
		const glm::vec2& getSize() const { return m_Size; }
		const glm::vec3& getLocalposition() const { return m_Localposition; }
		const glm::vec3& getWorldposition() const { return m_Worldposition; }
		void SetLocalPosition(float x, float y, float z);
		void SetWorldPosition(float x, float y, float z);
		void SetLocalPosition(glm::vec3 Localposition);
		void SetWorldPosition(glm::vec3 Worldposition);
		void SetSize(float width, float height);
	private:	
		glm::vec3 m_Localposition;
		glm::vec3 m_Worldposition;
		glm::vec2 m_Size;
	};
}
