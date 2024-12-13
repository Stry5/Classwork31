// Classwork33.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Months with 31 days:
    - 01 (jan)
    - 03 (mar)
    - 05 (may)
    - 07 (jul)
    - 08 (aug)
    - 10 (oct)
    - 12 (dec)
Months with 30 days:
    - 04 (apr)
    - 06 (jun)
    - 09 (sep)
    - 11 (nov)
Febuary 28 days normally, 29 if divisible by 4 or 400 if its a turn of the century year:
    - 02 (feb)
*/

#include <iostream>

namespace Dates {

    class Date {
    private:
        int year;
        int month;
        int day;
        bool isLeapYear;
        void addDayLimit(const int& day, const int& limit) {
            addMonth(1);
            setDay(day - (limit - this->day));
        }
        void subDayLimit(const int& day, const int& limit) {
            subMonth(1);
            setDay(limit - (day - this->day));
        }
        int daysInMonth(const int& month){
            int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
            if (month == 2 && (isLeapYear == true)) {
                return 29;
            }
            return days[month - 1];
        }
        bool checkLeapYear(const int& year) {
            return ((year % 4 == 0) || ((year % 400 == 0) && (year % 100 == 0)));
        }
    public:
        Date(int year, int month, int day) {
            if (year < 0) {
                throw std::invalid_argument("!! year cannot be negative");
            }
            else {
                setYear(year);
            }
            if (month < 0 || month > 12) {
                throw std::invalid_argument("!! invalid month !!");
            }
            else {
                setMonth(month);
            }
            if (day < 0 || month > 31) {
                throw std::invalid_argument("!! invalid day !!");
            }
            else {
                setDay(day);
            }
            isLeapYear = checkLeapYear(year);
        }

        // pass by value b/c allows for both passing a variable or a value itself

        void addYear(const int& year) {
            this->year += year;
            isLeapYear = checkLeapYear(year);

        }
        void subYear(const int& year) {
            if (this->year > 0) {
                this->year -= year;
                isLeapYear = checkLeapYear(year);
            }
            else {
                throw std::invalid_argument("!! Year cannot be negative !! ");
            }
        }

        void addMonth(int month){
            while (this->month + month > 12){
                addYear(1);
                month -= 12;
            }
            setMonth(this->month + month);

        }
        void subMonth(int month){
            while (this->month - month < 1) {
                subYear(1);
                month -= 12;
            }
            setMonth(this->month - month);
        }

        void addDays(int days) {
            while((this->day+days) > daysInMonth(this->month)){
                std::cout << days << std::endl;
                days -= daysInMonth(this->month);
                addMonth(1);
            }
            setDay(this->day+days);
        };
        void subDays(int days) {
            while (days > daysInMonth(this->day)) {
                days -= daysInMonth(this->month);

                std::cout << "this->day: " << this->day << std::endl;
                std::cout << "days: "<< days << std::endl;
                std::cout << "days in month: " << daysInMonth(this->month) << std::endl << std::endl;
                subMonth(1);

            }
            setDay(this->day - days);
        };


        // getters & setters
        int getYear() {
            return year;
        }
        int getMonth() {
            return month;
        }
        int getDay() {
            return day;
        }
        void setYear(const int& year) {
            this->year = year;
        };
        void setMonth(const int& month) {
            this->month = month;
        };
        void setDay(const int& day) {
            this->day = day;
        };


    };
}
namespace Times {

    class Time {
    private:
        int hour;
        int min;
        int sec;
    public:

        // getters and setters
        Time(int hour, int min, int sec) {

        }
        void setHour(int& hour) {
            this->hour = hour;
        }
        void setMin(int& min) {
            this->min = min;
        }
        void setSec(int& sec) {
            this->sec = sec;
        }

        int getHour() {
            return hour;
        }
        int getMin() {
            return min;
        }
        int getSec() {
            return sec;
        }

    };
}

// derived class
class DateTime : public Dates::Date, public Times::Time{
private:

public:
    void getDateTime() {
        return;
    };
};


int main()
{
    Dates::Date d1(2024,1,1);
    d1.subDays(9999);
    std::cout  << "month: " << d1.getMonth() << " day: " << d1.getDay() << " year: " << d1.getYear();

    return 0;
}
