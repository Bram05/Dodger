workspace "Dodger"
	configurations { "Debug", "Release" }

include "Dodger/vendor/glfw"

project "Dodger"
	location "Dodger"
	kind "ConsoleApp"
	language "C++"
	objdir "bin-int/%{cfg.buildcfg}"
	targetdir "bin/%{cfg.buildfg}"
	
	files { "Dodger/src/**.h", "Dodger/src/**.cpp" }

	links {
		"glfw",
		"dl",
		"X11",
		"pthread",
		"GL"
 	}
	includedirs { "vendor/glfw/include" }

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"
	
