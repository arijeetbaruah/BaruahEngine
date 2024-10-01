workspace "BaruahEngine"
    configurations { "Debug", "Release", "Dist" }
    architecture "x64"
    startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["spdlog"] = "vendor/spdlog/include"
IncludeDir["glm"] = "vendor/glm"
IncludeDir["GLFW"] = "vendor/glfw/include"
IncludeDir["Glad"] = "vendor/Glad/include"
IncludeDir["AssImp"] = "vendor/assimp/include"

include "vendor/glfw"
include "vendor/Glad"

project "BaruahEngine"
    location "BaruahEngine"
    kind "StaticLib"
    language "C++"
    staticruntime "on"
    cppdialect "c++20"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "bepch.h"
    pchsource "BaruahEngine/bepch.cpp"

    files
    {
        "%{prj.name}/**.cpp",
        "%{prj.name}/**.h",
        "%{prj.name}/**.cpp"
    }

    defines { "BE_ENABLE_ASSERTS" }

    links { "GLFW", "Glad", "opengl32.lib" }

    includedirs
    {
        "%{prj.name}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.AssImp}"
    }

    filter "system:windows"
        systemversion "latest"

        defines { "BE_PLATFORM_WINDOW", "BE_BUILD_DLL", "GLFW_INCLUDE_NONE" }

    filter "configurations:Debug"
        defines "BE_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "BE_Release"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "BE_Dist"
        runtime "Release"
        optimize "on"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    staticruntime "on"
    cppdialect "c++20"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/**.cpp",
        "%{prj.name}/**.h"
    }

    includedirs
    {
        "BaruahEngine",
        "%{IncludeDir.glm}",
        "%{IncludeDir.spdlog}",
        "${prj.name}"
    }

    links
    {
        "BaruahEngine", "GLFW", "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "BE_PLATFORM_WINDOW"
        }

    filter "configurations:Debug"
        defines "BE_DEBUG"
        symbols "on"

    filter "configurations:Release"
        defines "BE_Release"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "BE_Dist"
        runtime "Release"
        optimize "on"