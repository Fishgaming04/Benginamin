#pragma once
#include "Components.h"
#include <memory>

namespace dae {
	
	class Texture2D;
	class TextureComponent final: public GraphicalComponent
	{
	public:
		TextureComponent(GameObject* obj);


		virtual void Render() const;
		void SetTexture(const std::shared_ptr<Texture2D>& texture);


		virtual ~TextureComponent() = default;
		TextureComponent(const TextureComponent& other) = delete;
		TextureComponent(TextureComponent&& other) = delete;
		TextureComponent& operator=(const TextureComponent& other) = delete;
		TextureComponent& operator=(TextureComponent&& other) = delete;
	private: 
		std::shared_ptr<Texture2D> m_TexturePtr;
	};
}
