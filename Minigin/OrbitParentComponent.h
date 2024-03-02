#pragma once
#include "Components.h"
#include <glm/glm.hpp>
#include <math.h>

namespace dae {
    class OrbitParentComponent final : public UpdatingComponent
    {
    public:
        OrbitParentComponent(GameObject* obj);
        virtual ~OrbitParentComponent() {};

        virtual void Update(double elapsedTime);
        void SetRotationSpeed(int speed);
        void setDistanceFromPivot(float distance);

        OrbitParentComponent(const OrbitParentComponent& other) = delete;
        OrbitParentComponent(OrbitParentComponent&& other) = delete;
        OrbitParentComponent& operator=(const OrbitParentComponent& other) = delete;
        OrbitParentComponent& operator=(OrbitParentComponent&& other) = delete;

    private:
        glm::vec3 m_PivotPoint;
        double m_CurrentAngle;
        int m_RotationSpeed;
        float m_DistanceFromPivot;
    };
}

