#include <stdexcept>
#include <SDL_ttf.h>
#include "TextComponent.h"
#include "Renderer.h"
#include "Font.h"
#include "Texture2D.h"

dae::TextComponent::TextComponent(const std::string& text, std::shared_ptr<Font> font, SDL_Color color)
	: m_needsUpdate(true), m_text(text), m_font(std::move(font)), m_textTexture(nullptr), m_Color(color)
{ }

void dae::TextComponent::Update(GameObject& obj)
{
	if (m_needsUpdate)
	{
		obj;
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
		m_textTexture = std::make_shared<Texture2D>(texture);
		m_needsUpdate = false;
	}
}

//void dae::TextObject::Render() const
//{
//	if (m_textTexture != nullptr)
//	{
//		const auto& pos = m_transform.GetPosition();
//		Renderer::GetInstance().RenderTexture(*m_textTexture, pos.x, pos.y);
//	}
//}

// This implementation uses the "dirty flag" pattern
void dae::TextComponent::SetText(const std::string& text)
{
	m_text = text;
	m_needsUpdate = true;
}

void dae::TextComponent::SetPosition(const float x, const float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}


void dae::TextComponent::SetColor(SDL_Color color) {
	m_Color = color;
	m_needsUpdate = true;
}