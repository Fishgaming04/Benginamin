#pragma once
#include "Components.h"

namespace dae {
	class Transform;
	class Texture2D;
	class TextureComponent final: public GraphicalComponent
	{
	public:
		TextureComponent(GameObject* obj);


		virtual void Render() const;
		void SetTexture(Texture2D* texture);


		virtual ~TextureComponent() = default;
		TextureComponent(const TextureComponent& other) = delete;
		TextureComponent(TextureComponent&& other) = delete;
		TextureComponent& operator=(const TextureComponent& other) = delete;
		TextureComponent& operator=(TextureComponent&& other) = delete;
	private: 
		Texture2D* m_TexturePtr;
	};
}
