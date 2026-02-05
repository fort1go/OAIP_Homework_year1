#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

string lower(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

void telephones() {
    fstream input_file = fstream("data.dat", ios::in);
    if (!input_file.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }
    string search_model;
    cout << "Enter the model name: ";
    cin >> search_model;

    double from, to;
    cout << "Enter the price from and to: ";
    cin >> from >> to;

    bool found = false;
    string line;
    while (getline(input_file, line)) {
        int last_space_index = line.find_last_of(" ");
        string model_name = lower(line.substr(0, last_space_index));
        int price = stoi(line.substr(last_space_index + 1, line.length()));
        if (model_name.find(lower(search_model)) != string::npos) {
            if (from <= price && price <= to) {
                found = true;
                cout << model_name << " " << price << endl;
            }
        }
    }
    input_file.close();
    if (!found) {
        cout << "Model does not exist" << endl;
    }
}

string getUnits(int num) {
    string units[] = {"", "один", "два", "три", "четыре", "пять",
                     "шесть", "семь", "восемь", "девять"};
    return units[num];
}

string getThousandsUnits(int num) {
    string units[] = {"", "одна", "две", "три", "четыре", "пять",
                     "шесть", "семь", "восемь", "девять"};
    return units[num];
}

string getTeens(int num) {
    string teens[] = {"десять", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать",
                     "пятнадцать", "шестнадцать", "семнадцать", "восемнадцать", "девятнадцать"};
    return teens[num - 10];
}

string getTens(int num) {
    string tens[] = {"", "", "двадцать", "тридцать", "сорок", "пятьдесят",
                    "шестьдесят", "семьдесят", "восемьдесят", "девяносто"};
    return tens[num];
}

string getHundreds(int num) {
    string hundreds[] = {"", "сто", "двести", "триста", "четыреста", "пятьсот",
                        "шестьсот", "семьсот", "восемьсот", "девятьсот"};
    return hundreds[num];
}

string convertHundreds(int num, bool isThousand = false) {
    if (num == 0) return "";

    string result = "";

    if (num >= 100) {
        result += getHundreds(num / 100) + " ";
        num %= 100;
    }

    if (num >= 20) {
        result += getTens(num / 10) + " ";
        int units = num % 10;
        if (units > 0) {
            if (isThousand) {
                result += getThousandsUnits(units) + " ";
            } else {
                result += getUnits(units) + " ";
            }
        }
    } else if (num >= 10) {
        result += getTeens(num) + " ";
    } else if (num > 0) {
        if (isThousand) {
            result += getThousandsUnits(num) + " ";
        } else {
            result += getUnits(num) + " ";
        }
    }

    return result;
}

string getThousandForm(int num) {
    int lastDigit = num % 10;
    int lastTwoDigits = num % 100;

    if (lastTwoDigits >= 11 && lastTwoDigits <= 14) {
        return "тысяч";
    }

    if (lastDigit == 1) {
        return "тысяча";
    } else if (lastDigit >= 2 && lastDigit <= 4) {
        return "тысячи";
    } else {
        return "тысяч";
    }
}

string getRublesForm(int num) {
    int lastDigit = num % 10;
    int lastTwoDigits = num % 100;

    if (lastTwoDigits >= 11 && lastTwoDigits <= 14) {
        return "рублей";
    }

    if (lastDigit == 1) {
        return "рубль";
    } else if (lastDigit >= 2 && lastDigit <= 4) {
        return "рубля";
    } else {
        return "рублей";
    }
}

string getKopecksForm(int num) {
    int lastDigit = num % 10;
    int lastTwoDigits = num % 100;

    if (lastTwoDigits >= 11 && lastTwoDigits <= 14) {
        return "копеек";
    }

    if (lastDigit == 1) {
        return "копейка";
    } else if (lastDigit >= 2 && lastDigit <= 4) {
        return "копейки";
    } else {
        return "копеек";
    }
}

string convertAmount(double amount) {
    if (amount < 0.0 || amount > 999999.99) {
        return "Сумма вне допустимого диапазона";
    }

    int rubles = static_cast<int>(floor(amount));
    int kopecks = static_cast<int>(round((amount - rubles) * 100));

    if (kopecks >= 100) {
        rubles += kopecks / 100;
        kopecks %= 100;
    }

    string result = "";

    if (rubles == 0) {
        result = "ноль рублей ";
    } else {
        int thousands = rubles / 1000;
        int remainder = rubles % 1000;

        if (thousands > 0) {
            string thousandsText = convertHundreds(thousands, true);
            result += thousandsText + getThousandForm(thousands) + " ";
        }

        if (remainder > 0) {
            result += convertHundreds(remainder);
        }

        result += getRublesForm(rubles) + " ";
    }

    if (kopecks == 0) {
        result += "ноль копеек";
    } else {
        string kopecksText = convertHundreds(kopecks, true);
        result += kopecksText + getKopecksForm(kopecks);
    }

    return result;
}

void string_amount() {
    double amount;
    cout << "Введите сумму (0.0 < R < 999999.99): ";
    cin >> amount;

    string result = convertAmount(amount);
    cout << result << endl;
}

void delete_SK08K1111_XD() {
    string input, print = "";
    cout << "Введите вашу прекрасную строку (скобки должны открыться и закрыться): ";
    getline(cin, input);
    int skobka_count = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '(') {
            skobka_count++;
            if (skobka_count == 1) {
                print += ' ';
            }
        } else if (input[i] == ')') {
            skobka_count--;
            if (skobka_count == 0) {
                print += ' ';
            }
        } else if (skobka_count == 0) {
            if (i != input.length() - 1) {
                if (!(input[i] == ' ' && input[i + 1] == '(')) {
                    print += input[i];
                }
            } else {
                print += input[i];
            }
        }
    }
    cout << print << endl;
}

int main() {
    telephones();
    string_amount();
    delete_SK08K1111_XD();
    return 0;
}
