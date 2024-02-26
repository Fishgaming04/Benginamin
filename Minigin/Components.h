#pragma once

namespace dae {
    class GameObject;
    class Component
    {
    public:
        Component(GameObject* obj);
        virtual ~Component() {};

        virtual void Update() = 0;
        virtual void Render()const = 0;

        Component(const Component& other) = delete;
        Component(Component&& other) = delete;
        Component& operator=(const Component& other) = delete;
        Component& operator=(Component&& other) = delete;

    protected:
        GameObject* m_ObjectPtr;

    };


    class GraphicalComponent: public Component
    {
    public:
        GraphicalComponent(GameObject* obj);
        virtual ~GraphicalComponent() {};

        virtual void Update() override {};
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

        virtual void Update() override = 0 ;

        virtual void Render() const override {};

        UpdatingComponent(const UpdatingComponent& other) = delete;
        UpdatingComponent(UpdatingComponent&& other) = delete;
        UpdatingComponent& operator=(const UpdatingComponent& other) = delete;
        UpdatingComponent& operator=(UpdatingComponent&& other) = delete;


    };



    //not in use Probably won't be used
    //class InputComponent
    //{
    //public:

    //    virtual ~InputComponent() {}

    //    virtual void Update(GameObject& obj) = 0;

    //    InputComponent(const InputComponent& other) = delete;
    //    InputComponent(InputComponent&& other) = delete;
    //    InputComponent& operator=(const InputComponent& other) = delete;
    //    InputComponent& operator=(InputComponent&& other) = delete;
    //};
}

