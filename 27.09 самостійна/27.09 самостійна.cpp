#include <iostream>
#include <cmath>

class Fraction {
private:
    int numerator;   // Чисельник
    int denominator; // Знаменник

    // Допоміжна функція для знаходження Найбільшого Спільного Дільника (НСД)
    static int gcd(int a, int b) {
        a = std::abs(a);
        b = std::abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Скорочення дробу та нормалізація знака
    void reduce() {
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        int commonDivider = gcd(numerator, denominator);
        if (commonDivider > 1) {
            numerator /= commonDivider;
            denominator /= commonDivider;
        }
    }

public:
    // Конструктор
    explicit Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (denominator == 0) {
            std::cerr << "Помилка: Знаменник не може дорівнювати 0! Встановлено 1.\n";
            denominator = 1;
        }
        reduce();
    }

    // Геттери
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    // Виведення дробу
    void print() const {
        if (denominator == 1) {
            std::cout << numerator;
        }
        else {
            std::cout << numerator << "/" << denominator;
        }
    }

    // ==========================================
    // ЗАВДАННЯ 1: ПЕРЕВАНТАЖЕННЯ МНОЖЕННЯ (*)
    // ==========================================

    // 1. Fraction * Fraction (метод класу)
    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    // 2. Fraction * int (метод класу)
    Fraction operator*(int value) const {
        return Fraction(numerator * value, denominator);
    }

    // 3. int * Fraction (дружня функція)
    friend Fraction operator*(int value, const Fraction& frac) {
        return Fraction(value * frac.numerator, frac.denominator);
    }

    // ==========================================
    // ЗАВДАННЯ 2: ПЕРЕВАНТАЖЕННЯ ДІЛЕННЯ (/)
    // ==========================================

    // 1. Fraction / Fraction (метод класу)
    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            std::cerr << "Помилка: Ділення на нульовий дріб!\n";
            return Fraction(0, 1);
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    // 2. Fraction / int (метод класу)
    Fraction operator/(int value) const {
        if (value == 0) {
            std::cerr << "Помилка: Ділення на 0!\n";
            return Fraction(0, 1);
        }
        return Fraction(numerator, denominator * value);
    }

    // 3. int / Fraction (дружня функція)
    friend Fraction operator/(int value, const Fraction& frac) {
        if (frac.numerator == 0) {
            std::cerr << "Помилка: Ділення на 0!\n";
            return Fraction(0, 1);
        }
        return Fraction(value * frac.denominator, frac.numerator);
    }
};

// ==========================================
// ТЕСТУВАННЯ (MAIN)
// ==========================================
int main() {
    Fraction f1(3, 4); // 3/4
    Fraction f2(2, 5); // 2/5

    std::cout << "Початкові дроби:\n";
    std::cout << "f1 = "; f1.print(); std::cout << "\n";
    std::cout << "f2 = "; f2.print(); std::cout << "\n\n";

    // ------------------------------------------
    // Тестування Завдання 1 (Множення)
    // ------------------------------------------
    std::cout << "=== ЗАВДАННЯ 1: Множення (*) ===\n";

    Fraction resMul1 = f1 * f2;
    std::cout << "1. Fraction * Fraction : "; f1.print(); std::cout << " * "; f2.print(); std::cout << " = "; resMul1.print(); std::cout << "\n";

    Fraction resMul2 = f1 * 3;
    std::cout << "2. Fraction * int      : "; f1.print(); std::cout << " * 3 = "; resMul2.print(); std::cout << "\n";

    Fraction resMul3 = 2 * f2;
    std::cout << "3. int * Fraction      : 2 * "; f2.print(); std::cout << " = "; resMul3.print(); std::cout << "\n\n";

    // ------------------------------------------
    // Тестування Завдання 2 (Ділення)
    // ------------------------------------------
    std::cout << "=== ЗАВДАННЯ 2: Ділення (/) ===\n";

    Fraction resDiv1 = f1 / f2;
    std::cout << "1. Fraction / Fraction : "; f1.print(); std::cout << " / "; f2.print(); std::cout << " = "; resDiv1.print(); std::cout << "\n";

    Fraction resDiv2 = f1 / 2;
    std::cout << "2. Fraction / int      : "; f1.print(); std::cout << " / 2 = "; resDiv2.print(); std::cout << "\n";

    Fraction resDiv3 = 3 / f2;
    std::cout << "3. int / Fraction      : 3 / "; f2.print(); std::cout << " = "; resDiv3.print(); std::cout << "\n";

    return 0;
}
                                                                                   27.09 практика
#include <iostream>
#include <cmath>

                                                                                       class Fraction {
                                                                                       private:
                                                                                           int numerator;   // Чисельник
                                                                                           int denominator; // Знаменник

                                                                                           // Допоміжна функція для знаходження Найбільшого Спільного Дільника (НСД)
                                                                                           static int gcd(int a, int b) {
                                                                                               a = std::abs(a);
                                                                                               b = std::abs(b);
                                                                                               while (b != 0) {
                                                                                                   int temp = b;
                                                                                                   b = a % b;
                                                                                                   a = temp;
                                                                                               }
                                                                                               return a;
                                                                                           }

                                                                                           // Скорочення дробу та нормалізація знака
                                                                                           void reduce() {
                                                                                               if (denominator < 0) {
                                                                                                   numerator = -numerator;
                                                                                                   denominator = -denominator;
                                                                                               }
                                                                                               int commonDivider = gcd(numerator, denominator);
                                                                                               if (commonDivider > 1) {
                                                                                                   numerator /= commonDivider;
                                                                                                   denominator /= commonDivider;
                                                                                               }
                                                                                           }

                                                                                       public:
                                                                                           // Конструктор
                                                                                           explicit Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
                                                                                               if (denominator == 0) {
                                                                                                   std::cerr << "Помилка: Знаменник не може дорівнювати 0! Встановлено 1.\n";
                                                                                                   denominator = 1;
                                                                                               }
                                                                                               reduce();
                                                                                           }

                                                                                           // Геттери
                                                                                           int getNumerator() const { return numerator; }
                                                                                           int getDenominator() const { return denominator; }

                                                                                           // Виведення дробу
                                                                                           void print() const {
                                                                                               if (denominator == 1) {
                                                                                                   std::cout << numerator;
                                                                                               }
                                                                                               else {
                                                                                                   std::cout << numerator << "/" << denominator;
                                                                                               }
                                                                                           }

                                                                                           // ==========================================
                                                                                           // ЗАВДАННЯ 1: ПЕРЕВАНТАЖЕННЯ МНОЖЕННЯ (*)
                                                                                           // ==========================================

                                                                                           // 1. Fraction * Fraction (метод класу)
                                                                                           Fraction operator*(const Fraction& other) const {
                                                                                               return Fraction(numerator * other.numerator, denominator * other.denominator);
                                                                                           }

                                                                                           // 2. Fraction * int (метод класу)
                                                                                           Fraction operator*(int value) const {
                                                                                               return Fraction(numerator * value, denominator);
                                                                                           }

                                                                                           // 3. int * Fraction (дружня функція)
                                                                                           friend Fraction operator*(int value, const Fraction& frac) {
                                                                                               return Fraction(value * frac.numerator, frac.denominator);
                                                                                           }

                                                                                           // ==========================================
                                                                                           // ЗАВДАННЯ 2: ПЕРЕВАНТАЖЕННЯ ДІЛЕННЯ (/)
                                                                                           // ==========================================

                                                                                           // 1. Fraction / Fraction (метод класу)
                                                                                           Fraction operator/(const Fraction& other) const {
                                                                                               if (other.numerator == 0) {
                                                                                                   std::cerr << "Помилка: Ділення на нульовий дріб!\n";
                                                                                                   return Fraction(0, 1);
                                                                                               }
                                                                                               return Fraction(numerator * other.denominator, denominator * other.numerator);
                                                                                           }

                                                                                           // 2. Fraction / int (метод класу)
                                                                                           Fraction operator/(int value) const {
                                                                                               if (value == 0) {
                                                                                                   std::cerr << "Помилка: Ділення на 0!\n";
                                                                                                   return Fraction(0, 1);
                                                                                               }
                                                                                               return Fraction(numerator, denominator * value);
                                                                                           }

                                                                                           // 3. int / Fraction (дружня функція)
                                                                                           friend Fraction operator/(int value, const Fraction& frac) {
                                                                                               if (frac.numerator == 0) {
                                                                                                   std::cerr << "Помилка: Ділення на 0!\n";
                                                                                                   return Fraction(0, 1);
                                                                                               }
                                                                                               return Fraction(value * frac.denominator, frac.numerator);
                                                                                           }
                                                                                   };

                                                                                   // ==========================================
                                                                                   // ТЕСТУВАННЯ (MAIN)
                                                                                   // ==========================================
                                                                                   int main() {
                                                                                       Fraction f1(3, 4); // 3/4
                                                                                       Fraction f2(2, 5); // 2/5

                                                                                       std::cout << "Початкові дроби:\n";
                                                                                       std::cout << "f1 = "; f1.print(); std::cout << "\n";
                                                                                       std::cout << "f2 = "; f2.print(); std::cout << "\n\n";

                                                                                       // ------------------------------------------
                                                                                       // Тестування Завдання 1 (Множення)
                                                                                       // ------------------------------------------
                                                                                       std::cout << "=== ЗАВДАННЯ 1: Множення (*) ===\n";

                                                                                       Fraction resMul1 = f1 * f2;
                                                                                       std::cout << "1. Fraction * Fraction : "; f1.print(); std::cout << " * "; f2.print(); std::cout << " = "; resMul1.print(); std::cout << "\n";

                                                                                       Fraction resMul2 = f1 * 3;
                                                                                       std::cout << "2. Fraction * int      : "; f1.print(); std::cout << " * 3 = "; resMul2.print(); std::cout << "\n";

                                                                                       Fraction resMul3 = 2 * f2;
                                                                                       std::cout << "3. int * Fraction      : 2 * "; f2.print(); std::cout << " = "; resMul3.print(); std::cout << "\n\n";

                                                                                       // ------------------------------------------
                                                                                       // Тестування Завдання 2 (Ділення)
                                                                                       // ------------------------------------------
                                                                                       std::cout << "=== ЗАВДАННЯ 2: Ділення (/) ===\n";

                                                                                       Fraction resDiv1 = f1 / f2;
                                                                                       std::cout << "1. Fraction / Fraction : "; f1.print(); std::cout << " / "; f2.print(); std::cout << " = "; resDiv1.print(); std::cout << "\n";

                                                                                       Fraction resDiv2 = f1 / 2;
                                                                                       std::cout << "2. Fraction / int      : "; f1.print(); std::cout << " / 2 = "; resDiv2.print(); std::cout << "\n";

                                                                                       Fraction resDiv3 = 3 / f2;
                                                                                       std::cout << "3. int / Fraction      : 3 / "; f2.print(); std::cout << " = "; resDiv3.print(); std::cout << "\n";

                                                                                       return 0;
                                                                                   }

                                                                                   03.10 самостійна

#include <iostream>
#include <iomanip>
#include <compare> // Для std::strong_ordering

                                                                                       class Time {
                                                                                       private:
                                                                                           int hours;   // 0 - 23
                                                                                           int minutes; // 0 - 59
                                                                                           int seconds; // 0 - 59

                                                                                           // Нормалізація часу (переведення всього в секунди і назад)
                                                                                           void normalize() {
                                                                                               int totalSeconds = hours * 3600 + minutes * 60 + seconds;

                                                                                               // Захист від від'ємного часу (не менше за 00:00:00)
                                                                                               if (totalSeconds < 0) {
                                                                                                   totalSeconds = 0;
                                                                                               }

                                                                                               // Враховуємо перехід через добу (24 години)
                                                                                               totalSeconds %= 86400; // 24 * 3600 = 86400 секунд в добі

                                                                                               hours = totalSeconds / 3600;
                                                                                               minutes = (totalSeconds % 3600) / 60;
                                                                                               seconds = totalSeconds % 60;
                                                                                           }

                                                                                       public:
                                                                                           // Конструктор
                                                                                           explicit Time(int h = 0, int m = 0, int s = 0)
                                                                                               : hours(h), minutes(m), seconds(s) {
                                                                                               normalize();
                                                                                           }

                                                                                           // Геттери
                                                                                           int getHours() const { return hours; }
                                                                                           int getMinutes() const { return minutes; }
                                                                                           int getSeconds() const { return seconds; }

                                                                                           // Константний метод для відображення часу
                                                                                           void print() const {
                                                                                               std::cout << std::setfill('0')
                                                                                                   << std::setw(2) << hours << ":"
                                                                                                   << std::setw(2) << minutes << ":"
                                                                                                   << std::setw(2) << seconds;
                                                                                           }

                                                                                           // ==========================================
                                                                                           // 1. ОПЕРАТОР ПОРІВНЯННЯ (SPACESHIP <=> C++20)
                                                                                           // ==========================================
                                                                                           // Компілятор автоматично згенерує оператори ==, !=, <, <=, >, >=
                                                                                           auto operator<=>(const Time& other) const {
                                                                                               if (auto cmp = hours <=> other.hours; cmp != 0) return cmp;
                                                                                               if (auto cmp = minutes <=> other.minutes; cmp != 0) return cmp;
                                                                                               return seconds <=> other.seconds;
                                                                                           }

                                                                                           // Обов'язково додаємо explicit == для повної сумісності зі std::strong_ordering
                                                                                           bool operator==(const Time& other) const {
                                                                                               return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
                                                                                           }

                                                                                           // ==========================================
                                                                                           // 2. ІНКРЕМЕНТ ТА ДЕКРЕМЕНТ (++, --)
                                                                                           // ==========================================

                                                                                           // a. Префіксний ++: додає 1 секунду, повертає оновлений об'єкт
                                                                                           Time& operator++() {
                                                                                               seconds++;
                                                                                               normalize();
                                                                                               return *this;
                                                                                           }

                                                                                           // b. Постфіксний ++: додає 1 секунду, повертає стару копію
                                                                                           Time operator++(int) {
                                                                                               Time temp = *this;
                                                                                               seconds++;
                                                                                               normalize();
                                                                                               return temp;
                                                                                           }

                                                                                           // c. Префіксний --: віднімає 1 секунду (не менше 00:00:00), повертає оновлений об'єкт
                                                                                           Time& operator--() {
                                                                                               int totalSeconds = hours * 3600 + minutes * 60 + seconds;
                                                                                               if (totalSeconds > 0) {
                                                                                                   totalSeconds--;
                                                                                                   hours = totalSeconds / 3600;
                                                                                                   minutes = (totalSeconds % 3600) / 60;
                                                                                                   seconds = totalSeconds % 60;
                                                                                               }
                                                                                               return *this;
                                                                                           }

                                                                                           // c. Постфіксний --: віднімає 1 секунду, повертає стару копію
                                                                                           Time operator--(int) {
                                                                                               Time temp = *this;
                                                                                               int totalSeconds = hours * 3600 + minutes * 60 + seconds;
                                                                                               if (totalSeconds > 0) {
                                                                                                   totalSeconds--;
                                                                                                   hours = totalSeconds / 3600;
                                                                                                   minutes = (totalSeconds % 3600) / 60;
                                                                                                   seconds = totalSeconds % 60;
                                                                                               }
                                                                                               return temp;
                                                                                           }
                                                                                   };

                                                                                   // ==========================================
                                                                                   // ТЕСТУВАННЯ (MAIN)
                                                                                   // ==========================================
                                                                                   int main() {
                                                                                       std::cout << "=== 1. ТЕСТУВАННЯ ІНКРЕМЕНТУ (++) ===\n";
                                                                                       Time t1(23, 59, 58);
                                                                                       std::cout << "Початковий час: "; t1.print(); std::cout << "\n";

                                                                                       std::cout << "Префіксний ++:  "; (++t1).print(); std::cout << "\n";
                                                                                       std::cout << "Перехід доби ++: "; (++t1).print(); std::cout << " (перехід на 00:00:00)\n\n";

                                                                                       Time t2(12, 30, 15);
                                                                                       std::cout << "Постфіксний t2++ (вираз): "; (t2++).print(); std::cout << "\n";
                                                                                       std::cout << "Значення t2 після ++:    "; t2.print(); std::cout << "\n\n";


                                                                                       std::cout << "=== 2. ТЕСТУВАННЯ ДЕКРЕМЕНТУ (--) ===\n";
                                                                                       Time t3(0, 0, 1);
                                                                                       std::cout << "Початковий час: "; t3.print(); std::cout << "\n";
                                                                                       std::cout << "Зменшуємо до 0: "; (--t3).print(); std::cout << "\n";
                                                                                       std::cout << "Спроба < 00:00:00: "; (--t3).print(); std::cout << " (залишився 00:00:00)\n\n";


                                                                                       std::cout << "=== 3. ТЕСТУВАННЯ ОПЕРАТОРА SPACESHIP (<=>) ===\n";
                                                                                       Time timeA(10, 15, 30);
                                                                                       Time timeB(12, 00, 00);
                                                                                       Time timeC(10, 15, 30);

                                                                                       std::cout << "timeA (10:15:30) vs timeB (12:00:00):\n";
                                                                                       if (timeA < timeB)  std::cout << "  timeA < timeB\n";
                                                                                       if (timeA <= timeB) std::cout << "  timeA <= timeB\n";
                                                                                       if (timeA != timeB) std::cout << "  timeA != timeB\n";

                                                                                       std::cout << "timeA (10:15:30) vs timeC (10:15:30):\n";
                                                                                       if (timeA == timeC) std::cout << "  timeA == timeC\n";
                                                                                       if (timeA >= timeC) std::cout << "  timeA >= timeC\n";

                                                                                       return 0;
                                                                                   }
                                                                            03.10 практика
#include <iostream>
#include <iomanip>

                                                                                class Time {
                                                                                private:
                                                                                    int hours;   // Години (0+)
                                                                                    int minutes; // Хвилини (0-59)
                                                                                    int seconds; // Секунди (0-59)

                                                                                    // 1. Приватний метод для нормалізації часу
                                                                                    void normalize() {
                                                                                        int totalSeconds = hours * 3600 + minutes * 60 + seconds;

                                                                                        // Перевірка на від'ємне значення
                                                                                        if (totalSeconds < 0) {
                                                                                            totalSeconds = 0;
                                                                                        }

                                                                                        hours = totalSeconds / 3600;
                                                                                        minutes = (totalSeconds % 3600) / 60;
                                                                                        seconds = totalSeconds % 60;
                                                                                    }

                                                                                public:
                                                                                    // Конструктор за замовчуванням та з параметрами
                                                                                    explicit Time(int h = 0, int m = 0, int s = 0)
                                                                                        : hours(h), minutes(m), seconds(s) {
                                                                                        normalize();
                                                                                    }

                                                                                    // Геттери
                                                                                    int getHours() const { return hours; }
                                                                                    int getMinutes() const { return minutes; }
                                                                                    int getSeconds() const { return seconds; }

                                                                                    // ==========================================
                                                                                    // 2. ПЕРЕВАНТАЖЕННЯ ВВОДУ / ВИВОДУ (<<, >>)
                                                                                    // ==========================================

                                                                                    // a. Оператор виводу << (HH:MM:SS)
                                                                                    friend std::ostream& operator<<(std::ostream& os, const Time& t) {
                                                                                        os << std::setfill('0')
                                                                                            << std::setw(2) << t.hours << ":"
                                                                                            << std::setw(2) << t.minutes << ":"
                                                                                            << std::setw(2) << t.seconds;
                                                                                        return os;
                                                                                    }

                                                                                    // b. Оператор вводу >> (підтримує введення трьох чисел)
                                                                                    friend std::istream& operator>>(std::istream& is, Time& t) {
                                                                                        char sep1, sep2;
                                                                                        // Перевірка, чи це формат з роздільниками (наприклад 10:20:30) чи просто пробілами (10 20 30)
                                                                                        if (is >> t.hours) {
                                                                                            // Дивимося наступний символ без вилучення
                                                                                            char nextChar = is.peek();
                                                                                            if (nextChar == ':' || nextChar == ' ') {
                                                                                                is >> sep1 >> t.minutes;
                                                                                                nextChar = is.peek();
                                                                                                if (nextChar == ':' || nextChar == ' ') {
                                                                                                    is >> sep2 >> t.seconds;
                                                                                                }
                                                                                                else {
                                                                                                    is >> t.seconds;
                                                                                                }
                                                                                            }
                                                                                            else {
                                                                                                is >> t.minutes >> t.seconds;
                                                                                            }
                                                                                            t.normalize(); // Нормалізуємо зчитані значення
                                                                                        }
                                                                                        return is;
                                                                                    }

                                                                                
                                                                                    Time operator+(const Time& other) const {
                                                                                        return Time(hours + other.hours, minutes + other.minutes, seconds + other.seconds);
                                                                                    }

                                                                                    // b. Віднімання (Time - Time) з обнуленням при від'ємному результаті
                                                                                    Time operator-(const Time& other) const {
                                                                                        int totalSec1 = hours * 3600 + minutes * 60 + seconds;
                                                                                        int totalSec2 = other.hours * 3600 + other.minutes * 60 + other.seconds;

                                                                                        int diff = totalSec1 - totalSec2;
                                                                                        if (diff <= 0) {
                                                                                            return Time(0, 0, 0); // Обнуляємо, якщо результат менший або дорівнює 0
                                                                                        }

                                                                                        return Time(0, 0, diff);
                                                                                    }
                                                                            };

                                                                            // ==========================================
                                                                            // ТЕСТУВАННЯ (MAIN)
                                                                            // ==========================================
                                                                            int main() {
                                                                                std::cout << "=== 1. ТЕСТУВАННЯ НОРМАЛІЗАЦІЇ ===\n";
                                                                                Time t1(1, 65, 75); // 65 хв 75 сек -> повинно стати 2 години, 6 хв, 15 сек
                                                                                std::cout << "Створено Time(1, 65, 75): " << t1 << "\n\n";

                                                                                std::cout << "=== 2. ТЕСТУВАННЯ АРИФМЕТИКИ (+ та -) ===\n";
                                                                                Time t2(2, 45, 50);
                                                                                Time t3(1, 30, 20);

                                                                                std::cout << "t2 = " << t2 << "\n";
                                                                                std::cout << "t3 = " << t3 << "\n";

                                                                                Time sum = t2 + t3;
                                                                                std::cout << "t2 + t3 = " << sum << "\n";

                                                                                Time diff = t2 - t3;
                                                                                std::cout << "t2 - t3 = " << diff << "\n";

                                                                                Time negativeDiff = t3 - t2; // Менше значення - більше значення
                                                                                std::cout << "t3 - t2 (захист від від'ємного часу) = " << negativeDiff << "\n\n";

                                                                                std::cout << "=== 3. ТЕСТУВАННЯ ВВОДУ (>>) ===\n";
                                                                                Time tInput;
                                                                                std::cout << "Введіть час у форматі HH:MM:SS або HH MM SS: ";
                                                                                std::cin >> tInput;
                                                                                std::cout << "Ви зчитали: " << tInput << "\n";

                                                                                return 0;
                                                                            }
                                                                     
                                                                            04.10 самостійна 
#include <iostream>
#include <cstring>
#include <utility> // Для std::move

                                                                                class MyString {
                                                                                private:
                                                                                    char* data;
                                                                                    size_t length;

                                                                                public:
                                                                                    // 1. Конструктор за замовчуванням
                                                                                    MyString() : data(nullptr), length(0) {
                                                                                        data = new char[1];
                                                                                        data[0] = '\0';
                                                                                    }

                                                                                    // 2. Конструктор з параметром (C-string)
                                                                                    explicit MyString(const char* str) {
                                                                                        if (str != nullptr) {
                                                                                            length = std::strlen(str);
                                                                                            data = new char[length + 1];
                                                                                            std::strcpy(data, str);
                                                                                        }
                                                                                        else {
                                                                                            length = 0;
                                                                                            data = new char[1];
                                                                                            data[0] = '\0';
                                                                                        }
                                                                                    }

                                                                                    // 3. Конструктор копіювання (Copy Constructor)
                                                                                    MyString(const MyString& other) : length(other.length) {
                                                                                        std::cout << "[Copy Constructor]\n";
                                                                                        data = new char[length + 1];
                                                                                        std::strcpy(data, other.data);
                                                                                    }

                                                                                    // 4. Оператор присвоєння копіюванням (Copy Assignment)
                                                                                    MyString& operator=(const MyString& other) {
                                                                                        std::cout << "[Copy Assignment]\n";
                                                                                        if (this != &other) {
                                                                                            delete[] data;

                                                                                            length = other.length;
                                                                                            data = new char[length + 1];
                                                                                            std::strcpy(data, other.data);
                                                                                        }
                                                                                        return *this;
                                                                                    }

                                                                                    // ====================================================
                                                                                    // ПРАВИЛО П'ЯТИ: СЕМАНТИКА ПЕРЕМІЩЕННЯ (MOVE SEMANTICS)
                                                                                    // ====================================================

                                                                                    // 5. Конструктор переміщення (Move Constructor)
                                                                                    MyString(MyString&& other) noexcept : data(other.data), length(other.length) {
                                                                                        std::cout << "[Move Constructor]\n";

                                                                                        // Зачищаємо об'єкт-донор
                                                                                        other.data = nullptr;
                                                                                        other.length = 0;
                                                                                    }

                                                                                    // 6. Оператор присвоєння переміщенням (Move Assignment)
                                                                                    MyString& operator=(MyString&& other) noexcept {
                                                                                        std::cout << "[Move Assignment]\n";

                                                                                        // Перевірка на самоприсвоювання (a = std::move(a))
                                                                                        if (this != &other) {
                                                                                            // Очищаємо власні ресурси
                                                                                            delete[] data;

                                                                                            // Перехоплюємо ресурси донора
                                                                                            data = other.data;
                                                                                            length = other.length;

                                                                                            // Зачищаємо об'єкт-донор
                                                                                            other.data = nullptr;
                                                                                            other.length = 0;
                                                                                        }
                                                                                        return *this;
                                                                                    }

                                                                                    // Деструктор
                                                                                    ~MyString() {
                                                                                        delete[] data;
                                                                                    }

                                                                                    // Геттери
                                                                                    size_t getLength() const { return length; }
                                                                                    const char* c_str() const { return data ? data : ""; }

                                                                                    // ====================================================
                                                                                    // КОНКТЕНАЦІЯ РЯДКІВ (operator+)
                                                                                    // ====================================================
                                                                                    MyString operator+(const MyString& other) const {
                                                                                        size_t newLength = this->length + other.length;
                                                                                        char* newBuffer = new char[newLength + 1];

                                                                                        // Копіюємо першу частину
                                                                                        if (this->data != nullptr) {
                                                                                            std::strcpy(newBuffer, this->data);
                                                                                        }
                                                                                        else {
                                                                                            newBuffer[0] = '\0';
                                                                                        }

                                                                                        // Приєднуємо другу частину
                                                                                        if (other.data != nullptr) {
                                                                                            std::strcat(newBuffer, other.data);
                                                                                        }

                                                                                        // Створюємо та повертаємо новий об'єкт
                                                                                        MyString result(newBuffer);
                                                                                        delete[] newBuffer; // Очищаємо тимчасовий буфер

                                                                                        return result; // Тут компілятор може застосувати RVO або Move Constructor
                                                                                    }

                                                                                    // ====================================================
                                                                                    // ВИВЕДЕННЯ У ПОТІК (operator<<)
                                                                                    // ====================================================
                                                                                    friend std::ostream& operator<<(std::ostream& os, const MyString& myStr) {
                                                                                        if (myStr.data != nullptr) {
                                                                                            os << myStr.data;
                                                                                        }
                                                                                        return os;
                                                                                    }
                                                                            };

                                                                            // ==========================================
                                                                            // ТЕСТУВАННЯ (MAIN)
                                                                            // ==========================================
                                                                            int main() {
                                                                                std::cout << "=== 1. СТВОРЕННЯ ОБ'ЄКТІВ ===\n";
                                                                                MyString s1("Hello, ");
                                                                                MyString s2("World!");

                                                                                std::cout << "s1: " << s1 << "\n";
                                                                                std::cout << "s2: " << s2 << "\n\n";

                                                                                std::cout << "=== 2. КОПІЮВАННЯ ТА ПЕРЕМІЩЕННЯ ===\n";
                                                                                // Виклик конструктора копіювання
                                                                                MyString s3 = s1;
                                                                                std::cout << "s3 (копія s1): " << s3 << "\n";

                                                                                // Виклик конструктора переміщення через std::move
                                                                                MyString s4 = std::move(s3);
                                                                                std::cout << "s4 (переміщено з s3): " << s4 << "\n";
                                                                                std::cout << "s3 після переміщення (порожній): '" << s3 << "'\n\n";

                                                                                std::cout << "=== 3. ОПЕРАТОР ПРИСВОЄННЯ ПЕРЕМІЩЕННЯМ ===\n";
                                                                                MyString s5;
                                                                                s5 = MyString("Temporary String"); // Присвоєння тимчасового об'єкта (rvalue)
                                                                                std::cout << "s5: " << s5 << "\n\n";

                                                                                std::cout << "=== 4. КОНКАЦЕНАЦІЯ (operator+) ===\n";
                                                                                MyString s6 = s1 + s2;
                                                                                std::cout << "Результат s1 + s2: " << s6 << "\n";

                                                                                return 0;
                                                                            }
                                    04.10. практика 
#include <iostream>
#include <cstring>
#include <stdexcept> // Для обробки винятків (std::out_of_range)

                                        class MyString {
                                        private:
                                            char* data;
                                            size_t length;

                                        public:
                                            // 1. Конструктор за замовчуванням (гарантує, що data != nullptr)
                                            MyString() : length(0) {
                                                data = new char[1];
                                                data[0] = '\0';
                                            }

                                            // 2. Конструктор від C-рядка (const char* str)
                                            explicit MyString(const char* str) {
                                                if (str != nullptr) {
                                                    length = std::strlen(str);
                                                    data = new char[length + 1];
                                                    std::strcpy(data, str);
                                                }
                                                else {
                                                    length = 0;
                                                    data = new char[1];
                                                    data[0] = '\0';
                                                }
                                            }

                                            // ====================================================
                                            // ПРАВИЛО ТРЬОХ (RULE OF THREE)
                                            // ====================================================

                                            // 3. Деструктор
                                            ~MyString() {
                                                delete[] data;
                                            }

                                            // 4. Конструктор копіювання (Глибоке копіювання)
                                            MyString(const MyString& other) : length(other.length) {
                                                data = new char[length + 1];
                                                std::strcpy(data, other.data);
                                            }

                                            // 5. Оператор присвоєння копіюванням
                                            MyString& operator=(const MyString& other) {
                                                // Перевірка на самоприсвоювання (str = str)
                                                if (this != &other) {
                                                    // Звільняємо стару пам'ять
                                                    delete[] data;

                                                    // Виділяємо нову та копіюємо дані
                                                    length = other.length;
                                                    data = new char[length + 1];
                                                    std::strcpy(data, other.data);
                                                }
                                                return *this;
                                            }

                                            // ====================================================
                                            // ПЕРЕВАНТАЖЕННЯ ІНДЕКСАЦІЇ (operator[])
                                            // ====================================================

                                            // Версія для не-константних об'єктів (дозволяє запис: str[0] = 'A')
                                            char& operator[](size_t index) {
                                                if (index >= length) {
                                                    throw std::out_of_range("Помилка: Індекс виходить за межі рядка!");
                                                }
                                                return data[index];
                                            }

                                            // Версія для константних об'єктів (тільки для читання)
                                            const char& operator[](size_t index) const {
                                                if (index >= length) {
                                                    throw std::out_of_range("Помилка: Індекс виходить за межі рядка!");
                                                }
                                                return data[index];
                                            }

                                            // Допоміжні геттери
                                            size_t getLength() const { return length; }
                                            const char* c_str() const { return data; }
                                    };

                                    // ==========================================
                                    // ТЕСТУВАННЯ (MAIN)
                                    // ==========================================
                                    int main() {
                                        try {
                                            std::cout << "=== 1. БАЗОВІ КОНСТРУКТОРИ ТА ПРАВИЛО ТРЬОХ ===\n";
                                            MyString emptyStr; // Конструктор за замовчуванням
                                            std::cout << "Порожній рядок (довжина " << emptyStr.getLength() << "): \"" << emptyStr.c_str() << "\"\n";

                                            MyString str1("Hello, C++"); // Конструктор від C-рядка
                                            std::cout << "str1: " << str1.c_str() << "\n";

                                            MyString str2 = str1; // Конструктор копіювання
                                            std::cout << "str2 (копія str1): " << str2.c_str() << "\n";

                                            MyString str3;
                                            str3 = str1; // Оператор присвоєння
                                            std::cout << "str3 (присвоєно str1): " << str3.c_str() << "\n\n";

                                            std::cout << "=== 2. ТЕСТУВАННЯ ОПЕРАТОРА ІНДЕКСАЦІЇ [] ===\n";
                                            MyString mutableStr("Code");
                                            std::cout << "Оригінал: " << mutableStr.c_str() << "\n";

                                            // Модифікація символу через не-константний operator[]
                                            mutableStr[0] = 'M';
                                            std::cout << "Після mutableStr[0] = 'M': " << mutableStr.c_str() << "\n";

                                            // Читання через константний об'єкт
                                            const MyString constStr("Fixed");
                                            std::cout << "Читання constStr[2]: " << constStr[2] << "\n\n";

                                            std::cout << "=== 3. ПЕРЕВІРКА ВИХОДУ ЗА МЕЖІ (EXCEPTION) ===\n";
                                            // Спроба звернутися за межами довжини рядка
                                            std::cout << mutableStr[10] << "\n";

                                        }
                                        catch (const std::out_of_range& e) {
                                            std::cerr << "Спіймано виняток: " << e.what() << "\n";
                                        }

                                        return 0;
                                    }