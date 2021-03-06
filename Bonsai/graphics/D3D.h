﻿#pragma once
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")
#include "../bonsai.h"

using namespace DirectX;

namespace bonsai {
	namespace graphics {
		class Direct3D
		{
		public:
			Direct3D();
			Direct3D(const Direct3D&);
			~Direct3D();

			bool Initialize(int screenWidth, int screenHeight, bool vsync, HWND hwnd, bool fullscreen, float screenDepth, float screenNear);
			void Shutdown();

			void BeginScene(float red, float green, float blue, float alpha);
			void EndScene();

			inline ID3D11Device* GetDevice() { return m_Device; }
			inline ID3D11DeviceContext* GetDeviceContext() { return m_DeviceContext; }

			inline void GetWorldMatrix(XMMATRIX& world) { world = m_WorldMatrix; }
			inline XMMATRIX GetWorldMatrix() const { return m_WorldMatrix; }


			inline void TurnZBufferOn() const { m_DeviceContext->OMSetDepthStencilState(m_DepthStencilState, 1); }
			inline void TurnZBufferOff() const { m_DeviceContext->OMSetDepthStencilState(m_DepthDisabledStencilState, 1); }

			inline void TurnOnAlphaBlending() const
			{
				float blendFactor[4] = { 0.0f,0.0f,0.0f,0.0f };
				m_DeviceContext->OMSetBlendState(m_AlphaEnableBlendingState, blendFactor, 0xffffffff);
			}
			inline void TurnOffAlphaBlending() const
			{
				float blendFactor[4] = { 0.0f,0.0f,0.0f,0.0f };
				m_DeviceContext->OMSetBlendState(m_AlphaDisableBlendingState, blendFactor, 0xffffffff);
			}

			void GetVideoCardInfo(char*, int&);
		private:
			bool m_vsync_enabled;
			int m_VideoCardMemory;
			char m_VideoCardDescription[128];
			IDXGISwapChain* m_SwapChain;
			ID3D11Device* m_Device;
			ID3D11DeviceContext* m_DeviceContext;
			ID3D11RenderTargetView* m_RenderTargetView;
			ID3D11Texture2D* m_DepthStencilBuffer;
			ID3D11DepthStencilState* m_DepthStencilState;
			ID3D11DepthStencilState* m_DepthDisabledStencilState;
			ID3D11DepthStencilView* m_DepthStencilView;
			ID3D11RasterizerState* m_RasterState;
			ID3D11BlendState* m_AlphaEnableBlendingState;
			ID3D11BlendState* m_AlphaDisableBlendingState;

			XMMATRIX m_WorldMatrix;

		};
	}
}