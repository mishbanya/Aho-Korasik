#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int ALPHABET = 26, NMAX = 10000;

struct bohr_nod {
    int next_nod[ALPHABET], str_num, suff_link, move[ALPHABET], father, suff_flink;
    bool flag;
    char letter;
};

vector<bohr_nod> bohr;
vector<string> stroka;

bohr_nod make_bohr_nod(int p, char c) {
    bohr_nod v;
    memset(v.next_nod, 255, sizeof(v.next_nod));
    memset(v.move, 255, sizeof(v.move));
    v.flag = false;
    v.suff_link = -1;
    v.father = p;
    v.letter = c;
    v.suff_flink = -1;
    return v;
}
void bohr_ini() {
    bohr.push_back(make_bohr_nod(0, '$'));
}
void add_string_to_bohr(const string& s) {
    int num = 0;
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i] - 'a';
        if (bohr[num].next_nod[ch] == -1) {
            bohr.push_back(make_bohr_nod(num, ch));
            bohr[num].next_nod[ch] = bohr.size() - 1;
        }
        num = bohr[num].next_nod[ch];
    }
    bohr[num].flag = true;
    stroka.push_back(s);
    bohr[num].str_num = stroka.size() - 1;
}
bool is_string_in_bohr(const string& s) {
    int num = 0;
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i] - 'a';
        if (bohr[num].next_nod[ch] == -1) {
            return false;
        }
        num = bohr[num].next_nod[ch];
    }
    return true;
}
int get_move(int v, char ch);
int get_suff_link(int v) {
    if (bohr[v].suff_link == -1)
        if (v == 0 || bohr[v].father == 0)
            bohr[v].suff_link = 0;
        else
            bohr[v].suff_link = get_move(get_suff_link(bohr[v].father), bohr[v].letter);
    return bohr[v].suff_link;
}
int get_move(int v, char ch) {
    if (bohr[v].move[ch] == -1)
        if (bohr[v].next_nod[ch] != -1)
            bohr[v].move[ch] = bohr[v].next_nod[ch];
        else
            if (v == 0)
                bohr[v].move[ch] = 0;
            else
                bohr[v].move[ch] = get_move(get_suff_link(v), ch);
    return bohr[v].move[ch];
}
int get_suff_flink(int v) {
    if (bohr[v].suff_flink == -1) {
        int u = get_suff_link(v);
        if (u == 0)
            bohr[v].suff_flink = 0;
        else
            if (bohr[v].suff_flink = (bohr[u].flag)) {
                u;
            }
            else {
                get_suff_flink(u);
            }
    }
    return bohr[v].suff_flink;
}
void check(int v, int i) {
    for (int u = v; u != 0; u = get_suff_flink(u)) {
        if (bohr[u].flag) {
            cout << "Начиная с символа номер " << i - stroka[bohr[u].str_num].length() + 1 << " строка " << stroka[bohr[u].str_num] << endl;
        }
    }
}
void find_all_pos(const string& s) {
    int u = 0;
    for (int i = 0; i < s.length(); i++) {
        u = get_move(u, s[i] - 'a');
        check(u, i + 1);
    }
}