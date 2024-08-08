#if _DEBUG
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif


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
#include "TextComponent.h"
#include "TextureComponent.h"
#include "Scene.h"
#include "Components.h"
#include "GameObject.h"
#include "FPSComponent.h"
#include "OrbitParentComponent.h" 
#include "InputManager.h"
#include "Command.h"
#include "CounterComponent.h"
#include "CounterComponentObserver.h"
#include "SoundSignleton.h"
#include "StateMachine.h"
#include "CollisionSubject.h"
#include "TriggerSoundCommand.h"
#include "JsonReader.h"


using namespace dae;

void load()
{
	auto soundsystem = std::make_unique<SoundSystem>();
	SoundSingleton::provide(std::move(soundsystem));
	SoundSingleton::enableAudioLogging();


	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");
	auto& recourceManager = dae::ResourceManager::GetInstance();
	auto& soundManager = dae::SoundSingleton::getAudio();
	auto& input = InputManager::GetInstance();
	auto& CollsionSubject = dae::CollisionSubject().GetInstance();

	auto gameObj = std::make_unique<dae::GameObject>();

	soundManager.PlayMusic("../Data/BurgerTime/Soundtrack.mp3", -1);
	int sound = soundManager.LoadSound("../Data/BurgerTime/Soundtrack.mp3");
	soundManager.SetVolume(0);


	//auto Bob = std::make_unique<dae::GameObject>();
	//Bob = std::make_unique<dae::GameObject>();
	//Bob->AddComponent<dae::TextureComponent>();
	//Bob->GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("Character1.png"));
	//Bob->setTag("Envirement");
	//Bob->GetTransform()->SetSize(56, 56);
	//Bob->GetTransform()->SetWorldPosition(0, 200, 0);
	//CollsionSubject.addStaticGameObject(Bob.get());
	//input.AddCommand(ControllerInput::controllerButtons::DPAD_DOWN, buttonState::heldDown, std::make_unique<MoveCommand>(Bob.get(), glm::vec3(0, 1, 0), 200.0f), controllerIndex);
	//input.AddCommand(ControllerInput::controllerButtons::DPAD_UP, buttonState::heldDown, std::make_unique<MoveCommand>(Bob.get(), glm::vec3(0, -1, 0), 200.0f), controllerIndex);
	//input.AddCommand(ControllerInput::controllerButtons::DPAD_LEFT, buttonState::heldDown, std::make_unique<MoveCommand>(Bob.get(), glm::vec3(-1, 0, 0), 200.0f), controllerIndex);
	//input.AddCommand(ControllerInput::controllerButtons::DPAD_RIGHT, buttonState::heldDown, std::make_unique<MoveCommand>(Bob.get(), glm::vec3(1, 0, 0), 200.0f), controllerIndex);
	//scene.Add(Bob);


	unsigned int controllerIndex = input.AddController();
	auto Bub = std::make_unique<dae::GameObject>();
	Bub = std::make_unique<dae::GameObject>();
	Bub->AddComponent<dae::TextureComponent>();
	Bub->GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("BurgerTime/Sprites/Peter.png"));
	Bub->AddComponent<dae::StateMachine>();
	Bub->GetTransform()->SetSize(16, 16);
	Bub->setLocalPosition(48, 432, 0);
	Bub->setTag("Player");
	CollsionSubject.addMovingGameObject(Bub.get());
	input.AddCommand(SDL_SCANCODE_A, buttonState::heldDown, std::make_unique<MoveCommand>(Bub.get(), glm::vec3(-1, 0, 0), 100.0f));
	input.AddCommand(SDL_SCANCODE_D, buttonState::heldDown, std::make_unique<MoveCommand>(Bub.get(), glm::vec3(1, 0, 0), 100.0f));
	input.AddCommand(SDL_SCANCODE_F, buttonState::up, std::make_unique<TriggerSound>(sound));
	input.AddCommand(ControllerInput::controllerButtons::DPAD_LEFT, buttonState::heldDown, std::make_unique<MoveCommand>(Bub.get(), glm::vec3(-1, 0, 0), 200.0f), controllerIndex);
	input.AddCommand(ControllerInput::controllerButtons::DPAD_RIGHT, buttonState::heldDown, std::make_unique<MoveCommand>(Bub.get(), glm::vec3(1, 0, 0), 200.0f), controllerIndex);


	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	gameObj = std::make_unique<GameObject>();
	gameObj->AddComponent<dae::TextureComponent>();
	gameObj->AddComponent<dae::TextComponent>();
	gameObj->GetComponent<dae::TextComponent>()->SetFont(font);
	gameObj->AddComponent<dae::FPSComponent>();
	gameObj->GetComponent<dae::TextComponent>()->SetText(std::to_string(gameObj->GetComponent<dae::FPSComponent>()->GetFps()));
	gameObj->GetComponent<dae::TextComponent>()->SetColor(SDL_Color{ 255, 0, 0, 255 });
	gameObj->setLocalPosition(20, 20, 0);
	scene.Add(std::move(gameObj));


	JsonReader reader;
	reader.readLevelJson("../Data/BurgerTime/Levels/Level1.json", scene);




	scene.Add(std::move(Bub));
}



int main(int, char* []) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
	return 0;
}