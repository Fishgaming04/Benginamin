#pragma once
#include "Components.h"
#include <map>
#include <string>
#include <vector>
#include "Observers.h"
#include "GameObject.h"
namespace dae
{

    class CounterComponent final : public UpdatingComponent
    {
    public:

        CounterComponent(GameObject* obj);
        virtual ~CounterComponent() {};

        virtual void Update(double) override {};

        virtual void Render() const override {};
        int GetCounter(std::string name);
        void SetCounter(std::string name, int value);
		void setSubject(Subject* subject) { m_Subject = subject; }

        CounterComponent(const CounterComponent& other) = delete;
        CounterComponent(CounterComponent&& other) = delete;
        CounterComponent& operator=(const CounterComponent& other) = delete;
        CounterComponent& operator=(CounterComponent&& other) = delete;

    private:
        using Counters = std::map<std::string, int>;
        Counters m_Counters;

		Subject* m_Subject;
    };

}

