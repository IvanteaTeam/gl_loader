#include<gl_loader/gl.hpp>
#include<gl_loader/load.hpp>

namespace gl_loader
{

	static bool loaded = false;

	bool is_loaded()
	{
		return loaded;
	}

	static void load_impl();

	void load()
	{
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

		RegisterClassExW(&wc);
		HWND hwnd = CreateWindowExW(0, wc.lpszClassName, L"", WS_OVERLAPPEDWINDOW, -1, -1, -1, -1, 0, 0, wc.hInstance, 0);


		HDC hdc = GetDC(hwnd);

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

		wglMakeCurrent(hdc, ctx);

		gladLoaderLoadGL();


		wglDeleteContext(ctx);

		ReleaseDC(hwnd, hdc);
		DestroyWindow(hwnd);
		UnregisterClassW(wc.lpszClassName, wc.hInstance);
	}

}
