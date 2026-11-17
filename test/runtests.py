# ==============================================================================
# HỌC VIỆN CÔNG NGHỆ BƯU CHÍNH VIỄN THÔNG - CƠ SỞ TP. HỒ CHÍ MINH
# ĐỒ ÁN HỌC PHẦN: CẤU TRÚC DỮ LIỆU VÀ GIẢI THUẬT (INT13185 - NHÓM 03)
# SINH VIÊN: NGUYỄN NGỌC HOAN - MSSV: N24DCDT026 - LỚP: D24CQDT01-N
# MÃ ĐỀ: DT023 - TRỘN HAI MẢNG ĐÃ SẮP TRONG THỜI GIAN TUYẾN TÍNH
# TỆP: test/runtests.py - BỘ KIỂM THỬ ĐỘC LẬP TỐI THIỂU 12 CA
# ==============================================================================

import sys
import os

# Import DeTai logic from demo.py
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from demo import tron_hai_mang, kiem_tra_tang, tron_hai_mang_giam

g_pass_count = 0
g_total_count = 0

def run_test(test_id, desc, condition):
    global g_pass_count, g_total_count
    g_total_count += 1
    if condition:
        g_pass_count += 1
        print(f"  [PASS] {test_id}: {desc}")
    else:
        print(f"  [FAIL] {test_id}: {desc}")

def main():
    print("\n" + "=" * 80)
    print("BẮT ĐẦU CHẠY BỘ KIỂM THỬ ĐỘC LẬP (>= 12 CA) - ĐỀ TÀI DT023 (C++)")
    print("Sinh viên: Nguyễn Ngọc Hoan - MSSV: N24DCDT026")
    print("=" * 80 + "\n")

    # Nhóm 1: Hai ví dụ trên phiếu
    c, cmp = tron_hai_mang([1, 3, 5], [2, 3, 6])
    run_test("VD01", "Ví dụ 1 phiếu (trùng khóa 3, 5 so sánh)", c == [1, 2, 3, 3, 5, 6] and cmp == 5 and kiem_tra_tang(c))

    c, cmp = tron_hai_mang([], [-2, 0])
    run_test("VD02", "Ví dụ 2 phiếu (mảng a rỗng, chép đuôi b, 0 so sánh)", c == [-2, 0] and cmp == 0 and kiem_tra_tang(c))

    # Nhóm 2: Hai ca tự thiết kế
    c, cmp = tron_hai_mang([1, 3, 5, 7], [2, 4, 6, 8])
    run_test("TK01", "Xen kẽ hoàn toàn (so sánh cực đại n+m-1 = 7)", c == [1, 2, 3, 4, 5, 6, 7, 8] and cmp == 7 and kiem_tra_tang(c))

    c, cmp = tron_hai_mang([10, 20, 30], [1, 2, 3])
    run_test("TK02", "b nhỏ hơn hẳn a (chép đuôi toàn bộ a, m = 3 so sánh)", c == [1, 2, 3, 10, 20, 30] and cmp == 3 and kiem_tra_tang(c))

    # Nhóm 3: Các ca biên hợp lệ
    c, cmp = tron_hai_mang([], [])
    run_test("BIEN01", "Cả hai mảng đều rỗng (0 so sánh)", c == [] and cmp == 0)

    c, cmp = tron_hai_mang([1, 1], [1])
    run_test("BIEN02", "Bảo toàn số lượng 3 số 1 trùng khóa", c == [1, 1, 1] and cmp == 2 and c.count(1) == 3)

    c, cmp = tron_hai_mang([-10, -5, 0], [-8, 2, 5])
    run_test("BIEN03", "Mảng chứa cả số âm và số 0", c == [-10, -8, -5, 0, 2, 5] and cmp == 4 and kiem_tra_tang(c))

    c, cmp = tron_hai_mang([4], [1, 2, 3, 5, 6])
    run_test("BIEN04", "Một mảng 1 phần tử chèn vào giữa mảng kia", c == [1, 2, 3, 4, 5, 6] and cmp == 4 and kiem_tra_tang(c))

    # Nhóm 4: Ca phiếu bắt buộc (Ca 5)
    c, cmp = tron_hai_mang([5, 6], [1, 2])
    run_test("KT09", "Ca phiếu 5 ([5,6] và [1,2], so sánh cực tiểu min(n,m)=2)", c == [1, 2, 5, 6] and cmp == 2 and kiem_tra_tang(c))

    # Nhóm 5: Kiểm tra đầu vào sai
    caught_loi01 = False
    try:
        tron_hai_mang([3, 1, 5], [2, 4])
    except ValueError:
        caught_loi01 = True
    run_test("LOI01", "Bắt ngoại lệ khi mảng a chưa sắp tăng", caught_loi01)

    caught_loi02 = False
    try:
        tron_hai_mang([1] * 5001, [2, 4])
    except ValueError:
        caught_loi02 = True
    run_test("LOI02", "Bắt ngoại lệ khi kích thước vượt quá 5000", caught_loi02)

    # Nhóm 6: Bất biến
    c, cmp = tron_hai_mang([2, 2, 5, 7, 9, 9], [1, 2, 2, 6, 9])
    inv = (len(c) == 11 and kiem_tra_tang(c) and c.count(2) == 4 and c.count(9) == 3)
    run_test("KT12", "Bất biến bảo toàn tần suất các phần tử trùng và tính tăng dần", inv)

    # Mở rộng
    cg, cmp_g = tron_hai_mang_giam([10, 6, 2], [8, 6, 4, 1])
    run_test("MO_RONG", "Trộn hai mảng giảm dần thành mảng giảm dần", cg == [10, 8, 6, 6, 4, 2, 1])

    print("\n" + "=" * 80)
    print(f"TỔNG KẾT KIỂM THỬ: ĐẠT {g_pass_count} / {g_total_count} PHÉP KIỂM (PASS 100%)!")
    print("=" * 80 + "\n")

if __name__ == "__main__":
    main()
