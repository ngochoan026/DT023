// ==============================================================================
// HỌC VIỆN CÔNG NGHỆ BƯU CHÍNH VIỄN THÔNG - CƠ SỞ TP. HỒ CHÍ MINH
// ĐỒ ÁN HỌC PHẦN: CẤU TRÚC DỮ LIỆU VÀ GIẢI THUẬT (INT13185 - NHÓM 03)
// SINH VIÊN: NGUYỄN NGỌC HOAN - MSSV: N24DCDT026 - LỚP: D24CQDT01-N
// MÃ ĐỀ: DT023 - TRỘN HAI MẢNG ĐÃ SẮP TRONG THỜI GIAN TUYẾN TÍNH
// TỆP: demo.cpp - CHƯƠNG TRÌNH CHẠY TỪNG CA TỪ 1 ĐẾN 8 ĐỂ CHỤP ẢNH A01 ĐẾN A08
// ==============================================================================

#include "src/DeTai.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>

void in_banner(const std::string& ma_anh, const std::string& tieu_de) {
    std::cout << "\n" << std::string(80, '=') << "\n";
    std::cout << "CHƯƠNG TRÌNH THỰC THI ĐỀ TÀI DT023 (C++)\n";
    std::cout << "Sinh viên: Nguyễn Ngọc Hoan | MSSV: N24DCDT026 | Lớp: D24CQDT01-N\n";
    std::cout << ">>> MINH CHỨNG: [" << ma_anh << "] - " << tieu_de << "\n";
    std::cout << std::string(80, '=') << "\n";
}

// A01: Ví dụ 1 phiếu (VD01)
void chay_a01() {
    in_banner("ẢNH A01", "VÍ DỤ 1 TRÊN PHIẾU (VD01)");
    std::vector<int> a = {1, 3, 5};
    std::vector<int> b = {2, 3, 6};
    std::vector<int> exp = {1, 2, 3, 3, 5, 6};
    std::cout << "Mảng đầu vào a: " << DeTai::in_mang(a) << "\n";
    std::cout << "Mảng đầu vào b: " << DeTai::in_mang(b) << "\n";
    std::cout << "Kỳ vọng: " << DeTai::in_mang(exp) << " (giữ nguyên hai phần tử 3)\n\n";
    auto [c, cmp] = DeTai::lan_vet_tron(a, b, true);
    assert(c == exp);
    std::cout << "\n-> ĐÁNH GIÁ: [PASS A01 - VD01]. Kết quả c = " << DeTai::in_mang(c) << ", số so sánh = " << cmp << "\n";
}

// A02: Ví dụ 2 phiếu (VD02)
void chay_a02() {
    in_banner("ẢNH A02", "VÍ DỤ 2 TRÊN PHIẾU (VD02)");
    std::vector<int> a = {};
    std::vector<int> b = {-2, 0};
    std::vector<int> exp = {-2, 0};
    std::cout << "Mảng đầu vào a: " << DeTai::in_mang(a) << " (rỗng)\n";
    std::cout << "Mảng đầu vào b: " << DeTai::in_mang(b) << "\n";
    std::cout << "Kỳ vọng: " << DeTai::in_mang(exp) << " (mảng a rỗng từ đầu, sao chép đuôi b)\n\n";
    auto [c, cmp] = DeTai::lan_vet_tron(a, b, true);
    assert(c == exp);
    std::cout << "\n-> ĐÁNH GIÁ: [PASS A02 - VD02]. Kết quả c = " << DeTai::in_mang(c) << ", số so sánh = " << cmp << "\n";
}

// A03: Tự thiết kế 1 (TK01 - Xen kẽ hoàn toàn)
void chay_a03() {
    in_banner("ẢNH A03", "CA TỰ THIẾT KẾ 1 (TK01 - XEN KẼ HOÀN TOÀN)");
    std::vector<int> a = {1, 3, 5, 7};
    std::vector<int> b = {2, 4, 6, 8};
    std::vector<int> exp = {1, 2, 3, 4, 5, 6, 7, 8};
    std::cout << "Mục đích: Kiểm tra trường hợp các phần tử xen kẽ đều, đạt số phép so sánh cực đại n + m - 1 = 7.\n";
    std::cout << "Mảng đầu vào a: " << DeTai::in_mang(a) << "\n";
    std::cout << "Mảng đầu vào b: " << DeTai::in_mang(b) << "\n\n";
    auto [c, cmp] = DeTai::lan_vet_tron(a, b, true);
    assert(c == exp);
    std::cout << "\n-> ĐÁNH GIÁ: [PASS A03 - TK01]. Kết quả c = " << DeTai::in_mang(c) << ", số so sánh cực đại = " << cmp << "\n";
}

// A04: Tự thiết kế 2 (TK02 - b nhỏ hơn hẳn a)
void chay_a04() {
    in_banner("ẢNH A04", "CA TỰ THIẾT KẾ 2 (TK02 - B NHỎ HƠN HẲN A)");
    std::vector<int> a = {10, 20, 30};
    std::vector<int> b = {1, 2, 3};
    std::vector<int> exp = {1, 2, 3, 10, 20, 30};
    std::cout << "Mục đích: Kiểm tra nhánh chép đuôi toàn bộ mảng a khi mảng b cạn trước sau đúng m = 3 so sánh.\n";
    std::cout << "Mảng đầu vào a: " << DeTai::in_mang(a) << "\n";
    std::cout << "Mảng đầu vào b: " << DeTai::in_mang(b) << "\n\n";
    auto [c, cmp] = DeTai::lan_vet_tron(a, b, true);
    assert(c == exp);
    std::cout << "\n-> ĐÁNH GIÁ: [PASS A04 - TK02]. Kết quả c = " << DeTai::in_mang(c) << ", số so sánh = " << cmp << "\n";
}

// A05: Biên 1 (BIEN01 - Hai mảng rỗng)
void chay_a05() {
    in_banner("ẢNH A05", "CA BIÊN 1 (BIEN01 - CẢ HAI MẢNG ĐỀU RỖNG)");
    std::vector<int> a = {};
    std::vector<int> b = {};
    std::cout << "Mục đích: Kiểm tra biên cực tiểu n = 0, m = 0, thuật toán trả về mảng rỗng và không so sánh.\n";
    std::cout << "Mảng đầu vào a: " << DeTai::in_mang(a) << "\n";
    std::cout << "Mảng đầu vào b: " << DeTai::in_mang(b) << "\n\n";
    auto [c, cmp] = DeTai::lan_vet_tron(a, b, true);
    assert(c.empty());
    std::cout << "\n-> ĐÁNH GIÁ: [PASS A05 - BIEN01]. Kết quả c = " << DeTai::in_mang(c) << ", số so sánh = " << cmp << "\n";
}

// A06: Biên 2 (BIEN02 - Toàn bộ trùng khóa 1)
void chay_a06() {
    in_banner("ẢNH A06", "CA BIÊN 2 (BIEN02 - BẢO TOÀN PHẦN TỬ TRÙNG KHÓA)");
    std::vector<int> a = {1, 1};
    std::vector<int> b = {1};
    std::vector<int> exp = {1, 1, 1};
    std::cout << "Mục đích: Kiểm tra việc bảo toàn đầy đủ số lượng các khóa trùng nhau theo phiếu giao (3 số 1).\n";
    std::cout << "Mảng đầu vào a: " << DeTai::in_mang(a) << "\n";
    std::cout << "Mảng đầu vào b: " << DeTai::in_mang(b) << "\n\n";
    auto [c, cmp] = DeTai::lan_vet_tron(a, b, true);
    assert(c == exp);
    std::cout << "\n-> ĐÁNH GIÁ: [PASS A06 - BIEN02]. Kết quả c = " << DeTai::in_mang(c) << ", số so sánh = " << cmp << "\n";
}

// A07: Biên 3 (BIEN03 - Số âm và số 0)
void chay_a07() {
    in_banner("ẢNH A07", "CA BIÊN 3 (BIEN03 - CHỨA SỐ ÂM VÀ SỐ 0)");
    std::vector<int> a = {-10, -5, 0};
    std::vector<int> b = {-8, 2, 5};
    std::vector<int> exp = {-10, -8, -5, 0, 2, 5};
    std::cout << "Mục đích: Kiểm tra thuật toán hoạt động chính xác khi miền giá trị chứa số âm và số 0.\n";
    std::cout << "Mảng đầu vào a: " << DeTai::in_mang(a) << "\n";
    std::cout << "Mảng đầu vào b: " << DeTai::in_mang(b) << "\n\n";
    auto [c, cmp] = DeTai::lan_vet_tron(a, b, true);
    assert(c == exp);
    std::cout << "\n-> ĐÁNH GIÁ: [PASS A07 - BIEN03]. Kết quả c = " << DeTai::in_mang(c) << ", số so sánh = " << cmp << "\n";
}

// A08: Input sai (LOI01 - Validator)
void chay_a08() {
    in_banner("ẢNH A08", "KIỂM TRA DỮ LIỆU ĐẦU VÀO SAI (LOI01 - VALIDATOR)");
    std::vector<int> a = {3, 1, 5}; // Sai: 3 > 1 chưa sắp tăng
    std::vector<int> b = {2, 4};
    std::cout << "Mục đích: Kiểm tra hàm kiem_tra_dau_vao từ chối dữ liệu không hợp lệ (mảng a chưa sắp tăng).\n";
    std::cout << "Dữ liệu thử nghiệm: a = " << DeTai::in_mang(a) << ", b = " << DeTai::in_mang(b) << "\n\n";
    try {
        DeTai::tron_hai_mang(a, b);
        std::cout << "-> ĐÁNH GIÁ: [FAIL] Không bắt được lỗi!\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "-> KẾT QUẢ THỰC TẾ: Bắt thành công ngoại lệ std::invalid_argument!\n";
        std::cout << "   Thông báo lỗi hệ thống: \"" << e.what() << "\"\n";
        std::cout << "-> ĐÁNH GIÁ: [PASS A08 - LOI01] - Dữ liệu sai bị từ chối chính xác.\n";
    }
}

// Nhập bàn phím
void che_do_nhap_ban_phim() {
    in_banner("BÀN PHÍM", "CHẾ ĐỘ NHẬP DỮ LIỆU TÙY Ý TỪ BÀN PHÍM");
    try {
        std::cout << "Nhập các phần tử mảng a tăng dần (cách nhau bởi dấu cách, ví dụ: 1 3 5 8): ";
        std::string line_a;
        std::getline(std::cin, line_a);
        std::stringstream ss_a(line_a);
        std::vector<int> a;
        int val;
        while (ss_a >> val) a.push_back(val);

        std::cout << "Nhập các phần tử mảng b tăng dần (cách nhau bởi dấu cách, ví dụ: 2 3 7 9): ";
        std::string line_b;
        std::getline(std::cin, line_b);
        std::stringstream ss_b(line_b);
        std::vector<int> b;
        while (ss_b >> val) b.push_back(val);

        std::cout << "\nĐang thực hiện thuật toán trộn hai mảng...\n";
        DeTai::lan_vet_tron(a, b, true);
    } catch (const std::exception& e) {
        std::cout << "\n[LỖI DỮ LIỆU]: " << e.what() << "\n";
    }
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        std::string arg = argv[1];
        if (arg == "1" || arg == "a01" || arg == "vd01") { chay_a01(); return 0; }
        if (arg == "2" || arg == "a02" || arg == "vd02") { chay_a02(); return 0; }
        if (arg == "3" || arg == "a03" || arg == "tk01") { chay_a03(); return 0; }
        if (arg == "4" || arg == "a04" || arg == "tk02") { chay_a04(); return 0; }
        if (arg == "5" || arg == "a05" || arg == "bien01") { chay_a05(); return 0; }
        if (arg == "6" || arg == "a06" || arg == "bien02") { chay_a06(); return 0; }
        if (arg == "7" || arg == "a07" || arg == "bien03") { chay_a07(); return 0; }
        if (arg == "8" || arg == "a08" || arg == "loi01") { chay_a08(); return 0; }
        if (arg == "--keyboard" || arg == "-k") { che_do_nhap_ban_phim(); return 0; }
    }

    // Hiển thị menu khi không có tham số
    std::cout << "\n" << std::string(80, '=') << "\n";
    std::cout << "DANH SÁCH LỆNH CHẠY TỪNG CA ĐỂ CHỤP ẢNH MINH CHỨNG (A01 - A08):\n";
    std::cout << "  .\\demo.exe 1  -> [Ảnh A01] Ví dụ 1 phiếu (VD01: a=[1,3,5], b=[2,3,6])\n";
    std::cout << "  .\\demo.exe 2  -> [Ảnh A02] Ví dụ 2 phiếu (VD02: a=[], b=[-2,0])\n";
    std::cout << "  .\\demo.exe 3  -> [Ảnh A03] Ca tự thiết kế 1 (TK01: Xen kẽ hoàn toàn)\n";
    std::cout << "  .\\demo.exe 4  -> [Ảnh A04] Ca tự thiết kế 2 (TK02: b nhỏ hơn hẳn a)\n";
    std::cout << "  .\\demo.exe 5  -> [Ảnh A05] Ca biên 1 (BIEN01: Cả hai mảng rỗng)\n";
    std::cout << "  .\\demo.exe 6  -> [Ảnh A06] Ca biên 2 (BIEN02: Bảo toàn 3 số 1 trùng khóa)\n";
    std::cout << "  .\\demo.exe 7  -> [Ảnh A07] Ca biên 3 (BIEN03: Số âm và số 0)\n";
    std::cout << "  .\\demo.exe 8  -> [Ảnh A08] Kiểm tra dữ liệu đầu vào sai (LOI01)\n";
    std::cout << "  .\\test\\runtests.exe -> [Ảnh A09] Tổng kết toàn bộ bộ kiểm thử PASS 100%\n";
    std::cout << std::string(80, '-') << "\n";
    std::cout << "Nhập số (1-8) để chạy ngay ca tương ứng: ";

    std::string choice;
    if (std::getline(std::cin, choice)) {
        if (choice == "1") chay_a01();
        else if (choice == "2") chay_a02();
        else if (choice == "3") chay_a03();
        else if (choice == "4") chay_a04();
        else if (choice == "5") chay_a05();
        else if (choice == "6") chay_a06();
        else if (choice == "7") chay_a07();
        else if (choice == "8") chay_a08();
        else std::cout << "Lựa chọn không hợp lệ.\n";
    }

    return 0;
}
