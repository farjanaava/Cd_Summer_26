#include <iostream>
#include <string>
using namespace std;

void tokenize(string input)
{
    int i = 0;

    while (i < input.length())
    {
        if (input[i] == ' ')
        {
            i++;
            continue;
        }


        if (input[i] >= '0' && input[i] <= '9')
        {
            cout << "Number: ";

            while (i < input.length() && input[i] >= '0' && input[i] <= '9')
            {
                cout << input[i];
                i++;
            }

            cout << endl;
        }

        else if ((input[i] >= 'a' && input[i] <= 'z') ||
                 (input[i] >= 'A' && input[i] <= 'Z'))
        {
            string word = "";

            while (i < input.length() &&
                  ((input[i] >= 'a' && input[i] <= 'z') ||
                   (input[i] >= 'A' && input[i] <= 'Z')))
            {
                word += input[i];
                i++;
            }

            if (word == "cout" || word == "cin" ||
                word == "int" || word == "float" ||
                word == "double")
            {
                cout << "Keyword: " << word << endl;
            }
            else
            {
                cout << "Identifier: " << word << endl;
            }
        }


        else if (input[i] == '<' && input[i + 1] == '<')
        {
            cout << "Operator: <<" << endl;
            i += 2;
        }


        else if (input[i] == '>' && input[i + 1] == '>')
        {
            cout << "Operator: >>" << endl;
            i += 2;
        }


        else if (input[i] == '+' || input[i] == '-' ||
                 input[i] == '*' || input[i] == '/' ||
                 input[i] == '=')
        {
            cout << "Operator: " << input[i] << endl;
            i++;
        }

        else if (input[i] == ';' || input[i] == ',' ||
                 input[i] == '(' || input[i] == ')')
        {
            cout << "Punctuation: " << input[i] << endl;
            i++;
        }


        else
        {
            cout << "Lexical Error: " << input[i] << endl;
            i++;
        }
    }
}

int main()
{
    string input = "cout << 20 + student * 60 ;";

    tokenize(input);

    return 0;
}
