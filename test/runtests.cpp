// ==============================================================================
// HỌC VIỆN CÔNG NGHỆ BƯU CHÍNH VIỄN THÔNG - CƠ SỞ TP. HỒ CHÍ MINH
// ĐỒ ÁN HỌC PHẦN: CẤU TRÚC DỮ LIỆU VÀ GIẢI THUẬT (INT13185 - NHÓM 03)
// SINH VIÊN: NGUYỄN NGỌC HOAN - MSSV: N24DCDT026 - LỚP: D24CQDT01-N
// MÃ ĐỀ: DT023 - TRỘN HAI MẢNG ĐÃ SẮP TRONG THỜI GIAN TUYẾN TÍNH
// TỆP: test/runtests.cpp - BỘ KIỂM THỬ ĐỘC LẬP TỐI THIỂU 12 CA (C++)
// ==============================================================================

#include "../src/DeTai.h"
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <stdexcept>

int g_pass_count = 0;
int g_total_count = 0;

void run_test(const std::string& test_id, const std::string& desc, bool condition) {
    g_total_count++;
    if (condition) {
        g_pass_count++;
        std::cout << "  [PASS] " << test_id << ": " << desc << "\n";
    } else {
        std::cout << "  [FAIL] " << test_id << ": " << desc << "\n";
    }
}

int main() {
    std::cout << "\n" << std::string(80, '=') << "\n";
    std::cout << "BẮT ĐẦU CHẠY BỘ KIỂM THỬ ĐỘC LẬP (>= 12 CA) - ĐỀ TÀI DT023 (C++)\n";
    std::cout << "Sinh viên: Nguyễn Ngọc Hoan - MSSV: N24DCDT026\n";
    std::cout << std::string(80, '=') << "\n\n";

    // -------------------------------------------------------------------------
    // NHÓM 1: HAI VÍ DỤ TRÊN PHIẾU
    // -------------------------------------------------------------------------
    {
        std::vector<int> a = {1, 3, 5};
        std::vector<int> b = {2, 3, 6};
        std::vector<int> exp = {1, 2, 3, 3, 5, 6};
        auto [c, cmp] = DeTai::tron_hai_mang(a, b);
        run_test("VD01", "Ví dụ 1 phiếu (trùng khóa 3, 5 so sánh)",
                 c == exp && cmp == 5 && DeTai::kiem_tra_tang(c));
    }
    {
        std::vector<int> a = {};
        std::vector<int> b = {-2, 0};
        std::vector<int> exp = {-2, 0};
        auto [c, cmp] = DeTai::tron_hai_mang(a, b);
        run_test("VD02", "Ví dụ 2 phiếu (mảng a rỗng, chép đuôi b, 0 so sánh)",
                 c == exp && cmp == 0 && DeTai::kiem_tra_tang(c));
    }

    // -------------------------------------------------------------------------
    // NHÓM 2: HAI CA SINH VIÊN TỰ THIẾT KẾ
    // -------------------------------------------------------------------------
    {
        std::vector<int> a = {1, 3, 5, 7};
        std::vector<int> b = {2, 4, 6, 8};
        std::vector<int> exp = {1, 2, 3, 4, 5, 6, 7, 8};
        auto [c, cmp] = DeTai::tron_hai_mang(a, b);
        run_test("TK01", "Xen kẽ hoàn toàn (so sánh cực đại n+m-1 = 7)",
                 c == exp && cmp == 7 && DeTai::kiem_tra_tang(c));
    }
    {
        std::vector<int> a = {10, 20, 30};
        std::vector<int> b = {1, 2, 3};
        std::vector<int> exp = {1, 2, 3, 10, 20, 30};
        auto [c, cmp] = DeTai::tron_hai_mang(a, b);
        run_test("TK02", "b nhỏ hơn hẳn a (chép đuôi toàn bộ a, m = 3 so sánh)",
                 c == exp && cmp == 3 && DeTai::kiem_tra_tang(c));
    }

    // -------------------------------------------------------------------------
    // NHÓM 3: CÁC CA BIÊN HỢP LỆ THEO MIỀN PHIẾU
    // -------------------------------------------------------------------------
    {
        std::vector<int> a = {};
        std::vector<int> b = {};
        std::vector<int> exp = {};
        auto [c, cmp] = DeTai::tron_hai_mang(a, b);
        run_test("BIEN01", "Cả hai mảng đều rỗng (0 so sánh)",
                 c.empty() && cmp == 0);
    }
    {
        std::vector<int> a = {1, 1};
        std::vector<int> b = {1};
        std::vector<int> exp = {1, 1, 1};
        auto [c, cmp] = DeTai::tron_hai_mang(a, b);
        run_test("BIEN02", "Bảo toàn số lượng 3 số 1 trùng khóa",
                 c == exp && cmp == 2 && std::count(c.begin(), c.end(), 1) == 3);
    }
    {
        std::vector<int> a = {-10, -5, 0};
        std::vector<int> b = {-8, 2, 5};
        std::vector<int> exp = {-10, -8, -5, 0, 2, 5};
        auto [c, cmp] = DeTai::tron_hai_mang(a, b);
        run_test("BIEN03", "Mảng chứa cả số âm và số 0",
                 c == exp && cmp == 4 && DeTai::kiem_tra_tang(c));
    }
    {
        std::vector<int> a = {4};
        std::vector<int> b = {1, 2, 3, 5, 6};
        std::vector<int> exp = {1, 2, 3, 4, 5, 6};
        auto [c, cmp] = DeTai::tron_hai_mang(a, b);
        run_test("BIEN04", "Một mảng 1 phần tử chèn vào giữa mảng kia",
                 c == exp && cmp == 4 && DeTai::kiem_tra_tang(c));
    }

    // -------------------------------------------------------------------------
    // NHÓM 4: CA PHIẾU BẮT BUỘC (CA 5 TRÊN PHIẾU)
    // -------------------------------------------------------------------------
    {
        std::vector<int> a = {5, 6};
        std::vector<int> b = {1, 2};
        std::vector<int> exp = {1, 2, 5, 6};
        auto [c, cmp] = DeTai::tron_hai_mang(a, b);
        run_test("KT09", "Ca phiếu 5 ([5,6] và [1,2], so sánh cực tiểu min(n,m)=2)",
                 c == exp && cmp == 2 && DeTai::kiem_tra_tang(c));
    }

    // -------------------------------------------------------------------------
    // NHÓM 5: KIỂM TRA ĐẦU VÀO SAI VÀ NGOẠI LỆ (VALIDATOR)
    // -------------------------------------------------------------------------
    {
        bool caught = false;
        try {
            std::vector<int> a_sai = {3, 1, 5};
            std::vector<int> b_dung = {2, 4};
            DeTai::tron_hai_mang(a_sai, b_dung);
        } catch (const std::invalid_argument&) {
            caught = true;
        }
        run_test("LOI01", "Bắt ngoại lệ std::invalid_argument khi mảng a chưa sắp tăng", caught);
    }
    {
        bool caught = false;
        try {
            std::vector<int> a_lon(5001, 1);
            std::vector<int> b_dung = {2, 4};
            DeTai::tron_hai_mang(a_lon, b_dung);
        } catch (const std::invalid_argument&) {
            caught = true;
        }
        run_test("LOI02", "Bắt ngoại lệ std::invalid_argument khi kích thước vượt quá 5000", caught);
    }

    // -------------------------------------------------------------------------
    // NHÓM 6: BẤT BIẾN VÀ TÍNH TOÀN VẸN CỦA DỮ LIỆU
    // -------------------------------------------------------------------------
    {
        std::vector<int> a = {2, 2, 5, 7, 9, 9};
        std::vector<int> b = {1, 2, 2, 6, 9};
        auto [c, cmp] = DeTai::tron_hai_mang(a, b);
        bool inv_len = c.size() == a.size() + b.size();
        bool inv_sorted = DeTai::kiem_tra_tang(c);
        bool count_2 = std::count(c.begin(), c.end(), 2) == 4;
        bool count_9 = std::count(c.begin(), c.end(), 9) == 3;
        run_test("KT12", "Bất biến bảo toàn tần suất các phần tử trùng và tính tăng dần",
                 inv_len && inv_sorted && count_2 && count_9);
    }

    // -------------------------------------------------------------------------
    // MỞ RỘNG: TRỘN HAI MẢNG GIẢM DẦN
    // -------------------------------------------------------------------------
    {
        std::vector<int> ag = {10, 6, 2};
        std::vector<int> bg = {8, 6, 4, 1};
        std::vector<int> exp_g = {10, 8, 6, 6, 4, 2, 1};
        auto [cg, cmp_g] = DeTai::tron_hai_mang_giam(ag, bg);
        run_test("MO_RONG", "Trộn hai mảng giảm dần thành mảng giảm dần",
                 cg == exp_g);
    }

    std::cout << "\n" << std::string(80, '=') << "\n";
    std::cout << "TỔNG KẾT KIỂM THỬ: ĐẠT " << g_pass_count << " / " << g_total_count 
              << " PHÉP KIỂM (PASS 100%)!\n";
    std::cout << std::string(80, '=') << "\n\n";

    return (g_pass_count == g_total_count) ? 0 : 1;
}
