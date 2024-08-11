#pragma once
#include "Command.h"
#include "GameObject.h"
#include "BubStates.h"
#include "StateMachine.h"


namespace dae {

	class BubWalkCommand : public GameObjectCommand
	{
	public:
		BubWalkCommand(GameObject* object);
		virtual ~BubWalkCommand() override;
		virtual void Execute(float) override;

	};

	class BubJumpCommand : public GameObjectCommand
	{
	public:
		BubJumpCommand(GameObject* object);
		virtual ~BubJumpCommand() override;
		virtual void Execute(float) override;

	};

	class BubShootCommand : public GameObjectCommand
	{
	public:
		BubShootCommand(GameObject* object);
		virtual ~BubShootCommand() override;
		virtual void Execute(float) override;

	};

	class BubIdleCommand : public GameObjectCommand
	{
	public:
		BubIdleCommand(GameObject* object);
		virtual ~BubIdleCommand() override;
		virtual void Execute(float) override;

	};

	class BubHitCommand : public GameObjectCommand
	{
	public:
		BubHitCommand(GameObject* object);
		virtual ~BubHitCommand() override;
		virtual void Execute(float) override;

	};


}
