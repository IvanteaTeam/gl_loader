#include<gl_loader/gl.hpp>
#include<gl_loader/load.hpp>
#include<iostream>


namespace gl_loader
{

	class load_helper
	{
	public:
		load_helper()
		{
			load();
		}
	};

	static load_helper helper;

	static void load_impl();

	void load()
	{
		static bool loaded = false;
		if (!loaded)
			load_impl();
		loaded = true;
	}

	void load_impl()
	{



		WNDCLASSEXW wc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hbrBackground = 0;
		wc.hCursor = LoadCursor(0, IDC_ARROW);
		wc.hIcon = LoadIcon(0, IDI_APPLICATION);
		wc.hInstance = GetModuleHandleA(0);
		wc.lpfnWndProc = DefWindowProcW;
		wc.cbSize = sizeof(wc);
		wc.hIconSm = wc.hIcon;
		wc.lpszClassName = L"gl_loader dummy window class";
		wc.lpszMenuName = 0;
		wc.style = 0;

		std::cout << RegisterClassExW(&wc) << "\n";
		std::cout << GetLastError() << "\n";
		HWND hwnd = CreateWindowExW(0, wc.lpszClassName, L"", WS_OVERLAPPEDWINDOW, CW_DEFAULT, CW_DEFAULT, CW_DEFAULT, CW_DEFAULT, 0, 0, wc.hInstance, 0);
		std::cout << GetLastError() << "\n";

		std::cout << hwnd << "\n";

		HDC hdc = GetDC(hwnd);
		std::cout << GetLastError() << "\n";
		std::cout << hdc << "\n";

		PIXELFORMATDESCRIPTOR pfd =
		{
			sizeof(PIXELFORMATDESCRIPTOR),
			1,
			PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
			PFD_TYPE_RGBA,
			32,
			0, 0, 0, 0, 0, 0,
			0,
			0,
			0,
			0, 0, 0, 0,
			24,
			8,
			0,
			PFD_MAIN_PLANE,
			0,
			0, 0, 0
		};

		int pixel_format = ChoosePixelFormat(hdc, &pfd);

		SetPixelFormat(hdc, pixel_format, &pfd);

		HGLRC ctx = wglCreateContext(hdc);
		std::cout << GetLastError() << "\n";
		std::cout << ctx << "\n";

		wglMakeCurrent(hdc, ctx);
		std::cout << GetLastError() << "\n";
		//gladLoaderLoadGL();
		gladLoaderLoadGL();


		wglDeleteContext(ctx);
		std::cout << GetLastError() << "\n";

		ReleaseDC(hwnd, hdc);
		DestroyWindow(hwnd);
		UnregisterClassW(wc.lpszClassName, wc.hInstance);
	}

}
