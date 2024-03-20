#pragma once
#include "Components.h"
#include <map>
#include <string>
#include <vector>
namespace dae
{

    class CounterComponent final : public UpdatingComponent
    {
    public:

        CounterComponent(GameObject* obj);
        virtual ~CounterComponent() {}

        virtual void Update(double) override {};

        virtual void Render() const override {};
        int GetCounter(std::string health);
        void SetCounter(std::string health, int value);


        CounterComponent(const CounterComponent& other) = delete;
        CounterComponent(CounterComponent&& other) = delete;
        CounterComponent& operator=(const CounterComponent& other) = delete;
        CounterComponent& operator=(CounterComponent&& other) = delete;

    private:
        using Counters = std::map<std::string, int>;

        Counters m_Counters;
    };

}

