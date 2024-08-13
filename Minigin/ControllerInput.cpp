#include "ControllerInput.h"
#include <Windows.h>
#include <Xinput.h>
#include <iostream>
//#pragma comment(lib, "xinput.lib")
namespace dae {
	
	//ControllerInputImpl
	class ControllerInput::ControllerInputImpl final
	{
	public:
			ControllerInputImpl(unsigned int controllerIndex);

			void update();

			bool IsDownThisFrame(ControllerInput::controllerButtons button) const;
			bool IsUpThisFrame(ControllerInput::controllerButtons button) const;
			bool IsPressed(ControllerInput::controllerButtons button) const;

			unsigned int GetControllerIndex() const { return m_ControllerIndex; }

			~ControllerInputImpl() {};
			ControllerInputImpl(const ControllerInputImpl& other) = delete;
			ControllerInputImpl(ControllerInputImpl&& other) = delete;
			ControllerInputImpl& operator=(const ControllerInputImpl& other) = delete;
			ControllerInputImpl& operator=(ControllerInputImpl&& other) = delete;

		private:
			const unsigned int m_ControllerIndex;
			XINPUT_STATE previousState;
			XINPUT_STATE currentState;
			unsigned int buttonsPressedThisFrame;
			unsigned int buttonsReleasedThisFrame;
	};


	//functions

	ControllerInput::ControllerInputImpl::ControllerInputImpl(unsigned int controllerIndex)
		: previousState{}
		, currentState{}
		, buttonsPressedThisFrame{}
		, buttonsReleasedThisFrame{}
		, m_ControllerIndex{ controllerIndex }
	{
		ZeroMemory(&previousState, sizeof(XINPUT_STATE));
		ZeroMemory(&currentState, sizeof(XINPUT_STATE));
	}

	void ControllerInput::ControllerInputImpl::update()
	{
		CopyMemory(&previousState, &currentState, sizeof(XINPUT_STATE));
		ZeroMemory(&currentState, sizeof(XINPUT_STATE));
		XInputGetState(m_ControllerIndex, &currentState);

		auto buttonChanges = currentState.Gamepad.wButtons ^ previousState.Gamepad.wButtons;
		buttonsPressedThisFrame = buttonChanges & currentState.Gamepad.wButtons;
		buttonsReleasedThisFrame = buttonChanges & (~currentState.Gamepad.wButtons);

	}

	bool ControllerInput::ControllerInputImpl::IsDownThisFrame(ControllerInput::controllerButtons button) const
	{
		return buttonsPressedThisFrame & static_cast<unsigned int>(button);
	}

	bool ControllerInput::ControllerInputImpl::IsUpThisFrame(ControllerInput::controllerButtons button) const
	{
		return buttonsReleasedThisFrame & static_cast<unsigned int>(button);
	}

	bool ControllerInput::ControllerInputImpl::IsPressed(ControllerInput::controllerButtons button) const
	{
		return currentState.Gamepad.wButtons & static_cast<unsigned int>(button);
	}

	//ControllerInput

	ControllerInput::ControllerInput(unsigned int controllerIndex)
		: m_pImpl{ new ControllerInputImpl(controllerIndex) }
	{
	}

	void ControllerInput::update()
	{
		m_pImpl->update();
	}

	bool ControllerInput::IsDownThisFrame(controllerButtons button) const
	{
		return m_pImpl->IsDownThisFrame(button);
	}

	bool ControllerInput::IsUpThisFrame(controllerButtons button) const
	{
		return m_pImpl->IsUpThisFrame(button);
	}

	bool ControllerInput::IsPressed(controllerButtons button) const
	{
		return m_pImpl->IsPressed(button);	
	}

	unsigned int ControllerInput::GetControllerIndex() const
	{
		return m_pImpl->GetControllerIndex();
	}

	ControllerInput::~ControllerInput()
	{
		delete m_pImpl;
		m_pImpl = nullptr;
	}
}