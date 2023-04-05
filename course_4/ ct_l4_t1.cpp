#include <iostream>
#include <vector>


using namespace std;

template<class type>
void mergesort_index(typename vector<type>::iterator pstart, int lp, int rp, bool (cmp)(type e1, type e2)) {
    if (rp - lp > 2) {
        //initialisation of variables
        int mid = lp + (rp - lp) / 2; // not practical but aesthetic variable
        int l_lp = lp; // left_local_pointer
        int l_rp = mid; // right_local_pointer     (needed to merge vectors)
        vector<type> buffer = {};

        //sorting sub-vectors
        mergesort_index(pstart, lp, mid, cmp);
        mergesort_index(pstart, mid, rp, cmp);

        //merging data into buffer
        while (l_lp < mid or l_rp < rp) {
            if ((not cmp(*(pstart + l_lp), *(pstart + l_rp)) and l_lp < mid) or l_rp == rp) {
                buffer.push_back(*(pstart + l_lp++));
            } else {
                buffer.push_back(*(pstart + l_rp++));
            }
        }

        // taking data from buffer
        for (int i = 0; lp != rp;)
            *(pstart + lp++) = buffer[i++];

    } else if (rp - lp == 2) {
        if (cmp(*(pstart + lp), *(pstart + (rp - 1))))
            swap(*(pstart + lp), *(pstart + (rp - 1)));
    }
}

struct datetime {
    int year;
    int month;
    int day;
};

struct db_cell {
    datetime date; // seconds from 2023
    int size;
    int creatorId;
    string title;
    string data;
} a, b, c;

bool dt_cmp(db_cell e1, db_cell e2) {
    datetime el1 = e1.date;
    datetime el2 = e2.date;
    if (el1.year < el2.year) return true;
    else if (el1.year == el2.year) {
        if (el1.month < el2.month) return true;
        else if (el1.month == el2.month) {
            if (el1.day < el2.day) return true;
        }
    }
}
typedef bool (*sort_func) (db_cell cell1, db_cell);

bool size_cmp(db_cell cell1, db_cell cell2) {
    return cell1.size > cell2.size;
}
bool title_cmp(db_cell cell1, db_cell cell2) {
    return cell1.title > cell2.title;
}
bool data_cmp(db_cell cell1, db_cell cell2) {
    return cell1.data > cell2.data;
}
bool creator_cmp(db_cell cell1, db_cell cell2) {
    return cell1.creatorId > cell2.creatorId;
}

int main() {
    vector<db_cell> base;
    a.title = "a.txt";
    b.title = "b.txt";
    c.title = "c.txt";


    a.data = "B(document a.txt)";
    b.data = "C(document b.txt)";
    c.data = "A(document c.txt)";


    a.date.year = 2023;
    b.date.year = 2022;
    c.date.year = 2023;

    a.date.month = 3;
    b.date.month = 1;
    c.date.month = 2;

    a.date.day = 30;
    b.date.year = 2;
    c.date.year = 1;


    a.size = 3333;
    b.size = 2222;
    c.size = 1111;


    a.creatorId = 1;
    b.creatorId = 3;
    c.creatorId = 2;


    base.push_back(a);
    base.push_back(b);
    base.push_back(c);

    bool (*sort_funcs[]) (db_cell, db_cell) = {
            size_cmp,
            size_cmp,
            size_cmp
    };


    string ans;
    cout << "Param to sort :";
    cin >> ans;
    cout << "\n";
    if(ans == "title") mergesort_index(base.begin(), 0, base.size(), *title_cmp);
    else if(ans == "data") mergesort_index(base.begin(), 0, base.size(), *data_cmp);
    else if(ans == "size") mergesort_index(base.begin(), 0, base.size(), *size_cmp);
    else if(ans == "date") mergesort_index(base.begin(), 0, base.size(), *dt_cmp);
    else if(ans == "creator") mergesort_index(base.begin(), 0, base.size(), *creator_cmp);

    for (int i = 0; i < base.size(); i++) cout << base[i].title << " ";


    return 0;
}
// in CPP universal < simple (better to have )
// Created by zer-oRBT on 11.03.2023.
//
