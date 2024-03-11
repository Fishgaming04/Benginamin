#pragma once
#include <SDL.h>
#include "Singleton.h"
#include <vector>
namespace dae
{
	class Texture2D;
	/**
	 * Simple RAII wrapper for the SDL renderer
	 */
	class Renderer final : public Singleton<Renderer>
	{

	public:
		void Init(SDL_Window* window);
		void Render() const;
		void Destroy();
		//void Benchmark() const;
		void RenderTexture(const Texture2D& texture, float x, float y) const;
		void RenderTexture(const Texture2D& texture, float x, float y, float width, float height) const;

		SDL_Renderer* GetSDLRenderer() const;

		SDL_Window* GetWindow() const;

		const SDL_Color& GetBackgroundColor() const { return m_clearColor; }
		void SetBackgroundColor(const SDL_Color& color) { m_clearColor = color; }
	private:
		bool* m_IsWindowActive{ new bool {true} };
		int* m_NumberOfItarations{ new int{} };
		std::vector<float> result{};

		const int sizeArray{ 1'000'000 };
		//const int m_NumberOfItarations{ 10 };

		SDL_Renderer* m_renderer{};
		SDL_Window* m_window{};
		SDL_Color m_clearColor{};	
	};
}

