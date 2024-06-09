#pragma once
#include "Components.h"

namespace dae
{

	class GravityComponent : public UpdatingComponent
	{
	public:
		GravityComponent(GameObject* obj);
		virtual ~GravityComponent() {};

		virtual void Update(double elapsed);
		double GetMomentum();
		void addMomentum(double momentum);
		void SetMomentum(double scaler);
		void SetMomentumScaler(double scaler) { m_MomentumScaler = scaler; }
		void SetMaxMomentum(double maxMomentum) { m_MaxMomentum = maxMomentum; }

		GravityComponent(const GravityComponent& other) = delete;
		GravityComponent(GravityComponent&& other) = delete;
		GravityComponent& operator=(const GravityComponent& other) = delete;
		GravityComponent& operator=(GravityComponent&& other) = delete;
	private:
		double m_Momentum;
		double m_MaxMomentum;
		double m_MomentumScaler;
	};
}