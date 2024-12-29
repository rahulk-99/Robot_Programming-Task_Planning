/**
 * @file kitting.hpp
 * @brief Header file for the kitting task program.
 * 
 * This file contains the declarations of functions used in the kitting
 * task, including user prompts for block inputs and the planning
 * logic for the robot's actions.
 */

#ifndef KITTING_HPP
#define KITTING_HPP


//Function declaration fr robot's task
/**
 * @brief Central coordination function for the robot's task.
 *
 * This function orchestrates the flow of the kitting task by calling
 * other functions to prompt the user and generate a plan for block movement.
 */
void plan(); 

/**
 * @brief Prompts the user for the number of blocks in each colored bin.
 *
 * This function takes references to integers for green, blue, and red blocks
 * and ensures the input is between 1 and the maximum allowed.
 * 
 * @param green Reference to the integer representing green blocks in the bin.
 * @param blue Reference to the integer representing blue blocks in the bin.
 * @param red Reference to the integer representing red blocks in the bin.
 */
void blocks_userprompt(int& green, int& blue, int& red);   

/**
 * @brief Prompts the user for the number of blocks to place in the tray.
 *
 * This function ensures the input does not exceed the number of blocks 
 * available in the respective bins and checks that the total number 
 * of blocks is valid.
 * 
 * @param green_bin Current number of green blocks in the bin.
 * @param blue_bin Current number of blue blocks in the bin.
 * @param red_bin Current number of red blocks in the bin.
 * @param green_blocks Reference to the integer for blocks to be placed in the tray from green bin.
 * @param blue_blocks Reference to the integer for blocks to be placed in the tray from blue bin.
 * @param red_blocks Reference to the integer for blocks to be placed in the tray from red bin.
 */                                                                 //Function definition for user input for blocks in each colored bins meeting the requirements. This is uder defined
void tray_userprompt(int green_bin, int blue_bin, int red_bin, int& green_blocks, int& blue_blocks, int& red_blocks);       //Function definition for the goal achievenemt of number of blocks to be moved to tray. This is also user defined

/**
 * @brief Generates a plan for the robot's pick and place actions.
 *
 * This function details the actions of picking blocks from bins and placing 
 * them in the tray, updating the status of the bins and the tray.
 * 
 * @param green_blocks Number of green blocks to pick and place in the tray.
 * @param blue_blocks Number of blue blocks to pick and place in the tray.
 * @param red_blocks Number of red blocks to pick and place in the tray.
 * @param green_bin Reference to the integer representing remaining green blocks in the bin.
 * @param blue_bin Reference to the integer representing remaining blue blocks in the bin.
 * @param red_bin Reference to the integer representing remaining red blocks in the bin.
 */
void generate_Plan(int green_blocks, int blue_blocks, int red_blocks, int& green_bin, int& blue_bin, int& red_bin);         //Function definition for action plan of the robot

#endif // KITTING_HPP
