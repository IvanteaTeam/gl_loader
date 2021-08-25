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
			printf("here\n");
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


		WNDCLASSA wc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hbrBackground = 0;
		wc.hCursor = LoadCursor(0, IDC_ARROW);
		wc.hIcon = LoadIcon(0, IDI_APPLICATION);
		wc.hInstance = GetModuleHandleA(0);
		wc.lpfnWndProc = DefWindowProcW;
		wc.lpszClassName = "gl_loader dummy window class";
		wc.lpszMenuName = 0;
		wc.style = 0;

		std::cout << RegisterClassA(&wc) << "\n";
		std::cout << GetLastError() << "\n";
		HWND hwnd = CreateWindowExA(0, wc.lpszClassName, "", WS_OVERLAPPEDWINDOW, 0, 0, 0, 0, 0, 0, wc.hInstance, 0);
		std::cout << GetLastError() << "\n";

		std::cout << hwnd << "\n";

		HDC hdc = GetDC(hwnd);

		HGLRC ctx = wglCreateContext(hdc);

		std::cout << ctx << "\n";

		wglMakeCurrent(hdc, ctx);

		//gladLoaderLoadGL();
		gladLoaderLoadGL();


		wglDeleteContext(ctx);


		ReleaseDC(hwnd, hdc);
		DestroyWindow(hwnd);
		UnregisterClassA(wc.lpszClassName, wc.hInstance);
	}

}
