@echo off

pushd %~dp0\..\..\

call premake\premake5.exe vs2019 --file=scripts\premake5.lua
pause

popd