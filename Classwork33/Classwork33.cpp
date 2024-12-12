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
    public:
        Date(int& year, int& month, int& day) {
            setYear(year);
            setMonth(month);
            setDay(day);
        }

        Date(int year, int month, int day) {
            setYear(year);
            setMonth(month);
            setDay(day);
        }

        // pass by value b/c allows for both passing a variable or a value itself

        void addYear(const int& year) {
            this->year += year;
        }
        void subYear(const int& year) {
            if (this->year > 0) {
                this->year -= year;
            }
            else {
                throw std::invalid_argument("!! Year cannot be negative !! ");
            }
        }

        void addMonth(const int &month){
            if (this->month + month > 12) {
                addYear(1);
                setMonth(month - (12 - this->month));
            }
            else {
                setMonth(this->month + month);
            }
        }
        void subMonth(int month){
            if (this->month - month < 1) {
                subYear(1);
                setMonth(month - (12 - this->month));
            }else {
                setMonth(this->month + month);
            }
        }

        void addDay(int day) {
            switch (this->month) {
            case 1:
                if (this->day + day > 31) {
                    
                }
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
            default:
                throw std::invalid_argument("!! invalid year !!");
                break;
            }
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
        Time(int& hour, int& month, int& day) {
            this->hour = hour;
            this->min = min;
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
    Dates::Date d1(2024,12,12);
    d1.addMonth(3);
    std::cout << d1.getMonth();
}
