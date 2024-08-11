#pragma once
#include "Command.h"


namespace dae {
	class PeterWalkStateCommand : public StateCommand
	{
	public:
		PeterWalkStateCommand(GameObject* object);
		virtual ~PeterWalkStateCommand() override;
		virtual void Execute(float) override;

	};


	class PeterClimbStateCommand : public StateCommand
	{
	public:
		PeterClimbStateCommand(GameObject* object);
		virtual ~PeterClimbStateCommand() override;
		virtual void Execute(float) override;

	};

	class PeterIdleStateCommand : public StateCommand
	{
	public:
		PeterIdleStateCommand(GameObject* object);
		virtual ~PeterIdleStateCommand() override;
		virtual void Execute(float) override;

	};

	


}

