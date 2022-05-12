
solution "c_oop"
	configurations { "Debug", "Release" }
	platforms { "Linux" }
	location "build"

	project "c_shapes"
		location "build"
		kind "ConsoleApp"
		language "C"
		files
		{
			"c_shapes.c",
			"shape.h",
			"square.c",
			"square.h",
			"circle.c",
			"circle.h",
			"cinheritance.h"

		}
		--excludes {  }
		--libdirs { }
		--links { " }
		targetdir "build"
		
		filter "configurations:Debug"
			defines { "DEBUG" }
			symbols "On"

		filter "configurations:Release"
			defines { "NDEBUG" }
			optimize "On"

		filter { "platforms:Linux" }
			buildoptions { "-pedantic-errors", "-fno-strict-aliasing", "-Wunused-variable", "-Wreturn-type" }
