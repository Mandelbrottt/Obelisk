workspace "Obelisk-Standalone"
	architecture "x64"

	location "../"

	configurations {
		"Debug",
		"Development",
		"ReleaseSymbols",
		"Release"
	}	
	
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	startproject "Obelisk-Entry"
	
	include "../Obelisk/Entry/"
	
	include "../Obelisk/Engine/"

workspace "Obelisk-Editor"
	architecture "x64"

	location "../"

	configurations {
		"Debug",
		"Development",
		"ReleaseSymbols",
		"Release"
	}	
	
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	startproject "Obelisk-Editor"
	
	include "../Obelisk/Editor/"
	
	includeexternal "../Obelisk/Engine/"
