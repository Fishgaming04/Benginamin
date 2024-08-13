#pragma once
#include "StateMachine.h"
#include "GameObject.h"



namespace dae {
	class PeterIdleState final: public State
	{
	public:
		PeterIdleState() = default;
		virtual ~PeterIdleState() override = default;
		//virtual State* handleInput(GameObject& gameObject) override ;
		virtual State* update(GameObject&, double) override;
		virtual void enter(GameObject& gameObject) override;
		virtual void exit(GameObject&) override;
	private:

	};

	class PeterWalkingState final : public State
	{
	public:
		PeterWalkingState() = default;
		virtual ~PeterWalkingState() override = default;
		//virtual State* handleInput(GameObject& gameObject) override ;
		virtual State* update(GameObject&, double) override;
		virtual void enter(GameObject& gameObject) override;
		virtual void exit(GameObject&) override;
	private:

	};


	class PeterClimbingState final : public State
	{
	public:
		PeterClimbingState() = default;
		virtual ~PeterClimbingState() override = default;
		//virtual State* handleInput(GameObject& gameObject) override ;
		virtual State* update(GameObject&, double) override;
		virtual void enter(GameObject& gameObject) override;
		virtual void exit(GameObject&) override;
	private:

	};


	class PeterHitState final : public State
	{
	public:
		PeterHitState() = default;
		virtual ~PeterHitState() override = default;
		//virtual State* handleInput(GameObject& gameObject) override ;
		virtual State* update(GameObject&, double) override;
		virtual void enter(GameObject& gameObject) override;
		virtual void exit(GameObject&) override;
	private:

	};






}