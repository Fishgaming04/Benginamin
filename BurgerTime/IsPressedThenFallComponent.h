#pragma once
#include "Components.h"

namespace dae
{

    class IsPressedThenFallComponent final: public UpdatingComponent
    {
    public:

        IsPressedThenFallComponent(GameObject* obj);
        virtual ~IsPressedThenFallComponent() {}

        virtual void Update(double) override;


        void HitByTopping();
        void ResetTopping();

		void SetPressDistance(int distance) { m_Pressdistance = distance; }
		void SetFallingSpeed(int speed) { m_FallingSpeed = speed; }
		void SetIsFalling(bool isFalling) { m_IsFalling = isFalling; }
		bool GetIsFalling() const { return m_IsFalling; }

        

        IsPressedThenFallComponent(const IsPressedThenFallComponent& other) = delete;
        IsPressedThenFallComponent(IsPressedThenFallComponent&& other) = delete;
        IsPressedThenFallComponent& operator=(const IsPressedThenFallComponent& other) = delete;
        IsPressedThenFallComponent& operator=(IsPressedThenFallComponent&& other) = delete;
    private:
        int m_Pressdistance;
        int m_FallingSpeed; 
        bool m_IsFalling;


		std::vector<bool> m_IsPressed;
    };

}
