// Ring the bell using '\a' literal for the alarm.

#include <iostream>

const char BELL = '\a';

void ring()
{
    std::cout << BELL;
}

int main()
{
    ring();
}