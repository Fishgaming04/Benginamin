#pragma once
#include "Observers.h"


namespace dae {
    class GameObject;
    class Component
    {
    public:
        virtual ~Component() {};

        virtual void Update(double elapsedTime) = 0;
        virtual void Render()const = 0;
        GameObject* GetGameObject() const { return m_ObjectPtr; }


        Component(const Component& other) = delete;
        Component(Component&& other) = delete;
        Component& operator=(const Component& other) = delete;
        Component& operator=(Component&& other) = delete;
    protected:
        Component(GameObject* obj);
    private:
        GameObject* m_ObjectPtr;

    };


    class GraphicalComponent: public Component
    {
    public:
        GraphicalComponent(GameObject* obj);
        virtual ~GraphicalComponent() {};

        virtual void Update(double) override {};
        virtual void Render() const override = 0;

        GraphicalComponent(const GraphicalComponent& other) = delete;
        GraphicalComponent(GraphicalComponent&& other) = delete;
        GraphicalComponent& operator=(const GraphicalComponent& other) = delete;
        GraphicalComponent& operator=(GraphicalComponent&& other) = delete;


    };

    class UpdatingComponent : public Component
    {
    public:
    
        UpdatingComponent(GameObject* obj);
        virtual ~UpdatingComponent() {}

        virtual void Update(double elapsedTime) override = 0 ;

        virtual void Render() const override {};

        UpdatingComponent(const UpdatingComponent& other) = delete;
        UpdatingComponent(UpdatingComponent&& other) = delete;
        UpdatingComponent& operator=(const UpdatingComponent& other) = delete;
        UpdatingComponent& operator=(UpdatingComponent&& other) = delete;


    };

    class ObserverComponent : public Component, public Observer
    {
    public:

        ObserverComponent(GameObject* obj);
        virtual ~ObserverComponent();

        virtual void Update(double) {};
        virtual void Render() const override {};
        virtual void OnNotify(Event event, GameObject* actor) = 0;

        ObserverComponent(const ObserverComponent& other) = delete;
        ObserverComponent(ObserverComponent&& other) = delete;
        ObserverComponent& operator=(const ObserverComponent& other) = delete;
        ObserverComponent& operator=(ObserverComponent&& other) = delete;

        GameObject* GetIsWatching() const { return m_IsWatching; }
        void SetIsWatching(GameObject* object);
    private:
        GameObject* m_IsWatching;
    };
}

