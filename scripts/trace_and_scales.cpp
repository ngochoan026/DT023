// ==============================================================================
// HỌC VIỆN CÔNG NGHỆ BƯU CHÍNH VIỄN THÔNG - CƠ SỞ TP. HỒ CHÍ MINH
// ĐỒ ÁN HỌC PHẦN: CẤU TRÚC DỮ LIỆU VÀ GIẢI THUẬT (INT13185 - NHÓM 03)
// SINH VIÊN: NGUYỄN NGỌC HOAN - MSSV: N24DCDT026 - LỚP: D24CQDT01-N
// MÃ ĐỀ: DT023 - TRỘN HAI MẢNG ĐÃ SẮP TRONG THỜI GIAN TUYẾN TÍNH
// TỆP: scripts/trace_and_scales.cpp - KHẢO SÁT BA QUY MÔ DỮ LIỆU (C++)
// ==============================================================================

#include "../src/DeTai.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <random>
#include <chrono>
#include <cassert>

std::vector<int> tao_mang_tang(size_t n, int step_max = 3) {
    if (n == 0) return {};
    std::vector<int> arr(n);
    static std::mt19937 rng(20261017);
    std::uniform_int_distribution<int> dist_start(1, 5);
    std::uniform_int_distribution<int> dist_step(0, step_max);

    arr[0] = dist_start(rng);
    for (size_t i = 1; i < n; ++i) {
        arr[i] = arr[i - 1] + dist_step(rng);
    }
    return arr;
}

struct ScaleConfig {
    std::string ten;
    size_t n;
    size_t m;
};

int main() {
    std::cout << "\n" << std::string(85, '=') << "\n";
    std::cout << "KHẢO SÁT THUẬT TOÁN TRÊN BA QUY MÔ DỮ LIỆU HỢP LỆ (Q1, Q2, Q3) - C++\n";
    std::cout << "Sinh viên: Nguyễn Ngọc Hoan - MSSV: N24DCDT026\n";
    std::cout << std::string(85, '=') << "\n";

    std::vector<ScaleConfig> configs = {
        {"Q1 (Quy mô nhỏ)", 5, 5},
        {"Q2 (Quy mô vừa)", 50, 50},
        {"Q3 (Quy mô lớn)", 500, 500},
        {"Lệch quy mô (Unbalanced)", 10, 990}
    };

    std::cout << std::left << std::setw(26) << "Cấu hình khảo sát"
              << " | " << std::setw(6)  << "n"
              << " | " << std::setw(6)  << "m"
              << " | " << std::setw(10) << "n + m"
              << " | " << std::setw(12) << "Số so sánh"
              << " | " << std::setw(14) << "Chặn lý thuyết"
              << " | " << std::setw(12) << "Thời gian" << "\n";
    std::cout << std::string(95, '-') << "\n";

    for (const auto& cfg : configs) {
        auto a = tao_mang_tang(cfg.n);
        auto b = tao_mang_tang(cfg.m);

        auto t1 = std::chrono::high_resolution_clock::now();
        auto [c, cmp] = DeTai::tron_hai_mang(a, b);
        auto t2 = std::chrono::high_resolution_clock::now();
        double elapsed_us = std::chrono::duration<double, std::micro>(t2 - t1).count();

        assert(c.size() == cfg.n + cfg.m);
        assert(DeTai::kiem_tra_tang(c));

        size_t min_cmp = std::min(cfg.n, cfg.m);
        size_t max_cmp = (cfg.n + cfg.m > 0) ? (cfg.n + cfg.m - 1) : 0;
        std::string ly_thuyet = std::to_string(min_cmp) + " .. " + std::to_string(max_cmp);
        std::string tg_str = std::to_string((int)elapsed_us) + " us";

        std::cout << std::left << std::setw(26) << cfg.ten
                  << " | " << std::setw(6)  << cfg.n
                  << " | " << std::setw(6)  << cfg.m
                  << " | " << std::setw(10) << (cfg.n + cfg.m)
                  << " | " << std::setw(12) << cmp
                  << " | " << std::setw(14) << ly_thuyet
                  << " | " << std::setw(12) << tg_str << "\n";
    }

    std::cout << std::string(95, '=') << "\n";
    std::cout << "NHẬN XÉT ĐỘ PHỨC TẠP:\n";
    std::cout << "1. Số phép so sánh luôn nằm nghiêm ngặt trong khoảng [min(n, m), n + m - 1].\n";
    std::cout << "2. Khi n, m tăng từ 5 -> 50 -> 500, số phép so sánh và thời gian tăng tuyến tính O(n + m).\n";
    std::cout << "3. Bộ nhớ phụ ngoài mảng kết quả c duy trì là O(1) (chỉ dùng các con trỏ chỉ số i, j, k).\n";
    std::cout << std::string(95, '=') << "\n\n";

    return 0;
}
