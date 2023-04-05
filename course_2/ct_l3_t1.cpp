#include <iostream>
#include <vector>

using namespace std;

template<class t>
bool uni_cmp(t el1, t el2) {
    return (el1 > el2);
}

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
        if (cmp(*(pstart +lp),  *(pstart + (rp - 1))))
            swap(*(pstart + lp), *(pstart + (rp - 1)));
    }
}
//
// Created by zer-oRBT on 15.11.2022.
//

int main(){
    vector<int> a = {1, 3, 4, 2, 6, 1 ,0};
    vector<double> b = {10.212, 3.1234, 5.1123};
    for(int i = 0; i < a.size();i++) cout << a[i] << " ";
    cout << "\n";
    bool (*int_cmp) (int el1, int el2);
    int_cmp = uni_cmp;
    mergesort_index(a.begin(), 0, a.size(), *int_cmp);
    for(int i = 0; i < a.size();i++) cout << a[i] << " ";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    for(int i = 0; i < b.size();i++) cout << b[i] << " ";
    cout << "\n";
    bool (*double_cmp) (double el1, double el2);
    double_cmp = uni_cmp;
    mergesort_index(b.begin(), 0, b.size(), *double_cmp);
    for(int i = 0; i < b.size();i++) cout << b[i] << " ";
    cout << "\n";
    return 0;
}