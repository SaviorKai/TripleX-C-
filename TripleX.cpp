#include <iostream>
#include <ctime>

void PrintIntro(int Difficulty)
{
    std::cout << std::endl;
    std::cout << std::endl;
    if (Difficulty == 1)
    {
        std::cout << " You are secret agent Derpi <('.'<) and you are breaking into a level " << Difficulty;
        std::cout << " secure server room.\n Enter the correct 3 codes to continue...\n";
    }
    else
    {
        std::cout << " You reach a level " << Difficulty << " firewall. Enter the correct code to continue...\n";
    }
    
    
}

bool PlayGame(int GameDifficulty)    //IVAN NOTE: When creating functions, you create aruguements by setting varibles, which can then be used in the body of the function. Example: bool PlayGame(int GameDifficulty, int TestVar) 
{
    // Intro Text
    PrintIntro(GameDifficulty);
    
    // Creation of 3 number lock code Varibles
    const int CodeA = rand() % GameDifficulty + GameDifficulty;     //IVAN NOTE: Modulus Operator (%) gives you the remainder of a devision. Example: 9%4 = 1   (9/4 = 2.25)
    const int CodeB = rand() % GameDifficulty + GameDifficulty;
    const int CodeC = rand() % GameDifficulty + GameDifficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print Testing (Print sum and product vars to terminal)
    std::cout << "\n + There are 3 numbers in the code";
    std::cout << "\n + The codes add-up to: " << CodeSum;
    std::cout << "\n + The codes multiply to give: " << CodeProduct;

    //Store Player Input
    int GuessA, GuessB, GuessC;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << " Code 1: ";
    std::cin >> GuessA;    //IVAN NOTE: You can write these out in a group if you want. Example: std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << " Code 2: ";
    std::cin >> GuessB;    
    std::cout << " Code 3: ";
    std::cin >> GuessC;    
    
    //Check Player Input and provide feedback
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n *** Correct! You've passed the firewall. ***";
        return true;
    }
    else
    {
        std::cout << "\n --- Incorrect! You failed and died. <(o.O<) RIP ---";
        return false;
    }
    
    std::cout << std::endl;
}

int main()
{
    srand(time(NULL));      //IVAN NOTE: Randomizes Random so that its different everytime we play. Make sure to #include <ctime> before this will work.
    int LevelDifficulty = 1; 
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) //Loop game until max diff is reached
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);   //IVAN NOTE: This Set the Var AND calls the Function 'PlayGame();'
        std::cin.clear();   //Clears and errors
        std::cin.ignore();  //Discards the buffer

        if (bLevelComplete)
        {
            LevelDifficulty += 1;    //IVAN NOTE: Alternative way to write this is: ++LevelDifficulty
        }
        
    }

    //End Game
    std::cout << std::endl;
    std::cout << " \n*** (>^.^)> Good work agent Derpi! You've stolen the information. Now get out of there! ***\n";
    return 0;
}