#pragma once
#include "Components.h"

namespace dae {
	class FPSComponent final : public UpdatingComponent
	{
	public:
		FPSComponent(GameObject* obj);
		virtual ~FPSComponent() {};

		virtual void Update(double);
		int GetFps();

		FPSComponent(const FPSComponent& other) = delete;
		FPSComponent(FPSComponent&& other) = delete;
		FPSComponent& operator=(const FPSComponent& other) = delete;
		FPSComponent& operator=(FPSComponent&& other) = delete;
	private:
		int m_FPS;

	};



}
