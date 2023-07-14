#include <iostream>
#include <cstring>
#include <vector>
#include "Bohr.h"
using namespace std;


int main() {
    setlocale(LC_ALL, "rus");
    bohr_ini();
    add_string_to_bohr("xyz");
    add_string_to_bohr("yzyz");
    add_string_to_bohr("zxyxy");
    add_string_to_bohr("xyx");
    add_string_to_bohr("xzyyx");
    find_all_pos("zyxyzxyxyzxyyzyxyzxyzyxzyxyyyzxzxzxzxyxxxxzyyyxzyyxyzyyx");
}