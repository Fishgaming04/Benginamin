#pragma once
#include "StateMachine.h"
#include "GameObject.h"
#include "Texture2D.h"
#include "Command.h"

namespace dae {
	class EnemyWalkingState final : public State
	{
	public:
		EnemyWalkingState() = default;
		virtual ~EnemyWalkingState() override = default;
		//virtual State* handleInput(GameObject& gameObject) override ;
		virtual State* update(GameObject& gameObject, double deltaTime) override;
		virtual void enter(GameObject& gameObject) override;
		virtual void exit(GameObject&) override;
		
		void SetIsGoingLeft(bool isGoingLeft) { m_IsGoingLeft = isGoingLeft; m_IsDirtyMovement = true; }
		void SetTexture(std::shared_ptr<Texture2D> texture) { m_TextureWalking = texture; m_IsDirtyTexture = true;	}
		void SetSpeed(float speed) { m_Speed = speed; m_IsDirtyMovement = true; }
	private:
		MoveCommand* m_MoveCommand;

		std::shared_ptr<Texture2D> m_TextureWalking;
		bool m_IsDirtyTexture;
		bool m_IsGoingLeft;
		bool m_IsDirtyMovement;
		float m_Speed;
	};

	class EnemyClimbingState final : public State
	{
	public:
		EnemyClimbingState() = default;
		virtual ~EnemyClimbingState() override = default;
		//virtual State* handleInput(GameObject& gameObject) override ;
		virtual State* update(GameObject& gameObject, double deltaTime) override;
		virtual void enter(GameObject& gameObject) override;
		virtual void exit(GameObject&) override;

		void SetIsGoingUp(bool isGoingUp) { m_IsGoingUp = isGoingUp; m_IsDirtyMovement = true;}
		void SetTexture(std::shared_ptr<Texture2D> texture) { m_TextureClimb = texture; m_IsDirtyTexture = true;}
		void SetSpeed(float speed) { m_Speed = speed; m_IsDirtyMovement = true;}
	private:
		MoveCommand* m_MoveCommand;

		std::shared_ptr<Texture2D> m_TextureClimb;
		bool m_IsDirtyTexture;
		bool m_IsGoingUp;
		float m_Speed;
		bool m_IsDirtyMovement;
	};

	class EnemyHitState final : public State
	{
	public:
		EnemyHitState() = default;
		virtual ~EnemyHitState() override = default;
		//virtual State* handleInput(GameObject& gameObject) override ;
		virtual State* update(GameObject&, double deltaTime) override;
		virtual void enter(GameObject& gameObject) override;
		virtual void exit(GameObject&) override;

		void SetTexture(std::shared_ptr<Texture2D> texture) { m_TextureHit = texture; m_IsDirtyTexture = true;}
	private:
		std::shared_ptr<Texture2D> m_TextureHit;
		bool m_IsDirtyTexture;
	};
}

