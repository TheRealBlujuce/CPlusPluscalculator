#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

class Calculator
{
    public:
    float add(float x, float y) { return x + y; }
    float subtract(float x, float y) { return x - y; }
    float multiply(float x, float y) { return x * y; }
    float divide(float x, float y) { if(x != 0 && y!= 0){ return x / y; } else { return 0; } }
};

void SaveHistory(const vector<float>& history)
{
    ofstream file("history.txt");
    for (float result : history)
    {
        file << result << endl;
    }
    file.close();
};

vector<float> LoadHistory()
{

    vector<float> history;
    ifstream file("history.txt");
    float result;
    while (file >> result)
    {
        history.push_back(result);
    }
    file.close();
    return history;

};

int main()
{
    Calculator calc;
    char input;
    float a, b, result;
    bool isRunning = true;
    vector<float> history = LoadHistory();

    while (isRunning)
    {
        cout << "Enter the operation you would like to perform: +, -, *, /, q to quit, or s to show history: ";
        cin >> input;
        
        switch (input)
        {
            case '+':
                cout << "Enter Two Numbers:" << endl;
                cin >> a >> b;
                result = calc.add(a, b);
                cout << "The Result is: " << result << endl;
                history.push_back(result);
                break;
            case '-':
                cout << "Enter Two Numbers:" << endl;
                cin >> a >> b;
                result = calc.subtract(a, b);
                cout << "The Result is: " << result << endl;
                history.push_back(result);
                break;
            case '*':
                cout << "Enter Two Numbers:" << endl;
                cin >> a >> b;
                result = calc.multiply(a, b);
                cout << "The Result is: " << result << endl;
                history.push_back(result);
                break;
            case '/':
                cout << "Enter Two Numbers:" << endl;
                cin >> a >> b;
                result = calc.divide(a, b);
                cout << "The Result is: " << result << endl;
                history.push_back(result);
                break;
            case 's':
                cout << "---- Current History ----" << endl;
                for (float result : history)
                {
                    cout << result << endl;
                }
                break;
            case 'q':
                isRunning = false;
                break;
            default:
                break;
        }

        SaveHistory(history);
    }
};