#pragma once

namespace dae {

	class ControllerInputImpl;
	class ControllerInput final
	{

	private:
		ControllerInputImpl* m_pImpl;
	public:

		enum class controllerButtons {
			DPAD_UP			= 0x0001,
			DPAD_DOWN		= 0x0002,
			DPAD_LEFT		= 0x0004,
			DPAD_RIGHT		= 0x0008,
			START			= 0x0010,
			BACK			= 0x0020,
			LEFT_THUMB		= 0x0040,
			RIGHT_THUMB		= 0x0080,
			LEFT_SHOULDER	= 0x0100,
			RIGHT_SHOULDER	= 0x0200,
			BUTTON_A		= 0x1000,
			BUTTON_B		= 0x2000,
			BUTTON_X		= 0x4000,
			BUTTON_Y		= 0x8000
		};


		ControllerInput(unsigned int controllerIndex);

		void update();

		bool IsDownThisFrame(controllerButtons button) const;
		bool IsUpThisFrame(controllerButtons button) const;
		bool IsPressed(controllerButtons button) const;

		unsigned int GetControllerIndex() const;
		
		~ControllerInput();
		ControllerInput(const ControllerInput& other) = delete;
		ControllerInput(ControllerInput&& other) = delete;
		ControllerInput& operator=(const ControllerInput& other) = delete;
		ControllerInput& operator=(ControllerInput&& other) = delete;
	};
}

