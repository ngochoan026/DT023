# ==============================================================================
# HỌC VIỆN CÔNG NGHỆ BƯU CHÍNH VIỄN THÔNG - CƠ SỞ TP. HỒ CHÍ MINH
# ĐỒ ÁN HỌC PHẦN: CẤU TRÚC DỮ LIỆU VÀ GIẢI THUẬT (INT13185 - NHÓM 03)
# SINH VIÊN: NGUYỄN NGỌC HOAN - MSSV: N24DCDT026 - LỚP: D24CQDT01-N
# MÃ ĐỀ: DT023 - TRỘN HAI MẢNG ĐÃ SẮP TRONG THỜI GIAN TUYẾN TÍNH
# SCRIPT: Run_all.ps1 - BIÊN DỊCH VÀ CHẠY TOÀN BỘ CHƯƠNG TRÌNH C++
# ==============================================================================

param(
    [string]$Gxx = "g++"
)

Write-Host "======================================================================" -ForegroundColor Cyan
Write-Host "KHỞI CHẠY QUY TRÌNH BIÊN DỊCH VÀ KIỂM THỬ ĐỀ TÀI DT023 (C++)" -ForegroundColor Cyan
Write-Host "Sinh viên: Nguyễn Ngọc Hoan | MSSV: N24DCDT026 | Lớp: D24CQDT01-N" -ForegroundColor Cyan
Write-Host "======================================================================" -ForegroundColor Cyan

$LogDir = Join-Path $PSScriptRoot "docs\logs"
if (-not (Test-Path $LogDir)) {
    New-Item -ItemType Directory -Path $LogDir -Force | Out-Null
}

# 1. Biên dịch
Write-Host "`n[1/4] Đang biên dịch các tệp nguồn C++..." -ForegroundColor Yellow
& $Gxx -std=c++17 -O2 (Join-Path $PSScriptRoot "demo.cpp") (Join-Path $PSScriptRoot "src\DeTai.cpp") -o (Join-Path $PSScriptRoot "demo.exe")
& $Gxx -std=c++17 -O2 (Join-Path $PSScriptRoot "test\runtests.cpp") (Join-Path $PSScriptRoot "src\DeTai.cpp") -o (Join-Path $PSScriptRoot "test\runtests.exe")
& $Gxx -std=c++17 -O2 (Join-Path $PSScriptRoot "scripts\trace_and_scales.cpp") (Join-Path $PSScriptRoot "src\DeTai.cpp") -o (Join-Path $PSScriptRoot "scripts\trace_and_scales.exe")
Write-Host "-> Biên dịch hoàn tất!" -ForegroundColor Green

# 2. Chạy Demo
Write-Host "`n[2/4] Chạy demo hai ví dụ và lưu log..." -ForegroundColor Yellow
$DemoLog = Join-Path $LogDir "demo_examples.log"
& (Join-Path $PSScriptRoot "demo.exe") | Tee-Object -FilePath $DemoLog

# 3. Chạy Tests
Write-Host "`n[3/4] Chạy bộ kiểm thử và lưu log..." -ForegroundColor Yellow
$TestLog = Join-Path $LogDir "tests_all.log"
& (Join-Path $PSScriptRoot "test\runtests.exe") | Tee-Object -FilePath $TestLog

# 4. Chạy Khảo sát quy mô
Write-Host "`n[4/4] Chạy khảo sát quy mô và lưu log..." -ForegroundColor Yellow
$ScalesLog = Join-Path $LogDir "trace_scales.log"
& (Join-Path $PSScriptRoot "scripts\trace_and_scales.exe") | Tee-Object -FilePath $ScalesLog

Write-Host "`n======================================================================" -ForegroundColor Cyan
Write-Host "HOÀN TẤT TOÀN BỘ QUY TRÌNH THỰC THI!" -ForegroundColor Cyan
Write-Host "======================================================================" -ForegroundColor Cyan
