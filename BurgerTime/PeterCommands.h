#pragma once
#include "Command.h"


namespace dae {
	class PeterWalkStateCommand final : public GameObjectCommand
	{
	public:
		PeterWalkStateCommand(GameObject* object);
		virtual ~PeterWalkStateCommand() override;
		virtual void Execute(float) override;

	};


	class PeterClimbStateCommand final : public GameObjectCommand
	{
	public:
		PeterClimbStateCommand(GameObject* object);
		virtual ~PeterClimbStateCommand() override;
		virtual void Execute(float) override;

	};

	class PeterIdleStateCommand final : public GameObjectCommand
	{
	public:
		PeterIdleStateCommand(GameObject* object);
		virtual ~PeterIdleStateCommand() override;
		virtual void Execute(float) override;

	};

	


}

