#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Rule
{
    string lhs;         // Left-hand side
    vector<string> rhs; // Right-hand side
};

// Context-free grammar
class CFG
{
public:
    // Constructor
    CFG() {}

    // Add a production rule to the grammar
    void addRule(Rule rule)
    {
        rules.push_back(rule);
    }

    // Generate a string from the grammar
    string generate()
    {
        srand(time(nullptr)); // Seed the random number generator
        return expand("S");
    }

private:
    vector<Rule> rules;

    // Expand a nonterminal symbol using a production rule
    string expand(string symbol)
    {
        string result = "";
        for (int i = 0; i < rules.size(); i++)
        {
            if (rules[i].lhs == symbol)
            {
                int index = rand() % rules[i].rhs.size(); // Choose a random right-hand side
                for (int j = 0; j < rules[i].rhs[index].length(); j++)
                {
                    if (rules[i].rhs[index][j] >= 'A' && rules[i].rhs[index][j] <= 'Z')
                    {
                        result += expand(string(1, rules[i].rhs[index][j])); // Expand nonterminal symbols
                    }
                    else
                    {
                        result += rules[i].rhs[index][j]; // Copy terminal symbols
                    }
                }
                break;
            }
        }
        return result;
    }
};

// Example usage
int main()
{
    CFG grammar;
    grammar.addRule({"S", {"A", "aB"}});
    grammar.addRule({"A", {"aA", "bA", ""}});
    grammar.addRule({"B", {"bB", "aB", ""}});
    cout << grammar.generate() << endl;
    return 0;
}
