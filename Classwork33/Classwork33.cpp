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
        int daysInMonth(const int& month){
            int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
            if (month == 2 && (isLeapYear == true)) {
                return 29;
            }
            return days[month - 1];
        }
        bool checkLeapYear(const int& year) {
            if ((year % 4 == 0) || ((year % 400 == 0) && (year % 100 == 0))) {
                return true;
            }
            else {
                return false;
            }
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


        void addYears(const int& years) {
            this->year += years;
            isLeapYear = checkLeapYear(this->year);

        }
        void subYears(const int& years) {
            if (this->year > 0) {
                this->year -= years;
                isLeapYear = checkLeapYear(this->year);
            }
            else {
                throw std::invalid_argument("!! Year cannot be negative !! ");
            }
        }

        void addMonths(int months){
            while (this->month + month > 12){
                addYears(1);
                month -= 12;
            }
            setMonth(this->month + month);

        }
        void subMonths(int months){
            while (this->month - months < 1) {
                subYears(1);
                months -= 12;
            }
            setMonth(this->month - months);
        }

        void addDays(int days) {
            while((this->day+days) > daysInMonth(this->month)){
                std::cout << days << std::endl;
                days -= daysInMonth(this->month);
                addMonths(1);
            }
            setDay(this->day + days);
        };
        void subDays(int days) {

            while ((this->day - days) < 1) {
                days -= daysInMonth(this->month);
                subMonths(1);
            }
            if ((days * -1) == daysInMonth(this->month)) {
                setDay(0);
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
        Time(int hour, int min, int sec) {
            setHour(hour);
            setMin(min);
            setSec(sec);
        }

        void addHours(int hours) {
            while ((this->hour + hours) > 23) {
                hours -= 24;
            }
            setHour(this->hour + hours);
        }
        void subHours(int hours) {
            while ((this->hour - hours) < 0) {
                hours -= 24;
            }
            setHour(this->hour - hours);
        }

        void addMins(int mins){
            while (this->min + mins > 59) {
                mins -= 60;
                addHours(1);
            }
            setMin(this->min + mins);
        }
        void subMins(int mins){
            while (this->min - mins < 0) {
                mins -= 60;
                subHours(1);
            }
            setMin(this->min - mins);
        }

        void addSecs(int secs){
            while ((this->sec + secs) > 60) {
                secs -= 60;
                addMins(1);
            }
            setSec(this->sec + secs);
        }
        void subSecs(int secs) {
            while ((this->sec - secs) < 0) {
                secs -= 60;
                subMins(1);
            }
            setSec(this->sec - secs);
        }

        // getters and setters

        void setHour(const int& hour) {
            this->hour = hour;
        }
        void setMin(const int& min) {
            this->min = min;
        }
        void setSec(const int& sec) {
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
    void difference(DateTime d1, DateTime d2) {
        int numYears, numMonths, numDays, numHours, numMins, numSecs;
        numYears = d1.getYear() - d2.getYear();
        if (numYears < 0) {
            numYears *= -1;
        }
        for (int i = 0; i < numYears; i++) {
            numDays += 365;
        }

    }
};


int main()
{
    /*
    Dates::Date d1(2024,1,1);
    d1.subDays(9999);
    std::cout  << "month: " << d1.getMonth() << " day: " << d1.getDay() << " year: " << d1.getYear();

    */
    Times::Time t1(24, 00, 00);
    t1.subSecs(1);
    std::cout << "hours: " << t1.getHour() << " mins: " << t1.getMin() << " sec: " << t1.getSec();


    return 0;
}
