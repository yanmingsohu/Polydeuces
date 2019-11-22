@echo off

set PATH=%PATH%;../vs/x64/Release/
echo %date% %time% > test262.log

for /R ..\deps\test262\test %%i in (*.js) do (
  echo . >> test262.log
  echo %%i
  echo %%i >> test262.log
  Polydeuces %%i >> test262.log
)

echo Over.