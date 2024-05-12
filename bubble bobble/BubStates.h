#pragma once
#include "StateMachine.h"
#include "GameObject.h"
#include "TextComponent.h"
#include "ResourceManager.h"
namespace dae {

	class BubIdleState : public State
	{
	public:
		virtual ~BubIdleState() override = default;
		//virtual State* handleInput(GameObject& gameObject) override ;
		virtual State* update(GameObject& ) override;
		virtual void enter(GameObject& gameObject) override;
		virtual void exit(GameObject& ) override;
	private:

	};


	class BubWalkingingState : public State
	{
	public:
		virtual ~BubWalkingingState() override = default;
		//virtual State* handleInput(GameObject& gameObject) override ;
		virtual State* update(GameObject& ) override;
		virtual void enter(GameObject& gameObject) override;
		virtual void exit(GameObject& ) override;
	private:

	};

	class BubJumpingState : public State
	{
	public:
		virtual ~BubJumpingState() override = default;
		//virtual State* handleInput(GameObject& gameObject) override ;
		virtual State* update(GameObject& ) override;
		virtual void enter(GameObject& gameObject) override;
		virtual void exit(GameObject& ) override;
	private:

	};

	class BubBubbleState : public State
	{
	public:
		virtual ~BubBubbleState() override = default;
		//virtual State* handleInput(GameObject& gameObject) override ;
		virtual State* update(GameObject& ) override;
		virtual void enter(GameObject& gameObject) override;
		virtual void exit(GameObject& ) override;
	private:

	};

	class BubShootingState : public State
	{
	public:
		virtual ~BubShootingState() override = default;
		//virtual State* handleInput(GameObject& gameObject) override;
		virtual State* update(GameObject& ) override;
		virtual void enter(GameObject& gameObject) override;
		virtual void exit(GameObject& ) override;
	private:

	};

	class BubDeadState : public State
	{
	public:
		virtual ~BubDeadState() override = default;
		//virtual State* handleInput(GameObject& gameObject) override;
		virtual State* update(GameObject& ) override;
		virtual void enter(GameObject& gameObject) override;
		virtual void exit(GameObject& ) override;
	private:

	};
}
