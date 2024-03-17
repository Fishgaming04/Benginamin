#pragma once
#include <Windows.h>
#include <Xinput.h>
#include <map>
#include "Singleton.h"
#include "Command.h"
#include <vector>
#include "ControllerInput.h"
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
		InputManager();
		bool ProcessInput(float deltaTime);

		void AddCommand(const ControllerInput::controllerButtons button, const buttonState state, Command* command, const unsigned int controllerIndex);
		void RemoveCommand(const ControllerInput::controllerButtons button, const buttonState state, const unsigned int controllerIndex);

		//Put in controller class
		//bool IsDownThisFrame(unsigned int button) const;
		//bool IsUpThisFrame(unsigned int button) const;
		//bool IsPressed(unsigned int button) const;


		~InputManager();
		InputManager(const InputManager& other) = delete;
		InputManager(InputManager&& other) = delete;
		InputManager& operator=(const InputManager& other) = delete;
		InputManager& operator=(InputManager&& other) = delete;


	private:

		const unsigned int m_MaxControllers = 4;

		//XINPUT_STATE previousState;
		//XINPUT_STATE currentState;
		//unsigned int* buttonsPressedThisFrame;
		//unsigned int* buttonsReleasedThisFrame;
		
		using ControllerButton		= std::pair<unsigned int, ControllerInput::controllerButtons>;
		using ControllerButtonState = std::pair<ControllerButton, buttonState>;
		using ControllerCommands	= std::map<ControllerButtonState, Command*>;
	
		ControllerCommands m_ControllerCommands{};

		std::vector<ControllerInput*> m_Controllers{};
	};

}
