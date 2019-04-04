#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
void main()
{
// Setting variables for the code
	char message[100], ch, input1[100], input2[100];
	int i, key;
	
// Clear command window and takes a Menu Input
	system("@cls||clear");
	printf("====================================== \n");
	printf("Would you like to encrypt or decrypt: \n");
	printf("====================================== \n");
	printf(" \n");
	printf("Answer: ");
	scanf("%s", input1);
	
//Either Encrypt or Decrypt depending on user input
	
	if (strcmp(input1, "encrypt")== 0)
	{
	
	// Encryption	
	// User inputs a plain text string
	// Clears the command window for a cleaner UI
	system("@cls||clear");
	printf("Enter a message to encrypt: ");
	scanf(" %100[^\n]", message);
	// User inputs a key for rotations
	printf("Enter key: ");
	scanf(" %d", &key);
	
	// Takes every seperate character through [1] and rotates as per the key
	// 
		for(i = 0; message[i] != '\0'; ++i){
		ch = message[i];
		
		// Checks to make sure that the string character for each value is between a and z
		// If not will move to the else if statement
		if(ch >= 'a' && ch <= 'z')
		{
			// New ascii value = old ascii value + key rotations
			// This will allow each character to be encrypted into another character through ascii
			ch = ch + key;
			
			if(ch > 'z')
			{
				ch = ch - 'z' + 'a' - 1;
			}
			
			message[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z')
		{
			ch = ch + key;
			
			if(ch > 'Z')
			{
				ch = ch - 'Z' + 'A' - 1;
			}
			
			message[i] = ch;
		}
	}
	
	printf("Encrypted message: %s", message);
	}


	else if (strcmp(input1, "decrypt")== 0)
	{
		
	// Decryption
	// Clears the command window for a cleaner UI
	system("@cls||clear");
	printf("Enter a message to decrypt: ");
	scanf(" %100[^\n]", message);
	printf("Enter key: ");
	scanf(" %d", &key);
	
	for(i = 0; message[i] != '\0'; ++i){
		ch = message[i];
		
		if(ch >= 'a' && ch <= 'z')
		{
			ch = ch - key;
			
			if(ch < 'a')
			{
				ch = ch + 'z' - 'a' + 1;
			}
			
			message[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z')
		{
			ch = ch - key;
			
			if(ch < 'A')
			{
				ch = ch + 'Z' - 'A' + 1;
			}
			
			message[i] = ch;
		}
	}
	
	printf("Decrypted message: %s", message);
	
	}
}
