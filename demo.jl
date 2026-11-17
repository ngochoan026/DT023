# ==============================================================================
# HỌC VIỆN CÔNG NGHỆ BƯU CHÍNH VIỄN THÔNG - CƠ SỞ TP. HỒ CHÍ MINH
# ĐỒ ÁN HỌC PHẦN: CẤU TRÚC DỮ LIỆU VÀ GIẢI THUẬT (INT13185 - NHÓM 03)
# SINH VIÊN: NGUYỄN NGỌC HOAN - MSSV: N24DCDT026 - LỚP: D24CQDT01-N
# MÃ ĐỀ: DT023 - TRỘN HAI MẢNG ĐÃ SẮP TRONG THỜI GIAN TUYẾN TÍNH
# TỆP: demo.jl - CHẠY RIÊNG TỪNG VÍ DỤ TRÊN PHIẾU VÀ NHẬP BÀN PHÍM
# ==============================================================================

include(joinpath(@__DIR__, "src", "DeTai.jl"))
using .DeTai
using Printf

function in_tieu_de()
    println("\n" * "="^80)
    println("CHƯƠNG TRÌNH THỰC THI ĐỀ TÀI DT023 (JULIA)")
    println("Sinh viên: Nguyễn Ngọc Hoan | MSSV: N24DCDT026 | Lớp: D24CQDT01-N")
    println("="^80)
end

function chay_vd1()
    in_tieu_de()
    println("\n>>> [THỰC THI RIÊNG VÍ DỤ 1 TRÊN PHIẾU (VD01)]:")
    a1 = [1, 3, 5]
    b1 = [2, 3, 6]
    expected1 = [1, 2, 3, 3, 5, 6]
    println("Đầu vào a: $a1, b: $b1")
    println("Kỳ vọng c: $expected1 (giữ cả hai phần tử 3)\n")
    c1, so_sanh1 = lan_vet_tron(a1, b1; verbose=true)
    @assert c1 == expected1 "Lỗi: Kết quả actual không khớp expected!"
    println("\n-> ĐÁNH GIÁ: [PASS VD01]. Thực tế: c = $c1, số so sánh = $so_sanh1.")
end

function chay_vd2()
    in_tieu_de()
    println("\n>>> [THỰC THI RIÊNG VÍ DỤ 2 TRÊN PHIẾU (VD02)]:")
    a2 = Int[]
    b2 = [-2, 0]
    expected2 = [-2, 0]
    println("Đầu vào a: $a2 (rỗng), b: $b2")
    println("Kỳ vọng c: $expected2 (chép đuôi mảng b)\n")
    c2, so_sanh2 = lan_vet_tron(a2, b2; verbose=true)
    @assert c2 == expected2 "Lỗi: Kết quả actual không khớp expected!"
    println("\n-> ĐÁNH GIÁ: [PASS VD02]. Thực tế: c = $c2, số so sánh = $so_sanh2.")
end

function chay_morong()
    in_tieu_de()
    println("\n>>> [THỰC THI PHẦN MỞ RỘNG: TRỘN GIẢM DẦN]:")
    ag = [9, 5, 2]
    bg = [8, 5, 3, 1]
    expected_g = [9, 8, 5, 5, 3, 2, 1]
    println("Đầu vào a: $ag, b: $bg (giảm dần)")
    cg, so_sanh_g = tron_hai_mang_giam(ag, bg)
    @assert cg == expected_g "Lỗi: Kết quả actual không khớp expected!"
    println("-> ĐÁNH GIÁ: [PASS MỞ RỘNG]. Thực tế: cg = $cg, số so sánh = $so_sanh_g.")
end

function che_do_nhap_ban_phim()
    in_tieu_de()
    println("\n>>> [CHẾ ĐỘ NHẬP DỮ LIỆU TỪ BÀN PHÍM]:")
    try
        print("Nhập mảng a tăng dần (ví dụ: 1 3 5): ")
        line_a = readline()
        a = isempty(strip(line_a)) ? Int[] : parse.(Int, split(line_a))

        print("Nhập mảng b tăng dần (ví dụ: 2 3 6): ")
        line_b = readline()
        b = isempty(strip(line_b)) ? Int[] : parse.(Int, split(line_b))

        println("\nĐang xử lý trộn hai mảng...")
        lan_vet_tron(a, b; verbose=true)
    catch e
        println("[LỖI]: ", e)
    end
end

# Main entry point
if !isempty(ARGS)
    arg = ARGS[1]
    if arg in ["1", "--vd1", "-1"]
        chay_vd1()
    elseif arg in ["2", "--vd2", "-2"]
        chay_vd2()
    elseif arg in ["3", "--morong", "-3"]
        chay_morong()
    elseif arg in ["4", "--keyboard", "-k"]
        che_do_nhap_ban_phim()
    elseif arg in ["5", "--all", "-a"]
        chay_vd1()
        chay_vd2()
        chay_morong()
    else
        println("Cách dùng: julia demo.jl [1|2|3|--keyboard|--all]")
    end
else
    # Mặc định chạy 1 rồi 2
    chay_vd1()
    chay_vd2()
end
