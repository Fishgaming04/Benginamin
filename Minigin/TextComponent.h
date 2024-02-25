#pragma once
#include <string>
#include <memory>
#include "Components.h"
#include "Transform.h"



namespace dae
{
	class Font;
	class Texture2D;
	class TextComponent final : public UpdatingComponent
	{
	public:
		virtual void Update(GameObject& obj);
		//virtual void Render(GameObject& obj) const override;

		void SetText(const std::string& text);
		void SetPosition(float x, float y);
		void SetColor(SDL_Color color = SDL_Color(255, 255, 255, 255));

		TextComponent(const std::string& text, std::shared_ptr<Font> font, SDL_Color color = SDL_Color(255, 255, 255, 255));
		virtual ~TextComponent() = default;
		TextComponent(const TextComponent& other) = delete;
		TextComponent(TextComponent&& other) = delete;
		TextComponent& operator=(const TextComponent& other) = delete;
		TextComponent& operator=(TextComponent&& other) = delete;
	private:
		bool m_needsUpdate;
		std::string m_text;
		SDL_Color m_Color;
		Transform m_transform{};
		std::shared_ptr<Font> m_font;
		std::shared_ptr<Texture2D> m_textTexture;
	};
}
