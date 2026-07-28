/*#include <iostream>

class Age {
    int years, months, days;

public:
    // Parameterized constructor with default values
    Age(int y = 0, int m = 0, int d = 0) {
        years = y;
        months = m;
        days = d;
    }

    // Display function
    void display() const {
        std::cout << years << " years, "
                  << months << " months, "
                  << days << " days" << std::endl;
    }

    // Overload + operator
    Age operator + (const Age& a) {
        Age temp;

        temp.days = days + a.days;
        temp.months = months + a.months;
        temp.years = years + a.years;

        // Normalize days → months
        if (temp.days >= 30) {
            temp.months += temp.days / 30;
            temp.days = temp.days % 30;
        }

        // Normalize months → years
        if (temp.months >= 12) {
            temp.years += temp.months / 12;
            temp.months = temp.months % 12;
        }

        return temp;
    }
};

int main() {
    int y, m, d;

    std::cout << "Enter current age (years months days): ";
    std::cin >> y >> m >> d;
    Age currentAge(y, m, d);   // parameterized constructor

    std::cout << "Enter period to add (years months days): ";
    std::cin >> y >> m >> d;
    Age period(y, m, d);       // parameterized constructor

    Age newAge = currentAge + period;

    std::cout << "\nNew age after given period:\n";
    newAge.display();

    return 0;
} */
#include <iostream>

class Age {
    int years, months, days;

public:
    // Parameterized constructor
    Age(int y = 0, int m = 0, int d = 0) {
        years = y;
        months = m;
        days = d;
    }

    // Display function
    void display() const {
        std::cout << years << " years, "
                  << months << " months, "
                  << days << " days" << std::endl;
    }

    // Operator overloading
    Age operator + (const Age& a) {
        Age temp;

        temp.days = days + a.days;
        temp.months = months + a.months;
        temp.years = years + a.years;

        // Convert days to months
        if (temp.days >= 30) {
            temp.months += temp.days / 30;
            temp.days %= 30;
        }

        // Convert months to years
        if (temp.months >= 12) {
            temp.years += temp.months / 12;
            temp.months %= 12;
        }

        return temp;
    }
};

int main() {
    // Passing values directly in constructor
    Age currentAge(20, 10, 25);
    Age period(2, 3, 10);

    Age newAge = currentAge + period;

    std::cout << "Current Age: ";
    currentAge.display();

    std::cout << "Period Added: ";
    period.display();

    std::cout << "New Age: ";
    newAge.display();

    return 0;
}