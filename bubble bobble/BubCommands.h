#pragma once
#include "Command.h"
#include "GameObject.h"
#include "BubStates.h"
#include "StateMachine.h"


namespace dae {

	class BubWalkCommand : public StateCommand
	{
	public:
		BubWalkCommand(GameObject* object);
		virtual ~BubWalkCommand() override;
		virtual void Execute(float) override;

	};

	class BubJumpCommand : public StateCommand
	{
	public:
		BubJumpCommand(GameObject* object);
		virtual ~BubJumpCommand() override;
		virtual void Execute(float) override;

	};

	class BubShootCommand : public StateCommand
	{
	public:
		BubShootCommand(GameObject* object);
		virtual ~BubShootCommand() override;
		virtual void Execute(float) override;

	};

	class BubIdleCommand : public StateCommand
	{
	public:
		BubIdleCommand(GameObject* object);
		virtual ~BubIdleCommand() override;
		virtual void Execute(float) override;

	};

	class BubHitCommand : public StateCommand
	{
	public:
		BubHitCommand(GameObject* object);
		virtual ~BubHitCommand() override;
		virtual void Execute(float) override;

	};


}
