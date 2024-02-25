#pragma once


namespace dae {
    class GameObject;

    class Component
    {
    public:
        Component();
        virtual ~Component() {};

        virtual void Update(GameObject& obj) = 0;
        virtual void Render(GameObject& obj)const = 0;

        Component(const Component& other) = delete;
        Component(Component&& other) = delete;
        Component& operator=(const Component& other) = delete;
        Component& operator=(Component&& other) = delete;
    };


    class GraphicalComponent: public Component
    {
    public:
        GraphicalComponent() {};
        virtual ~GraphicalComponent() {};

        virtual void Update(GameObject& obj) override =0;
        virtual void Render(GameObject& obj) const override { obj; };

        GraphicalComponent(const GraphicalComponent& other) = delete;
        GraphicalComponent(GraphicalComponent&& other) = delete;
        GraphicalComponent& operator=(const GraphicalComponent& other) = delete;
        GraphicalComponent& operator=(GraphicalComponent&& other) = delete;
    };

    class UpdatingComponent : public Component
    {
    public:
    
        UpdatingComponent() {};
        virtual ~UpdatingComponent() {}

        virtual void Update(GameObject& obj) override = 0 ;

        virtual void Render(GameObject&) const override {};

        UpdatingComponent(const UpdatingComponent& other) = delete;
        UpdatingComponent(UpdatingComponent&& other) = delete;
        UpdatingComponent& operator=(const UpdatingComponent& other) = delete;
        UpdatingComponent& operator=(UpdatingComponent&& other) = delete;
    };

    class InputComponent
    {
    public:

        virtual ~InputComponent() {}

        virtual void Update(GameObject& obj) = 0;

        InputComponent(const InputComponent& other) = delete;
        InputComponent(InputComponent&& other) = delete;
        InputComponent& operator=(const InputComponent& other) = delete;
        InputComponent& operator=(InputComponent&& other) = delete;
    };
}

