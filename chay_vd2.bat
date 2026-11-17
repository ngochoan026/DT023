@echo off
chcp 65001 >nul
cls
if not exist demo.exe (
    echo [THONG BAO] Chua co file demo.exe, dang bien dich bang g++...
    call build.bat
)
cls
demo.exe 2
echo.
pause
