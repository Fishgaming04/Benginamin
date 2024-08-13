#pragma once
#include "Command.h"
#include "Sound.h"
#include "SoundSignleton.h"
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

	class PeterWalkCommand final : public GameObjectCommand
	{
	public:
		PeterWalkCommand(GameObject* object, glm::vec3 direction, float speed = 20.0f);
		virtual ~PeterWalkCommand() override;
		virtual void Execute(float) override;
	private:
		MoveCommand* m_MoveCommand;
	};

	class PeterClimbCommand final : public GameObjectCommand
	{
	public:
		PeterClimbCommand(GameObject* object, glm::vec3 direction, float speed = 20.0f);
		virtual ~PeterClimbCommand() override;
		virtual void Execute(float) override;
	private:
		MoveCommand* m_MoveCommand;
	};
	

	class MuteMusicbCommand final : public GameObjectCommand
	{
	public:
		MuteMusicbCommand();
		virtual ~MuteMusicbCommand() override;
		virtual void Execute(float) override;
	private:
		bool m_IsMuted;
		Sound& m_Sound;
	};

}

