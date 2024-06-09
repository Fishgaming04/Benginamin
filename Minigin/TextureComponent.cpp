#include "TextureComponent.h"
#include "Components.h"
#include "Renderer.h"
#include "GameObject.h"
#include "Texture2D.h"
namespace dae {


	TextureComponent::TextureComponent(GameObject* obj)
		:GraphicalComponent(obj)
		,m_TexturePtr{nullptr}
	{
	}

	void TextureComponent::Render() const {
		if (m_TexturePtr != nullptr) {
			const auto& pos = GetGameObject()->GetTransform()->GetWorldRect();
			Renderer::GetInstance().RenderTexture(*m_TexturePtr, pos.x, pos.y);
		}
		
	}

	void TextureComponent::SetTexture(const std::shared_ptr<Texture2D>& texture) {
		m_TexturePtr = texture;
	}
}