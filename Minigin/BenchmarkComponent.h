#pragma once
#include "Components.h"
#include <vector>

namespace dae {
    struct transfrom {
        float matrix[16] = {
            1,0,0,0,
            0,1,0,0,
            0,0,1,0,
            0,0,0,1,
        };
    };

    class gameobject {
    public:
        transfrom local;
        int id;
    };

    class gameobjectAlt {
    public:
        transfrom* local;
        int id;
    };



	class BenchmarkComponent : public UpdatingComponent
	{
    public:
        BenchmarkComponent(GameObject* obj);
        virtual ~BenchmarkComponent();

        virtual void Update(double elapsedTime) override;
        virtual void RenderUI() override;

        BenchmarkComponent(const BenchmarkComponent& other) = delete;
        BenchmarkComponent(BenchmarkComponent&& other) = delete;
        BenchmarkComponent& operator=(const BenchmarkComponent& other) = delete;
        BenchmarkComponent& operator=(BenchmarkComponent&& other) = delete;
    private:
        void IntBenchmark();
        void GameObjectBenchmark();
        void GameObjectAltBenchmark();
         
        bool* m_IsWindowActive{ new bool {true} };
        int* m_NumberOfItarations{ new int{} };
        std::vector<float> m_ResultInt{};
        std::vector<float> m_ResultGameObj{};
        std::vector<float> m_ResultGameObjAlt{};
        
        const int sizeArray{ 1'000'000 };

	};

}

