#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// Write your Student class here
#define STUDENT_MAX 5
class Student
{
private:
        int scores[5];
        int _index;
public:
    Student()
    {
        _index = 0;
    }
    void input();
    int getScore(int index) const;
    void setScore(int score);
    int calculateTotalScore(void);
};

void Student::input()
{
	_index = 0;
    for (int i = 0;  i < STUDENT_MAX; i++) 
    {
        std::cin >> scores[i];
		_index++;
    }

}
int Student::getScore(int index) const
{
    if (index < 0 || index >= STUDENT_MAX) 
		return  0;
    return  (scores[index]);
}
void Student::setScore(int score)
{
    if (_index < 0 || _index > STUDENT_MAX) 
		return;
    scores[_index++] = score;
}
int Student::calculateTotalScore(void)
{
    int sumScore = 0;
    for (int i = 0;  i < STUDENT_MAX; i++) 
    {
        sumScore += getScore(i);
    }
    return sumScore;
}
int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();
    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}
