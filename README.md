# BÁO CÁO MÃ NGUỒN ĐỀ TÀI CÁ NHÂN DT023 (C++)

## 1. Thông tin sinh viên và đề tài
* **Học phần**: Cấu trúc dữ liệu và giải thuật (INT13185 — Nhóm 03)
* **Giảng viên hướng dẫn**: ThS. Hồ Nhựt Minh
* **Họ và tên**: Nguyễn Ngọc Hoan
* **Mã số sinh viên (MSSV)**: N24DCDT026
* **Lớp**: D24CQDT01-N
* **Mã đề tài**: DT023
* **Tên đề tài**: Trộn hai mảng đã sắp trong thời gian tuyến tính (Merge Two Sorted Arrays in Linear Time)
* **Căn cứ giáo trình**: Giáo trình Cấu trúc dữ liệu và Giải thuật (INT1306), Chương 2, Mục 2.8 Bài 23; liên hệ tiêu chí sắp xếp Mục 2.1; trang in 33, 61; trang PDF 45, 73.

---

## 2. Mô tả bài toán và nguyên lý cài đặt
* **Mục tiêu**: Hợp nhất hai mảng số nguyên đã sắp tăng không giảm $a$ (dài $n$) và $b$ (dài $m$) thành một mảng tăng không giảm duy nhất $c$ dài $n + m$ trong thời gian tuyến tính $O(n + m)$ mà không dùng hàm sort lại toàn bộ.
* **Ngôn ngữ cài đặt**: **C++** (chuẩn ISO C++17). Cấu trúc dữ liệu chính: `std::vector<int>`.
* **Kỹ thuật hai chỉ số (Two-Pointers)**:
  1. Dùng hai chỉ số $i$ và $j$ trỏ vào đầu mảng $a$ và $b$. So sánh $a[i]$ và $b[j]$, chọn phần tử nhỏ hơn hoặc bằng đưa vào $c$, tăng chỉ số tương ứng.
  2. Khi một mảng cạn, sao chép tuần tự toàn bộ phần đuôi còn lại của mảng kia vào $c$.
  3. Giữ nguyên toàn bộ số lần xuất hiện của các giá trị trùng lặp.
* **Yêu cầu mở rộng**: Hàm `DeTai::tron_hai_mang_giam` trộn hai mảng giảm dần thành một mảng giảm dần với phép so sánh đảo chiều $a[i] \ge b[j]$.

---

## 3. Cấu trúc thư mục mã nguồn
```text
N24DCDT026_DT023_NguyenNgocHoan_MaNguon/
├── src/
│   ├── DeTai.h                # Khai báo các hàm và cấu trúc giao tiếp
│   └── DeTai.cpp              # Cài đặt thuật toán: kiem_tra_dau_vao, tron_hai_mang, lan_vet_tron, tron_hai_mang_giam
├── test/
│   └── runtests.cpp           # Bộ kiểm thử chuẩn hóa (12 ca kiểm thử độc lập)
├── scripts/
│   └── trace_and_scales.cpp   # Khảo sát 3 quy mô (Q1, Q2, Q3) và cấu hình lệch
├── docs/
│   ├── anh_ket_qua/           # Chứa 11 ảnh minh chứng thực thi (A01 -> A11)
│   └── logs/                  # Chứa file log kết quả chạy
├── demo.cpp                   # Chương trình demo hỗ trợ từng lệnh riêng cho mỗi ví dụ
├── build.bat                  # Script biên dịch toàn bộ mã nguồn bằng g++
├── chay_vd1.bat               # 1-click chạy riêng Ví dụ 1 trên phiếu
├── chay_vd2.bat               # 1-click chạy riêng Ví dụ 2 trên phiếu
├── nhap_phim.bat              # 1-click chạy chế độ nhập bàn phím
├── chay_test.bat              # 1-click chạy bộ kiểm thử 12 ca
├── khao_sat.bat               # 1-click chạy khảo sát 3 quy mô
├── Run_all.ps1                # Script PowerShell tự động biên dịch và chạy
└── README.md                  # Hướng dẫn thông tin đề tài, môi trường và câu lệnh
```

---

## 4. Hướng dẫn biên dịch và các lệnh chạy riêng từng ví dụ

### Bước 1: Biên dịch chương trình (chỉ cần làm 1 lần)
Chạy script `build.bat` hoặc gõ lệnh:
```cmd
g++ -std=c++17 -O2 demo.cpp src/DeTai.cpp -o demo.exe
g++ -std=c++17 -O2 test/runtests.cpp src/DeTai.cpp -o test/runtests.exe
g++ -std=c++17 -O2 scripts/trace_and_scales.cpp src/DeTai.cpp -o scripts/trace_and_scales.exe
```

### Bước 2: Từng lệnh chạy riêng biệt

| Mục đích kiểm tra | Lệnh chạy dòng lệnh (CMD/PowerShell) | Hoặc nhấp đúp tệp BAT |
| :--- | :--- | :--- |
| **Chạy riêng Ví dụ 1 (VD01)** | `.\demo.exe 1` | `chay_vd1.bat` |
| **Chạy riêng Ví dụ 2 (VD02)** | `.\demo.exe 2` | `chay_vd2.bat` |
| **Nhập dữ liệu mới từ bàn phím** | `.\demo.exe --keyboard` | `nhap_phim.bat` |
| **Chạy phần mở rộng (giảm dần)**| `.\demo.exe 3` | - |
| **Chạy bộ kiểm thử (12 ca)** | `.\test\runtests.exe` | `chay_test.bat` |
| **Chạy khảo sát 3 quy mô** | `.\scripts\trace_and_scales.exe`| `khao_sat.bat` |
| **Mở Menu tương tác chọn bài**| `.\demo.exe` | - |
