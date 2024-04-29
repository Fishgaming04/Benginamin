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
#include "CounterComponent.h"
#include "CounterComponentObserver.h"
#include "SoundSignleton.h"
#include "TriggerSoundCommand.h"

using namespace dae;


void load()
{

<<<<<<< HEAD
<<<<<<< HEAD
	auto soundsystem = std::make_unique<SoundSystem>();
	SoundSingleton::provide(std::move(soundsystem));
	SoundSingleton::enableAudioLogging();
=======
	ConsoleAudio* soundsystem{ new ConsoleAudio{} };
	soundsystem;
	SoundSingleton::provide(soundsystem);
>>>>>>> parent of 03d3b21 (memory leaks but works)
=======
	ConsoleAudio* soundsystem{ new ConsoleAudio{} };
	soundsystem;
	SoundSingleton::provide(soundsystem);
>>>>>>> parent of 03d3b21 (memory leaks but works)
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");
	auto& recourceManager = dae::ResourceManager::GetInstance();
	//auto& soundManager = dae::SoundSingleton::getAudio();
	auto& input = InputManager::GetInstance();

	auto gameObj = std::make_shared<dae::GameObject>();

	
<<<<<<< HEAD
<<<<<<< HEAD
	//soundManager.PlayMusic("../Data/Music/06_SuperDrunk.mp3", -1);
	//int sound = soundManager.LoadSound("../Data/SoundEffects/Bubble_Bobble_SFX2.wav");
=======
	int sound = soundManager.LoadSound("../Data/Music/06_SuperDrunk.mp3");
	int sound2 = soundManager.LoadSound("../Data/SoundEffects/Bubble_Bobble_SFX2.wav");
>>>>>>> parent of 03d3b21 (memory leaks but works)
=======
	int sound = soundManager.LoadSound("../Data/Music/06_SuperDrunk.mp3");
	int sound2 = soundManager.LoadSound("../Data/SoundEffects/Bubble_Bobble_SFX2.wav");
>>>>>>> parent of 03d3b21 (memory leaks but works)

	auto Rotating1 = std::make_shared<dae::GameObject>();
	Rotating1 = std::make_shared<dae::GameObject>();
	Rotating1->AddComponent<dae::TextureComponent>();
	Rotating1->GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("Character1.png"));
	unsigned int controllerIndex = input.AddController();
	input.AddCommand(ControllerInput::controllerButtons::DPAD_DOWN, buttonState::heldDown, std::make_unique<MoveCommand>(Rotating1.get(), glm::vec3(0, 1, 0), 200.0f), controllerIndex);
	input.AddCommand(ControllerInput::controllerButtons::DPAD_UP, buttonState::heldDown, std::make_unique<MoveCommand>(Rotating1.get(), glm::vec3(0, -1, 0), 200.0f), controllerIndex);
	input.AddCommand(ControllerInput::controllerButtons::DPAD_LEFT, buttonState::heldDown, std::make_unique<MoveCommand>(Rotating1.get(), glm::vec3(-1, 0, 0), 200.0f), controllerIndex);
	input.AddCommand(ControllerInput::controllerButtons::DPAD_RIGHT, buttonState::heldDown, std::make_unique<MoveCommand>(Rotating1.get(), glm::vec3(1, 0, 0), 200.0f), controllerIndex);
	scene.Add(Rotating1);

	auto Rotating2 = std::make_shared<dae::GameObject>();
	Rotating2 = std::make_shared<dae::GameObject>();
	Rotating2->AddComponent<dae::TextureComponent>();
	Rotating2->GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("Character2.png"));
	Rotating2->AddComponent<dae::CounterComponent>();
	Rotating2->GetComponent<dae::CounterComponent>()->SetCounter("Health", 100);
	Rotating2->GetComponent<dae::CounterComponent>()->SetCounter("Exp", 0);
	input.AddCommand(SDL_SCANCODE_S, buttonState::heldDown, std::make_unique<MoveCommand>(Rotating2.get(), glm::vec3(0, 1, 0), 100.0f));
	input.AddCommand(SDL_SCANCODE_W, buttonState::heldDown, std::make_unique<MoveCommand>(Rotating2.get(), glm::vec3(0, -1, 0), 100.0f));
	input.AddCommand(SDL_SCANCODE_A, buttonState::heldDown, std::make_unique<MoveCommand>(Rotating2.get(), glm::vec3(-1, 0, 0), 100.0f));
	input.AddCommand(SDL_SCANCODE_D, buttonState::heldDown, std::make_unique<MoveCommand>(Rotating2.get(), glm::vec3(1, 0, 0), 100.0f));
	input.AddCommand(SDL_SCANCODE_X, buttonState::up, std::make_unique<IncreaseCounter>(Rotating2.get(), "Health", -10));
	input.AddCommand(SDL_SCANCODE_C, buttonState::up, std::make_unique<IncreaseCounter>(Rotating2.get(), "Exp", 1));
<<<<<<< HEAD
<<<<<<< HEAD
	//input.AddCommand(SDL_SCANCODE_F, buttonState::up, std::make_unique<TriggerSound>(sound));
=======
	input.AddCommand(SDL_SCANCODE_F, buttonState::up, std::make_unique<TriggerSound>(sound2));
>>>>>>> parent of 03d3b21 (memory leaks but works)
=======
	input.AddCommand(SDL_SCANCODE_F, buttonState::up, std::make_unique<TriggerSound>(sound2));
>>>>>>> parent of 03d3b21 (memory leaks but works)
	scene.Add(Rotating2);

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
	gameObj->GetComponent<dae::TextComponent>()->SetText(prefix + std::to_string(Rotating2->GetComponent<dae::CounterComponent>()->GetCounter("Health")));
	gameObj->GetComponent<dae::TextComponent>()->SetColor(SDL_Color{ 0, 255, 0, 255 });
	gameObj->AddComponent<dae::CounterComponentObserver>();
	gameObj->GetComponent<dae::CounterComponentObserver>()->SetCounter("Health");
	gameObj->GetComponent<dae::CounterComponentObserver>()->SetPrefix(prefix);
	gameObj->GetComponent<dae::CounterComponentObserver>()->SetIsWatching(Rotating2.get());
	gameObj->setLocalPosition(20, 100, 0);
	scene.Add(gameObj);


	gameObj = std::make_shared<dae::GameObject>();
	gameObj->AddComponent<dae::TextureComponent>();
	gameObj->AddComponent<dae::TextComponent>();
	gameObj->GetComponent<dae::TextComponent>()->SetFont(font);
	std::string prefixExp = "Exp: ";
	gameObj->GetComponent<dae::TextComponent>()->SetText(prefixExp + std::to_string(Rotating2->GetComponent<dae::CounterComponent>()->GetCounter("Exp")));
	gameObj->GetComponent<dae::TextComponent>()->SetColor(SDL_Color{ 0, 255, 0, 255 });
	gameObj->AddComponent<dae::CounterComponentObserver>();
	gameObj->GetComponent<dae::CounterComponentObserver>()->SetCounter("Exp");
	gameObj->GetComponent<dae::CounterComponentObserver>()->SetPrefix(prefixExp);
	gameObj->GetComponent<dae::CounterComponentObserver>()->SetIsWatching(Rotating2.get());
	gameObj->setLocalPosition(20, 140, 0);
	scene.Add(gameObj);

	
	soundManager.PlaySoundEffect(sound);
}



int main(int, char* []) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
	return 0;
}