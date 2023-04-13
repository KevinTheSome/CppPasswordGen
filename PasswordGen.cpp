#include <iostream>
#include <thread> // thred and for this => this_thread::sleep_for(std::chrono::seconds(1));
#include <chrono>  // secends
#include <fstream>

char uppercaseAlphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
char lowercaseAlphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
char AllNumbers[10] = { '0','1','2','3','4','5','6','7','8','9' };
char SpecChar[31] = { '~','`','!','@','#','$','%','^','&','*','(',')','_','-','+','=','{','[','}',']','|','\\',':','; ','"','<',',','>','.','?','/' };
int HowMany;
int HowLong;
std::string SpecCharBool;
std::string ExternalBool;

int Random(int max) {
    return rand() % max;
}

char SpecCharGen() {
    switch (Random(4)){
    case 0:
        return uppercaseAlphabet[Random(25)];
        break;
    case 1:
        return lowercaseAlphabet[Random(25)];
        break;
    case 2:
        return AllNumbers[Random(9)];
        break;
    case 3:
        return SpecChar[Random(30)];
        break;
    }
}

char NonSpecCharGen() {
    switch (Random(3)) {
    case 0:
        return uppercaseAlphabet[Random(25)];
        break;
    case 1:
        return lowercaseAlphabet[Random(25)];
        break;
    case 2:
        return AllNumbers[Random(9)];
        break;
    }
}

int main()
{
    char OnlySoitdosntclose;
    srand(time(NULL));

    //This is the Input It works sometimes
    std::cout <<"\n Do you want to save it in a file or copy from console?(yes/no):";
    std::cin >> ExternalBool;
    if (ExternalBool == "Yes" or ExternalBool == "yes" or ExternalBool == "YES" or ExternalBool == "Y" or ExternalBool == "y") {
        ExternalBool = "yes";
    }
    else if (ExternalBool == "No" or ExternalBool == "no" or ExternalBool == "NO" or ExternalBool == "nO" or ExternalBool == "N" or ExternalBool == "n") {
        ExternalBool = "no";
    }
    std::cout << "\n Do you want to Special cherecters in the password?(yes/no):";
    std::cin >> SpecCharBool;
    if (SpecCharBool == "Yes" or SpecCharBool == "yes" or SpecCharBool == "YES" or SpecCharBool == "Y" or SpecCharBool == "y") {
        SpecCharBool = "yes"; 
    }
    else if (SpecCharBool == "No" or SpecCharBool == "no" or SpecCharBool == "NO" or SpecCharBool == "nO" or SpecCharBool == "N" or SpecCharBool == "n") {
        SpecCharBool = "no"; 
    }
    std::cout << "\n How many Passwords you want to generate ? : ";
    std::cin >> HowMany;
    std::cout << "\n How Long Passwords you want to generate ? : ";
    std::cin >> HowLong;

    //clears the screen
    std::cout << "\033c";
    //The output I guess

    if (ExternalBool == "yes") {
        std::ofstream PasswordFile;
        PasswordFile.open("Passwords.txt", std::ios_base::app);
        for (int i = 0; i < HowMany; i++)
        {
            for (int i = 0; i < HowLong; i++)
            {
                if (SpecCharBool == "yes") {
                    PasswordFile << SpecCharGen();
                }
                else {
                    PasswordFile << NonSpecCharGen();
                }
            }
            PasswordFile << "\n";
            std::cout << std::endl;
        }
        PasswordFile.close();
    }
    else {
        for (int i = 0; i < HowMany; i++)
        {
            for (int i = 0; i < HowLong; i++)
            {
                if (SpecCharBool == "yes") {
                    std::cout << SpecCharGen();
                }
                else {
                    std::cout << NonSpecCharGen();
                }
            }
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << "Type anything to close. \n";
    std::cin >> OnlySoitdosntclose;
}
