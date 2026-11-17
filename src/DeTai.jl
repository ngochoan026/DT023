# ==============================================================================
# HỌC VIỆN CÔNG NGHỆ BƯU CHÍNH VIỄN THÔNG - CƠ SỞ TP. HỒ CHÍ MINH
# HỌC PHẦN: CẤU TRÚC DỮ LIỆU VÀ GIẢI THUẬT (INT13185 - NHÓM 03)
# GIẢNG VIÊN HƯỚNG DẪN: THS. HỒ NHỰT MINH
# SINH VIÊN: NGUYỄN NGỌC HOAN - MSSV: N24DCDT026 - LỚP: D24CQDT01-N
# MÃ ĐỀ: DT023 - TRỘN HAI MẢNG ĐÃ SẮP TRONG THỜI GIAN TUYẾN TÍNH
# CĂN CỨ: CHƯƠNG 2, MỤC 2.8 BÀI 23; TIÊU CHÍ SẮP XẾP MỤC 2.1
# ==============================================================================

module DeTai

using Printf

export kiem_tra_dau_vao, kiem_tra_tang, tron_hai_mang, lan_vet_tron, tron_hai_mang_giam, giai_bai

"""
    kiem_tra_tang(arr::Vector{Int}) -> Bool

Kiểm tra một mảng số nguyên có được sắp xếp tăng không giảm hay không (arr[k] <= arr[k+1]).
Trả về true nếu hợp lệ, false nếu phát hiện nghịch thế (arr[k] > arr[k+1]).
"""
function kiem_tra_tang(arr::Vector{Int})::Bool
    for k in 1:(length(arr) - 1)
        if arr[k] > arr[k + 1]
            return false
        end
    end
    return true
end

"""
    kiem_tra_dau_vao(a::Vector{Int}, b::Vector{Int})

Xác thực hợp đồng dữ liệu đầu vào theo đúng phiếu đề tài DT023:
1. Độ dài mảng 0 <= n, m <= 5000 (cho phép một hoặc cả hai mảng rỗng).
2. Cả hai mảng a và b phải được sắp xếp tăng không giảm.
Ném ngoại lệ ArgumentError nếu vi phạm điều kiện.
"""
function kiem_tra_dau_vao(a::Vector{Int}, b::Vector{Int})
    n, m = length(a), length(b)
    if n < 0 || n > 5000
        throw(ArgumentError("Kích thước mảng a không hợp lệ: n = $n (yêu cầu 0 <= n <= 5000)"))
    end
    if m < 0 || m > 5000
        throw(ArgumentError("Kích thước mảng b không hợp lệ: m = $m (yêu cầu 0 <= m <= 5000)"))
    end
    if !kiem_tra_tang(a)
        throw(ArgumentError("Mảng a chưa được sắp xếp tăng không giảm!"))
    end
    if !kiem_tra_tang(b)
        throw(ArgumentError("Mảng b chưa được sắp xếp tăng không giảm!"))
    end
    return true
end

"""
    tron_hai_mang(a::Vector{Int}, b::Vector{Int}) -> (Vector{Int}, Int)

Thuật toán trộn hai mảng đã sắp tăng không giảm thành một mảng tăng duy nhất
với thời gian tuyến tính O(n + m) và bộ nhớ phụ O(1) ngoài mảng kết quả c.
Trả về: (mảng kết quả c độ dài n + m, số phép so sánh giữa 2 phần tử).
"""
function tron_hai_mang(a::Vector{Int}, b::Vector{Int})
    # Kiểm tra tính hợp lệ của đầu vào
    kiem_tra_dau_vao(a, b)

    n = length(a)
    m = length(b)
    c = Vector{Int}(undef, n + m)
    i = 1
    j = 1
    k = 1
    so_so_sanh = 0

    # Pha 1: Lần lượt so sánh phần tử đầu còn lại của a và b
    while i <= n && j <= m
        so_so_sanh += 1
        if a[i] <= b[j]
            c[k] = a[i]
            i += 1
        else
            c[k] = b[j]
            j += 1
        end
        k += 1
    end

    # Pha 2: Chép phần đuôi còn lại của mảng a (khi b đã cạn)
    while i <= n
        c[k] = a[i]
        i += 1
        k += 1
    end

    # Pha 3: Chép phần đuôi còn lại của mảng b (khi a đã cạn)
    while j <= m
        c[k] = b[j]
        j += 1
        k += 1
    end

    return (c, so_so_sanh)
end

"""
    lan_vet_tron(a::Vector{Int}, b::Vector{Int}; verbose=true)

Thực hiện thuật toán trộn kèm in ra bảng lần vết (trace table) chi tiết
từng bước so sánh hai chỉ số i, j, chọn phần tử và trạng thái mảng c.
"""
function lan_vet_tron(a::Vector{Int}, b::Vector{Int}; verbose=true)
    kiem_tra_dau_vao(a, b)
    n = length(a)
    m = length(b)
    c = Int[]
    i = 1
    j = 1
    so_so_sanh = 0
    step = 0

    if verbose
        println("="^80)
        println("BẢNG LẦN VẾT THUẬT TOÁN TRỘN HAI MẢNG (Two-Pointers) - ĐỀ TÀI DT023")
        println("Sinh viên: Nguyễn Ngọc Hoan - MSSV: N24DCDT026")
        println("Đầu vào: a = $a, b = $b")
        println("-"^80)
        @printf("%-6s | %-4s | %-4s | %-20s | %-16s | %-20s\n", 
                "Bước", "i", "j", "So sánh", "Chọn", "Mảng c hiện tại")
        println("-"^80)
        @printf("%-6d | %-4d | %-4d | %-20s | %-16s | %-20s\n", 
                0, i, j, "Khởi tạo", "-", string(c))
    end

    while i <= n && j <= m
        step += 1
        so_so_sanh += 1
        so_sanh_str = "a[$i]=$(a[i]) <= b[$j]=$(b[j])"
        if a[i] <= b[j]
            val = a[i]
            push!(c, val)
            if verbose
                @printf("%-6d | %-4d | %-4d | %-20s | a[%d]=%-8d | %-20s\n", 
                        step, i, j, so_sanh_str, i, val, string(c))
            end
            i += 1
        else
            val = b[j]
            push!(c, val)
            if verbose
                @printf("%-6d | %-4d | %-4d | %-20s | b[%d]=%-8d | %-20s\n", 
                        step, i, j, so_sanh_str, j, val, string(c))
            end
            j += 1
        end
    end

    while i <= n
        step += 1
        val = a[i]
        push!(c, val)
        if verbose
            @printf("%-6d | %-4d | %-4d | %-20s | a[%d]=%-8d (đuôi)| %-20s\n", 
                    step, i, j, "b đã cạn", i, val, string(c))
        end
        i += 1
    end

    while j <= m
        step += 1
        val = b[j]
        push!(c, val)
        if verbose
            @printf("%-6d | %-4d | %-4d | %-20s | b[%d]=%-8d (đuôi)| %-20s\n", 
                    step, i, j, "a đã cạn", j, val, string(c))
        end
        j += 1
    end

    if verbose
        println("-"^80)
        println("KẾT QUẢ: c = $c")
        println("Độ dài mảng kết quả: $(length(c)) (khớp n + m = $(n+m))")
        println("Tổng số phép so sánh giữa 2 phần tử: $so_so_sanh")
        println("="^80)
    end

    return (c, so_so_sanh)
end

"""
    tron_hai_mang_giam(a::Vector{Int}, b::Vector{Int}) -> (Vector{Int}, Int)

Yêu cầu mở rộng của đề tài DT023:
Trộn hai mảng đã sắp giảm dần thành một mảng giảm dần duy nhất.
Phép so sánh đảo chiều thành a[i] >= b[j].
"""
function tron_hai_mang_giam(a::Vector{Int}, b::Vector{Int})
    n, m = length(a), length(b)
    # Kiểm tra tính giảm dần
    for k in 1:(n - 1)
        if a[k] < a[k + 1]
            throw(ArgumentError("Mảng a chưa được sắp giảm dần"))
        end
    end
    for k in 1:(m - 1)
        if b[k] < b[k + 1]
            throw(ArgumentError("Mảng b chưa được sắp giảm dần"))
        end
    end

    c = Vector{Int}(undef, n + m)
    i = 1
    j = 1
    k = 1
    so_so_sanh = 0

    while i <= n && j <= m
        so_so_sanh += 1
        if a[i] >= b[j]  # Chọn phần tử lớn hơn để giữ thứ tự giảm dần
            c[k] = a[i]
            i += 1
        else
            c[k] = b[j]
            j += 1
        end
        k += 1
    end

    while i <= n
        c[k] = a[i]
        i += 1
        k += 1
    end

    while j <= m
        c[k] = b[j]
        j += 1
        k += 1
    end

    return (c, so_so_sanh)
end

"""
    giai_bai(du_lieu)

Hàm chuẩn hóa theo khung mã cá nhân: nhận tuple (a, b) và trả về mảng kết quả c.
"""
function giai_bai(du_lieu)
    a, b = du_lieu
    c, _ = tron_hai_mang(a, b)
    return c
end

end # module DeTai
