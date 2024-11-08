This repository consists of all the files that we created and used for our project in C entitled "Hospital Management System".
The HMS aims to replace the use of traditional ledgers with more organised and systematic way of storing details about a patients health.
There are uses of different basic C functions and data types to create a cohesive and hopefully a positive impact driven program.

Anyone can view and use these files as their wish but a small credit to the authors would be really appreciated.
Any faults in the codes and suggestions for better approach for running the code is welcome.

# Hospital Management System

This Hospital Management System is a console-based application written in C. It provides essential functionalities for managing patient records, including adding, viewing, searching, editing, and deleting data on a file. This system is intended to simplify patient data management for healthcare institutions.

## Project Structure
The project is divided into several modules, each responsible for a specific functionality, and includes the following files:
- **main.cpp**: The main program file that coordinates user actions.
- **makechoice.h**: Defines a function for displaying and handling the user’s menu choice.
- **adding_info.h**: Contains functions to add new patient data.
- **viewing_info.h**: Includes functions to view existing patient data.
- **searching_info.h**: Provides search functionality to locate specific patient records.
- **editting_info.h**: Enables editing of patient data.
- **deleting_info.h**: Manages the deletion of patient data.

## Features
The Hospital Management System supports the following operations:
1. **Add Patient Data**: Allows the user to input multiple patient records.
2. **View Patient Data**: Displays all stored patient records.
3. **Search Patient Data**: Finds and displays specific patient records based on search criteria.
4. **Edit Patient Data**: Modifies existing patient records.
5. **Delete Patient Data**: Removes a patient record from the database.

## Usage
1. **Start the Program**: Run the `main.cpp` file.
2. **Menu Navigation**: 
   - The program will display a menu of choices (1-5) to manage patient records.
   - Enter the corresponding number to perform the desired action.
3. **Adding Records**: 
   - Choose option `1` to add patient data.
   - Enter the number of records you want to add.
4. **Viewing Records**: 
   - Choose option `2` to view all patient records.
5. **Searching Records**:
   - Choose option `3` to search for a patient by criteria.
6. **Editing Records**:
   - Choose option `4` to edit an existing record.
7. **Deleting Records**:
   - Choose option `5` to delete a specific record.

## Code Overview
The core functionality is managed by a set of functions implemented in separate header files, making the code modular and easier to maintain.

### Main Functionality
The `main.cpp` file contains the main program loop:
- **choices()**: Prompts the user for a selection from the menu.
- **add()**: Adds new patient records to the database.
- **view()**: Displays all patient records.
- **search()**: Searches the database for specific patient records.
- **edit()**: Allows editing of an existing patient record.
- **delete()**: Removes a patient record from the database.

The program uses a `switch` statement to handle different operations, looping back to the menu after each action until the user exits.
