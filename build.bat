@echo off
echo ========================================================
echo BIEN DICH MA NGUON DE TAI DT023 (C++)
echo Sinh vien: Nguyen Ngoc Hoan - MSSV: N24DCDT026
echo ========================================================

g++ -std=c++17 -O2 demo.cpp src/DeTai.cpp -o demo.exe
if %ERRORLEVEL% NEQ 0 (
    echo [LOI] Khong the bien dich demo.cpp
    exit /b 1
)
echo [1/3] Da bien dich thanh cong: demo.exe

g++ -std=c++17 -O2 test/runtests.cpp src/DeTai.cpp -o test/runtests.exe
if %ERRORLEVEL% NEQ 0 (
    echo [LOI] Khong the bien dich test/runtests.cpp
    exit /b 1
)
echo [2/3] Da bien dich thanh cong: test\runtests.exe

g++ -std=c++17 -O2 scripts/trace_and_scales.cpp src/DeTai.cpp -o scripts/trace_and_scales.exe
if %ERRORLEVEL% NEQ 0 (
    echo [LOI] Khong the bien dich scripts/trace_and_scales.cpp
    exit /b 1
)
echo [3/3] Da bien dich thanh cong: scripts\trace_and_scales.exe

echo ========================================================
echo HOAN TAT BIEN DICH TOAN BO MA NGUON!
echo ========================================================
