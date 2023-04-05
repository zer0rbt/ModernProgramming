#include <gtest/gtest.h>
#include "LinkedListCode.cpp"

using namespace std;

// Tests for ".append()"
TEST(TwllTests, AppendSuccess) {
    vector<int> a = {1, 2, 3, 0, 1, 6, -1};
    TWLL<int> B;
    B.append(31622);
    for (int i = 0; i < a.size(); i++)
        B.append(a[i]);
    B.append(776601);

    vector<int> output;
    vector<int> excepted_output = {31622, 1, 2, 3, 0, 1, 6, -1, 776601};

    Node<int> *cou = B.first;
    while (cou != nullptr) {
        output.push_back(cou->elem);
        cou = cou->next;
    }
    ASSERT_EQ(output, excepted_output);
}

// Tests for ".insertAt()"
TEST(TwllTests, InsertionSuccess) {

    vector<int> a = {1, 2, 3, 0, 1, 6, -1};
    TWLL<int> B;
    B.insertAt(0, 31622);
    for (int i = 0; i < a.size(); i++)
        B.append(a[i]);
    B.insertAt(5, 776601);
    B.insertAt(10000, 451);

    vector<int> output;
    vector<int> excepted_output = {31622, 1, 2, 3, 0, 776601, 1, 6, -1, 451};

    Node<int> *cou = B.first;
    while (cou != nullptr) {
        output.push_back(cou->elem);
        cou = cou->next;
    }
    ASSERT_EQ(output, excepted_output);
}

// Tests for ".remove()"
TEST(TwllTests, RemovalSuccess) {
    vector<int> a = {1, 2, 3, 0, 1, 6, -1};
    TWLL<int> B;
    for (int i = 0; i < a.size(); i++)
        B.append(a[i]);
    B.remove(0, 1);
    B.remove(2, 4);
    B.remove(3, 4);
    vector<int> output;
    vector<int> excepted_output = {2, 3, 6};

    Node<int> *cou = B.first;
    while (cou != nullptr) {
        output.push_back(cou->elem);
        cou = cou->next;
    }
    ASSERT_EQ(output, excepted_output);
}

// Tests for ".clear()"
TEST(TwllTests, ClearSuccess) {
    vector<int> a = {1, 2, 3, 0, 1, 6, -1};
    TWLL<int> B;
    for (int i = 0; i < a.size(); i++)
        B.append(a[i]);
    B.clear();

    ASSERT_EQ(B.first, nullptr);
    ASSERT_EQ(B.last, nullptr);
}

int main(int argc, char **argv){

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();

}
//
// Created by zer-oRBT on 25.03.2023.
//
