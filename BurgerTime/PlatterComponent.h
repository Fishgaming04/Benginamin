#pragma once
#include "Components.h"
#include "Observers.h"

namespace dae
{
    class PlatterComponent final : public UpdatingComponent
    {
    public:

        PlatterComponent(GameObject* obj);
        virtual ~PlatterComponent() {}

        virtual void Update(double) override;
		bool SetIsDirty(bool isDirty = true) { return m_IsDirty = isDirty; }
        void addObserver(ObserverComponent* observer);
		void removeObserver(ObserverComponent* observer);

        PlatterComponent(const PlatterComponent& other) = delete;
        PlatterComponent(PlatterComponent&& other) = delete;
        PlatterComponent& operator=(const PlatterComponent& other) = delete;
        PlatterComponent& operator=(PlatterComponent&& other) = delete;
    private:
        
        bool m_IsDirty;
        bool m_BurgerCompleted;

		Subject m_Subject;
    };
}