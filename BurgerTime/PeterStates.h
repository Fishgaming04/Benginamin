#pragma once
#include "StateMachine.h"
#include "GameObject.h"



namespace dae {
	class PeterIdleState : public State
	{
	public:
		PeterIdleState() = default;
		virtual ~PeterIdleState() override = default;
		//virtual State* handleInput(GameObject& gameObject) override ;
		virtual State* update(GameObject&) override;
		virtual void enter(GameObject& gameObject) override;
		virtual void exit(GameObject&) override;
	private:

	};

	class PeterWalkingState : public State
	{
	public:
		PeterWalkingState() = default;
		virtual ~PeterWalkingState() override = default;
		//virtual State* handleInput(GameObject& gameObject) override ;
		virtual State* update(GameObject&) override;
		virtual void enter(GameObject& gameObject) override;
		virtual void exit(GameObject&) override;
	private:

	};


	class PeterClimbingState : public State
	{
	public:
		PeterClimbingState() = default;
		virtual ~PeterClimbingState() override = default;
		//virtual State* handleInput(GameObject& gameObject) override ;
		virtual State* update(GameObject&) override;
		virtual void enter(GameObject& gameObject) override;
		virtual void exit(GameObject&) override;
	private:

	};


	class PeterHitState : public State
	{
	public:
		PeterHitState() = default;
		virtual ~PeterHitState() override = default;
		//virtual State* handleInput(GameObject& gameObject) override ;
		virtual State* update(GameObject&) override;
		virtual void enter(GameObject& gameObject) override;
		virtual void exit(GameObject&) override;
	private:

	};






}