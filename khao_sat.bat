@echo off
chcp 65001 >nul
cls
if not exist scripts\trace_and_scales.exe (
    echo [THONG BAO] Chua co file scripts\trace_and_scales.exe, dang bien dich bang g++...
    call build.bat
)
cls
scripts\trace_and_scales.exe
echo.
pause
