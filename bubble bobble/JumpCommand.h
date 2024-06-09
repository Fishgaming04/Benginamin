#pragma once
#include "Command.h"

namespace dae {

	class JumpCommand : public StateCommand
	{
	public:
		JumpCommand(GameObject* object, float jumpheight);

		virtual void Execute(float) override;

		//rule of 5
		virtual ~JumpCommand() override;
		JumpCommand(const JumpCommand& other) = delete;
		JumpCommand(JumpCommand&& other) = delete;
		JumpCommand& operator=(const JumpCommand& other) = delete;
		JumpCommand& operator=(JumpCommand&& other) = delete;
	private:
		const float m_JumpHeight;
		const double m_maxMomentum{ 0.3 };
	};

}

