workspace "Obelisk"
	architecture "x64"

	location "../"

	configurations {
		"Debug",
		"Development",
		"ReleaseSymbols",
		"Release"
	}	
	
	startproject "Entry"

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
	-- Include directories relative to root folder (solution directory)
	IncludeDir = {}
	
	project "Entry"
		location "%{wks.location}/Obelisk/Entry/"
		kind "WindowedApp"
		language "C++"
		cppdialect "C++17"
		staticruntime "off"
		floatingpoint "fast"
	
		flags {
			"FatalWarnings",
			"MultiProcessorCompile"
		}
		
		targetdir("%{wks.location}/build/bin/" .. outputdir .. "/Entry/")
		objdir("%{wks.location}/build/obj/" .. outputdir .. "/Entry/")
	
		files {
			"%{prj.location}/src/**.cpp",
			"%{prj.location}/src/**.h",
			"%{prj.location}/src/**.hpp",
			"%{prj.location}/src/**.inl",
		}
	
		links {
			"Obelisk"
		}
	
		includedirs {
			"%{wks.location}/Obelisk/Engine/src/"
		}
	
		defines {
			"_CRT_SECURE_NO_WARNINGS"
		}
	
	project "Obelisk"
		location "%{wks.location}/Obelisk/Engine/"
		kind "SharedLib"
		language "C++"
		cppdialect "C++17"
		staticruntime "off"
		floatingpoint "fast"
	
		flags {
			"FatalWarnings",
			"MultiProcessorCompile"
		}
		
		targetdir("%{wks.location}/build/bin/" .. outputdir .. "/Engine/")
		objdir("%{wks.location}/build/obj/" .. outputdir .. "/Engine/")
	
		pchheader "oblpch.h"
		pchsource "../Obelisk/Engine/pch/oblpch.cpp"
		
		files {
			"%{prj.location}/src/**.cpp",
			"%{prj.location}/src/**.h",
			"%{prj.location}/src/**.hpp",
			"%{prj.location}/src/**.inl",
			"%{prj.location}/pch/*",
		}
		
		includedirs {
			"%{prj.location}/src/",
			"%{prj.location}/pch/",
		}
		
		defines {
			"OBL_ENGINE",
			"_CRT_SECURE_NO_WARNINGS"
		}
	
		postbuildcommands {
			"{COPY} %{wks.location}build/bin/" .. outputdir .. "/Engine/Obelisk.dll %{wks.location}build/bin/"..outputdir.."/Entry/"
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
