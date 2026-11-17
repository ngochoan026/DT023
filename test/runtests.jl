# ==============================================================================
# HỌC VIỆN CÔNG NGHỆ BƯU CHÍNH VIỄN THÔNG - CƠ SỞ TP. HỒ CHÍ MINH
# ĐỒ ÁN HỌC PHẦN: CẤU TRÚC DỮ LIỆU VÀ GIẢI THUẬT (INT13185 - NHÓM 03)
# SINH VIÊN: NGUYỄN NGỌC HOAN - MSSV: N24DCDT026 - LỚP: D24CQDT01-N
# MÃ ĐỀ: DT023 - TRỘN HAI MẢNG ĐÃ SẮP TRONG THỜI GIAN TUYẾN TÍNH
# TỆP: test/runtests.jl - BỘ KIỂM THỬ ĐỘC LẬP TỐI THIỂU 12 CA
# ==============================================================================

using Test
include(joinpath(@__DIR__, "..", "src", "DeTai.jl"))
using .DeTai

println("\n" * "="^80)
println("BẮT ĐẦU CHẠY BỘ KIỂM THỬ ĐỘC LẬP (>= 12 CA) - ĐỀ TÀI DT023")
println("Sinh viên: Nguyễn Ngọc Hoan - MSSV: N24DCDT026")
println("="^80 * "\n")

@testset "BỘ KIỂM THỬ TOÀN DIỆN ĐỀ TÀI DT023" begin

    # --------------------------------------------------------------------------
    # NHÓM 1: HAI VÍ DỤ TRÊN PHIẾU
    # --------------------------------------------------------------------------
    @testset "Ca VD01 - Ví dụ 1 phiếu (Trùng phần tử khóa 3)" begin
        a = [1, 3, 5]
        b = [2, 3, 6]
        expected = [1, 2, 3, 3, 5, 6]
        c, cmp = tron_hai_mang(a, b)
        @test c == expected
        @test cmp == 5
        @test length(c) == length(a) + length(b)
        @test kiem_tra_tang(c)
        println("  [PASS] VD01: a=$a, b=$b -> c=$c (So sánh: $cmp)")
    end

    @testset "Ca VD02 - Ví dụ 2 phiếu (Mảng a rỗng, chép đuôi b)" begin
        a = Int[]
        b = [-2, 0]
        expected = [-2, 0]
        c, cmp = tron_hai_mang(a, b)
        @test c == expected
        @test cmp == 0
        @test length(c) == length(a) + length(b)
        @test kiem_tra_tang(c)
        println("  [PASS] VD02: a=$a, b=$b -> c=$c (So sánh: $cmp)")
    end

    # --------------------------------------------------------------------------
    # NHÓM 2: HAI CA SINH VIÊN TỰ THIẾT KẾ
    # --------------------------------------------------------------------------
    @testset "Ca TK01 - Xen kẽ hoàn toàn (Số phép so sánh cực đại)" begin
        a = [1, 3, 5, 7]
        b = [2, 4, 6, 8]
        expected = [1, 2, 3, 4, 5, 6, 7, 8]
        c, cmp = tron_hai_mang(a, b)
        @test c == expected
        @test cmp == 7  # n + m - 1 = 4 + 4 - 1 = 7
        @test length(c) == 8
        @test kiem_tra_tang(c)
        println("  [PASS] TK01: a=$a, b=$b -> c=$c (So sánh cực đại: $cmp)")
    end

    @testset "Ca TK02 - Mảng b nhỏ hơn hẳn a (Chép đuôi toàn bộ a)" begin
        a = [10, 20, 30]
        b = [1, 2, 3]
        expected = [1, 2, 3, 10, 20, 30]
        c, cmp = tron_hai_mang(a, b)
        @test c == expected
        @test cmp == 3  # m = 3
        @test length(c) == 6
        @test kiem_tra_tang(c)
        println("  [PASS] TK02: a=$a, b=$b -> c=$c (So sánh cực tiểu m: $cmp)")
    end

    # --------------------------------------------------------------------------
    # NHÓM 3: CÁC CA BIÊN HỢP LỆ THEO MIỀN PHIẾU
    # --------------------------------------------------------------------------
    @testset "Ca BIEN01 - Cả hai mảng đều rỗng" begin
        a = Int[]
        b = Int[]
        expected = Int[]
        c, cmp = tron_hai_mang(a, b)
        @test c == expected
        @test cmp == 0
        @test isempty(c)
        println("  [PASS] BIEN01: Cả hai mảng rỗng -> c=$c (So sánh: $cmp)")
    end

    @testset "Ca BIEN02 - Toàn bộ phần tử trùng khóa (3 số 1)" begin
        a = [1, 1]
        b = [1]
        expected = [1, 1, 1]
        c, cmp = tron_hai_mang(a, b)
        @test c == expected
        @test cmp == 2
        @test count(==(1), c) == 3
        println("  [PASS] BIEN02: Bảo toàn 3 số 1 -> c=$c (So sánh: $cmp)")
    end

    @testset "Ca BIEN03 - Chứa số âm và số 0" begin
        a = [-10, -5, 0]
        b = [-8, 2, 5]
        expected = [-10, -8, -5, 0, 2, 5]
        c, cmp = tron_hai_mang(a, b)
        @test c == expected
        @test cmp == 5
        @test kiem_tra_tang(c)
        println("  [PASS] BIEN03: Số âm và 0 -> c=$c (So sánh: $cmp)")
    end

    @testset "Ca BIEN04 - Một mảng đơn lẻ 1 phần tử chèn giữa" begin
        a = [4]
        b = [1, 2, 3, 5, 6]
        expected = [1, 2, 3, 4, 5, 6]
        c, cmp = tron_hai_mang(a, b)
        @test c == expected
        @test cmp == 4
        @test kiem_tra_tang(c)
        println("  [PASS] BIEN04: Mảng 1 phần tử lọt giữa -> c=$c (So sánh: $cmp)")
    end

    # --------------------------------------------------------------------------
    # NHÓM 4: CA PHIẾU BẮT BUỘC (CA 5 TRÊN PHIẾU)
    # --------------------------------------------------------------------------
    @testset "Ca KT09 - Ca 5 trên phiếu ([5,6] và [1,2])" begin
        a = [5, 6]
        b = [1, 2]
        expected = [1, 2, 5, 6]
        c, cmp = tron_hai_mang(a, b)
        @test c == expected
        @test cmp == 2
        @test kiem_tra_tang(c)
        println("  [PASS] KT09: Ca 5 trên phiếu -> c=$c (So sánh: $cmp)")
    end

    # --------------------------------------------------------------------------
    # NHÓM 5: KIỂM TRA ĐẦU VÀO SAI VÀ NGOẠI LỆ (VALIDATOR)
    # --------------------------------------------------------------------------
    @testset "Ca LOI01 - Input sai: Mảng a chưa sắp xếp tăng" begin
        a_sai = [3, 1, 5]
        b_dung = [2, 4]
        @test_throws ArgumentError tron_hai_mang(a_sai, b_dung)
        println("  [PASS] LOI01: Đã bắt đúng ArgumentError khi mảng a chưa sắp tăng.")
    end

    @testset "Ca LOI02 - Input sai: Mảng b chưa sắp xếp tăng" begin
        a_dung = [1, 3]
        b_sai = [5, 2, 8]
        @test_throws ArgumentError tron_hai_mang(a_dung, b_sai)
        println("  [PASS] LOI02: Đã bắt đúng ArgumentError khi mảng b chưa sắp tăng.")
    end

    # --------------------------------------------------------------------------
    # NHÓM 6: BẤT BIẾN VÀ TÍNH TOÀN VẸN CỦA DỮ LIỆU
    # --------------------------------------------------------------------------
    @testset "Ca KT12 - Kiểm tra bất biến đa khóa và bảo toàn tần suất" begin
        a = [2, 2, 5, 7, 9, 9]
        b = [1, 2, 2, 6, 9]
        c, cmp = tron_hai_mang(a, b)
        @test length(c) == length(a) + length(b)
        @test kiem_tra_tang(c)
        # Kiểm tra tần suất số 2 (a có 2, b có 2 -> c phải có 4)
        @test count(==(2), c) == 4
        # Kiểm tra tần suất số 9 (a có 2, b có 1 -> c phải có 3)
        @test count(==(9), c) == 3
        println("  [PASS] KT12: Bất biến tần suất khóa trùng khớp tuyệt đối.")
    end

    # --------------------------------------------------------------------------
    # MỞ RỘNG: TRỘN HAI MẢNG GIẢM DẦN
    # --------------------------------------------------------------------------
    @testset "Ca MO_RONG - Trộn giảm dần" begin
        ag = [10, 6, 2]
        bg = [8, 6, 4, 1]
        expected_g = [10, 8, 6, 6, 4, 2, 1]
        cg, cmp_g = tron_hai_mang_giam(ag, bg)
        @test cg == expected_g
        println("  [PASS] MO_RONG: Trộn giảm dần khớp hoàn hảo -> cg=$cg")
    end

end

println("\n" * "="^80)
println("TỔNG KẾT: TẤT CẢ CÁC CA KIỂM THỬ ĐỀU ĐẠT CHUẨN PASS 100%!")
println("="^80 * "\n")
