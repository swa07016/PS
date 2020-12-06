#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */
    string result = "";
    string str_hour = s.substr(0, 2);
    string flag = s.substr(8, 2);
    int hour = stoi(str_hour);
    if(flag == "AM" && hour == 12) hour = 0;
    if(flag == "PM" && hour == 12) hour = 12;
    else if(flag == "PM") hour += 12;
    if(hour < 10) result += "0";
    result += to_string(hour) + ":" + s.substr(3, 5);
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
