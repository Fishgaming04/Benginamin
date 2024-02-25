#include "TextureComponent.h"
#include "Components.h"
namespace dae {


	TextureComponent::TextureComponent(GameObject* obj)
		:GraphicalComponent(obj)
		,m_TexturePtr{nullptr}
	{
		

	}

	void TextureComponent::Render() const {
		

	}

	void TextureComponent::SetTexture(Texture2D* texture) {
		m_TexturePtr = texture;
	}
}