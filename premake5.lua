workspace "Dodger"
	configurations { "Debug", "Release" }

include "Dodger/vendor/glfw"
include "Dodger/vendor/glad"
include "Dodger/vendor/stb_image"

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
		"glad",
        "stb_image"
 	}
	sysincludedirs { "%{prj.location}/vendor/glfw/include", "%{prj.location}/vendor/glad/include", "%{prj.location}/vendor/glm/", "%{prj.location}/vendor" }
    warnings "Extra"

    filter "system:linux"
        buildoptions { "-Weffc++", "-Wsign-conversion" } -- Even more warnings

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"
	
