# 1 "reverse.c"
# 1 "/home/engineer/MyPrograms/dailyTasks/Nov15//"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "reverse.c"
int reverse(int num)
{
 int digit = 0, rev = 0, temp = num;

 while(temp!=0)
 {
  digit=temp%10;
  rev=(rev*10)+digit;
  temp=temp/10;
 }
 return rev;
}
