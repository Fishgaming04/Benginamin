#include <stdexcept>
#include "Renderer.h"
#include "SceneManager.h"
#include "Texture2D.h"
#include "imgui.h"
#include "backends/imgui_impl_sdl2.h"
#include "backends/imgui_impl_opengl3.h"
#include "imgui_plot.h"
#include <chrono>

int GetOpenGLDriverIndex()
{
	auto openglIndex = -1;
	const auto driverCount = SDL_GetNumRenderDrivers();
	for (auto i = 0; i < driverCount; i++)
	{
		SDL_RendererInfo info;
		if (!SDL_GetRenderDriverInfo(i, &info))
			if (!strcmp(info.name, "opengl"))
				openglIndex = i;
	}
	return openglIndex;
	
}


void dae::Renderer::Init(SDL_Window* window)
{
	m_window = window;
	m_renderer = SDL_CreateRenderer(window, GetOpenGLDriverIndex(), SDL_RENDERER_ACCELERATED);
	if (m_renderer == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateRenderer Error: ") + SDL_GetError());
	}
	//IMGUI_CHECKVERSION();
	//ImGui::CreateContext();
	//ImGui_ImplSDL2_InitForOpenGL(window, SDL_GL_GetCurrentContext());
	//ImGui_ImplOpenGL3_Init();

}

void dae::Renderer::Render() const
{
	const auto& color = GetBackgroundColor();
	SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
	SDL_RenderClear(m_renderer);
	SceneManager::GetInstance().Render();

	////ImGui::Render();
	//ImGui_ImplOpenGL3_NewFrame();
	//ImGui_ImplSDL2_NewFrame();
	////ImGui::NewFrame();
	////ImGui::ShowDemoWindow();
	//std::vector<float> steps;

	//for (float stepsize{ 1 }; stepsize <= 1024; stepsize *= 2) {
	//	steps.push_back(stepsize);
	//}



	//ImGui::NewFrame();



	//ImGui::Begin("My First Tool", m_IsWindowActive);
	//ImGui::InputInt("number of itarations", m_NumberOfItarations, 1);

	////std::vector<float> result{};
	//if (ImGui::Button("Trash The Cash")) {
	//	std::vector<int> array(sizeArray);
	//	std::vector<std::vector<long long>> measurements(11);
	//	for (int itarations{}; itarations <= *m_NumberOfItarations; ++itarations) {
	//		int stepcount{};
	//		for (int stepsize{ 1 }; stepsize <= 1024; stepsize *= 2) {
	//			for (int itaration{}; itaration <= *m_NumberOfItarations; ++itaration) {
	//				auto start{ std::chrono::high_resolution_clock::now() };
	//				for (int index{ 0 }; index < sizeArray; index += stepsize) {
	//					array[index] *= 2;
	//				}
	//				auto end{ std::chrono::high_resolution_clock::now() };
	//				auto duration{ std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() };
	//				measurements[stepcount].push_back(duration);
	//			}

	//			++stepcount;

	//		}

	//		for (std::vector<long long> measuring : measurements) {
	//			long long sum{};
	//			for (long long element : measuring) {
	//				sum += element;
	//			}
	//			sum -= *std::min_element(measuring.begin(), measuring.end());
	//			sum -= *std::max_element(measuring.begin(), measuring.end());
	//			//std::cout << "avarage: " << (sum / (measuring.size() - 2)) / 1000.f << "\n";
	//			result.push_back(float((sum / (measuring.size() - 2))));
		//	}
		//}
	//} 


	//static ImU32 colors[3] = { ImColor(0, 255, 0), ImColor(255, 0, 0), ImColor(0, 0, 255) };
	// Draw first plot with multiple sources

	//if (result.size() > 2) {

	//	ImGui::PlotConfig conf;
	//	conf.values.xs = steps.data();
	//	conf.values.ys = result.data(); // use ys_list to draw several lines simultaneously
	//	conf.values.count = int(steps.size());
	//	//conf.values.colors = colors;
	//	conf.tooltip.show = true;
	//	conf.line_thickness = 2.0f;
	//	conf.grid_y.show = true;
	//	conf.tooltip.format = "x=%.2f, y=%.2f";
	//	conf.grid_y.size = 5000.f;
	//	conf.scale.min = 0.0f;
	//	conf.scale.max = 5000.0f;
	//	conf.frame_size = ImVec2(200, 200);
	//	ImGui::Plot("plot1", conf);
	//}

	// Draw second plot with the selection
	// reset previous values
	//conf.values.ys_list = nullptr;
	//conf.selection.show = false;
	// set new ones
	//conf.values.ys = y_data3;
	//conf.values.offset = selection_start;
	//conf.values.count = selection_length;

	

	//ImGui::End();




	//ImGui::EndFrame();
	//ImGui::Render();
	//
	//ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	SDL_RenderPresent(m_renderer);
}

void dae::Renderer::Destroy()
{
	//ImGui_ImplOpenGL3_Shutdown();
	//ImGui_ImplSDL2_Shutdown();
	//ImGui::DestroyContext();

	delete m_IsWindowActive;
	m_IsWindowActive = nullptr;

	delete m_NumberOfItarations;
	m_NumberOfItarations = nullptr;

	if (m_renderer != nullptr)
	{
		SDL_DestroyRenderer(m_renderer);
		m_renderer = nullptr;
	}
}

//void dae::Renderer::Benchmark() const{
//
//	std::vector<int> array(sizeArray);
//	std::vector<float> result{};
//	std::vector<std::vector<long long>> measurements(11);
//	for (int itarations{}; itarations <= *m_NumberOfItarations; ++itarations) {
//		int stepcount{};
//		for (int stepsize{ 1 }; stepsize <= 1024; stepsize *= 2) {
//			for (int itaration{}; itaration <= *m_NumberOfItarations; ++itaration) {
//				auto start{ std::chrono::high_resolution_clock::now() };
//				for (int index{ 0 }; index < sizeArray; index += stepsize) {
//					array[index] *= 2;
//				}
//				auto end{ std::chrono::high_resolution_clock::now() };
//				auto duration{ std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() };
//				measurements[stepcount].push_back(duration);
//			}
//
//			++stepcount;
//
//		}
//
//		for (std::vector<long long> measuring : measurements) {
//			long long sum{};
//			for (long long element : measuring) {
//				sum += element;
//			}
//			sum -= *std::min_element(measuring.begin(), measuring.end());
//			sum -= *std::max_element(measuring.begin(), measuring.end());
//			//std::cout << "avarage: " << (sum / (measuring.size() - 2)) / 1000.f << "\n";
//			result.push_back(float((sum / (measuring.size() - 2))));
//		}
//}
//}

void dae::Renderer::RenderTexture(const Texture2D& texture, const float x, const float y) const
{
	SDL_Rect dst{};
	dst.x = static_cast<int>(x);
	dst.y = static_cast<int>(y);
	SDL_QueryTexture(texture.GetSDLTexture(), nullptr, nullptr, &dst.w, &dst.h);
	SDL_RenderCopy(GetSDLRenderer(), texture.GetSDLTexture(), nullptr, &dst);
}

void dae::Renderer::RenderTexture(const Texture2D& texture, const float x, const float y, const float width, const float height) const
{
	SDL_Rect dst{};
	dst.x = static_cast<int>(x);
	dst.y = static_cast<int>(y);
	dst.w = static_cast<int>(width);
	dst.h = static_cast<int>(height);
	SDL_RenderCopy(GetSDLRenderer(), texture.GetSDLTexture(), nullptr, &dst);
}

SDL_Renderer* dae::Renderer::GetSDLRenderer() const { return m_renderer; }


SDL_Window* dae::Renderer::GetWindow() const {
	return m_window;
}