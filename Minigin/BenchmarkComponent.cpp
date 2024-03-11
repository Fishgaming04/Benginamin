#include "BenchmarkComponent.h"
#include "imgui.h"
#include "Renderer.h"
#include "backends/imgui_impl_sdl2.h"
#include "backends/imgui_impl_opengl3.h"
#include "imgui_plot.h"
#include <chrono>


using namespace dae;

BenchmarkComponent::BenchmarkComponent(GameObject* obj)
	:UpdatingComponent(obj)
{

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui_ImplSDL2_InitForOpenGL(Renderer::GetInstance().GetWindow(), SDL_GL_GetCurrentContext());
	ImGui_ImplOpenGL3_Init();
}

BenchmarkComponent::~BenchmarkComponent() {
	delete m_IsWindowActive;
	m_IsWindowActive = nullptr;

	delete m_NumberOfItarations;
	m_NumberOfItarations = nullptr;


	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();
}

void dae::BenchmarkComponent::Update(double elapsedTime)
{
	elapsedTime;
}

void dae::BenchmarkComponent::RenderUI()
{

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	std::vector<float> steps;

	for (float stepsize{ 1 }; stepsize <= 1024; stepsize *= 2) {
		steps.push_back(stepsize);
	}



	ImGui::NewFrame();



	ImGui::Begin("Int trashcash", m_IsWindowActive);
	ImGui::InputInt("number of itarations", m_NumberOfItarations, 1);

	//std::vector<float> result{};
	if (ImGui::Button("Trash The Cash")) {
		m_ResultInt.clear();
		IntBenchmark();
	}


	if (m_ResultInt.size() > 2) {

		ImGui::PlotConfig conf;
		conf.values.xs = steps.data();
		conf.values.ys = m_ResultInt.data(); // use ys_list to draw several lines simultaneously
		conf.values.count = int(steps.size());
		//conf.values.colors = colors;
		conf.tooltip.show = true;
		conf.line_thickness = 2.0f;
		conf.grid_y.show = true;
		conf.tooltip.format = "x=%.2f, y=%.2f";
		conf.grid_y.size = 5000.f;
		conf.scale.min = 0.0f;
		conf.scale.max = 5000.0f;
		conf.frame_size = ImVec2(200, 200);
		ImGui::Plot("plot1", conf);
	}



	ImGui::End();

	ImGui::Begin("GameObj TrashCash", m_IsWindowActive);
	ImGui::InputInt("number of itarations", m_NumberOfItarations, 1);

	//std::vector<float> result{};
	if (ImGui::Button("Trash cache GameObj")) {
		m_ResultGameObj.clear();
		GameObjectBenchmark();
	}

	if (m_ResultGameObj.size() > 2) {

		ImGui::PlotConfig conf;
		conf.values.xs = steps.data();
		conf.values.ys = m_ResultGameObj.data(); // use ys_list to draw several lines simultaneously
		conf.values.count = int(steps.size());
		//conf.values.colors = colors;
		conf.tooltip.show = true;
		conf.line_thickness = 2.0f;
		conf.grid_y.show = true;
		conf.tooltip.format = "x=%.2f, y=%.2f";
		conf.grid_y.size = 5000.f;
		conf.scale.min = 0.0f;
		conf.scale.max = 5000.0f;
		conf.frame_size = ImVec2(200, 200);
		ImGui::Plot("plot1", conf);
	}


	if (ImGui::Button("Trash The Cash GameObjAlt")) {
		m_ResultGameObjAlt.clear();
		GameObjectAltBenchmark();
	}



	if (m_ResultGameObjAlt.size() > 2) {

		ImGui::PlotConfig conf;
		conf.values.xs = steps.data();
		conf.values.ys = m_ResultGameObjAlt.data(); // use ys_list to draw several lines simultaneously
		conf.values.count = int(steps.size());
		//conf.values.colors = colors;
		conf.tooltip.show = true;
		conf.line_thickness = 2.0f;
		conf.grid_y.show = true;
		conf.tooltip.format = "x=%.2f, y=%.2f";
		conf.grid_y.size = 5000.f;
		conf.scale.min = 0.0f;
		conf.scale.max = 5000.0f;
		conf.frame_size = ImVec2(200, 200);
		ImGui::Plot("plot1", conf);
	}




	if (m_ResultGameObjAlt.size() > 2 && m_ResultGameObj.size() > 2) {

		const ImU32 colors[2] = { ImColor(0,255,0), ImColor(0,0,255) };
		const float* data[] = { m_ResultGameObj.data(), m_ResultGameObjAlt.data() };
		ImGui::PlotConfig conf;
		conf.values.xs = steps.data();
		conf.values.ys_list = data; // use ys_list to draw several lines simultaneously
		conf.values.ys_count = 2; // use ys_list to draw several lines simultaneously
		conf.values.count = int(steps.size());
		conf.values.colors = colors;
		conf.tooltip.show = true;
		conf.line_thickness = 2.0f;
		conf.grid_y.show = true;
		conf.tooltip.format = "x=%.2f, y=%.2f";
		conf.grid_y.size = 5000.f;
		conf.scale.min = 0.0f;
		conf.scale.max = 5000.0f;
		conf.frame_size = ImVec2(200, 200);
		ImGui::Plot("plot1", conf);
	

	
	}
	ImGui::End();


	ImGui::EndFrame();
	ImGui::Render();

	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void dae::BenchmarkComponent::IntBenchmark()
{
	std::vector<int> array(sizeArray);

	std::vector<std::vector<long long>> measurements(11);
	for (int itarations{}; itarations <= *m_NumberOfItarations; ++itarations) {
		int stepcount{};
		for (int stepsize{ 1 }; stepsize <= 1024; stepsize *= 2) {
			auto start{ std::chrono::high_resolution_clock::now() };
			for (int index{ 0 }; index < sizeArray; index += stepsize) {
				array[index] *= 2;
			}
			auto end{ std::chrono::high_resolution_clock::now() };
			auto duration{ std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() };
			measurements[stepcount].push_back(duration);

			++stepcount;

		}
		
		for (std::vector<long long> measuring : measurements) {
			long long sum{};
			for (long long element : measuring) {
				sum += element;
			}
			sum -= *std::min_element(measuring.begin(), measuring.end());
			sum -= *std::max_element(measuring.begin(), measuring.end());
			m_ResultInt.push_back(float((sum / (measuring.size() - 2))));
		}
}
}

void dae::BenchmarkComponent::GameObjectBenchmark()
{
	std::vector<gameobject> array(sizeArray);

	std::vector<std::vector<long long>> measurements(11);
	for (int itarations{}; itarations <= *m_NumberOfItarations; ++itarations) {
		int stepcount{};
		for (int stepsize{ 1 }; stepsize <= 1024; stepsize *= 2) {
			auto start{ std::chrono::high_resolution_clock::now() };
			for (int index{ 0 }; index < sizeArray; index += stepsize) {
				array[index].id *= 2;
			}
			auto end{ std::chrono::high_resolution_clock::now() };
			auto duration{ std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() };
			measurements[stepcount].push_back(duration);

			++stepcount;

		}
	}
	for (std::vector<long long> measuring : measurements) {
		long long sum{};
		for (long long element : measuring) {
			sum += element;
		}
		sum -= *std::min_element(measuring.begin(), measuring.end());
		sum -= *std::max_element(measuring.begin(), measuring.end());
		m_ResultGameObj.push_back(float((sum / (measuring.size() - 2))));
	}
}

void dae::BenchmarkComponent::GameObjectAltBenchmark()
{
	std::vector<gameobjectAlt> array(sizeArray);

	std::vector<std::vector<long long>> measurements(11);
	for (int itarations{}; itarations <= *m_NumberOfItarations; ++itarations) {
		int stepcount{};
		for (int stepsize{ 1 }; stepsize <= 1024; stepsize *= 2) {
			auto start{ std::chrono::high_resolution_clock::now() };
			for (int index{ 0 }; index < sizeArray; index += stepsize) {
				array[index].id *= 2;
			}
			auto end{ std::chrono::high_resolution_clock::now() };
			auto duration{ std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() };
			measurements[stepcount].push_back(duration);

			++stepcount;
		}
	}
	for (std::vector<long long> measuring : measurements) {
		long long sum{};
		for (long long element : measuring) {
			sum += element;
		}
		sum -= *std::min_element(measuring.begin(), measuring.end());
		sum -= *std::max_element(measuring.begin(), measuring.end());
		m_ResultGameObjAlt.push_back(float((sum / (measuring.size() - 2))));
	}
}
