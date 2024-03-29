#include <stdexcept>
#include "TextComponent.h"
#include "Renderer.h"
#include "Font.h"
#include "Texture2D.h"
#include "GameObject.h"

namespace dae {

dae::TextComponent::TextComponent(GameObject* obj)
	: UpdatingComponent(obj)
	, m_needsUpdate(true)
	, m_text("")
	, m_font(nullptr)
	, m_Color(SDL_Color(255, 255, 255, 255))
	, m_TextureComponentPtr()
{ 
	if (!GetGameObject()->HasComponent<TextureComponent>()) {
		GetGameObject()->AddComponent<TextureComponent>();
	}
	m_TextureComponentPtr = GetGameObject()->GetComponent<TextureComponent>();
}

void dae::TextComponent::Update(double)
{
	if (m_needsUpdate)
	{
		const auto surf = TTF_RenderText_Blended(m_font->GetFont(), m_text.c_str(), m_Color);
		if (surf == nullptr) 
		{
			throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
		}
		auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);
		if (texture == nullptr) 
		{
			throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
		}
		SDL_FreeSurface(surf);

	
		m_TextureComponentPtr->SetTexture(std::make_shared<Texture2D>(texture));

		
		m_needsUpdate = false;
	}
}

// This implementation uses the "dirty flag" pattern
void dae::TextComponent::SetText(const std::string& text)
{
	m_text = text;
	m_needsUpdate = true;
}


void dae::TextComponent::SetColor(SDL_Color color) {
	m_Color = color;
	m_needsUpdate = true;
}

void dae::TextComponent::SetFont(std::shared_ptr<Font> font) {
	m_font = (std::move(font));
	m_needsUpdate = true;
}
}