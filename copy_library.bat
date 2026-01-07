echo off

set project=%1
set config=%2
set platform=%3

copy .\build\lib\Shared\%config%-%platform%\apron-shared.dll .\build\bin\%project%\%config%-%platform%\apron-shared.dll