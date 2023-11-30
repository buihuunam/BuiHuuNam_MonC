#include <iostream>
using namespace std;

// Lớp cơ sở abstract
class absList {
protected:
    int dataId;

public:
    // Hàm tạo với giá trị mặc định cho dataId
    absList(int pId = 0) : dataId(pId) {}

    // Hàm hủy ảo để đảm bảo hàm hủy được gọi đúng đối tượng khi kết thúc
    virtual ~absList() {}

    // Trả về giá trị của đối tượng
    int getData() {
        return dataId;
    }

    // Phương thức ảo để thêm một phần tử mới vào đầu danh sách
    virtual absList* addFirst(int pId) = 0;

    // Phương thức ảo để lấy đối tượng con nếu có
    virtual absList* getSubItem() = 0;

    // Phương thức ảo để hiển thị tất cả các phần tử trong danh sách
    virtual void showAll(ostream&) const = 0;

    // Phương thức ảo để đếm tổng số phần tử trong danh sách
    virtual int countAll() const {
        return 0; // Tạm thời 0 phần tử
    }

    // Phương thức mới để hiển thị tất cả các phần tử trong danh sách
    virtual void ShowAll() const {
        showAll(cout);
    }
};

// Lớp đơn giản kế thừa từ lớp cơ sở abstract
class simpleList : public absList {
public:
    // Hàm tạo của lớp đơn giản
    simpleList(int pId) : absList(pId) {}

    // Phương thức thêm một phần tử mới vào đầu danh sách
    virtual absList* addFirst(int pId) {
        dataId = pId;
        return this;
    }

    // Phương thức lấy đối tượng con, luôn trả về NULL vì lớp đơn giản không có đối tượng con
    virtual absList* getSubItem() {
        return NULL;
    }

    // Phương thức hiển thị tất cả các phần tử trong danh sách
    virtual void showAll(ostream& outDev) const {
        outDev << dataId << " ";
    }

    // Phương thức đếm tổng số phần tử trong danh sách, luôn trả về 1 vì chỉ có một phần tử
    virtual int countAll() const {
        return 1;
    }
};

// Lớp danh sách tuyến tính kế thừa từ lớp cơ sở abstract
class linearList : public absList {
    absList* subLst;

public:
    // Hàm tạo của lớp danh sách tuyến tính
    linearList(int pId) : absList(pId), subLst(NULL) {}

    // Hàm hủy của lớp danh sách tuyến tính
    virtual ~linearList() {
        if (subLst != NULL)
            delete subLst;
    }

    // Phương thức thêm một phần tử mới vào đầu danh sách
    virtual absList* addFirst(int pId) {
        // Tạo một đối tượng danh sách tuyến tính mới và gán đối tượng hiện tại làm đối tượng con
        linearList* Lst = new linearList(pId);
        Lst->subLst = this;
        return Lst;
    }

    // Phương thức lấy đối tượng con
    virtual absList* getSubItem() {
        return subLst;
    }

    // Phương thức hiển thị tất cả các phần tử trong danh sách và đệ quy để hiển thị các phần tử con
    virtual void showAll(ostream& outDev) const {
        // In giá trị của đối tượng hiện tại
        outDev << dataId << " ";

        // In giá trị của các đối tượng con nếu có
        if (subLst != NULL) {
            subLst->showAll(outDev);
        }
    }

    // Phương thức đếm tổng số phần tử trong danh sách và đệ quy để đếm số phần tử của các đối tượng con
    virtual int countAll() const {
        int count = 1; // Bắt đầu với 1 vì đã có một phần tử là đối tượng hiện tại

        // Đệ quy đếm số lượng phần tử của các đối tượng con
        if (subLst != NULL) {
            count += subLst->countAll();
        }

        return count;
    }
};

int main() {
    // Tạo một đối tượng con trỏ thuộc lớp danh sách tuyến tính và gán giá trị cho đối tượng
    absList* lnkLst = new linearList(37);

    // Thêm các phần tử mới vào đầu danh sách
    for (int i = 1; i <= 8; i++) {
        lnkLst = lnkLst->addFirst(i * i - 7 * i);
    }

    // In ra tổng số phần tử trong danh sách
    cout << "Total elements: " << lnkLst->countAll() << endl;

    // Hiển thị tất cả các phần tử trong danh sách
    cout << "All elements: ";
    lnkLst->ShowAll();
    cout << endl;

    // Giải phóng bộ nhớ
    delete lnkLst;

    return 0;
}
