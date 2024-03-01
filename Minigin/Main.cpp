#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include <string>
#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "TextComponent.h"
#include "TextureComponent.h"
#include "Scene.h"
#include "Components.h"
#include "GameObject.h"
#include "FPSComponent.h"

void load()
{

	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");
	auto& recourceManager = dae::ResourceManager::GetInstance();

	auto gameObj = std::make_shared<dae::GameObject>();
	gameObj->AddComponent<dae::TextureComponent>();
	gameObj->GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("background.tga"));
	scene.Add(gameObj);

	gameObj = std::make_shared<dae::GameObject>();
	gameObj->AddComponent<dae::TextureComponent>();
	gameObj->GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("logo.tga"));
	//gameObj->GetTransform()->SetPosition(216, 180, 0);
	scene.Add(gameObj);

	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	gameObj = std::make_shared<dae::GameObject>();
	gameObj->AddComponent<dae::TextureComponent>();
	gameObj->AddComponent<dae::TextComponent>();
	gameObj->GetComponent<dae::TextComponent>()->SetFont(font);
	gameObj->GetComponent<dae::TextComponent>()->SetText("Programming 4 Assignment");
	gameObj->GetComponent<dae::TextComponent>()->SetColor(SDL_Color(255, 0, 0, 255));
	//gameObj->GetTransform()->SetPosition(80, 20, 0);
	scene.Add(gameObj);

	gameObj = std::make_shared<dae::GameObject>();
	gameObj->AddComponent<dae::TextureComponent>();
	gameObj->AddComponent<dae::TextComponent>();
	gameObj->GetComponent<dae::TextComponent>()->SetFont(font);
	gameObj->AddComponent<dae::FPSComponent>();
	gameObj->GetComponent<dae::TextComponent>()->SetText(std::to_string(gameObj->GetComponent<dae::FPSComponent>()->GetFps()));
	gameObj->GetComponent<dae::TextComponent>()->SetColor(SDL_Color(255, 0, 0, 255));
	//gameObj->GetTransform()->SetPosition(20, 20, 0);
	scene.Add(gameObj);
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}