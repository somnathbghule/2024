
// Online C++ compiler to run C++ program online
#include <iostream>

std::string getNumberInWord(int digit, int placeholder);

const char *lessThan20[] = {
"zero", "one", "two", "three", "four", "five",  "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" 
};

const char *multipleOf100[] = {"hundred", "thousand"};
const char *multipleOf10[] = {"", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" };

void printNumberInWords (int n) {
    static int placeholder = 1;
    static int digit = 0;
    std::string word;
    int number = n;
    if (n) {
            int tenthPlace = 10;
            digit = n % tenthPlace;
            if (digit != 0) {
                if ((placeholder % 1000) == 0 && (n % 1000) > 9) {
                    placeholder *= tenthPlace; 
                    tenthPlace = 100;
                    digit = n % tenthPlace;
                } 
                word = getNumberInWord(digit, placeholder);
            }
            n = n / tenthPlace;
            placeholder *= tenthPlace; 
        
        printNumberInWords(n);
        std::cout << word <<" ";
    }
}

int calculatePlaceHolder(int digit) {
    if (digit < 20) {
        return 1;
    }
    if (digit >= 20 && digit < 100) {
        return 10;
    }
    
    if (digit >= 100 && digit < 1000) {
        return 100;
    }
    if (digit > 1000 && digit <= 1000) {
        return 10000;
    }
    if (digit > 10000 && digit <= 100000) {
        return 100000;
    }

    return 1000;
}

std::string getNumberInWord(int digit, int placeholder) {
    //std::cout  << "digit \"" << digit << "\" placeholder \"" << placeholder << "\""<< std::endl; 
    switch (placeholder) {
        case 1:
        return  lessThan20[digit];

        case 10:
        if ((digit %  10) && digit > 20) {
            return std::string(multipleOf10[digit/10]) + std::string(" ") + getNumberInWord(digit%10, 1);
        }
        return multipleOf10[digit];
                
        case 100 :
        return getNumberInWord(digit, 1) + " hundered";
        
        case 1000:
        return getNumberInWord(digit, calculatePlaceHolder(digit)) + " thousand";

        case 10000:
        if (digit < 10) {
            digit = digit*10;
        }
        return getNumberInWord(digit, 1000);

        case 100000:
        return getNumberInWord(digit, calculatePlaceHolder(digit)) + " lakh";
        
        case 1000000:
        if (digit < 10) {
            digit = digit*10;
        }
        return getNumberInWord(digit, 100000);

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

    printNumberInWords(n);
    std::cout << std::endl;
    return 0;
}
