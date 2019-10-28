@echo off
pushd antlr-cpp-runtime

rmdir /S /Q runtime\bin
rmdir /S /Q runtime\obj
rmdir /S /Q lib
mkdir lib

call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\VsDevCmd.bat

pushd runtime"
msbuild antlr4cpp-vs2017.vcxproj /p:configuration="Release Static" /p:platform=x64
popd

xcopy "runtime\bin\vs-2015\*.lib" lib\ /s

popd
echo OK