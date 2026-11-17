# DANH MỤC VÀ HƯỚNG DẪN 11 ẢNH MINH CHỨNG THỰC THI (A01 - A11)

Theo yêu cầu chuẩn của học phần INT13185 (Mục 4 trong `00_HUONG_DAN_SINH_VIEN.html`), sinh viên cần chụp đủ 11 ảnh màn hình kết quả thực thi và lưu tệp ảnh gốc tại thư mục này (`docs/anh_ket_qua/`) đồng thời chèn trực tiếp vào đúng vị trí trong Báo cáo Word.

---

### Danh mục 11 ảnh minh chứng bắt buộc:
1. **A01_VD01.png**: Chụp màn hình chạy Ví dụ 1 trên phiếu ($a=[1, 3, 5], b=[2, 3, 6] \to c=[1, 2, 3, 3, 5, 6]$) kèm bảng lần vết chỉ số và số phép so sánh = 5.
2. **A02_VD02.png**: Chụp màn hình chạy Ví dụ 2 trên phiếu ($a=[], b=[-2, 0] \to c=[-2, 0]$, nhánh chép đuôi khi $a$ rỗng từ đầu).
3. **A03_TK01.png**: Chụp màn hình chạy ca tự thiết kế 1 (Xen kẽ hoàn toàn $a=[1,3,5,7], b=[2,4,6,8]$, số phép so sánh cực đại 7).
4. **A04_TK02.png**: Chụp màn hình chạy ca tự thiết kế 2 (Toàn bộ $b$ nhỏ hơn $a$: $a=[10,20,30], b=[1,2,3]$, nhánh chép đuôi toàn bộ $a$).
5. **A05_BIEN01.png**: Chụp màn hình ca biên 1 (Hai mảng đều rỗng $a=[], b=[] \to c=[]$).
6. **A06_BIEN02.png**: Chụp màn hình ca biên 2 (Bảo toàn số lượng phần tử trùng khóa: $a=[1, 1], b=[1] \to c=[1, 1, 1]$).
7. **A07_BIEN03.png**: Chụp màn hình ca biên 3 (Dữ liệu chứa số âm và số 0: $a=[-10,-5,0], b=[-8,2,5]$).
8. **A08_LOI01.png**: Chụp màn hình kiểm tra input không hợp lệ (Mảng chưa sắp tăng bị hàm `kiem_tra_dau_vao` ném ngoại lệ `ArgumentError`).
9. **A09_Tests_TongKet.png**: Chụp màn hình chạy lệnh `julia test/runtests.jl` tổng kết toàn bộ >= 12 ca kiểm thử đạt trạng thái PASS 100%.
10. **A10_Clone_Sach.png**: Chụp màn hình mở cửa sổ dòng lệnh ở một thư mục mới hoàn toàn, chạy lệnh `git clone <URL>`, kiểm tra `git log -1` ra đúng mã SHA commit C và chạy `julia demo.jl` tái hiện kết quả.
11. **A11_GitHub_Repo.png**: Chụp màn hình trình duyệt hiển thị kho GitHub thật của sinh viên, thấy rõ URL, commit C và danh sách file trong repo.
