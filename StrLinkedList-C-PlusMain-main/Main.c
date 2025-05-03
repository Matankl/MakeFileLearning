# include "StrList.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    //Define input stopper and list
    int input;
    int run = 1;
    StrList* list = StrList_alloc();
    char word[100];


    while (run)
    {

    //Get int input from the user until its a numbr between 0 and 13
    do
    {
        scanf("%d", &input);
    } while (input < 0 || input > 13);
 
        
    //Switch case for the input
    switch (input)
    {
    //Exit the program
    case 0:
        run = 0;
        break;

    // Get a story from the user and add it to the list word by word
    case 1:
    //option A
        // int wordsInStory = 0;
        // scanf("%d", &wordsInStory);
        // for (int i = 0; i < wordsInStory; i++)
        // {
        //     scanf("%s", word);
        //     StrList_insertLast(list, word);
        // }


    //option B
    // Get the number of words from the user
    int numWords;
    scanf("%d", &numWords);
    getchar();  // Consume the newline character left in the input buffer

    // Get the Story from the user
    char inputBuffer[1000];  // Adjust the size based on your needs
    fgets(inputBuffer, sizeof(inputBuffer), stdin);

    // Tokenize the input and add each word to the StrList
    char* token = strtok(inputBuffer, " \n");

    // Loop until there are no more tokens or the desired number of words is reached
    while (token != NULL && StrList_size(list) < (size_t)numWords) {
        StrList_insertLast(list, token);
        token = strtok(NULL, " \n");
    }
    
        break;


    // Get index and word from the user and add the word to the list at the given index
    case 2:
    //Scan the index and the word
    scanf("%d", &input);
    scanf("%s", word);

    StrList_insertAt(list, word, input);
        break;


    // Print the list
    case 3:
    StrList_print(list);
        break;
    

    // Print the size of the list
    case 4:
    printf("%ld\n", StrList_size(list));
        break;


    // Print the word at the given index
    case 5:
    scanf("%d", &input);
    StrList_printAt(list, input);
        break;
    

    // Print the number of characters in the list
    case 6:

    int overallsize = 0;
    size_t listSize = StrList_size(list);
    for (size_t i = 0; i < listSize; i++){
        overallsize += strlen(StrList_getData(list, i));
    }
    printf("%d\n", overallsize);
    break;


    // Print how many times the word appears in the list
    case 7:
    scanf("%s", word);
    printf("%d\n", StrList_count(list, word));
    break;


    // Get a Word and delete all the nodes containing the word
    case 8:
    scanf("%s", word);
    StrList_remove(list, word);
    break;


    // Get an index and delete the node at the given index
    case 9:
    scanf("%d", &input);
    StrList_removeAt(list, input);
    break;


    // Reverse the list
    case 10:
    StrList_reverse(list);
    break;


    // Free all the nodes in the list 
    case 11:
    while (StrList_size(list) > 0)
    {
        StrList_removeAt(list, 0);
    }
    break;


    // Sort the list in lexicographical order
    case 12:
    StrList_sort(list);
    break;


    // Print is sorted in lexicographical order
    case 13:
    if (StrList_isSorted(list))
    printf("true\n");
    else {printf("false\n");}
    break;
}







    }

    StrList_free(list);
    return 0;









}
/*
TODO: Check if in case 4 the size type is correct for the print function
TODO:  if you have freed everything you allocated
TODO:  every time uses "%ld\n" or Size_t cahck if it is correct
TODO:  fix delete


*/
