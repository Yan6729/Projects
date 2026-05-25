#include "borwein.h"

static double borwein_function(int n, double x) {
    if (x == 0.0) return 1.0;

    double result = 1.0;
    for (int k = 0; k <= n; ++k) {
        double denom = x / (2.0 * k + 1.0);
        result *= sin(denom) / denom;
    }
    return result;
}

static double midpoint(int n) {
    double gn = 5000.0 / 10000.0;
    double sum = 0.0;
    for (int k = 0; k < 10000; ++k) {
        double a = k * gn;
        double b = (k + 1) * gn;
        sum += (b - a) * borwein_function(n, (a + b) / 2.0);
    }

    return sum;
}

static double trapezoidal(int n) {
    double gn = 10000.0;
    double sum = 0.0;
    double dx = 5000.0 / gn;

    for (int k = 0; k < gn; ++k) {
        double a = dx * k;
        double b = (k + 1) * dx;
        sum += (b - a) / 2.0 * (borwein_function(n, a) + borwein_function(n, b));
    }

    return sum;
}

static double simpson(int n) {
    double gn = 5000.0 / 10000.0;
    double sum = 0.0;

    for (int l = 0; l < 10000; ++l) {
        double a = l * gn;
        double b = (l + 1) * gn;
        sum += (b - a) / 6.0 * (borwein_function(n, a) + 4 * borwein_function(n, (a + b) / 2) + borwein_function(n, b));
    }

    return sum;
}

static void calculate(int n, Text &txt1, Text &txt2, Text &txt3)
{
    double reference = M_PI / 2.0;

    double mid = midpoint(n);
    string s = "Midpoint:\nI" + to_string(n) + " = " + to_string(mid) + "\n"
    + "diff = " + to_string(abs(reference - mid)) + "\n\n";
    init_text(txt1, s.c_str(), Vector2f{250, 200}, Color::Magenta, 15);

    double trap = trapezoidal(n);
    string s1 = "Trapezoidal:\nI" + to_string(n) + " = " + to_string(trap) + "\n"
    + "diff = " + to_string(abs(reference - trap)) + "\n\n";
    init_text(txt2, s1.c_str(), Vector2f{350, 300}, Color::Blue, 15);


    double simp = simpson(n);
    string s2 = "Simpson:\nI" + to_string(n) + " = " + to_string(simp) + "\n"
    + "diff = " + to_string(abs(reference - simp));
    init_text(txt3, s2.c_str(), Vector2f{450, 400}, Color::Cyan, 15);

}

static int is_digit(const char *str)
{
    for (int a = 0; str[a] != '\0'; ++a) {
        if (!isdigit(str[a])) {
            return 1;
        }
    }
    return 0;
}

int cherche(const char *str, char c)
{
    int b = 0;

    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] == c) {
            b++;
        }
    }
    return b;
}

int error_case(const char *str, Text *txt1, Text *txt2, Text *txt3)
{
   int n = 0;

    if (str == NULL || cherche(str, '-') > 1) {
        exit(84);
    }
    n = stoi(str);
    if (n < 0 || n > 5000) {
        cerr << "n must be a positive integer <= 5000" << endl;
        exit(84);
    }
    calculate(n, *txt1, *txt2, *txt3);
    return 0;
}
