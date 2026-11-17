// ==============================================================================
// HỌC VIỆN CÔNG NGHỆ BƯU CHÍNH VIỄN THÔNG - CƠ SỞ TP. HỒ CHÍ MINH
// HỌC PHẦN: CẤU TRÚC DỮ LIỆU VÀ GIẢI THUẬT (INT13185 - NHÓM 03)
// GIẢNG VIÊN HƯỚNG DẪN: THS. HỒ NHỰT MINH
// SINH VIÊN: NGUYỄN NGỌC HOAN - MSSV: N24DCDT026 - LỚP: D24CQDT01-N
// MÃ ĐỀ: DT023 - TRỘN HAI MẢNG ĐÃ SẮP TRONG THỜI GIAN TUYẾN TÍNH
// ==============================================================================

#ifndef DETAI_H
#define DETAI_H

#include <vector>
#include <utility>
#include <string>

namespace DeTai {

// Kiểm tra một mảng số nguyên có tăng không giảm (arr[k] <= arr[k+1]) hay không
bool kiem_tra_tang(const std::vector<int>& arr);

// Kiểm tra tính hợp lệ của đầu vào:
// 1. Kích thước 0 <= n, m <= 5000
// 2. Cả 2 mảng a và b đều đã sắp tăng không giảm
// Ném ngoại lệ std::invalid_argument nếu không hợp lệ
void kiem_tra_dau_vao(const std::vector<int>& a, const std::vector<int>& b);

// Thuật toán trộn hai mảng đã sắp tăng thành mảng tăng trong thời gian O(n + m)
// Trả về: pair<mảng kết quả c, số phép so sánh giữa 2 phần tử>
std::pair<std::vector<int>, long long> tron_hai_mang(const std::vector<int>& a, const std::vector<int>& b);

// Thuật toán trộn kèm in ra bảng lần vết (trace table) chi tiết từng bước
std::pair<std::vector<int>, long long> lan_vet_tron(const std::vector<int>& a, const std::vector<int>& b, bool verbose = true);

// Phần mở rộng theo yêu cầu phiếu: Trộn hai mảng giảm dần thành một mảng giảm dần
std::pair<std::vector<int>, long long> tron_hai_mang_giam(const std::vector<int>& a, const std::vector<int>& b);

// Hàm giải bài toán nhận hai mảng và trả về mảng kết quả
std::vector<int> giai_bai(const std::vector<int>& a, const std::vector<int>& b);

// Hàm phụ trợ in mảng dạng [x1, x2, ...]
std::string in_mang(const std::vector<int>& arr);

} // namespace DeTai

#endif // DETAI_H
