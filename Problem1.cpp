/**
 *   ALBRIT BENDO
 *   PROBLEM 1
 * 
 *   IDEA: 
 *
 *   My idea is to use two C++ lists. One of them is to store all the students,
 *   and the other one is to store the selected students, respectively player_to_pick
 *   and picked_player. 
 *   First I declare a skill variable which is a random number and push it to the list. In 
 *   this way I get the skill rating for all the students. Then I pick P students from 
 *   player_to_pick by continuously popping one-by-one. Now I have the picked_player filled
 *   and I can sort them so it is easier to get the max element from the list.
 *   Afterwords I compute the difference of the max element with the smallest and continuously
 *   pop the elements that are already computed, while the max element is a "global" variable.
 *   Then I print the sum respectively to the case.
 **/

#include <iostream>
#include <list>
#include <algorithm>
#include <ctime>

using namespace std;

int main() 
{
    srand(time(0));

    list<int> player_to_pick; // Total number of students
    list<int> picked_player; // Picked students
    int j = 1;
 
    int T; // Variable for tests
    cin >> T;
    if(T < 1 || T > 100) { // 1 <= T <= 100
        exit(1);
    }
    else {
        for(int i = 0; i < T; i++) {

            int N; // Variable for all the students size
            cin >> N; 

            for(int i = 0; i < N; i++) {
                int skill = rand() % 10000 + 1; // Get some random values for skill
                player_to_pick.push_back(skill); // Store them
            }

            for(auto& x: player_to_pick) {
                cout << x << " ";
            }

            int P; // Variable for picked number of students size
            cin >> P;

            for(int i = 0; i < P; i++) {
                if(P < 2 || P > N) // 2 <= P <= N
                    break;
                else
                {
                    int element = player_to_pick.front(); // Copy the picked students
                    picked_player.push_back(element);    // to the other list
                    player_to_pick.pop_front();
                }
            }
                cout << endl;
            for(auto& x: picked_player) {
                cout << x << " ";
            }

            picked_player.sort(); // Sort the values

            int sum = 0;
            int x = picked_player.back(); // Get the max value
            for(int i = P; i > 0; --i) {
                while(!picked_player.empty()) {
                    int y = picked_player.front();
                    sum += x - y; // Compute the sum of hours needed
                    picked_player.pop_front();
                }
            }
            cout << "\nCase #" << j << ": " << sum << endl; 
            j++;       
        } 
    }
    return 0;
}

/*
As the football coach at your local school, you have been tasked
with picking a team of exactly P students to represent your school.
There are N students for you to pick from.
The i-th student has a skill rating Si, which is a positive integer
indicating how skilled they are.

You have decided that a team is fair if it has exactly P students on it
and they all have the same skill rating. 
That way, everyone plays as a team. Initially, it might not be possible
to pick a fair team, so you will give some of the students one-on-one coaching. 
It takes one hour of coaching to increase the skill rating of any student by 1.

The competition season is starting very soon 
(in fact, the first match has already started!),
so you'd like to find the minimum number of hours of coaching you need to give
before you are able to pick a fair team.

INPUT:

The first line of the input gives the number of test cases, T.
T test cases follow. Each test case starts with a line containing
the two integers N and P, the number of students and the number
of students you need to pick, respectively. Then, 
another line follows containing N integers Si; 
the i-th of these is the skill of the i-th student.

OUTPUT:

For each test case, output one line containing Case #x: y,
where x is the test case number (starting from 1) and y is 
the minimum number of hours of coaching needed, 
before you can pick a fair team of P students.

LIMITS:

Time limit: 15 seconds per test set.
Memory limit: 1 GB.
1 ≤ T ≤ 100.
1 ≤ Si ≤ 10000, for all i.
2 ≤ P ≤ N.

*/