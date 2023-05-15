#include <bits/stdc++.h>
using namespace std;

string s;
map<string, float> grades;
float sum, score;



int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    grades["A+"] = 4.5;
    grades["A0"] = 4.0;
    grades["B+"] = 3.5;
    grades["B0"] = 3.0;
    grades["C+"] = 2.5;
    grades["C0"] = 2.0;
    grades["D+"] = 1.5;
    grades["D0"] = 1.0;
    grades["F"] = 0.0;

    for(int i = 0; i < 20; i++) {
        cin >> s;
        float sub_grade = 0.0;
        string my_grade = "";
        cin >> sub_grade >> my_grade;

        if(my_grade == "P") continue; 

        sum += sub_grade;
        score += sub_grade * grades[my_grade];

    }

    cout << score / sum;
}