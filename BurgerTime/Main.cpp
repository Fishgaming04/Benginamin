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
#include "CounterComponent.h"
#include "CounterIncreaseObserver.h"
#include "SoundSignleton.h"
#include "StateMachine.h"
#include "CollisionSubject.h"
#include "TriggerSoundCommand.h"
#include "JsonReader.h"
#include "CollisionPlayerComponent.h"
#include "PeterCommands.h"
#include "EnemyComponent.h"
#include "EnemyCollisionComponent.h"
#include "CounterDisplay.h"

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

	//soundManager.PlayMusic("../Data/BurgerTime/Soundtrack.mp3", -1);
	int sound = soundManager.LoadSound("../Data/BurgerTime/Soundtrack.mp3");
	soundManager.SetVolume(0);
	auto subject = std::make_shared<Subject>();
	auto  CounterSubject = std::make_shared<Subject>();
		
	auto Counter = std::make_unique<dae::GameObject>();

	Counter->AddComponent<dae::CounterComponent>();
	Counter->AddComponent<dae::CounterIncreaseObserver>();
	Counter->GetComponent<dae::CounterIncreaseObserver>()->setCounterName("Points");

	subject->AddObserver(Counter->GetComponent<dae::CounterIncreaseObserver>());

	auto Text = std::make_unique<dae::GameObject>();
	Text->AddComponent<dae::TextureComponent>();
	Text->AddComponent<dae::TextComponent>();
	Text->GetComponent<dae::TextComponent>()->SetText("Points: 0");
	Text->GetComponent<dae::TextComponent>()->SetFont(recourceManager.LoadFont("Lingua.otf", 36));
	Text->GetComponent<dae::TextComponent>()->SetColor(SDL_Color{ 255, 0, 0, 255 });
	Text->setLocalPosition(20, 80, 0);
	Text->AddComponent<dae::CounterDisplay>();
	Text->GetComponent<dae::CounterDisplay>()->SetCounter("Points");
	Text->GetComponent<dae::CounterDisplay>()->SetPrefix("Points: ");


	CounterSubject->AddObserver(Text->GetComponent<dae::CounterDisplay>());
	Counter->GetComponent<dae::CounterComponent>()->setSubject(CounterSubject);

	

	JsonReader reader{480,480,4,12};
	reader.setSubject(subject);
	reader.setLevelLadder				(recourceManager.LoadTexture( "../Data/BurgerTime/Ladders/Ladder1.png"));
	reader.setLevelPlatform				(recourceManager.LoadTexture( "../Data/BurgerTime/Platforms/Platform1.png"));
	reader.setPlatterTexture			(recourceManager.LoadTexture( "../Data/BurgerTime/Misc/Plate.png"));
	reader.setLevelBurgerTopTexture		(recourceManager.LoadTexture("../Data/BurgerTime/Ingredients/BunTopSide.png"), recourceManager.LoadTexture("../Data/BurgerTime/Ingredients/BunTopMiddle.png"));
	reader.setLevelBurgerMeatTexture	(recourceManager.LoadTexture("../Data/BurgerTime/Ingredients/PattySide.png"), recourceManager.LoadTexture("../Data/BurgerTime/Ingredients/PattyMiddle.png"));
	reader.setLevelBurgerLettuceTexture	(recourceManager.LoadTexture("../Data/BurgerTime/Ingredients/LettuceSide.png"), recourceManager.LoadTexture("../Data/BurgerTime/Ingredients/LettuceMiddle.png"));
	reader.setLevelBurgerCheeseTexture	(recourceManager.LoadTexture("../Data/BurgerTime/Ingredients/CheeseSide.png"), recourceManager.LoadTexture("../Data/BurgerTime/Ingredients/CheeseMiddle.png"));
	reader.setLevelBurgerTomatoTexture	(recourceManager.LoadTexture("../Data/BurgerTime/Ingredients/TomatoSide.png"), recourceManager.LoadTexture("../Data/BurgerTime/Ingredients/TomatoMiddle.png"));
	reader.setLevelBurgerBottomTexture	(recourceManager.LoadTexture("../Data/BurgerTime/Ingredients/BunBottomSide.png"), recourceManager.LoadTexture("../Data/BurgerTime/Ingredients/BunBottomMiddle.png"));
	reader.readLevelJson("../Data/BurgerTime/Levels/Level1.json", scene);



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
	std::cout << "main controller: " << controllerIndex << std::endl;
	auto Peter = std::make_unique<dae::GameObject>();
	Peter = std::make_unique<dae::GameObject>();
	Peter->AddComponent<dae::TextureComponent>();
	Peter->GetComponent<dae::TextureComponent>()->SetTexture(recourceManager.LoadTexture("BurgerTime/Sprites/Peter.png"));
	Peter->AddComponent<dae::StateMachine>();
	Peter->GetTransform()->SetSize(16, 18);
	Peter->setLocalPosition(240, 53, 0);
	Peter->setTag("Player");
	Peter->AddComponent<dae::CollisionPlayersComponent>();
	CollsionSubject.AddObserver(Peter->GetComponent<dae::CollisionPlayersComponent>());
	CollsionSubject.addMovingGameObject(Peter.get());
	input.AddCommand(SDL_SCANCODE_A, buttonState::down, std::make_unique<PeterWalkStateCommand>(Peter.get()));
	input.AddCommand(SDL_SCANCODE_D, buttonState::down, std::make_unique<PeterWalkStateCommand>(Peter.get()));
	input.AddCommand(SDL_SCANCODE_W, buttonState::down, std::make_unique<PeterClimbStateCommand>(Peter.get()));
	input.AddCommand(SDL_SCANCODE_S, buttonState::down, std::make_unique<PeterClimbStateCommand>(Peter.get()));
	input.AddCommand(SDL_SCANCODE_A, buttonState::heldDown, std::make_unique<PeterWalkCommand>(Peter.get(),  glm::vec3(-1, 0, 0), 100.0f));
	input.AddCommand(SDL_SCANCODE_D, buttonState::heldDown, std::make_unique<PeterWalkCommand>(Peter.get(),  glm::vec3(1,  0, 0), 100.0f));	
	input.AddCommand(SDL_SCANCODE_W, buttonState::heldDown, std::make_unique<PeterClimbCommand>(Peter.get(), glm::vec3(0, -1, 0), 100.0f));
	input.AddCommand(SDL_SCANCODE_S, buttonState::heldDown, std::make_unique<PeterClimbCommand>(Peter.get(), glm::vec3(0,  1, 0), 100.0f));
	input.AddCommand(SDL_SCANCODE_A, buttonState::up, std::make_unique<PeterIdleStateCommand>(Peter.get()));
	input.AddCommand(SDL_SCANCODE_D, buttonState::up, std::make_unique<PeterIdleStateCommand>(Peter.get()));
	input.AddCommand(SDL_SCANCODE_W, buttonState::up, std::make_unique<PeterIdleStateCommand>(Peter.get()));
	input.AddCommand(SDL_SCANCODE_S, buttonState::up, std::make_unique<PeterIdleStateCommand>(Peter.get()));
	input.AddCommand(SDL_SCANCODE_F, buttonState::up, std::make_unique<TriggerSound>(sound));
	input.AddCommand(ControllerInput::controllerButtons::DPAD_LEFT	, buttonState::down, std::make_unique<PeterWalkStateCommand>(Peter.get()), controllerIndex);
	input.AddCommand(ControllerInput::controllerButtons::DPAD_RIGHT	, buttonState::down, std::make_unique<PeterWalkStateCommand>(Peter.get()), controllerIndex);
	input.AddCommand(ControllerInput::controllerButtons::DPAD_UP	, buttonState::down, std::make_unique<PeterClimbStateCommand>(Peter.get()), controllerIndex);
	input.AddCommand(ControllerInput::controllerButtons::DPAD_DOWN	, buttonState::down, std::make_unique<PeterClimbStateCommand>(Peter.get()), controllerIndex);
	input.AddCommand(ControllerInput::controllerButtons::DPAD_LEFT	, buttonState::heldDown, std::make_unique<PeterWalkCommand>(Peter.get(), glm::vec3(-1, 0, 0), 100.0f), controllerIndex);
	input.AddCommand(ControllerInput::controllerButtons::DPAD_RIGHT	, buttonState::heldDown, std::make_unique<PeterWalkCommand>(Peter.get(), glm::vec3(1, 0, 0), 100.0f), controllerIndex);
	input.AddCommand(ControllerInput::controllerButtons::DPAD_UP	, buttonState::heldDown, std::make_unique<PeterClimbCommand>(Peter.get(), glm::vec3(0, -1, 0), 100.0f), controllerIndex);
	input.AddCommand(ControllerInput::controllerButtons::DPAD_DOWN	, buttonState::heldDown, std::make_unique<PeterClimbCommand>(Peter.get(), glm::vec3(0,  1, 0), 100.0f), controllerIndex);
	input.AddCommand(ControllerInput::controllerButtons::DPAD_LEFT	, buttonState::up, std::make_unique<PeterIdleStateCommand>(Peter.get()), controllerIndex);
	input.AddCommand(ControllerInput::controllerButtons::DPAD_RIGHT	, buttonState::up, std::make_unique<PeterIdleStateCommand>(Peter.get()), controllerIndex);
	input.AddCommand(ControllerInput::controllerButtons::DPAD_UP	, buttonState::up, std::make_unique<PeterIdleStateCommand>(Peter.get()), controllerIndex);
	input.AddCommand(ControllerInput::controllerButtons::DPAD_DOWN	, buttonState::up, std::make_unique<PeterIdleStateCommand>(Peter.get()), controllerIndex);
	input.AddCommand(ControllerInput::controllerButtons::LEFT_SHOULDER, buttonState::down, std::make_unique<TriggerSound>(sound), controllerIndex);





	auto Enemy = std::make_unique<dae::GameObject>();
	std::shared_ptr<Texture2D> walkingTexture{recourceManager.LoadTexture("BurgerTime/Sprites/HotdogWalk.png")};
	std::shared_ptr<Texture2D> climbingTexture{recourceManager.LoadTexture("BurgerTime/Sprites/HotdogClimb.png")};
	std::shared_ptr<Texture2D> hitTexture{recourceManager.LoadTexture("BurgerTime/Sprites/HotdogStunned.png")};
	float speed{ 50.f };
	int points{ 100 };
	int hitDuration{ 2 };
	Enemy->AddComponent<dae::TextureComponent>();
	Enemy->GetComponent<dae::TextureComponent>()->SetTexture(walkingTexture);
	Enemy->AddComponent<dae::StateMachine>();
	Enemy->AddComponent<dae::EnemyComponent>();
	Enemy->GetComponent<dae::EnemyComponent>()->SetTextureWalking(walkingTexture);
	Enemy->GetComponent<dae::EnemyComponent>()->SetTextureClimb(climbingTexture);
	Enemy->GetComponent<dae::EnemyComponent>()->SetTextureHit(hitTexture);
	Enemy->GetComponent<dae::EnemyComponent>()->SetPlayer(Peter.get());
	Enemy->GetComponent<dae::EnemyComponent>()->SetSpeed(speed);
	Enemy->GetComponent<dae::EnemyComponent>()->SetPoints(points);
	Enemy->GetComponent<dae::EnemyComponent>()->SetHitDuration(hitDuration);
	Enemy->GetComponent<dae::EnemyComponent>()->SetSpawnPosition(glm::vec3(-40, 18, 0));
	Enemy->GetComponent<dae::EnemyComponent>()->TouchingGround();
	Enemy->GetComponent<dae::EnemyComponent>()->SetSubject(subject);
	Enemy->AddComponent<dae::CollisionEnemyComponent>();
	Enemy->GetTransform()->SetSize(16, 18);
	Enemy->setTag("Enemy");
	CollsionSubject.addMovingGameObject(Enemy.get());
	CollsionSubject.AddObserver(Enemy->GetComponent<dae::CollisionEnemyComponent>());






	scene.Add(std::move(Counter));
	scene.Add(std::move(Text));
	scene.Add(std::move(Peter));
	scene.Add(std::move(Enemy));
}



int main(int, char* []) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
	return 0;
}