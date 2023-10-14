#include <iostream>
#include <string>

class Date {
private:
    int year;
    int month;
    int day;

public:
    Date() : year(0), month(0), day(0) {}

    Date(int y, int m, int d) : year(y), month(m), day(d) {}

    Date operator+(const Date& rhs) const {
        Date result = *this;

        result.year += rhs.year;
        result.month += rhs.month;
        result.day += rhs.day;

        // Handle rollovers
        while (result.day > 28) { // Assuming February always has 28 days
            int maxDaysInMonth = 28;
            if (result.month == 2)
                maxDaysInMonth = 28;
            else if (result.month == 4 || result.month == 6 || result.month == 9 || result.month == 11)
                maxDaysInMonth = 30;
            else
                maxDaysInMonth = 31;

            if (result.day > maxDaysInMonth) {
                result.day -= maxDaysInMonth;
                result.month++;
            }
        }

        while (result.month > 12) {
            result.month -= 12;
            result.year++;
        }

        return result;
    }

    std::string to_string() {
        return std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day);
    }
};

int main() {
    Date date1(2023, 10, 15);
    Date date2(2023, 10, 8);

    Date date3 = date1 + date2;

    std::cout << "Date 1: " << date1.to_string() << std::endl;
    std::cout << "Date 2: " << date2.to_string() << std::endl;
    std::cout << "Date 1 + Date 2: " << date3.to_string() << std::endl;

    return 0;
}

