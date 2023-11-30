#include <iostream>
#include <iomanip>

using namespace std;

// Định nghĩa hằng số
const int MAX_HOURS_WORKED = 80;

// Định nghĩa cấu trúc cho người làm công theo giờ
struct HourlyPaid {
    double hoursWorked;
    double hourlyRate;
};

// Định nghĩa cấu trúc cho người làm công theo lương
struct Salaried {
    double salary;
    double bonus;
};

// Định nghĩa cấu trúc union
union Payroll {
    HourlyPaid hourlyWorker;
    Salaried salariedWorker;
};

int main() {
    // Khởi tạo union và cờ để xác định người làm công theo giờ hay theo lương
    Payroll payroll;
    char workerType;

    // Nhập loại người làm công
    cout << "Chọn loại người làm công (H for Hourly, S for Salaried): ";
    cin >> workerType;

    // Xác định cấu trúc được sử dụng dựa trên loại người làm công
    if (workerType == 'H' || workerType == 'h') {
        cout << "Nhập số giờ làm việc: ";
        cin >> payroll.hourlyWorker.hoursWorked;

        // Kiểm tra hợp lệ cho số giờ làm việc
        while (payroll.hourlyWorker.hoursWorked < 0 || payroll.hourlyWorker.hoursWorked > MAX_HOURS_WORKED) {
            cout << "Số giờ làm việc không hợp lệ. Vui lòng nhập lại: ";
            cin >> payroll.hourlyWorker.hoursWorked;
        }

        cout << "Nhập giá trị giờ làm việc: $";
        cin >> payroll.hourlyWorker.hourlyRate;

        // Kiểm tra hợp lệ cho giá trị giờ làm việc
        while (payroll.hourlyWorker.hourlyRate < 0) {
            cout << "Giá trị giờ làm việc không hợp lệ. Vui lòng nhập lại: $";
            cin >> payroll.hourlyWorker.hourlyRate;
        }

        // Tính lương cho người làm công theo giờ
        double pay = payroll.hourlyWorker.hoursWorked * payroll.hourlyWorker.hourlyRate;
        cout << "Lương: $" << fixed << setprecision(2) << pay << endl;

    } else if (workerType == 'S' || workerType == 's') {
        cout << "Nhập lương cơ bản: $";
        cin >> payroll.salariedWorker.salary;

        // Kiểm tra hợp lệ cho lương cơ bản
        while (payroll.salariedWorker.salary < 0) {
            cout << "Lương cơ bản không hợp lệ. Vui lòng nhập lại: $";
            cin >> payroll.salariedWorker.salary;
        }

        cout << "Nhập thưởng: $";
        cin >> payroll.salariedWorker.bonus;

        // Kiểm tra hợp lệ cho thưởng
        while (payroll.salariedWorker.bonus < 0) {
            cout << "Thưởng không hợp lệ. Vui lòng nhập lại: $";
            cin >> payroll.salariedWorker.bonus;
        }

        // Tính lương cho người làm công theo lương
        double pay = payroll.salariedWorker.salary + payroll.salariedWorker.bonus;
        cout << "Lương: $" << fixed << setprecision(2) << pay << endl;

    } else {
        cout << "Lựa chọn không hợp lệ." << endl;
    }

    return 0;
}
