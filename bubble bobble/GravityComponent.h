#pragma once
#include "Components.h"

namespace dae
{

	class MomentumComponent : public UpdatingComponent
	{
	public:
		MomentumComponent(GameObject* obj);
		virtual ~MomentumComponent() {};

		virtual void Update(double);
		double GetMomentum();
		void addMomentum(double momentum);
		void SetMomentumScaler(double scaler) { m_MomentumScaler = scaler; }
		void SetMaxMomentum(double maxMomentum) { m_MaxMomentum = maxMomentum; }

		MomentumComponent(const MomentumComponent& other) = delete;
		MomentumComponent(MomentumComponent&& other) = delete;
		MomentumComponent& operator=(const MomentumComponent& other) = delete;
		MomentumComponent& operator=(MomentumComponent&& other) = delete;
	private:
		double m_Momentum;
		double m_MaxMomentum;
		double m_MomentumScaler;
	};
}