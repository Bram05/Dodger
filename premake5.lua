workspace "Dodger"
	configurations { "Debug", "Release" }

include "Dodger/vendor/glfw"
include "Dodger/vendor/glad"

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
		"GL",
		"glad"
 	}
	includedirs { "%{prj.location}/vendor/glfw/include", "%{prj.location}/vendor/glad/include", "%{prj.location}/vendor/glm/" }

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"
	
