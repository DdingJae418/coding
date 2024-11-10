#include <string>
#include <vector>
#include <iostream>

using namespace std;

void solveProblem1(vector<int> &student, int num)
{
    for (int i = 0; i < num; i++)
    {
        student.push_back((i%5)+1);
    }
}

void solveProblem2(vector<int> &student, int num)
{
    for (int i = 0; i < num; i++)
    {
        switch(i%8)
        {
        case 0: case 2:
        case 4: case 6:
            student.push_back(2);
            break;
        case 1:
            student.push_back(1);
            break;
        case 3:
            student.push_back(3);
            break;
        case 5:
            student.push_back(4);
            break;
        case 7:
            student.push_back(5);
            break;
        default:
            break;
        }
    }
}

void solveProblem3(vector<int> &student, int num)
{
    for (int i = 0; i < num; i++)
    {
        switch(i%10)
        {
        case 0: case 1:
            student.push_back(3);
            break;
        case 2: case 3:
            student.push_back(1);
            break;
        case 4: case 5:
            student.push_back(2);
            break;
        case 6: case 7:
            student.push_back(4);
            break;
        case 8: case 9:
            student.push_back(5);
            break;
        default:
            return;
        }
    }
}

void matchProblem(const vector<int> &student, const vector<int> &answers, int &score)
{
    for (int i = 0; i<answers.size(); i++)
    {
        if(student[i] == answers[i]) score++;
    }
}

vector<int> solution(vector<int> answers) {
    vector<int> student1, student2, student3;
    int score1 = 0; 
    int score2 = 0;
    int score3 = 0;
    
    solveProblem1(student1, answers.size());
    solveProblem2(student2, answers.size());
    solveProblem3(student3, answers.size());

    matchProblem(student1, answers, score1);
    matchProblem(student2, answers, score2);
    matchProblem(student3, answers, score3);

    vector<int> answer;
    if(score1 >= score2 && score1 >= score3)
        answer.push_back(1);
    if(score2 >= score1 && score2 >= score3)
        answer.push_back(2);
    if(score3 >= score1 && score3 >= score2)
        answer.push_back(3);
    return answer;
}



int main(void)
{
    vector<int> student1, student2, student3;
    int score1 = 0; 
    int score2 = 0;
    int score3 = 0;

    solveProblem1(student1, 38);
    solveProblem2(student2, 38);
    solveProblem3(student3, 38);

    for (int num: student1)
    {
        cout<<num<<" ";
    }
    cout<<endl;
    for (int num: student2)
    {
        cout<<num<<" ";
    }   
    cout<<endl;
    for (int num: student3)
    {
        cout<<num<<" ";
    }
}