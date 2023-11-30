#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// Base class for patient
class Patient {
protected:
    int patientID;
    int daysAdmitted;

public:
    Patient(int id) : patientID(id), daysAdmitted(0) {}

    int getPatientID() const {
        return patientID;
    }

    // Process patient activity (pure virtual)
    virtual void processActivity(const vector<string>& activity) = 0;

    // Calculate patient fee (pure virtual)
    virtual int calculateFee() const = 0;

    virtual ~Patient() {}
};

// Outpatient class derived from Patient
class Outpatient : public Patient {
private:
    int examinationFee;

public:
    Outpatient(int id) : Patient(id), examinationFee(0) {}

    void processActivity(const vector<string>& activity) override {
        if (activity[2] == "KB") {
            examinationFee += stoi(activity[3]);
        }
    }

    int calculateFee() const override {
        return examinationFee;
    }
};

// Inpatient class derived from Patient
class Inpatient : public Patient {
private:
    int dailyRoomFee;
    char roomType;

public:
    Inpatient(int id) : Patient(id), dailyRoomFee(0), roomType(' ') {}

    void processActivity(const vector<string>& activity) override {
        if (activity[2] == "NV") {
            daysAdmitted++;
            dailyRoomFee = stoi(activity[3]);
            roomType = activity[4][0];
        } else if (activity[2] == "XV") {
            daysAdmitted++;
        }
    }

    int calculateFee() const override {
        if (daysAdmitted > 0) {
            int totalRoomFee = daysAdmitted * dailyRoomFee;
            return totalRoomFee;
        }
        return 0;
    }
};

// Hospital class to manage patients and calculate total fees
class Hospital {
private:
    vector<Patient*> patients;

public:
    Hospital() {}

    // Read log file and process activities
    void readLog(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                vector<string> activity;
                stringstream ss(line);
                string token;
                while (getline(ss, token, ' ')) {
                    activity.push_back(token);
                }
                processActivity(activity);
            }
            file.close();
        }
    }

    // Process each activity and update patient information
    void processActivity(const vector<string>& activity) {
        int patientID = stoi(activity[1]);
        Patient* patient = findPatient(patientID);

        if (patient == nullptr) {
            if (activity[2] == "KB") {
                patient = new Outpatient(patientID);
            } else if (activity[2] == "NV") {
                patient = new Inpatient(patientID);
            }

            if (patient != nullptr) {
                patients.push_back(patient);
            }
        }

        if (patient != nullptr) {
            patient->processActivity(activity);
        }
    }

    // Calculate total fees for all patients
    int calculateTotalFee() const {
        int totalFee = 0;
        for (const auto& patient : patients) {
            totalFee += patient->calculateFee();
        }
        return totalFee;
    }

    // Print statistics (number of outpatient and inpatient)
    void printStatistics() const {
        int outpatientCount = 0;
        int inpatientCount = 0;

        for (const auto& patient : patients) {
            if (dynamic_cast<Outpatient*>(patient) != nullptr) {
                outpatientCount++;
            } else if (dynamic_cast<Inpatient*>(patient) != nullptr) {
                inpatientCount++;
            }
        }

        cout << "Outpatient Count: " << outpatientCount << endl;
        cout << "Inpatient Count: " << inpatientCount << endl;
    }

    // Destructor to free allocated memory
    ~Hospital() {
        for (const auto& patient : patients) {
            delete patient;
        }
    }

private:
    // Find patient by ID
    Patient* findPatient(int id) const {
        for (const auto& patient : patients) {
            if (patient->getPatientID() == id) {
                return patient;
            }
        }
        return nullptr;
    }
};

int main() {
    Hospital hospital;
    hospital.readLog("activity_log.txt");
    hospital.printStatistics();

    int totalFee = hospital.calculateTotalFee();
    cout << "Total Hospital Fee: " << totalFee << " VND" << endl;

    return 0;
}
