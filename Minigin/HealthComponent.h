#pragma once
#include "Components.h"


namespace dae
{

    class HealthComponent final : public UpdatingComponent
    {
    public:

        HealthComponent(GameObject* obj);
        virtual ~HealthComponent() {}

        virtual void Update(double elapsedTime) override;

        virtual void Render() const override {};
        int GetHealth();
        void SetHealth(int health);


        HealthComponent(const HealthComponent& other) = delete;
        HealthComponent(HealthComponent&& other) = delete;
        HealthComponent& operator=(const HealthComponent& other) = delete;
        HealthComponent& operator=(HealthComponent&& other) = delete;

    private:
        int m_Health;
    };

}

