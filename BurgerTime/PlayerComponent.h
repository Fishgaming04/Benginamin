#pragma once
#include "Components.h"
#include "Texture2D.h"
#include "StateMachine.h"
#include "GameObject.h"
#include "Observers.h"
namespace dae
{

    class PlayerComponent final : public UpdatingComponent
    {
    public:

        PlayerComponent(GameObject* obj);
        virtual ~PlayerComponent() {}

        virtual void Update(double elapsedTime) override;

        void SetSpawnPosition(const glm::vec3& position);
		void SetSubject(std::shared_ptr<Subject> subject) { m_Subject = subject; }
		void SetLives(int lives) { m_lives = lives; }
		void SetHitDuration(double duration) { m_HitDuration = duration; }
        PlayerComponent(const PlayerComponent& other) = delete;
        PlayerComponent(PlayerComponent&& other) = delete;
        PlayerComponent& operator=(const PlayerComponent& other) = delete;
        PlayerComponent& operator=(PlayerComponent&& other) = delete;
    private:
        double m_HitTimer;
		double m_HitDuration;
        int m_lives;


        glm::vec3 m_SpawnPosition;

        std::shared_ptr<Subject> m_Subject;
    };
}



