#pragma once
#include "Components.h"
#include "Texture2D.h"
#include "StateMachine.h"
#include "GameObject.h"
#include "Observers.h"
namespace dae
{

    class EnemyComponent final: public UpdatingComponent 
    {
    public:

        EnemyComponent(GameObject* obj);
        virtual ~EnemyComponent() {}

        virtual void Update(double elapsedTime) override;

		bool GetIsGoingLeft() const { return m_IsGoingLeft; }
		bool GetIsHit() const { return m_IsHit; }


		//ladderDirections: 
        // 1 = up
        // 2 = down
        // 3 = Both 

		void IsOverlappingWithLadder(int LadderDirections);
		void TurnAround();
        void Hit();
		void TouchingGround();

		void SetSubject(Subject* subject) { m_Subject = subject; }

        void SetTextureClimb(const std::shared_ptr<Texture2D>& texture);
        void SetTextureWalking(const std::shared_ptr<Texture2D>& texture);
        void SetTextureHit(const std::shared_ptr<Texture2D>& texture);

        void SetSpawnPosition(const glm::vec3& position);
		void SetPlayer(GameObject* player) { m_Player = player; }
		void SetHitDuration(double duration) { m_HitDuration = duration; }
		void SetSpeed(float speed) { m_Speed = speed; }
		void SetPoints(int points) { m_Points = points; }
        EnemyComponent(const EnemyComponent& other) = delete;
        EnemyComponent(EnemyComponent&& other) = delete;
        EnemyComponent& operator=(const EnemyComponent& other) = delete;
        EnemyComponent& operator=(EnemyComponent&& other) = delete;
    private:
        std::shared_ptr<Texture2D> m_TextureClimb;
        std::shared_ptr<Texture2D> m_TextureWalking;
        std::shared_ptr<Texture2D> m_TextureHit;

		StateMachine* m_StateMachine;

        int m_Points;

		float m_Speed;
        bool m_IsGoingLeft;
        bool m_IsHit; 
		double m_HitTimer;
		double m_HitDuration;

		glm::vec3 m_SpawnPosition;
		GameObject* m_Player;

		Subject* m_Subject;
    };
}


