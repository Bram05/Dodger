project "stb_image"
	language "C++"
	kind "StaticLib"
	objdir "bin-int/%{cfg.buildcfg}"
	targetdir "bin/%{cfg.buildcfg}"

	files {
		"stb_image.h",
		"stb_image.cpp"
	}

	filter "configurations:Debug"
		defines { "DEBUG"}
		symbols "on"

	filter "configurations:Release"
		defines { "NDEBUG"}
		optimize "on"
