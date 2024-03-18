#pragma once
#include <Windows.h>
#include <Xinput.h>
#include <map>
#include "Singleton.h"
#include "Command.h"
#include <vector>
#include "ControllerInput.h"
#include "KeyboardInput.h"
#include <memory>
#pragma comment(lib, "xinput.lib")


namespace dae
{

	enum class buttonState {
		down,
		up,
		heldDown
	};

	class InputManager final : public Singleton<InputManager>
	{
	public:
		bool ProcessInput(float deltaTime);

		void AddCommand(const ControllerInput::controllerButtons button, const buttonState state, std::unique_ptr<Command>, const unsigned int controllerIndex);
		void AddCommand(const SDL_Scancode key, const buttonState state, std::unique_ptr<Command> command);
		void RemoveCommand(const ControllerInput::controllerButtons button, const buttonState state, const unsigned int controllerIndex);
		void RemoveCommand(const SDL_Scancode key, const buttonState state);

		unsigned int AddController();


	private:

		
		//Controller
		
		using ControllerButton		= std::pair<unsigned int, ControllerInput::controllerButtons>;
		using ControllerButtonState = std::pair<ControllerButton, buttonState>;
		using ControllerCommands	= std::map<ControllerButtonState, std::unique_ptr<Command>>;
	
		ControllerCommands m_ControllerCommands{};
		std::vector<std::unique_ptr<ControllerInput>> m_Controllers{};

		const unsigned int m_MaxControllers = 4;

		//Keyboard

		using KeyboardKeyState		= std::pair<SDL_Keycode, buttonState>;
		using KeyboardCommands		= std::map<KeyboardKeyState, std::unique_ptr<Command>>;

		KeyboardCommands m_KeyboardCommands{};


		KeyboardInput m_Keyboard{};
	
	};

}
