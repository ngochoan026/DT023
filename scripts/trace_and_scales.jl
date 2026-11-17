# ==============================================================================
# HỌC VIỆN CÔNG NGHỆ BƯU CHÍNH VIỄN THÔNG - CƠ SỞ TP. HỒ CHÍ MINH
# ĐỒ ÁN HỌC PHẦN: CẤU TRÚC DỮ LIỆU VÀ GIẢI THUẬT (INT13185 - NHÓM 03)
# SINH VIÊN: NGUYỄN NGỌC HOAN - MSSV: N24DCDT026 - LỚP: D24CQDT01-N
# MÃ ĐỀ: DT023 - TRỘN HAI MẢNG ĐÃ SẮP TRONG THỜI GIAN TUYẾN TÍNH
# TỆP: scripts/trace_and_scales.jl - KHẢO SÁT 3 QUY MÔ DỮ LIỆU HỢP LỆ (Q1, Q2, Q3)
# ==============================================================================

include(joinpath(@__DIR__, "..", "src", "DeTai.jl"))
using .DeTai
using Printf
using Random

Random.seed!(20261017)

println("\n" * "="^85)
println("KHẢO SÁT THUẬT TOÁN TRÊN BA QUY MÔ DỮ LIỆU HỢP LỆ (Q1, Q2, Q3)")
println("Sinh viên: Nguyễn Ngọc Hoan - MSSV: N24DCDT026")
println("="^85)

function tao_mang_tang(n, step_max=3)
    if n == 0
        return Int[]
    end
    arr = Vector{Int}(undef, n)
    arr[1] = rand(1:5)
    for i in 2:n
        arr[i] = arr[i - 1] + rand(0:step_max)
    end
    return arr
end

configs = [
    ("Q1 (Quy mô nhỏ)", 5, 5),
    ("Q2 (Quy mô vừa)", 50, 50),
    ("Q3 (Quy mô lớn)", 500, 500),
    ("Lệch quy mô (Unbalanced)", 10, 990)
]

@printf("%-26s | %-6s | %-6s | %-10s | %-12s | %-10s\n",
        "Cấu hình khảo sát", "n", "m", "n + m", "Số so sánh", "Chặn lý thuyết")
println("-"^85)

for (label, n, m) in configs
    a = tao_mang_tang(n)
    b = tao_mang_tang(m)
    c, cmp = tron_hai_mang(a, b)
    
    # Kiểm tra tính đúng đắn
    @assert length(c) == n + m
    @assert kiem_tra_tang(c)
    
    min_cmp = min(n, m)
    max_cmp = n + m > 0 ? n + m - 1 : 0
    ly_thuyet = "$min_cmp .. $max_cmp"
    
    @printf("%-26s | %-6d | %-6d | %-10d | %-12d | %-10s\n",
            label, n, m, n + m, cmp, ly_thuyet)
end

println("="^85)
println("NHẬN XÉT ĐỘ PHỨC TẠP:")
println("1. Số phép so sánh luôn nằm nghiêm ngặt trong khoảng [min(n, m), n + m - 1].")
println("2. Khi n, m tăng từ 5 -> 50 -> 500, số phép so sánh và thời gian tăng tuyến tính O(n + m).")
println("3. Bộ nhớ phụ ngoài mảng kết quả c duy trì là O(1) (chỉ dùng các con trỏ chỉ số i, j, k).")
println("="^85 * "\n")
