﻿#pragma once
#include "D3D.h"
#include "Camera.h"
#include "Model.h"
#include "Shader.h"
#include "Light.h"
#include "Text.h"
#include "Frustum.h"
#include <SimpleMath.h>

namespace bonsai {
	namespace graphics {
		const bool FULL_SCREEN(false);
		//TODO: FIX VSYNC with Raw input
		const bool VSYNC_ENABLED(false);


		class Scene
		{
		public:
			Scene();
			Scene(const Scene& scene);
			~Scene();

			bool Initialize(int screenWidth, int screenHeight, HWND hwnd);
			void Shutdown();
			bool Frame();

			Camera* GetCamera() const { return m_Camera; }

		private:
			bool Render();

		private:
			Direct3D * m_Direct3D;
			Camera* m_Camera;
			Model* m_Model;
			
			Shader* m_TextureShader;
			Light* m_Light;

		public:
			Text* m_Text;
		};
	}
}