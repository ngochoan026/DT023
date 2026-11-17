// ==============================================================================
// HỌC VIỆN CÔNG NGHỆ BƯU CHÍNH VIỄN THÔNG - CƠ SỞ TP. HỒ CHÍ MINH
// HỌC PHẦN: CẤU TRÚC DỮ LIỆU VÀ GIẢI THUẬT (INT13185 - NHÓM 03)
// GIẢNG VIÊN HƯỚNG DẪN: THS. HỒ NHỰT MINH
// SINH VIÊN: NGUYỄN NGỌC HOAN - MSSV: N24DCDT026 - LỚP: D24CQDT01-N
// MÃ ĐỀ: DT023 - TRỘN HAI MẢNG ĐÃ SẮP TRONG THỜI GIAN TUYẾN TÍNH
// ==============================================================================

#include "DeTai.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>

namespace DeTai {

std::string in_mang(const std::vector<int>& arr) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        oss << arr[i];
        if (i + 1 < arr.size()) oss << ", ";
    }
    oss << "]";
    return oss.str();
}

bool kiem_tra_tang(const std::vector<int>& arr) {
    if (arr.empty()) return true;
    for (size_t k = 0; k + 1 < arr.size(); ++k) {
        if (arr[k] > arr[k + 1]) {
            return false;
        }
    }
    return true;
}

void kiem_tra_dau_vao(const std::vector<int>& a, const std::vector<int>& b) {
    size_t n = a.size();
    size_t m = b.size();
    if (n > 5000) {
        throw std::invalid_argument("Kích thước mảng a vượt quá 5000 phần tử (n = " + std::to_string(n) + ")");
    }
    if (m > 5000) {
        throw std::invalid_argument("Kích thước mảng b vượt quá 5000 phần tử (m = " + std::to_string(m) + ")");
    }
    if (!kiem_tra_tang(a)) {
        throw std::invalid_argument("Mảng a chưa được sắp xếp tăng không giảm!");
    }
    if (!kiem_tra_tang(b)) {
        throw std::invalid_argument("Mảng b chưa được sắp xếp tăng không giảm!");
    }
}

std::pair<std::vector<int>, long long> tron_hai_mang(const std::vector<int>& a, const std::vector<int>& b) {
    kiem_tra_dau_vao(a, b);

    size_t n = a.size();
    size_t m = b.size();
    std::vector<int> c(n + m);
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    long long so_so_sanh = 0;

    // Pha 1: Lần lượt so sánh 2 phần tử đầu còn lại
    while (i < n && j < m) {
        so_so_sanh++;
        if (a[i] <= b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    // Pha 2: Chép phần đuôi mảng a (khi b cạn)
    while (i < n) {
        c[k++] = a[i++];
    }

    // Pha 3: Chép phần đuôi mảng b (khi a cạn)
    while (j < m) {
        c[k++] = b[j++];
    }

    return {c, so_so_sanh};
}

std::pair<std::vector<int>, long long> lan_vet_tron(const std::vector<int>& a, const std::vector<int>& b, bool verbose) {
    kiem_tra_dau_vao(a, b);

    size_t n = a.size();
    size_t m = b.size();
    std::vector<int> c;
    c.reserve(n + m);
    size_t i = 0;
    size_t j = 0;
    long long so_so_sanh = 0;
    int step = 0;

    if (verbose) {
        std::cout << std::string(80, '=') << "\n";
        std::cout << "BẢNG LẦN VẾT THUẬT TOÁN TRỘN HAI MẢNG (Two-Pointers) - ĐỀ TÀI DT023\n";
        std::cout << "Sinh viên: Nguyễn Ngọc Hoan - MSSV: N24DCDT026\n";
        std::cout << "Đầu vào: a = " << in_mang(a) << ", b = " << in_mang(b) << "\n";
        std::cout << std::string(80, '-') << "\n";
        std::cout << std::left << std::setw(6)  << "Bước"
                  << " | " << std::setw(4)  << "i"
                  << " | " << std::setw(4)  << "j"
                  << " | " << std::setw(20) << "So sánh"
                  << " | " << std::setw(16) << "Chọn"
                  << " | " << std::setw(20) << "Mảng c hiện tại" << "\n";
        std::cout << std::string(80, '-') << "\n";
        std::cout << std::left << std::setw(6)  << 0
                  << " | " << std::setw(4)  << i
                  << " | " << std::setw(4)  << j
                  << " | " << std::setw(20) << "Khởi tạo"
                  << " | " << std::setw(16) << "-"
                  << " | " << std::setw(20) << in_mang(c) << "\n";
    }

    while (i < n && j < m) {
        step++;
        so_so_sanh++;
        std::string so_sanh_str = "a[" + std::to_string(i) + "]=" + std::to_string(a[i]) + 
                                  " <= b[" + std::to_string(j) + "]=" + std::to_string(b[j]);
        if (a[i] <= b[j]) {
            int val = a[i];
            std::string chon_str = "a[" + std::to_string(i) + "]=" + std::to_string(val);
            c.push_back(val);
            if (verbose) {
                std::cout << std::left << std::setw(6)  << step
                          << " | " << std::setw(4)  << i
                          << " | " << std::setw(4)  << j
                          << " | " << std::setw(20) << so_sanh_str
                          << " | " << std::setw(16) << chon_str
                          << " | " << std::setw(20) << in_mang(c) << "\n";
            }
            i++;
        } else {
            int val = b[j];
            std::string chon_str = "b[" + std::to_string(j) + "]=" + std::to_string(val);
            c.push_back(val);
            if (verbose) {
                std::cout << std::left << std::setw(6)  << step
                          << " | " << std::setw(4)  << i
                          << " | " << std::setw(4)  << j
                          << " | " << std::setw(20) << so_sanh_str
                          << " | " << std::setw(16) << chon_str
                          << " | " << std::setw(20) << in_mang(c) << "\n";
            }
            j++;
        }
    }

    while (i < n) {
        step++;
        int val = a[i];
        std::string chon_str = "a[" + std::to_string(i) + "]=" + std::to_string(val) + " (đuôi)";
        c.push_back(val);
        if (verbose) {
            std::cout << std::left << std::setw(6)  << step
                      << " | " << std::setw(4)  << i
                      << " | " << std::setw(4)  << j
                      << " | " << std::setw(20) << "b đã cạn"
                      << " | " << std::setw(16) << chon_str
                      << " | " << std::setw(20) << in_mang(c) << "\n";
        }
        i++;
    }

    while (j < m) {
        step++;
        int val = b[j];
        std::string chon_str = "b[" + std::to_string(j) + "]=" + std::to_string(val) + " (đuôi)";
        c.push_back(val);
        if (verbose) {
            std::cout << std::left << std::setw(6)  << step
                      << " | " << std::setw(4)  << i
                      << " | " << std::setw(4)  << j
                      << " | " << std::setw(20) << "a đã cạn"
                      << " | " << std::setw(16) << chon_str
                      << " | " << std::setw(20) << in_mang(c) << "\n";
        }
        j++;
    }

    if (verbose) {
        std::cout << std::string(80, '-') << "\n";
        std::cout << "KẾT QUẢ CUỐI CÙNG: c = " << in_mang(c) << "\n";
        std::cout << "Độ dài mảng kết quả: " << c.size() << " (khớp n + m = " << (n + m) << ")\n";
        std::cout << "Tổng số phép so sánh giữa 2 phần tử: " << so_so_sanh << "\n";
        std::cout << std::string(80, '=') << "\n";
    }

    return {c, so_so_sanh};
}

std::pair<std::vector<int>, long long> tron_hai_mang_giam(const std::vector<int>& a, const std::vector<int>& b) {
    size_t n = a.size();
    size_t m = b.size();

    // Kiểm tra giảm dần
    for (size_t k = 0; k + 1 < n; ++k) {
        if (a[k] < a[k + 1]) throw std::invalid_argument("Mảng a chưa được sắp giảm dần!");
    }
    for (size_t k = 0; k + 1 < m; ++k) {
        if (b[k] < b[k + 1]) throw std::invalid_argument("Mảng b chưa được sắp giảm dần!");
    }

    std::vector<int> c(n + m);
    size_t i = 0, j = 0, k = 0;
    long long so_so_sanh = 0;

    while (i < n && j < m) {
        so_so_sanh++;
        if (a[i] >= b[j]) { // Chọn phần tử lớn hơn để giữ thứ tự giảm dần
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    while (i < n) c[k++] = a[i++];
    while (j < m) c[k++] = b[j++];

    return {c, so_so_sanh};
}

std::vector<int> giai_bai(const std::vector<int>& a, const std::vector<int>& b) {
    return tron_hai_mang(a, b).first;
}

} // namespace DeTai
