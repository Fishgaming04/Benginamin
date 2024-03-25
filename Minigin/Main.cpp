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
#include <iostream>
#include <steam_api.h>
#include "Achievements.h"
#include "steam_api.h"
#include "AchievementObserver.h"
#include "CounterTriggerAchievementObserver.h"
using namespace dae;


// Defining our achievements
enum EAchievements
{
	ACH_WIN_ONE_GAME = 0,
	ACH_WIN_100_GAMES = 1,
	ACH_TRAVEL_FAR_ACCUM = 2,
	ACH_TRAVEL_FAR_SINGLE = 3,
	NEW_ACHIEVEMENT_0_4 = 4,
};

Achievement_t g_Achievements[] =
{
	_ACH_ID(ACH_WIN_ONE_GAME, "Winner"),
	_ACH_ID(ACH_WIN_100_GAMES, "Champion"),
	_ACH_ID(ACH_TRAVEL_FAR_ACCUM, "Interstellar"),
	_ACH_ID(ACH_TRAVEL_FAR_SINGLE, "Orbiter"),
	_ACH_ID(NEW_ACHIEVEMENT_0_4, "NEW_ACHIEVEMENT_NAME_0_4")
};

CSteamAchievements* g_SteamAchievements = nullptr;

auto achievementObserver{ new dae::AchievementObserver() } ;

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
	Rotating1->AddComponent<dae::CounterComponent>();
	Rotating1->GetComponent<dae::CounterComponent>()->SetCounter("Health", 100);
	Rotating1->GetComponent<dae::CounterComponent>()->SetCounter("Exp", 0);
	input.AddCommand(SDL_SCANCODE_K, buttonState::heldDown	, std::make_unique<MoveCommand>(Rotating1.get()		, glm::vec3(0, 1, 0)	, 100.0f));
	input.AddCommand(SDL_SCANCODE_I, buttonState::heldDown	, std::make_unique<MoveCommand>(Rotating1.get()		, glm::vec3(0, -1, 0)	, 100.0f));
	input.AddCommand(SDL_SCANCODE_J, buttonState::heldDown	, std::make_unique<MoveCommand>(Rotating1.get()		, glm::vec3(-1, 0, 0)	, 100.0f));
	input.AddCommand(SDL_SCANCODE_L, buttonState::heldDown	, std::make_unique<MoveCommand>(Rotating1.get()		, glm::vec3(1, 0, 0)	, 100.0f));
	input.AddCommand(SDL_SCANCODE_N, buttonState::up		, std::make_unique<IncreaseCounter>(Rotating1.get()	, "Health"				, -10));
	input.AddCommand(SDL_SCANCODE_M, buttonState::up		, std::make_unique<IncreaseCounter>(Rotating1.get()	, "Exp"					, 1));
	scene.Add(Rotating1);
	
	auto Rotating2 = std::make_shared<dae::GameObject>();
	Rotating2 = std::make_shared<dae::GameObject>();
	Rotating2->AddComponent<dae::TextureComponent>();
	Rotating2->GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("Character2.png"));
	Rotating2->AddComponent<dae::CounterComponent>();
	Rotating2->GetComponent<dae::CounterComponent>()->SetCounter("Health", 100);
	Rotating2->GetComponent<dae::CounterComponent>()->SetCounter("Exp", 0);
	input.AddCommand(SDL_SCANCODE_S, buttonState::heldDown, std::make_unique<MoveCommand>(Rotating2.get(), glm::vec3(0, 1, 0)	, 100.0f));
	input.AddCommand(SDL_SCANCODE_W, buttonState::heldDown, std::make_unique<MoveCommand>(Rotating2.get(), glm::vec3(0, -1, 0)	, 100.0f));
	input.AddCommand(SDL_SCANCODE_A, buttonState::heldDown, std::make_unique<MoveCommand>(Rotating2.get(), glm::vec3(-1, 0, 0)	, 100.0f));
	input.AddCommand(SDL_SCANCODE_D, buttonState::heldDown, std::make_unique<MoveCommand>(Rotating2.get(), glm::vec3(1, 0, 0)	, 100.0f));
	input.AddCommand(SDL_SCANCODE_X, buttonState::up, std::make_unique<IncreaseCounter>(Rotating2.get(), "Health" , -10));
	input.AddCommand(SDL_SCANCODE_C, buttonState::up, std::make_unique<IncreaseCounter>(Rotating2.get(), "Exp"	, 1));
	scene.Add(Rotating2);

	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 20);
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

	achievementObserver->setAchievements(g_SteamAchievements);


	gameObj = std::make_shared<dae::GameObject>();
	gameObj->AddComponent<dae::TextureComponent>();
	gameObj->AddComponent<dae::TextComponent>();
	gameObj->GetComponent<dae::TextComponent>()->SetFont(font);
	std::string prefix = "Health: ";
	gameObj->GetComponent<dae::TextComponent>()->SetText(prefix + std::to_string(Rotating2->GetComponent<dae::CounterComponent>()->GetCounter("Health")));
	gameObj->GetComponent<dae::TextComponent>()->SetColor(SDL_Color(0, 255, 0, 255));
	gameObj->AddComponent<dae::CounterComponentObserver>();
	gameObj->GetComponent<dae::CounterComponentObserver>()->SetCounter("Health");
	gameObj->GetComponent<dae::CounterComponentObserver>()->SetPrefix(prefix);
	gameObj->GetComponent<dae::CounterComponentObserver>()->AddIsWatching(Rotating2.get());
	gameObj->setLocalPosition(20, 100, 0);
	scene.Add(gameObj);


	gameObj = std::make_shared<dae::GameObject>();
	gameObj->AddComponent<dae::TextureComponent>();
	gameObj->AddComponent<dae::TextComponent>();
	gameObj->GetComponent<dae::TextComponent>()->SetFont(font);
	std::string prefixExp = "Exp: ";
	gameObj->GetComponent<dae::TextComponent>()->SetText(prefixExp + std::to_string(Rotating2->GetComponent<dae::CounterComponent>()->GetCounter("Exp")));
	gameObj->GetComponent<dae::TextComponent>()->SetColor(SDL_Color(0, 255, 0, 255));
	gameObj->AddComponent<dae::CounterComponentObserver>();
	gameObj->GetComponent<dae::CounterComponentObserver>()->SetCounter("Exp");
	gameObj->GetComponent<dae::CounterComponentObserver>()->SetPrefix(prefixExp);
	gameObj->GetComponent<dae::CounterComponentObserver>()->AddIsWatching(Rotating2.get());
	gameObj->AddComponent<dae::CounterTriggerAchievementObserver>();
	gameObj->GetComponent<dae::CounterTriggerAchievementObserver>()->SetAchievementObserver(achievementObserver);
	gameObj->GetComponent<dae::CounterTriggerAchievementObserver>()->SetCounterTrigger("Exp", 15);
	gameObj->GetComponent<dae::CounterTriggerAchievementObserver>()->SetAchievement(Event::Win);
	gameObj->GetComponent<dae::CounterTriggerAchievementObserver>()->AddIsWatching(Rotating2.get());
	gameObj->setLocalPosition(20, 140, 0);
	scene.Add(gameObj);

	gameObj = std::make_shared<dae::GameObject>();
	gameObj->AddComponent<dae::TextureComponent>();
	gameObj->AddComponent<dae::TextComponent>();
	gameObj->GetComponent<dae::TextComponent>()->SetFont(font);
	gameObj->GetComponent<dae::TextComponent>()->SetText(prefixExp + std::to_string(Rotating1->GetComponent<dae::CounterComponent>()->GetCounter("Exp")));
	gameObj->GetComponent<dae::TextComponent>()->SetColor(SDL_Color(0, 255, 255, 255));
	gameObj->AddComponent<dae::CounterComponentObserver>();
	gameObj->GetComponent<dae::CounterComponentObserver>()->SetCounter("Exp");
	gameObj->GetComponent<dae::CounterComponentObserver>()->SetPrefix(prefixExp);
	gameObj->GetComponent<dae::CounterComponentObserver>()->AddIsWatching(Rotating1.get());
	gameObj->AddComponent<dae::CounterTriggerAchievementObserver>();
	gameObj->GetComponent<dae::CounterTriggerAchievementObserver>()->SetAchievementObserver(achievementObserver);
	gameObj->GetComponent<dae::CounterTriggerAchievementObserver>()->SetCounterTrigger("Exp", 15);
	gameObj->GetComponent<dae::CounterTriggerAchievementObserver>()->SetAchievement(Event::Win);
	gameObj->GetComponent<dae::CounterTriggerAchievementObserver>()->AddIsWatching(Rotating1.get());
	gameObj->setLocalPosition(20, 220, 0);
	scene.Add(gameObj);

	gameObj = std::make_shared<dae::GameObject>();
	gameObj->AddComponent<dae::TextureComponent>();
	gameObj->AddComponent<dae::TextComponent>();
	gameObj->GetComponent<dae::TextComponent>()->SetFont(font);
	gameObj->GetComponent<dae::TextComponent>()->SetText(prefix + std::to_string(Rotating1->GetComponent<dae::CounterComponent>()->GetCounter("Health")));
	gameObj->GetComponent<dae::TextComponent>()->SetColor(SDL_Color(0, 255, 255, 255));
	gameObj->AddComponent<dae::CounterComponentObserver>();
	gameObj->GetComponent<dae::CounterComponentObserver>()->SetCounter("Health");
	gameObj->GetComponent<dae::CounterComponentObserver>()->SetPrefix(prefix);
	gameObj->GetComponent<dae::CounterComponentObserver>()->AddIsWatching(Rotating1.get());
	gameObj->setLocalPosition(20, 180, 0);
	scene.Add(gameObj);


	gameObj = std::make_shared<dae::GameObject>();
	gameObj->AddComponent<dae::TextureComponent>();
	gameObj->AddComponent<dae::TextComponent>();
	gameObj->GetComponent<dae::TextComponent>()->SetFont(font);
	gameObj->GetComponent<dae::TextComponent>()->SetText("Use wasd to move and x and c to get points and take damage");
	gameObj->GetComponent<dae::TextComponent>()->SetColor(SDL_Color(0, 255, 0, 255));
	gameObj->setLocalPosition(20, 260, 0);
	scene.Add(gameObj);

	gameObj = std::make_shared<dae::GameObject>();
	gameObj->AddComponent<dae::TextureComponent>();
	gameObj->AddComponent<dae::TextComponent>();
	gameObj->GetComponent<dae::TextComponent>()->SetFont(font);
	gameObj->GetComponent<dae::TextComponent>()->SetText("Use IJKL to move and N and M to get points and take damage");
	gameObj->GetComponent<dae::TextComponent>()->SetColor(SDL_Color(0, 255, 255, 255));
	gameObj->setLocalPosition(20, 280, 0); 
	scene.Add(gameObj);

} 

int main(int, char* []) {
	//SteamErrMsg errMsg;
	if (!SteamAPI_Init())
	{
		std::cerr << "Fatal Error - Steam must be running to play this game (SteamAPI_Init() failed)." << std::endl;
		//std::cout << errMsg << std::endl;
	}
	else {
		g_SteamAchievements = new CSteamAchievements(g_Achievements, 4);
		std::cout << "Successfully initialized steam." << std::endl;
		//std::cout << errMsg << std::endl;
	}
	dae::Minigin engine("../Data/");
	engine.Run(load); 
	if (achievementObserver) delete achievementObserver;
	if (g_SteamAchievements) delete g_SteamAchievements;
	SteamAPI_Shutdown();
	return 0;
}
