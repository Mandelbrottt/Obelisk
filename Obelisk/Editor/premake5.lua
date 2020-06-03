project "Obelisk-Editor"
    location "%{wks.location}/Obelisk/Editor/"
    kind "WindowedApp"
    language "C#"
    dotnetframework "4.6"
    staticruntime "off"
    floatingpoint "fast"

    namespace "Obelisk"
    
    flags { 
        "FatalWarnings",
        "MultiProcessorCompile",
        "WPF"
    }

    targetdir("%{wks.location}/build/bin/" .. outputdir .. "/Editor/")
    objdir("%{wks.location}/build/obj/" .. outputdir .. "/Editor/")

    targetname "Obelisk"
    
    files {
        "%{prj.location}/src/**.cs",
        "%{prj.location}/src/**.xaml",
        "%{prj.location}/src/**.config",
        "%{prj.location}/src/Properties/**.*"
    }

    links {
        "System",
        "System.Data",
        "System.Xml",
        "System.Core",
        "System.Xml.Linq",
        "System.Data.DataSetExtensions",
        "System.Net.Http",
        "System.Xaml",
        "WindowsBase",
        "PresentationCore",
        "PresentationFramework",
        "Microsoft.CSharp",
        
        "Obelisk-Engine"
    }

    filter "system:windows"
        systemversion "latest"

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