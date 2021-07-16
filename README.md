# DoAn-ThiTracNghiem-C++
                                                    Đề tài:
Thi trắc nghiệm : Ta tổ chức các danh sách sau:
- Danh sách môn học: danh sách tuyến tính (MAMH (C15), TENMH).
- Danh sách Lop : mảng con trỏ (MALOP, TENLOP, con trỏ): con trỏ sẻ trỏ đến danh sách
sinh viên thuộc lớp đó.
- Danh sách sinh viên : danh sách liên kết đơn (MASV, HO, TEN, PHAI, password, con
trỏ): con trỏ sẽ trỏ đến điểm các môn đã thi trắc nghiệm.
- Danh sách Điểm thi (danh sách liên kết đơn) (Mamh, Diem)
- Danh sách Câu hỏi thi (cây nhị phân tìm kiếm với key = Id) (Id, Mă MH, Nội dung, A, B,
C, D, Đáp án); trong đó A, B, C, D là 4 chọn lựa tương ứng với nội dung câu hỏi.
Chương trình có các chức năng sau:

  a. Đăng nhập dựa vào mã sinh viên, password. Nếu tài khoản đăng nhập là GV, pass là GV
  thì sẽ có toàn quyền.
  
  b. NhapLop
  
  c. In ds lớp
  
  d. Nhập sinh viên của lớp : nhập vào mã lớp trước, sau đó nhập các sinh viên vào lớp đó.
  
  e. Nhập môn học: cho phép cập nhật (thêm / xóa / hiệu chỉnh ) thông tin của môn học
  
  f. Nhập câu hỏi thi (Id là số ngẫu nhiên do chương trình tự tạo )
  
  g. Thi Trắc nghiệm ( trước khi thi hỏi người thi môn thi, số câu hỏi thi, số phút thi-sau đó
  lấy ngẫu nhiên các câu hỏi trong danh sách câu hỏi thi của môn;
  
  ## Những lưu ý cần tối ưu
  - Cần làm lại đọc ghi file ( đọc ghi file tạo quá nhiều file, nên gộp lại)
  - Khi thêm câu hỏi thi thì có thêm lựa chọn môn thay vì ghi
  - Phần random number cho ID cây nhị phân ý tưởng đã đúng nhưng làm nhiều bước, loại bỏ những không cần thiết
  - Lúc thi cần show tên sinh viên và môn thi 
  
  ## Những hình ảnh trong đồ án
  Màn hình đăng nhập
  ![Login Page](https://firebasestorage.googleapis.com/v0/b/react-native-108e9.appspot.com/o/1.PNG?alt=media&token=ab62d9a9-8cdf-4dd6-ba96-89ff741d2d0e)
  
  Màn hình Menu QL
  ![GV Page](https://firebasestorage.googleapis.com/v0/b/react-native-108e9.appspot.com/o/2.PNG?alt=media&token=1fafd41a-51fe-4f19-acb9-39b7c9761a82)
  
  Màn hình thi
  ![Thi Page](https://firebasestorage.googleapis.com/v0/b/react-native-108e9.appspot.com/o/3.PNG?alt=media&token=8f60c96d-f9ba-4ddf-8152-cf34ef6150f2)
  
  Màn hình QL Câu hỏi thi
  ![CHT Page](https://firebasestorage.googleapis.com/v0/b/react-native-108e9.appspot.com/o/4.PNG?alt=media&token=64376898-2bcb-441f-ad4f-55767db42f16)
  
  ## Nếu có bug hay thắc gì liên hệ:
  Email Me: dompham300721@gmail.com (welcome, say hi)
