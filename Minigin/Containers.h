#pragma once
class GameObject;

class GraphicalComponent
{
public:

    virtual ~GraphicalComponent() {}

    virtual void Update(GameObject& obj) = 0;

    GraphicalComponent(const GraphicalComponent& other) = delete;
    GraphicalComponent(GraphicalComponent&& other) = delete;
    GraphicalComponent& operator=(const GraphicalComponent& other) = delete;
    GraphicalComponent& operator=(GraphicalComponent&& other) = delete;
};

class UpdatingComponent
{
public:

    virtual ~UpdatingComponent() {}

    virtual void Update(GameObject& obj) = 0;

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
