@echo off
set OUTLIB=%cd%\antlr-cpp-runtime\lib
rmdir /S /Q %OUTLIB%
mkdir %OUTLIB%

pushd antlr-cpp-runtime\runtime\Cpp

rmdir /S /Q runtime\bin
rmdir /S /Q runtime\obj

set VS_VERSION=2019
call "C:\Program Files (x86)\Microsoft Visual Studio\%VS_VERSION%\Community\Common7\Tools\VsDevCmd.bat

pushd runtime
msbuild antlr4cpp-vs%VS_VERSION%.vcxproj /p:configuration="Release Static" /p:platform=x64
popd

xcopy "runtime\bin\vs-%VS_VERSION%\*.lib" %OUTLIB% /s

popd
echo OK