project "Obelisk-Entry"
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