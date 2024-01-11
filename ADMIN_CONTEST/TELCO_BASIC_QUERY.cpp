/*
Description
Write a C program to perform some queries on a telco data (comming from stdin) with the following format:
The first block of data consists of lines (terminated by a line containing #), each line (number of lines can be up to 100000) is under the form:
        call <from_number> <to_number> <date> <from_time> <end_time>
which is a call from the phone number <from_number> to a phone number <to_number> on <date>, and starting at time-point <from_time>, terminating at time-point <end_time>
<from_number> and <to_number> are string of 10 characters (a phone number is correct if it contains only digits 0,1,...,9, otherwise, the phone number is incorrect)
<date> is under the form YYYY-MM-DD (for example 2022-10-21)
<from_time> and <to_time> are under the form hh:mm:ss (for example, 10:07:23)

The second block consists of queries (terminated by a line containing #), each query in a line (number of lines can be up to 100000) and belongs to one of the following types:
?check_phone_number: print to stdout (in a new line) value 1 if no phone number is incorrect
?number_calls_from <phone_number>: print to stdout (in a new line) the number of times a call is made from <phone_number>
?number_total_calls: print to stdout (in a new line) the total number of calls of the data
?count_time_calls_from <phone_number>: print to stdout (in a new line) the total time duration (in seconds) the calls are made from <phone_number>

Example
Input
call 0912345678 0132465789 2022-07-12 10:30:23 10:32:00
call 0912345678 0945324545 2022-07-13 11:30:10 11:35:11
call 0132465789 0945324545 2022-07-13 11:30:23 11:32:23
call 0945324545 0912345678 2022-07-13 07:30:23 07:48:30
#
?check_phone_number
?number_calls_from 0912345678
?number_total_calls
?count_time_calls_from 0912345678
?count_time_calls_from 0132465789
#

Output
1
2
4
398
120
*/

#include <bits/stdc++.h>
using namespace std;

int checkPhone = 1;

void check_phone_number(const string &phone)
{
    for (char c : phone)
    {
        if (c < '0' || c > '9')
            checkPhone = 0;
    }
}
int main()
{
    map<string, int> call;
    map<string, int> count;
    string cmd;
    int i = 0;
    while (true)
    {
        cin >> cmd;
        if (cmd == "#")
            break;
        string from_phone, to_phone, date, start_time, end_time;
        cin >> from_phone >> to_phone >> date >> start_time >> end_time;
        check_phone_number(from_phone);
        check_phone_number(to_phone);
        long long int time_call = ((end_time[0] - start_time[0]) * 10 + (end_time[1] - start_time[1])) * 3600 + ((end_time[3] - start_time[3]) * 10 + (end_time[4] - start_time[4])) * 60 + ((end_time[6] - start_time[6]) * 10 + (end_time[7] - start_time[7]));
        call[from_phone] += time_call;
        // cout << call[from_phone] << endl;
        count[from_phone]++;
        // cout << count[from_phone] << endl;
        i++;
    }

    while (true)
    {
        cin >> cmd;
        if (cmd == "#")
            break;
        if (cmd == "?check_phone_number")
            cout << checkPhone << endl;
        if (cmd == "?number_calls_from")
        {
            string phone;
            cin >> phone;
            cout << count[phone] << endl;
        }
        if (cmd == "?number_total_calls")
            cout << i << endl;
        if (cmd == "?count_time_calls_from") {
            string phone;
            cin >> phone;
            cout << call[phone] << endl;
        }
    }
    return 0;
}