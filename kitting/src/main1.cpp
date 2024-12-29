#include<iostream>

int main(){
const int max_block = 10;   //Maximum number of blocks per bin

int green_bin{};         //Initialization of variable for number of green blocks
int blue_bin{};          //Initialization of variable for number of blue blocks
int red_bin{};           //Initialization of variable for number of red blocks

std::cout << "Please enter the number of blocks in each bin (maximum "<< max_block <<" 10 blocks per bin)\n ";
std::cout << "===========================================================================\n" ;

//Prompt for Green bin
std::cout << "Green bin: ";
std::cin >> green_bin ;
while (green_bin < 1 || green_bin > max_block){           //Condition to meet robustness criteria which is integer should be positive integer and max 10
    std::cout << "Invalid input. Please enter a number between 0 and " << max_block << ": ";
    std::cin >> green_bin;
}

//Prompt for Blue bin
std::cout << "Blue bin: ";
std::cin >> blue_bin ;
while (blue_bin < 1 || blue_bin > max_block){             //Condition to meet robustness criteria which is integer should be positive integer and max 10
    std::cout << "Invalid input. Please enter a number between 0 and " << max_block << ": ";
    std::cin >> blue_bin;
}

//Prompt for Red bin
std::cout << "Red bin: ";
std::cin >> red_bin ;
while (red_bin < 1 || red_bin > max_block){               //Condition to meet robustness criteria which is integer should be positive integer and max 10
    std::cout << "Invalid input. Please enter a number between 0 and " << max_block << ": ";
    std::cin >> red_bin;
}

// std::cout<< green_bin << "-" << blue_bin << "-" << red_bin;


int green_blocks{};
int blue_blocks{};
int red_blocks{};

bool total_valid = false;

while (!total_valid){

//Prompt for goal specification i.e. number of blocks to place in tray
std::cout << "Please enter the number of blocks for each color to place in the tray (max " << max_block << " blocks per color)\n ";
std::cout << "===========================================================================\n" ;

//Prompt for number of green blocks to place in a tray
std::cout << "Green blocks: ";
std::cin >> green_blocks;
while (green_blocks < 1 || green_blocks > green_bin){
    std::cout << "Invalid input. Please enter a positive integer and not exceeding " << green_bin << ": ";
    std::cin >> green_blocks;
}


//Prompt for number of blue blocks to place in a tray
std::cout << "Blue blocks: ";
std::cin >> blue_blocks;
while (blue_blocks < 1 || blue_blocks > blue_bin){
    std::cout << "Invalid input. Please enter a positive integer and not exceeding " << blue_bin << ": ";
    std::cin >> blue_blocks;
}

//Prompt for number of green blocks to place in a tray
std::cout << "Red blocks: ";
std::cin >> red_blocks;
while (red_blocks < 1 || red_blocks > red_bin){
    std::cout << "Invalid input. Please enter a positive integer and not exceeding " << red_bin << ": ";
    std::cin >> red_blocks;
}

//total check condition
int total_blocks;
total_blocks = green_blocks + blue_blocks + red_blocks;
if (total_blocks > 0 &&  total_blocks <11){
    total_valid = true;
} else{
    std::cout << "Invalid total. The total no of blocks to be placed in tray must be between 1 and 10. Please re-enter again.\n";
}
}

//Prinitng the plan
std::cout << "\nGenerating a plan....\n";
std::cout << "====================================================\n";

//Pick and place plan
int green_remaining = green_blocks;
int blue_remaining = blue_blocks;
int red_remaining = red_blocks;
int total_required{};
total_required = green_blocks + blue_blocks + red_blocks;
// While there are blocks remaining to be placed
    while (green_remaining > 0) {
            std::cout << "Pick 1 green block: " << (--green_bin) << " blocks remaining in the green bin.\n";
            --green_remaining; // Decrease the count of remaining green blocks
            --total_required;  // Decrease total required blocks
            std::cout << "Place 1 green block in the tray: " << (total_required) << " block still needed in the tray.\n";
    }
        
    while (blue_remaining > 0) {
            std::cout << "Pick 1 blue block: " << (--blue_bin) << " blocks remaining in the blue bin.\n";
            --blue_remaining; // Decrease the count of remaining blue blocks
            --total_required;  // Decrease total required blocks
            std::cout << "Place 1 blue block in the tray: " << (total_required) << " block still needed in the tray.\n";
    }

    while (red_remaining > 0) {
            std::cout << "Pick 1 red block: " << (--red_bin) << " blocks remaining in the red bin.\n";
            --red_remaining; // Decrease the count of remaining red blocks
            --total_required;  // Decrease total required blocks
            // std::cout << "Place 1 red block in the tray: " << (total_required) << " block still needed in the tray.\n";
        if (total_required == 0) {
        std::cout << "Place 1 red block in the tray: Tray completed.\n";
        } else {
        std::cout << "Place 1 red block in the tray: " << total_required << " block(s) still needed in the tray.\n";
        }
    }

std::cout << "\n==================================================\n";
std::cout << "\nPlan generated..... exit.\n";



return 0;

}