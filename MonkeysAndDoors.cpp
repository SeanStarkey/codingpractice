// There are 100 doors, all closed.
// In a nearby cage are 100 monkeys.

// The first monkey is let out, and runs along the doors opening every one.
// The second monkey is then let out, and runs along the doors closing the 2nd, 4th, 6th,… - all the even-numbered doors.
// The third monkey is let out. He attends only to the 3rd, 6th, 9th,… doors (every third door, in other words), closing any that is open and opening any that is closed, and so on.
// After all 100 monkeys have done their work in this way, what state are the doors in after the last pass?

#include <iostream>

int main() {
    bool doors[100];

    // true is an open door
    for (int d=0; d<100; d++)
        doors[d] = false;

    for (int monkey=1; monkey<=100; monkey++) {
        for (int place=(monkey-1); place<100; place+=monkey)
            doors[place] = !doors[place];
    }

    int count=0;
    for (int d=0; d<100; d++)
        if (doors[d])
            count++;

    std::cout << count << std::endl;
    return count;
}
