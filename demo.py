# ==============================================================================
# HỌC VIỆN CÔNG NGHỆ BƯU CHÍNH VIỄN THÔNG - CƠ SỞ TP. HỒ CHÍ MINH
# ĐỒ ÁN HỌC PHẦN: CẤU TRÚC DỮ LIỆU VÀ GIẢI THUẬT (INT13185 - NHÓM 03)
# SINH VIÊN: NGUYỄN NGỌC HOAN - MSSV: N24DCDT026 - LỚP: D24CQDT01-N
# MÃ ĐỀ: DT023 - TRỘN HAI MẢNG ĐÃ SẮP TRONG THỜI GIAN TUYẾN TÍNH
# TỆP: demo.py - CHƯƠNG TRÌNH THỰC THI (CHO PHÉP CHẠY TRỰC TIẾP TRÊN MÁY BẬT DEVICE GUARD)
# ==============================================================================

import sys

def in_mang(arr):
    return "[" + ", ".join(map(str, arr)) + "]"

def kiem_tra_tang(arr):
    for k in range(len(arr) - 1):
        if arr[k] > arr[k + 1]:
            return False
    return True

def kiem_tra_dau_vao(a, b):
    if len(a) > 5000:
        raise ValueError(f"Kích thước mảng a vượt quá 5000 phần tử (n = {len(a)})")
    if len(b) > 5000:
        raise ValueError(f"Kích thước mảng b vượt quá 5000 phần tử (m = {len(b)})")
    if not kiem_tra_tang(a):
        raise ValueError("Mảng a chưa được sắp xếp tăng không giảm!")
    if not kiem_tra_tang(b):
        raise ValueError("Mảng b chưa được sắp xếp tăng không giảm!")

def tron_hai_mang(a, b):
    kiem_tra_dau_vao(a, b)
    n, m = len(a), len(b)
    c = []
    i, j = 0, 0
    so_so_sanh = 0
    while i < n and j < m:
        so_so_sanh += 1
        if a[i] <= b[j]:
            c.append(a[i])
            i += 1
        else:
            c.append(b[j])
            j += 1
    while i < n:
        c.append(a[i])
        i += 1
    while j < m:
        c.append(b[j])
        j += 1
    return c, so_so_sanh

def lan_vet_tron(a, b, verbose=True):
    kiem_tra_dau_vao(a, b)
    n, m = len(a), len(b)
    c = []
    i, j = 0, 0
    so_so_sanh = 0
    step = 0

    if verbose:
        print("=" * 80)
        print("BẢNG LẦN VẾT THUẬT TOÁN TRỘN HAI MẢNG (Two-Pointers) - ĐỀ TÀI DT023 (C++)")
        print("Sinh viên: Nguyễn Ngọc Hoan - MSSV: N24DCDT026")
        print(f"Đầu vào: a = {in_mang(a)}, b = {in_mang(b)}")
        print("-" * 80)
        print(f"{'Bước':<6} | {'i':<4} | {'j':<4} | {'So sánh':<20} | {'Chọn':<16} | {'Mảng c hiện tại':<20}")
        print("-" * 80)
        print(f"{0:<6} | {0:<4} | {0:<4} | {'Khởi tạo':<20} | {'-':<16} | {in_mang(c):<20}")

    while i < n and j < m:
        step += 1
        so_so_sanh += 1
        so_sanh_str = f"a[{i}]={a[i]} <= b[{j}]={b[j]}"
        if a[i] <= b[j]:
            val = a[i]
            chon_str = f"a[{i}]={val}"
            c.append(val)
            if verbose:
                print(f"{step:<6} | {i:<4} | {j:<4} | {so_sanh_str:<20} | {chon_str:<16} | {in_mang(c):<20}")
            i += 1
        else:
            val = b[j]
            chon_str = f"b[{j}]={val}"
            c.append(val)
            if verbose:
                print(f"{step:<6} | {i:<4} | {j:<4} | {so_sanh_str:<20} | {chon_str:<16} | {in_mang(c):<20}")
            j += 1

    while i < n:
        step += 1
        val = a[i]
        chon_str = f"a[{i}]={val} (đuôi)"
        c.append(val)
        if verbose:
            print(f"{step:<6} | {i:<4} | {j:<4} | {'b đã cạn':<20} | {chon_str:<16} | {in_mang(c):<20}")
        i += 1

    while j < m:
        step += 1
        val = b[j]
        chon_str = f"b[{j}]={val} (đuôi)"
        c.append(val)
        if verbose:
            print(f"{step:<6} | {i:<4} | {j:<4} | {'a đã cạn':<20} | {chon_str:<16} | {in_mang(c):<20}")
        j += 1

    if verbose:
        print("-" * 80)
        print(f"KẾT QUẢ CUỐI CÙNG: c = {in_mang(c)}")
        print(f"Độ dài mảng kết quả: {len(c)} (khớp n + m = {n + m})")
        print(f"Tổng số phép so sánh giữa 2 phần tử: {so_so_sanh}")
        print("=" * 80)

    return c, so_so_sanh

def tron_hai_mang_giam(a, b):
    for k in range(len(a) - 1):
        if a[k] < a[k + 1]: raise ValueError("Mảng a chưa được sắp giảm dần")
    for k in range(len(b) - 1):
        if b[k] < b[k + 1]: raise ValueError("Mảng b chưa được sắp giảm dần")
    c = []
    i, j = 0, 0
    so_so_sanh = 0
    while i < len(a) and j < len(b):
        so_so_sanh += 1
        if a[i] >= b[j]:
            c.append(a[i])
            i += 1
        else:
            c.append(b[j])
            j += 1
    while i < len(a): c.append(a[i]); i += 1
    while j < len(b): c.append(b[j]); j += 1
    return c, so_so_sanh

def in_tieu_de():
    print("\n" + "=" * 80)
    print("CHƯƠNG TRÌNH THỰC THI ĐỀ TÀI DT023 (C++)")
    print("Sinh viên: Nguyễn Ngọc Hoan | MSSV: N24DCDT026 | Lớp: D24CQDT01-N")
    print("Đề tài: Trộn hai mảng đã sắp trong thời gian tuyến tính O(n + m)")
    print("=" * 80)

def chay_vd1():
    in_tieu_de()
    print("\n>>> [THỰC THI RIÊNG VÍ DỤ 1 TRÊN PHIẾU (VD01)]:")
    a1 = [1, 3, 5]
    b1 = [2, 3, 6]
    expected1 = [1, 2, 3, 3, 5, 6]
    print(f"Mảng đầu vào a: {in_mang(a1)} (độ dài n = {len(a1)})")
    print(f"Mảng đầu vào b: {in_mang(b1)} (độ dài m = {len(b1)})")
    print(f"Kết quả kỳ vọng: {in_mang(expected1)} (giữ nguyên hai phần tử 3 vì mỗi mảng đóng góp một phần tử)\n")
    c1, cmp1 = lan_vet_tron(a1, b1, True)
    assert c1 == expected1
    print("\n-> ĐÁNH GIÁ: [PASS VD01]")
    print(f"   Kết quả thực tế: c = {in_mang(c1)}")
    print(f"   Tổng số phép so sánh thực hiện: {cmp1}")
    print(f"   Độ dài mảng kết quả: {len(c1)} (khớp n + m = {len(a1) + len(b1)})")

def chay_vd2():
    in_tieu_de()
    print("\n>>> [THỰC THI RIÊNG VÍ DỤ 2 TRÊN PHIẾU (VD02)]:")
    a2 = []
    b2 = [-2, 0]
    expected2 = [-2, 0]
    print(f"Mảng đầu vào a: {in_mang(a2)} (mảng rỗng, n = 0)")
    print(f"Mảng đầu vào b: {in_mang(b2)} (độ dài m = {len(b2)})")
    print(f"Kết quả kỳ vọng: {in_mang(expected2)} (mảng a hết từ đầu, chỉ sao chép phần còn lại của b)\n")
    c2, cmp2 = lan_vet_tron(a2, b2, True)
    assert c2 == expected2
    print("\n-> ĐÁNH GIÁ: [PASS VD02]")
    print(f"   Kết quả thực tế: c = {in_mang(c2)}")
    print(f"   Tổng số phép so sánh thực hiện: {cmp2} (vì mảng a rỗng)")
    print(f"   Độ dài mảng kết quả: {len(c2)} (khớp n + m = {len(a2) + len(b2)})")

def chay_morong():
    in_tieu_de()
    print("\n>>> [THỰC THI PHẦN MỞ RỘNG: TRỘN HAI MẢNG GIẢM DẦN]:")
    ag = [9, 5, 2]
    bg = [8, 5, 3, 1]
    expected_g = [9, 8, 5, 5, 3, 2, 1]
    print(f"Mảng giảm dần a: {in_mang(ag)}")
    print(f"Mảng giảm dần b: {in_mang(bg)}")
    print(f"Kết quả kỳ vọng: {in_mang(expected_g)} (giảm dần)\n")
    cg, cmp_g = tron_hai_mang_giam(ag, bg)
    assert cg == expected_g
    print("-> ĐÁNH GIÁ: [PASS PHẦN MỞ RỘNG]")
    print(f"   Kết quả thực tế: c = {in_mang(cg)}")
    print(f"   Tổng số phép so sánh: {cmp_g}")

def che_do_nhap_ban_phim():
    in_tieu_de()
    print("\n>>> [CHẾ ĐỘ NHẬP DỮ LIỆU TÙY Ý TỪ BÀN PHÍM]:")
    try:
        line_a = input("Nhập các phần tử mảng a tăng dần (cách nhau bởi dấu cách, ví dụ: 1 3 5 8): ")
        a = [int(x) for x in line_a.split()] if line_a.strip() else []
        line_b = input("Nhập các phần tử mảng b tăng dần (cách nhau bởi dấu cách, ví dụ: 2 3 7 9): ")
        b = [int(x) for x in line_b.split()] if line_b.strip() else []
        print("\nĐang thực hiện thuật toán trộn hai mảng...")
        lan_vet_tron(a, b, True)
    except Exception as e:
        print(f"\n[LỖI DỮ LIỆU]: {e}")

if __name__ == "__main__":
    if len(sys.argv) > 1:
        arg = sys.argv[1]
        if arg in ["1", "--vd1", "-1"]:
            chay_vd1()
        elif arg in ["2", "--vd2", "-2"]:
            chay_vd2()
        elif arg in ["3", "--morong", "-3"]:
            chay_morong()
        elif arg in ["4", "--keyboard", "-k"]:
            che_do_nhap_ban_phim()
        elif arg in ["5", "--all", "-a"]:
            chay_vd1()
            chay_vd2()
            chay_morong()
        else:
            print("Cách dùng: python demo.py [1|2|3|--keyboard|--all]")
    else:
        in_tieu_de()
        print("Vui lòng chọn chế độ muốn thực thi:")
        print("  [1] Chạy riêng Ví dụ 1 trên phiếu (VD01: a=[1,3,5], b=[2,3,6])")
        print("  [2] Chạy riêng Ví dụ 2 trên phiếu (VD02: a=[], b=[-2,0])")
        print("  [3] Chạy phần mở rộng (Trộn mảng giảm dần)")
        print("  [4] Nhập dữ liệu mới từ bàn phím")
        print("  [5] Chạy tất cả các ví dụ lần lượt")
        print("  [0] Thoát chương trình")
        print("-" * 80)
        try:
            choice = input("Nhập lựa chọn của bạn (0-5): ").strip()
            if choice == "1": chay_vd1()
            elif choice == "2": chay_vd2()
            elif choice == "3": chay_morong()
            elif choice == "4": che_do_nhap_ban_phim()
            elif choice == "5":
                chay_vd1(); chay_vd2(); chay_morong()
            else: print("Tạm biệt!")
        except (KeyboardInterrupt, EOFError):
            pass
