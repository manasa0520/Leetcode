#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <sstream>

using namespace std;

// Global variables
vector<string> code;
vector<string> firstStepCode;  // To store first step representation
int nextinstr = 0;

// Function to create a new list containing index i
list<int> makelist(int i) {
    list<int> newList;
    newList.push_back(i);
    return newList;
}

// Function to merge two lists
list<int> merge(list<int> p1, list<int> p2) {
    p1.splice(p1.end(), p2);
    return p1;
}

// Function to backpatch a list with target address
void backpatch(list<int>& patchlist, int target) {
    for (int addr : patchlist) {
        // Replace '?' with target in the instruction
        size_t pos = code[addr].find('?');
        if (pos != string::npos) {
            code[addr].replace(pos, 1, to_string(target));
        }
    }
}

// Function to parse the condition from the if statement
string parseCondition(const string& input) {
    size_t openParen = input.find('(');
    size_t closeParen = input.find(')');
    if (openParen == string::npos || closeParen == string::npos) {
        return "";
    }
    return input.substr(openParen + 1, closeParen - openParen - 1);
}

// Function to parse the statements from the if-else
void parseStatements(const string& input, string& stmt1, string& stmt2) {
    size_t thenPos = input.find(')');
    size_t elsePos = input.find("else");
   
    if (thenPos == string::npos || elsePos == string::npos) {
        stmt1 = "";
        stmt2 = "";
        return;
    }
   
    // Extract statement after if
    size_t stmt1Start = input.find_first_not_of(" ;", thenPos + 1);
    size_t stmt1End = input.find(';', stmt1Start);
    stmt1 = input.substr(stmt1Start, stmt1End - stmt1Start);
   
    // Extract statement after else
    size_t stmt2Start = input.find_first_not_of(" ", elsePos + 4);
    size_t stmt2End = input.find(';', stmt2Start);
    stmt2 = input.substr(stmt2Start, stmt2End - stmt2Start);
}

// Function to generate code for if-else statement
void generateIfElse(string condition, string stmt1, string stmt2) {
    // Step 1: Evaluate condition and emit "if condition goto ?"
    code.push_back(to_string(nextinstr) + ": if " + condition + " goto ?");
    firstStepCode.push_back(to_string(nextinstr) + ": if " + condition + " goto ?");
    nextinstr++;
   
    // Step 2: true_list = makelist(index of above)
    list<int> true_list = makelist(nextinstr - 1);
   
    // Step 3: Emit "goto ?" → false_list = makelist(index of this instruction)
    code.push_back(to_string(nextinstr) + ": goto ?");
    firstStepCode.push_back(to_string(nextinstr) + ": goto ?");
    list<int> false_list = makelist(nextinstr);
    nextinstr++;
   
    // Step 4: Generate code for S1
    int s1_start = nextinstr;
    code.push_back(to_string(nextinstr) + ": " + stmt1);
    firstStepCode.push_back(to_string(nextinstr) + ": " + stmt1);
    nextinstr++;
   
    // Step 5: Emit "goto ?" → next_list = makelist(index of this instruction)
    code.push_back(to_string(nextinstr) + ": goto ?");
    firstStepCode.push_back(to_string(nextinstr) + ": goto ?");
    list<int> next_list = makelist(nextinstr);
    nextinstr++;
   
    // Step 6: backpatch(true_list, beginning of S1)
    backpatch(true_list, s1_start);
   
    // Step 7: Generate code for S2
    int s2_start = nextinstr;
    code.push_back(to_string(nextinstr) + ": " + stmt2);
    firstStepCode.push_back(to_string(nextinstr) + ": " + stmt2);
    nextinstr++;
   
    // Step 8: backpatch(false_list, beginning of S2)
    backpatch(false_list, s2_start);
   
    // Backpatch next_list to instruction after S2
    backpatch(next_list, nextinstr);
}

int main() {
    string input;
    cout << "Enter if-else statement (e.g., if (a < b) x = 1; else x = 2;): ";
    getline(cin, input);

    string condition = parseCondition(input);
    string stmt1, stmt2;
    parseStatements(input, stmt1, stmt2);

    if (condition.empty() || stmt1.empty() || stmt2.empty()) {
        cout << "Invalid input format. Please use format: if (condition) statement1; else statement2;\n";
        return 1;
    }

    cout << "\nGenerating code for: " << input << "\n\n";
   
    generateIfElse(condition, stmt1, stmt2);
   
    cout << "First Step:\n";
    for (const string& instr : firstStepCode) {
        cout << instr << endl;
    }
   
    cout << "\nSecond Step (after backpatching):\n";
    for (const string& instr : code) {
        cout << instr << endl;
    }
   
    return 0;
}
