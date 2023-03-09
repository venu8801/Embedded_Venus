# 1 "sum_digits.c"
# 1 "/home/engineer/MyPrograms/dailyTasks/Nov15//"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "sum_digits.c"
int sum_digits(int num)
{
 int temp = num;
 int digit = 0, sum = 0;
 while(temp > 0)
 {
  digit = temp % 10;

  temp = temp / 10;

  sum = sum + digit;
 }
 return sum;
}
