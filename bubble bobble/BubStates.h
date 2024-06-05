#pragma once
#include "StateMachine.h"
#include "GameObject.h"
#include "TextComponent.h"
#include "ResourceManager.h"
namespace dae {

//                       ┌──────────┐                    
//                       │  Bubble  │                    
//                       └────┬─────┘                    
//                            │                          
// ┌───────────────────────┐  │  ┌──────────────────────┐
// │                       ▼  ▼  ▼                      │
// │                     ┌─────────┐                    │
// │          ┌─────────►│  Idle   │◄────────┐          │
// │          │          └─────────┘         │          │
// │          │                              │          │
// │          │                              │          │
// │          │                              │          │
// │          │                              │          │
// │          ▼                              ▼          │
// │       ┌───────┐                    ┌─────────┐     │
// │       │  Hit  │ ◄────────────────┬─┤ Walking │◄──┐ │
// │       └───────┘                  │ └─────────┘   │ │
// │           ▲                      │      ▲        │ │
// │           │                      │      │        │ │
// │           │                      │      │        │ │
// │           │                      │      │        │ │
// │           │                      │      ▼        │ │
// │      ┌────┴───┐                  ├───────────┐   │ │
// └─────►│  Jump  │◄────────────────►│   Shoot   │◄──┼─┘
//        └────────┘                  └───────────┘   │  
//              ▲                                     │  
//              └─────────────────────────────────────┘  


	class BubIdleState : public State
	{
	public:
		BubIdleState() = default;
		virtual ~BubIdleState() override = default;
		//virtual State* handleInput(GameObject& gameObject) override ;
		virtual State* update(GameObject& ) override;
		virtual void enter(GameObject& gameObject) override;
		virtual void exit(GameObject& ) override;
	private:

	};


	class BubWalkingState : public State
	{
	public:
		BubWalkingState() = default;
		virtual ~BubWalkingState() override = default;
		//virtual State* handleInput(GameObject& gameObject) override ;
		virtual State* update(GameObject& ) override;
		virtual void enter(GameObject& gameObject) override;
		virtual void exit(GameObject& ) override;
	private:

	};

	class BubJumpingState : public State
	{
	public:
		BubJumpingState() = default;
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
		BubBubbleState() = default;
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
		BubShootingState() = default;
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
		BubDeadState() = default;
		virtual ~BubDeadState() override = default;
		//virtual State* handleInput(GameObject& gameObject) override;
		virtual State* update(GameObject& ) override;
		virtual void enter(GameObject& gameObject) override;
		virtual void exit(GameObject& ) override;
	private:

	};
}
