#include<iostream>
#include "kitting.hpp"

const int max_block = 10;      //Constant is defined for maximum number of blocks in a bin
                               // This is a constant as we were told not to define global variable in the assignment

//Function definition for user input for blocks in each colored bins meeting the requirements. This is uder defined
void blocks_userprompt(int& green, int& blue, int& red) {       
    std::cout << "Please enter the number of blocks in each bin (maximum " << max_block << " blocks per bin)\n";
    std::cout << "===========================================================================\n";

    // Prompt for Green bin
    std::cout << "Green bin: ";
    std::cin >> green;
    while (green < 1 || green > max_block) {            //Condition for blocks which is maximum 10 and minimum 1 (mentioned in precondition in pick).
        std::cout << "Invalid input. Please enter a number between 1 and " << max_block << ": ";
        std::cin >> green;                              //Final input for green bins after until it meets the condition
    }

    // Prompt for Blue bin
    std::cout << "Blue bin: ";
    std::cin >> blue;
    while (blue < 1 || blue > max_block) {              //Condition for blocks which is maximum 10 and minimum 1 (mentioned in precondition in pick).
        std::cout << "Invalid input. Please enter a number between 1 and " << max_block << ": ";
        std::cin >> blue;                               //Final input for blue bins after until it meets the condition
    }

    // Prompt for Red bin
    std::cout << "Red bin: ";
    std::cin >> red;
    while (red < 1 || red > max_block) {                //Condition for blocks which is maximum 10 and minimum 1 (mentioned in precondition in pick).
        std::cout << "Invalid input. Please enter a number between 1 and " << max_block << ": ";
        std::cin >> red;                                //Final input for red bins after until it meets the condition
    }
}


//Function definition for the goal achievenemt of number of blocks to be moved to tray. This is also user defined
void tray_userprompt(int green_bin, int blue_bin, int red_bin, int& green_blocks, int& blue_blocks, int& red_blocks) {
    bool total_valid = false;           //Bool declared to check the condition on total summation of blocks to be moved to tray
    
    while (!total_valid) {              //Loop for user such that they can enter inputs until it meets the summation criteria
        std::cout << "Please enter the number of blocks for each color to place in the tray (max " << max_block << " blocks per color)\n";
        std::cout << "===========================================================================\n";

        // Prompt for number of green blocks to place in a tray
        std::cout << "Green blocks: ";
        std::cin >> green_blocks;
        while (green_blocks < 0 || green_blocks > green_bin) {      //Ensuring positive value and value to be move should not exceed the existing number of blocks
            std::cout << "Invalid input. Please enter a positive integer and not exceeding " << green_bin << ": ";
            std::cin >> green_blocks;                               //Number of green blocks to be moved to tray
        }

        // Prompt for number of blue blocks to place in a tray
        std::cout << "Blue blocks: ";
        std::cin >> blue_blocks;
        while (blue_blocks < 0 || blue_blocks > blue_bin) {         //Ensuring positive value and value to be move should not exceed the existing number of blocks
            std::cout << "Invalid input. Please enter a positive integer and not exceeding " << blue_bin << ": ";
            std::cin >> blue_blocks;                                //Number of blue blocks to be moved to tray
        }

        // Prompt for number of red blocks to place in a tray
        std::cout << "Red blocks: ";
        std::cin >> red_blocks;
        while (red_blocks < 0 || red_blocks > red_bin) {            //Ensuring positive value and value to be move should not exceed the existing number of blocks
            std::cout << "Invalid input. Please enter a positive integer and not exceeding " << red_bin << ": ";
            std::cin >> red_blocks;                                 //Number of red blocks to be moved to tray
        }

        // Total check condition
        int total_blocks = green_blocks + blue_blocks + red_blocks;         //total_block is defined to calculate total number of blocks to be moved to tray
        if (total_blocks > 0 && total_blocks <= max_block) {                //Ensuring total number of block should be at max 10
            total_valid = true;
        } else {
            std::cout << "Invalid total. The total number of blocks to be placed in the tray must be between 1 and " << max_block << ". Please re-enter.\n";  //prompt the user to enter new values until all conditions are satisfied.
        }
    }
}


//Function definition for action plan of the robot
void generate_Plan(int green_blocks, int blue_blocks, int red_blocks, int& green_bin, int& blue_bin, int& red_bin) {
    std::cout << "\nGenerating a plan....\n";
    std::cout << "====================================================\n";

    int total_required = green_blocks + blue_blocks + red_blocks;       //total_required variable defined to check if tray is completed or block is remaining to move

    // Pick and Place action plan for robot starting with green bin
    while (green_blocks > 0) {          //Robot will pick green blocks untill it becomes 0
        std::cout << "Pick 1 green block: " << (--green_bin) << " blocks remaining in the green bin.\n";
        --green_blocks;                 //Decerement of blocks to be mobved after the pick
        --total_required;               //Decerement to show total blocks required to move
        std::cout << "Place 1 green block in the tray: " << total_required << " block(s) still needed in the tray.\n";      //Showing tray status
    }

    // Pick and Place action plan for robot for blue bin
    while (blue_blocks > 0) {           //Robot will pick blue blocks untill it becomes 0
        std::cout << "Pick 1 blue block: " << (--blue_bin) << " blocks remaining in the blue bin.\n";
        --blue_blocks;                  //Decerement of blocks to be mobved after the pick
        --total_required;               //Decerement to show total blocks required to move
        std::cout << "Place 1 blue block in the tray: " << total_required << " block(s) still needed in the tray.\n";
    }

    while (red_blocks > 0) {            //Robot will pick red blocks untill it becomes 0
        std::cout << "Pick 1 red block: " << (--red_bin) << " blocks remaining in the red bin.\n";
        --red_blocks;                   //Decerement of blocks to be mobved after the pick
        --total_required;               //Decerement to show total blocks required to move
        if (total_required == 0) {      //Check for task completion status
            std::cout << "Place 1 red block in the tray: Tray completed.\n";   //Will print tray completed if all block moved to tray
        } else {
            std::cout << "Place 1 red block in the tray: " << total_required << " block(s) still needed in the tray.\n";
        }
    }

    std::cout << "\n==================================================\n";
    std::cout << "\nPlan generated..... exit.\n";
}


//Function call for central coordination of robot's task
void plan() {
    int green_bin, blue_bin, red_bin;                       //color_bin variables are defined for number of blocks in a respective bin
    blocks_userprompt(green_bin, blue_bin, red_bin);        //Function call for user prompt for number of blocks in a bin

    int green_blocks, blue_blocks, red_blocks;              //color_blocks are defined for number of blocks to be moved in a tray from the respective colored bins
    tray_userprompt(green_bin, blue_bin, red_bin, green_blocks, blue_blocks, red_blocks);   //Function call for user prompt for number of blocks from each bin to be moved to tray

    generate_Plan(green_blocks, blue_blocks, red_blocks, green_bin, blue_bin, red_bin);     //Function call for robot pick and place action plan
}
