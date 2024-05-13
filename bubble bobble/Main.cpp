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
#include "TriggerSoundCommand.h"
#include "BubStates.h"
#include "StateMachine.h"
#include "BubCommands.h"

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

	auto gameObj = std::make_shared<dae::GameObject>();

	soundManager.PlayMusic("../Data/Music/06_SuperDrunk.mp3", -1);
	int sound = soundManager.LoadSound("../Data/SoundEffects/Bubble_Bobble_SFX2.wav");


	auto Bob = std::make_shared<dae::GameObject>();
	Bob = std::make_shared<dae::GameObject>();
	Bob->AddComponent<dae::TextureComponent>();
	Bob->GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("Character2.png"));
	unsigned int controllerIndex = input.AddController();
	input.AddCommand(ControllerInput::controllerButtons::DPAD_DOWN, buttonState::heldDown, std::make_unique<MoveCommand>(Bob.get(), glm::vec3(0, 1, 0), 200.0f), controllerIndex);
	input.AddCommand(ControllerInput::controllerButtons::DPAD_UP, buttonState::heldDown, std::make_unique<MoveCommand>(Bob.get(), glm::vec3(0, -1, 0), 200.0f), controllerIndex);
	input.AddCommand(ControllerInput::controllerButtons::DPAD_LEFT, buttonState::heldDown, std::make_unique<MoveCommand>(Bob.get(), glm::vec3(-1, 0, 0), 200.0f), controllerIndex);
	input.AddCommand(ControllerInput::controllerButtons::DPAD_RIGHT, buttonState::heldDown, std::make_unique<MoveCommand>(Bob.get(), glm::vec3(1, 0, 0), 200.0f), controllerIndex);
	scene.Add(Bob);

	auto Bub = std::make_shared<dae::GameObject>();
	Bub = std::make_shared<dae::GameObject>();
	Bub->AddComponent<dae::TextureComponent>();
	Bub->GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("Character1.png"));
	Bub->AddComponent<dae::CounterComponent>();
	Bub->AddComponent<dae::StateMachine>();
	Bub->GetComponent<dae::StateMachine>()->SetState(new BubIdleState{});
	Bub->GetComponent<dae::CounterComponent>()->SetCounter("Health", 100);
	Bub->GetComponent<dae::CounterComponent>()->SetCounter("Exp", 0);
	input.AddCommand(SDL_SCANCODE_S, buttonState::heldDown, std::make_unique<MoveCommand>(Bub.get(), glm::vec3(0, 1, 0), 100.0f));
	input.AddCommand(SDL_SCANCODE_W, buttonState::heldDown, std::make_unique<MoveCommand>(Bub.get(), glm::vec3(0, -1, 0), 100.0f));
	input.AddCommand(SDL_SCANCODE_A, buttonState::heldDown, std::make_unique<MoveCommand>(Bub.get(), glm::vec3(-1, 0, 0), 100.0f));
	input.AddCommand(SDL_SCANCODE_D, buttonState::heldDown, std::make_unique<MoveCommand>(Bub.get(), glm::vec3(1, 0, 0), 100.0f));
	input.AddCommand(SDL_SCANCODE_A, buttonState::down, std::make_unique<BubWalkCommand>( Bub.get()));
	input.AddCommand(SDL_SCANCODE_D, buttonState::down, std::make_unique<BubWalkCommand>( Bub.get()));
	input.AddCommand(SDL_SCANCODE_D, buttonState::up,		std::make_unique<BubIdleCommand>( Bub.get()));
	input.AddCommand(SDL_SCANCODE_A, buttonState::up,		std::make_unique<BubIdleCommand>( Bub.get()));
	input.AddCommand(SDL_SCANCODE_SPACE, buttonState::down, std::make_unique<BubJumpCommand>( Bub.get()));
	input.AddCommand(SDL_SCANCODE_LSHIFT, buttonState::down,std::make_unique<BubShootCommand>(Bub.get()));
	input.AddCommand(SDL_SCANCODE_X, buttonState::up,		std::make_unique<IncreaseCounter>(Bub.get(), "Health", -10));
	input.AddCommand(SDL_SCANCODE_X, buttonState::up,		std::make_unique<BubHitCommand>( Bub.get()));
	input.AddCommand(SDL_SCANCODE_C, buttonState::up,		std::make_unique<IncreaseCounter>(Bub.get(), "Exp", 1));
	input.AddCommand(SDL_SCANCODE_F, buttonState::up,		std::make_unique<TriggerSound>(sound));	
	
	scene.Add(Bub);
	


	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	gameObj = std::make_shared<dae::GameObject>();
	gameObj->AddComponent<dae::TextureComponent>();
	gameObj->AddComponent<dae::TextComponent>();
	gameObj->GetComponent<dae::TextComponent>()->SetFont(font);
	gameObj->AddComponent<dae::FPSComponent>();
	gameObj->GetComponent<dae::TextComponent>()->SetText(std::to_string(gameObj->GetComponent<dae::FPSComponent>()->GetFps()));
	gameObj->GetComponent<dae::TextComponent>()->SetColor(SDL_Color{ 255, 0, 0, 255 });
	gameObj->setLocalPosition(20, 20, 0);
	scene.Add(gameObj);


	gameObj = std::make_shared<dae::GameObject>();
	gameObj->AddComponent<dae::TextureComponent>();
	gameObj->AddComponent<dae::TextComponent>();
	gameObj->GetComponent<dae::TextComponent>()->SetFont(font);
	std::string prefix = "Health: ";
	gameObj->GetComponent<dae::TextComponent>()->SetText(prefix + std::to_string(Bub->GetComponent<dae::CounterComponent>()->GetCounter("Health")));
	gameObj->GetComponent<dae::TextComponent>()->SetColor(SDL_Color{ 0, 255, 0, 255 });
	gameObj->AddComponent<dae::CounterComponentObserver>();
	gameObj->GetComponent<dae::CounterComponentObserver>()->SetCounter("Health");
	gameObj->GetComponent<dae::CounterComponentObserver>()->SetPrefix(prefix);
	gameObj->GetComponent<dae::CounterComponentObserver>()->SetIsWatching(Bub.get());
	gameObj->setLocalPosition(20, 100, 0);
	scene.Add(gameObj);


	gameObj = std::make_shared<dae::GameObject>();
	gameObj->AddComponent<dae::TextureComponent>();
	gameObj->AddComponent<dae::TextComponent>();
	gameObj->GetComponent<dae::TextComponent>()->SetFont(font);
	std::string prefixExp = "Exp: ";
	gameObj->GetComponent<dae::TextComponent>()->SetText(prefixExp + std::to_string(Bub->GetComponent<dae::CounterComponent>()->GetCounter("Exp")));
	gameObj->GetComponent<dae::TextComponent>()->SetColor(SDL_Color{ 0, 255, 0, 255 });
	gameObj->AddComponent<dae::CounterComponentObserver>();
	gameObj->GetComponent<dae::CounterComponentObserver>()->SetCounter("Exp");
	gameObj->GetComponent<dae::CounterComponentObserver>()->SetPrefix(prefixExp);
	gameObj->GetComponent<dae::CounterComponentObserver>()->SetIsWatching(Bub.get());
	gameObj->setLocalPosition(20, 140, 0);
	scene.Add(gameObj);

}



int main(int, char* []) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
	return 0;
}