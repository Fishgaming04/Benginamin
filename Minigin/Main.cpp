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
#include "OrbitParentComponent.h"

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
	gameObj->setLocalPosition(216.0f, 180.0f, 0.0f);
	scene.Add(gameObj);

	auto Pivot = std::make_shared<dae::GameObject>();
	Pivot = std::make_shared<dae::GameObject>();
	Pivot->setLocalPosition(200.0f, 200.0f, 0.0f);
	scene.Add(Pivot);

	auto Rotating1 = std::make_shared<dae::GameObject>();
	Rotating1 = std::make_shared<dae::GameObject>();
	Rotating1->AddComponent<dae::TextureComponent>();
	Rotating1->GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("Character1.png"));
	Rotating1->SetParent(Pivot.get());
	Rotating1->AddComponent<dae::OrbitParentComponent>();
	Rotating1->GetComponent<dae::OrbitParentComponent>()->setDistanceFromPivot(100.0f);
	Rotating1->GetComponent<dae::OrbitParentComponent>()->SetRotationSpeed(1);
	scene.Add(Rotating1);	
	
	auto Rotating2 = std::make_shared<dae::GameObject>();
	Rotating2 = std::make_shared<dae::GameObject>();
	Rotating2->AddComponent<dae::TextureComponent>();
	Rotating2->GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("Character2.png"));
	Rotating2->SetParent(Rotating1.get());
	Rotating2->AddComponent<dae::OrbitParentComponent>();
	Rotating1->GetComponent<dae::OrbitParentComponent>()->setDistanceFromPivot(50.0f);
	Rotating1->GetComponent<dae::OrbitParentComponent>()->SetRotationSpeed(2);
	scene.Add(Rotating2);

	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	gameObj = std::make_shared<dae::GameObject>();
	gameObj->AddComponent<dae::TextureComponent>();
	gameObj->AddComponent<dae::TextComponent>();
	gameObj->GetComponent<dae::TextComponent>()->SetFont(font);
	gameObj->GetComponent<dae::TextComponent>()->SetText("Programming 4 Assignment");
	gameObj->GetComponent<dae::TextComponent>()->SetColor(SDL_Color(255, 0, 0, 255));
	gameObj->setLocalPosition(80, 20, 0);
	scene.Add(gameObj);

	gameObj = std::make_shared<dae::GameObject>();
	gameObj->AddComponent<dae::TextureComponent>();
	gameObj->AddComponent<dae::TextComponent>();
	gameObj->GetComponent<dae::TextComponent>()->SetFont(font);
	gameObj->AddComponent<dae::FPSComponent>();
	gameObj->GetComponent<dae::TextComponent>()->SetText(std::to_string(gameObj->GetComponent<dae::FPSComponent>()->GetFps()));
	gameObj->GetComponent<dae::TextComponent>()->SetColor(SDL_Color(255, 0, 0, 255));
	gameObj->setLocalPosition(20, 20, 0);
	scene.Add(gameObj);
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}