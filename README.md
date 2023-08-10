# Briefly about the project
This is my term paper on structure in C. I created structure of grocery store catalog and I implemented search, sorting, editing, deleting, adding products. Initially, the data is read from the CSV-file, the dialogue with the user takes place in the console by selecting the number of the desired action.

# The structure
The CTL (CATALOG) structure includes 8 fields: name, section (dairy, bakery, meat etc.), code, number of consignment, price, weight, size (3 numbers: x, y, z), and what number of product was bought in three days (also three numbers). Section field I made via doubly linked list (structures Node2 and list2).

# Functions
clear (void) - to clear the console in
dependence of operating system.

Create (list2*) - to create a doubly connected
linear list.

save (void) - to overwrite a file (i.e.
save user changes).

inpup (CTL) - for filling cards with strings
from file.

head (void) - for beautiful output of titles
card fields.

little_outpup (void) - to output one card.

count_strings (int) - to count the number of rows in
file.

delete_mass (int) - to delete one card.

add (void) - to add one more card.

edit (CTL) - to edit any field of card.

find_card (void) - to search for a card by different
fields.

sort (void) - to sort cards by
different fields.

# How it works
Initially, there are two files, both in CSV format: the first one contains several prepared cards, while the second one contains categories of products which are later linked to corresponding fields of the cards using pointers in a doubly linked list. First, the count_strings function is used to determine the number of lines in these files. Then, a two-dimensional array of structures is populated with the cards, and the categories are stored in a doubly linked linear list. If the categories list is empty, a corresponding message is displayed, suggesting the manual addition of several categories. Similarly, if the cards list is empty.

At the beginning of the program's execution, the user selects their operating system so that the console clearing function operates correctly. All interactions with the user are implemented by having them input a number corresponding to the desired action. The user is prompted to choose from one of the possible actions (display all cards, add a new card, delete one of them, sort the cards, find a card, modify, or finish working), until the user decides to finish working with the program. At that point, the user is prompted to save the changes. If the user agrees, the files containing the cards and categories are overwritten according to the changes made.

# Examples
1. Searching
   
   ![image](https://github.com/lvshk03/Directory-processing/assets/69760973/e278eac9-62eb-4636-ad2d-00fca44602c2)
   ![image](https://github.com/lvshk03/Directory-processing/assets/69760973/7b195625-7d93-4179-b4b4-38dfe51e6d60)
   
3. Sorting
   
   ![image](https://github.com/lvshk03/Directory-processing/assets/69760973/f97f8668-31a6-442d-80e1-948a6dc15db2)
   ![image](https://github.com/lvshk03/Directory-processing/assets/69760973/4788685f-ab67-4200-91c0-fae43f4e1b00)

5. Output
   
   ![image](https://github.com/lvshk03/Directory-processing/assets/69760973/4aa69a5d-44c5-4e5a-a676-ac6ece22ed8e)
   ![image](https://github.com/lvshk03/Directory-processing/assets/69760973/5ed6f921-6835-468b-844f-1eb42d1d3c45)

7. Adding new card
   
   ![image](https://github.com/lvshk03/Directory-processing/assets/69760973/8e58b6d9-4d5e-4495-88ad-6865d280d05d)
   ![image](https://github.com/lvshk03/Directory-processing/assets/69760973/dff26be6-2eae-46b5-9298-7773c05a26e0)

9. Deleting card
    
   ![image](https://github.com/lvshk03/Directory-processing/assets/69760973/747fcd66-2f58-4d13-b3ed-4d59cca63b7c)
   ![image](https://github.com/lvshk03/Directory-processing/assets/69760973/45d4040c-6fc9-48b8-a88b-65e0b8223875)

11. Exiting the program
    
   ![image](https://github.com/lvshk03/Directory-processing/assets/69760973/90b387d0-3cb3-4f0b-a941-317090e8d58c)
   ![image](https://github.com/lvshk03/Directory-processing/assets/69760973/0765da8f-1f2b-468d-8cee-a8681605604d)


