#pragma once
#include <string>
#include <memory>
#include <SDL_ttf.h>
#include "Components.h"
#include "Transform.h"
#include "TextureComponent.h"

namespace dae
{
	class Font;
	class Texture2D;
	class TextComponent final : public UpdatingComponent
	{
	public:
		virtual void Update(double elapsedTime);
		//virtual void Render(GameObject& obj) const override;

		void SetText(const std::string& text);
		void SetColor(SDL_Color color = SDL_Color{ 255, 255, 255, 255 });
		void SetFont(std::shared_ptr<Font> font);

		//this needs seperate function 
		TextComponent(GameObject* obj);
		virtual ~TextComponent() = default;
		TextComponent(const TextComponent& other) = delete;
		TextComponent(TextComponent&& other) = delete;
		TextComponent& operator=(const TextComponent& other) = delete;
		TextComponent& operator=(TextComponent&& other) = delete;
	private:
		bool m_needsUpdate;
		std::string m_text;
		SDL_Color m_Color;
		std::shared_ptr<Font> m_font;
		TextureComponent* m_TextureComponentPtr;
	};
}
