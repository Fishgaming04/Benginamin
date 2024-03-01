#pragma once
#include "Components.h"
#include <glm/glm.hpp>
#include <math.h>

namespace dae {
    class Transform;
    class OrbitParentComponent final : public GraphicalComponent
    {
    public:
        OrbitParentComponent(GameObject* obj);
        virtual ~OrbitParentComponent() {};

        virtual void Update(double elapsedTime);
        void SetRotationSpeed(int speed);
        void setDistanceFromPivot(int distance);

        OrbitParentComponent(const OrbitParentComponent& other) = delete;
        OrbitParentComponent(OrbitParentComponent&& other) = delete;
        OrbitParentComponent& operator=(const OrbitParentComponent& other) = delete;
        OrbitParentComponent& operator=(OrbitParentComponent&& other) = delete;

    private:
        Transform* m_TransformPtr;
        glm::vec3 m_PivotPoint;
        double m_CurrentAngle;
        int m_RotationSpeed;
        int m_DistanceFromPivot;
    };
}

