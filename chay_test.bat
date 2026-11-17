@echo off
chcp 65001 >nul
cls
if not exist test\runtests.exe (
    echo [THONG BAO] Chua co file test\runtests.exe, dang bien dich bang g++...
    call build.bat
)
cls
test\runtests.exe
echo.
pause
