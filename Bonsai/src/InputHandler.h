﻿#pragma once

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")
#include "../graphics/Camera.h"
#include <ctime>
#include <dinput.h>
#include "../util/RawInput.h"
namespace bonsai {

	class InputHandler
	{
	public:
		InputHandler(HWND hwndm);
		InputHandler(const InputHandler&);
		~InputHandler();

		void Initialize();

		void KeyDown(unsigned int);
		void KeyUp(unsigned int);

		bool IsKeyDown(unsigned int);

		void ParseInputs(bonsai::graphics::Camera* camera, LPARAM lparam);

	private:
		bool m_Keys[256];


		const float m_MouseSensitivity = 0.05f;
	public:

		RawInput* m_RawInput;

	};
}