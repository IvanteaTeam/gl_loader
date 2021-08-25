#include<gl_loader/gl.hpp>
#include<gl_loader/load.hpp>

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
		//gladLoaderLoadGL();
	}

}
