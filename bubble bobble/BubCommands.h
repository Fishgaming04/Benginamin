#pragma once
#include "Command.h"
#include "GameObject.h"
#include "BubStates.h"
#include "StateMachine.h"


namespace dae {

	class BubWalkCommand : public StateCommand
	{
	public:
		virtual ~BubWalkCommand() override;
		virtual void Execute(float) override;

	};

	class BubJumpCommand : public StateCommand
	{
	public:
		virtual ~BubJumpCommand() override;
		virtual void Execute(float) override;

	};

	class BubShootCommand : public StateCommand
	{
	public:
		virtual ~BubShootCommand() override;
		virtual void Execute(float) override;

	};

	class BubIdleCommand : public StateCommand
	{
	public:
		virtual ~BubIdleCommand() override;
		virtual void Execute(float) override;

	};

	class BubHitCommand : public StateCommand
	{
	public:
		virtual ~BubHitCommand() override;
		virtual void Execute(float) override;

	};


}
