
// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
#include <string>
#include <logging.h>

std::string getNumberInWord(int digit, int placeholder);
bool getPlaceHolder(int &digit, int &placeholder);

const char *lessThan20[] = {
    "", "one", "two", "three", "four", "five",  "six", "seven", "eight", "nine","ten","eleven", "twelve", "thirteen", "fourteen", 
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

const char *multipleOf10[] = {"", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" };

void printNumberInWords (int n, std::stack <std::string> &words) {
    static int placeholder = 1;
    static int digit = 0;
    std::string word;
    int number = n;
    int prevPopped = 0;
    int lastDigit = 0;
    if (n < 20) {
        word = getNumberInWord(n, 1);
        std::cout << word <<" ";
        return;
    }
    while (n) {

        lastDigit = digit;
        digit = n % 10;

        if (digit != 0) {
            word = getNumberInWord(digit, placeholder);
            if (!word.empty()) {
                if (placeholder/10 == 1000 || placeholder/10 == 100000) {
                    if (!words.empty() && lastDigit) {
                        LOG("popping " + words.top());
                        words.pop();
                    }
                    word = getNumberInWord(digit*10 + lastDigit, placeholder/10);
                } else if (placeholder == 1 && (number % 100 < 20)) {
                    if (!words.empty()) {
                        LOG("popping " + words.top());
                        words.pop();
                    }
                    word = getNumberInWord(number % 100, 1);
                }
                words.push(word);
            }
        } 

        n = n / 10;
        placeholder *= 10; 
    }

    while(!words.empty()) {
        std::cout<<words.top() << " "; 
        words.pop();
    }
}

std::string getNumberInWord(int digit, int placeholder) {
    //LOG("digit \"" + digit + "\" placeholder \"" + placeholder + "\""); 
    switch (placeholder) {
        case 1:
        if (digit > sizeof(lessThan20)) {
            
            return getNumberInWord(digit, placeholder);
        }
        return  lessThan20[digit];

        case 10:
        return std::string(multipleOf10[digit]);
                
        case 100:
        if (digit > 19) {
            
            return getNumberInWord(digit, 10);
        }
        return getNumberInWord(digit, 1) + " hundered";
        
        case 1000:
        if (digit > 19) {
            
            return getNumberInWord(digit/10, 10) + " "+ getNumberInWord(digit%10, 1) + " thousand";
        }
        return getNumberInWord(digit, 1) + " thousand";

        case 10000:
        return getNumberInWord(digit/10, 1000);

        case 100000:
        if (digit > 19) {
            
            return getNumberInWord(digit/10, 10) + " "+ getNumberInWord(digit%10, 1) + " lakh";
        }
        return getNumberInWord(digit, 1) + " lakh";
        
        case 1000000:
        return getNumberInWord(digit/10, 100000) ;

        default:
        std::cout << "Not handled yet" << std::endl;
        std::cout << "digit = " << digit << std::endl;
        std::cout << "placeholder = " << placeholder << std::endl;
        break;
    }
    
    return std::string("");
}

int main() {
    // Write C++ code here
    std::cout << "Enter Number: ";
    int n = 0;

    std::cin >> n ;
    std::stack <std::string> words;

    printNumberInWords(n, words);
    std::cout << std::endl;
    return 0;
}
