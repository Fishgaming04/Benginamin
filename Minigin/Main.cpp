#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include <string>
#include "ResourceManager.h"
#include "sceneManager.h"
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
#include "InputManager.h"
#include "Command.h"


using namespace dae;


void load()
{

	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");
	auto& recourceManager = dae::ResourceManager::GetInstance();
	auto& input = InputManager::GetInstance();

	auto gameObj = std::make_shared<dae::GameObject>();
	gameObj->AddComponent<dae::TextureComponent>();
	gameObj->GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("background.tga"));
	scene.Add(gameObj);

	gameObj = std::make_shared<dae::GameObject>();
	gameObj->AddComponent<dae::TextureComponent>();
	gameObj->GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("logo.tga"));
	gameObj->setLocalPosition(216.0f, 180.0f, 0.0f);
	scene.Add(gameObj);



	auto Rotating1 = std::make_shared<dae::GameObject>();
	Rotating1 = std::make_shared<dae::GameObject>();
	Rotating1->AddComponent<dae::TextureComponent>();
	Rotating1->GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("Character1.png"));
	unsigned int controllerIndex = input.AddController();
	input.AddCommand(ControllerInput::controllerButtons::DPAD_DOWN	, buttonState::heldDown, std::make_unique<MoveCommand>(Rotating1.get(), glm::vec3(0, 1, 0)	, 200.0f), controllerIndex);
	input.AddCommand(ControllerInput::controllerButtons::DPAD_UP	, buttonState::heldDown, std::make_unique<MoveCommand>(Rotating1.get(), glm::vec3(0, -1, 0)	, 200.0f), controllerIndex);
	input.AddCommand(ControllerInput::controllerButtons::DPAD_LEFT	, buttonState::heldDown, std::make_unique<MoveCommand>(Rotating1.get(), glm::vec3(-1, 0, 0)	, 200.0f), controllerIndex);
	input.AddCommand(ControllerInput::controllerButtons::DPAD_RIGHT	, buttonState::heldDown, std::make_unique<MoveCommand>(Rotating1.get(), glm::vec3(1, 0, 0)	, 200.0f), controllerIndex);
	scene.Add(Rotating1);	
	
	auto Rotating2 = std::make_shared<dae::GameObject>();
	Rotating2 = std::make_shared<dae::GameObject>();
	Rotating2->AddComponent<dae::TextureComponent>();
	Rotating2->GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("Character2.png"));
	input.AddCommand(SDL_SCANCODE_S, buttonState::heldDown, std::make_unique<MoveCommand>(Rotating2.get(), glm::vec3(0, 1, 0)	, 100.0f));
	input.AddCommand(SDL_SCANCODE_W, buttonState::heldDown, std::make_unique<MoveCommand>(Rotating2.get(), glm::vec3(0, -1, 0)	, 100.0f));
	input.AddCommand(SDL_SCANCODE_A, buttonState::heldDown, std::make_unique<MoveCommand>(Rotating2.get(), glm::vec3(-1, 0, 0)	, 100.0f));
	input.AddCommand(SDL_SCANCODE_D, buttonState::heldDown, std::make_unique<MoveCommand>(Rotating2.get(), glm::vec3(1, 0, 0)	, 100.0f));
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

int main(int, char* []) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
	return 0;
}