workspace "Obelisk"
	architecture "x64"

	location "../"

	configurations {
		"Debug",
		"Development",
		"ReleaseSymbols",
		"Release"
	}	
	
	startproject "Obelisk"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}

project "Obelisk"
	location "%{wks.location}/Obelisk/"
	kind "WindowedApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	floatingpoint "fast"

	flags {
		"FatalWarnings",
		"MultiProcessorCompile"
	}
	
	targetdir("%{wks.location}/build/" .. outputdir .. "/")
	objdir("%{wks.location}/build/obj/" .. outputdir .. "/")

	pchheader "oblpch.hpp"
	pchsource "../Obelisk/pch/oblpch.cpp"
	
	files {
		"%{prj.location}/include/**.hpp",
		"%{prj.location}/source/**.cpp",
		"%{prj.location}/source/**.inl",
		"%{prj.location}/pch/*",
	}
	
	includedirs {
		"%{prj.location}/include/",
		"%{prj.location}/pch/",
	}
	
	defines {
		"OBELISK_ENGINE",
		"_CRT_SECURE_NO_WARNINGS"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"WIN32_LEAN_AND_MEAN"
		}

	filter "configurations:Debug"
		defines { "OBL_DEBUG" }
		runtime "debug"
		optimize "off"
		symbols "on"

	filter "configurations:Development"
		defines { "OBL_DEVELOPMENT" }
		runtime "release"
		optimize "debug"
		symbols "on"

	filter "configurations:ReleaseSymbols"
		defines { "OBL_RELEASE" }
		runtime "release"
		optimize "speed"
		symbols "on"

	filter "configurations:Release"
		defines { "OBL_RELEASE" }
		runtime "release"
		optimize "speed"
		symbols "off"

	filter "configurations:not Debug"

	filter "configurations:not Development"

	filter "configurations:not Release"
