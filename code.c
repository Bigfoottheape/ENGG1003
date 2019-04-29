#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	<math.h>
#include	<conio.h>
#include	<dir.h>
#include 	<sys/stat.h>
struct stat st = {0};

#define COLOUR 	\033[1;35m
#define RESET	\033[0m

// A delay function used later in thre brute force program
void delay (unsigned int mseconds)
{
	for(mseconds; mseconds > 0; mseconds--)
	{
		for (unsigned i=0x200000; i--;);
	}
}

void main()
{
	

// Setting variables for the code
	char message[500], ch, input1[100], input2[100], filename[100], subfile[100], subfilecode[100], alpha[100], alphacode[100];
	int i, key=0, max, k, repeat = 1;
	char lowercase[26] = "abcdefghijklmnopqrstuvwxyz";
	char uppercase[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
while (repeat > 0)
{

// User inputs an option either rotate or substitute
system("@cls||clear");
	printf("===================================== \n");
	printf("Would you like to: \n \033[1;35mRotate\033[0m \n \033[1;35mSubstitute\033[0m \n");
	printf("===================================== \n");
	printf(" \n");
	printf("Answer: ");
	scanf("%s", input2);

// If no input matches rotate or substitute, the user will keep being prompted until either of those strings is entered
while ((strcmp(input2, "rotate") != 0) && (strcmp(input2, "substitute")!= 0))
{
	system("@cls||clear");
	printf("===================================== \n");
	printf("Would you like to: \n \033[1;35mRotate\033[0m \n \033[1;35mSubstitute\033[0m \n");
	printf("===================================== \n");
	printf(" \n");
	printf("Answer: ");
	scanf("%s", input2);
}

///////////////////////////////////////////////////////////////////////////////////////////////
// START OF ROTATE //
if (strcmp(input2, "rotate")== 0)
		{

// Clear command window and takes a Menu Input
	system("@cls||clear");
	printf("===================================== \n");
	printf("Would you like to: \n \033[1;35mEncrypt\033[0m \n \033[1;35mDecrypt\033[0m \n \033[1;35mBrute\033[0m \n");
	printf("===================================== \n");
	printf(" \n");
	printf("Answer: ");
	scanf("%s", input1);
	
//Either Encrypt or Decrypt depending on user input
while ((strcmp(input1, "encrypt") != 0) && (strcmp(input1, "decrypt")!= 0) && (strcmp(input1, "brute")!= 0))
{
	// Clear command window and takes a Menu Input
	system("@cls||clear");
	printf("===================================== \n");
	printf("Would you like to: \n \033[1;35mEncrypt\033[0m \n \033[1;35mDecrypt\033[0m \n \033[1;35mBrute\033[0m \n");
	printf("===================================== \n");
	printf(" \n");
	printf("Answer: ");
	scanf("%s", input1);
}


	if (strcmp(input1, "encrypt")== 0)
		{
	
	// Encryption	
	// Clears the command window for a cleaner UI
		system("@cls||clear");
	// User inputs a plain text string
		printf("===================================== \n");
		printf("Enter a message to \033[1;35mencrypt\033[0m: \n");
		printf("===================================== \n");
		printf(" \n");
		printf("Plaintext: ");
		scanf(" %100[^\n]", message);
		
		system("@cls||clear");
		printf("===================================== \n");
	// User inputs a key for rotations
		printf("Enter key: \n");
		printf("===================================== \n");
		printf(" \n");
		printf("Plaintext: ");
		scanf(" %d", &key);
	
	// Asks the user what file name to give to the file with
	// the encrypted message
		system("@cls||clear");
		printf("===================================== \n");
		printf("Enter the file name to \033[1;35mencrypt\033[0m: \n");
		printf("===================================== \n");
		printf("\n");
		printf("File name (add.txt):");
		scanf(" %100[^\n]", filename);
	
	// Takes every seperate character through [1] and rotates as per the key
	// Will repeat until ever character in the string has been rotated by the specified key
	// Checks to make sure that the string character for each value is a real ascii values
	// If not will move to the else if statement
	for(i = 0; message[i] != '\0'; i++)
	{
		for (k = 0; key >= k; k++)
		{
		ch = message[i];
		
		if (ch >= 'A' && ch < 'Z')
		{
			ch++;
		}
		else if (ch >= 'a' && ch < 'z')
		{
			ch++;
		}
		else if (ch == 'Z')
		{
			ch = 'a';
		}
		else if (ch == 'z')
		{
			ch = 'A';
		}
		message[i] = ch;
		}
	
	}
	printf("Encrypted message: %s", message);
	
	// Opens a new file with the name entered previously and write the ecrypted message to it as text.
	// Then closes the file
	FILE *f;
	f = fopen(filename,"w+");
	fprintf(f,"%s",message);
	fclose(f);
		printf("\n");
		printf("\n");
		printf("\033[1;35m(0) - Quit\033[0m: \n");
		printf("\033[1;35m(1) - Retry\033[0m: \n");
		scanf(" %d", &repeat);
}

	else if (strcmp(input1, "decrypt")== 0)
	{
		
	// Decryption
	// Clears the command window for a cleaner UI
		system("@cls||clear");
	// Enters the filename of the decrypted file tp decrypt
		printf("===================================== \n");
		printf("Enter the file name to \033[1;35mdecrypt\033[0m: \n");
		printf("===================================== \n");
		printf("\n");
		printf("File name (add.txt):");
		scanf(" %100[^\n]", filename);
	
	// Repeats the promt until a file is located
		while (stat(filename, &st) == -1)
		{
		system("@cls||clear");
		printf("===================================== \n");
		printf("Enter the file name to \033[1;35mdecrypt\033[0m: \n");
		printf("===================================== \n");
		printf("\n");
		printf("File name (add.txt):");
		scanf(" %100[^\n]", filename);
		}
	
	// Opens the file and reads the decrypted message and assigns to message variable
		FILE *f;
		f = fopen(filename,"r");
		fgets(message, 100, f);	
 
	// User inputs the key for the amount of rotations in the rotation cypher
		system("@cls||clear");
		printf("===================================== \n");
		printf("\033[1;35mEnter key:\033[0m: \n");
		printf("===================================== \n");
		printf("\n");
		printf("Key:");
		scanf(" %d", &key);

	for(i = 0; message[i] != '\0'; i++)
	{
		for (k = 0; key >= k && (message[i] != '\0'); k++)
		{
		ch = message[i];
		
		if (ch > 'A' && ch <= 'Z')
		{
			ch--;
		}
		else if (ch > 'a' && ch <= 'z')
		{
			ch--;
		}
		else if (ch == 'a')
		{
			ch = 'Z';
		}
		else if (ch == 'A')
		{
			ch = 'z';
		}
		message[i] = ch;
		}
		printf("Decrypted message: %s", message);
		
		printf("\n");
		printf("\n");
		printf("\033[1;35m(0) - Quit\033[0m: \n");
		printf("\033[1;35m(1) - Retry\033[0m: \n");
		scanf(" %d", &repeat);
	}
}
	else if (strcmp(input1, "brute")== 0)
	{
	
	// Selects a encrypted rotation cypher file through user input of the file name
		system("@cls||clear");
		printf("===================================== \n");
		printf("Enter the file name to \033[1;35mBrute force\033[0m: \n");
		printf("===================================== \n");
		printf("\n");
		printf("File name (add.txt):");
		scanf(" %100[^\n]", filename);
		
	// Repeats until a legitamate file has been located	
		while (stat(filename, &st) == -1)
		{
		system("@cls||clear");
		printf("===================================== \n");
		printf("Enter the file name to \033[1;35mBrute force\033[0m: \n");
		printf("===================================== \n");
		printf("\n");
		printf("File name (add.txt):");
		scanf(" %100[^\n]", filename);
		}
	// Opens the file as entered above and assigns the encrypted message to the message variable
		FILE *f;
		f = fopen(filename,"r");
		fgets(message, 500, f);
		fclose(f);		
		
	// Prompts the user on how many times they want to rotate the brute force for (key)
		max = 1;
		do {
		system("@cls||clear");
		printf("===================================== \n");
		printf("Enter the amount of times you want to \033[1;35mBrute force\033[0m for: \n");
		printf("===================================== \n");
		printf("Times: ");
		scanf(" %d", &max);
		} while (max < 0);
		
	// Standard rotation decryption repeated for keys 1-(user selected)
for (key = 0; (max >= key) ; key = key + 1)
{	
	for(i = 0; message[i] != '\0'; i++)
	{		
		ch = message[i];
		
		if (ch > 'A' && ch <= 'Z')
		{
			ch--;
		}
		else if (ch > 'a' && ch <= 'z')
		{
			ch--;
		}
		else if (ch == 'a')
		{
			ch = 'Z';
		}
		else if (ch == 'A')
		{
			ch = 'z';
		}
		message[i] = ch;
		}
		// Prints the decrypted message along with the current key, with a delay between each print.
		printf("Decrypted message: %s \n", message);
		printf("Key: %d \n", key);
		printf("\n");
		delay(15);
		
		printf("\n");
		printf("\n");
		printf("\033[1;35m(0) - Quit\033[0m: \n");
		printf("\033[1;35m(1) - Retry\033[0m: \n");
		scanf(" %d", &repeat);
	}
	}
}
// END OF ROTATE //
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////
// START OF SUBSTITUTE //
if ((strcmp(input2, "substitute")== 0) || (strcmp(input2, "sub")== 0))
{
	// Clear command window and takes a Menu Input
	system("@cls||clear");
	printf("===================================== \n");
	printf("Would you like to: \n \033[1;35mEncrypt\033[0m \n \033[1;35mDecrypt\033[0m \n \033[1;35mSpecial\033[0m \n");
	printf("===================================== \n");
	printf(" \n");
	printf("Answer: ");
	scanf("%s", input1);

	// Repeats the action until a correct input is entered
	while ((strcmp(input1, "encrypt") != 0) && (strcmp(input1, "decrypt")!= 0) && (strcmp(input1, "special")!= 0))
	{
	// Clear command window and takes a Menu Input
	system("@cls||clear");
	printf("===================================== \n");
	printf("Would you like to: \n \033[1;35mEncrypt\033[0m \n \033[1;35mDecrypt\033[0m \n \033[1;35mSpecial\033[0m \n");
	printf("===================================== \n");
	printf(" \n");
	printf("Answer: ");
	scanf("%s", input1);
	}

	// Runs below statement for "encrypt" string entered
	if (strcmp(input1, "encrypt")== 0)
		{
		system("@cls||clear");
		printf("===================================== \n");
		printf("Enter the file name to \033[1;35mEncrypt\033[0m: \n");
		printf("===================================== \n");
		printf("\n");
		printf("File name (add.txt):");
		scanf(" %100[^\n]", alphacode);
		
		// Repeats until a valid file is found
		while (stat(alphacode, &st) == -1)
		{
		system("@cls||clear");
		printf("===================================== \n");
		printf("Enter the file name to \033[1;35mEncrypt\033[0m: \n");
		printf("===================================== \n");
		printf("\n");
		printf("File name (add.txt):");
		scanf(" %100[^\n]", alphacode);
		}
		// Opens file with filename and retrieves message as message alpha variable.
		FILE *f;
		f = fopen(alphacode,"r");
		fgets(alpha, 100, f);
		fclose(f);
		
		// Asks the user for the file name of the encrypted alphabet 
		system("@cls||clear");
		printf("===================================== \n");
		printf("Enter the file name of the \033[1;35mEncrypted Key\033[0m: \n");
		printf("===================================== \n");
		printf("\n");
		printf("File name (add.txt):");
		scanf(" %100[^\n]", subfile);
		
		while (stat(subfile, &st) == -1)
		{
		system("@cls||clear");
		printf("===================================== \n");
		printf("Enter the file name of the \033[1;35mEncrypted Key\033[0m: \n");
		printf("===================================== \n");
		printf("\n");
		printf("File name (add.txt):");
		scanf(" %100[^\n]", subfile);
		}
		// Opens the file for the encrypted key
		f = fopen(subfile,"r");
		fgets(subfilecode, 100, f);
		fclose(f);
		
		// Below program takes the first value of the encrypted alphabet and replaces it for the first value of the regular alphabet (A)
		// This repeats for each value of the alphabet so that all values from the encrypted key replace the subsequent values of the message.
		for (int n=0; alpha[n] != '\0'; n++)
		{
			 if (alpha[n] == 'a' || alpha[n] == 'A') {alpha[n] = subfilecode[0];}
		else if (alpha[n] == 'b' || alpha[n] == 'B') {alpha[n] = subfilecode[1];}
		else if (alpha[n] == 'c' || alpha[n] == 'C') {alpha[n] = subfilecode[2];}
		else if (alpha[n] == 'd' || alpha[n] == 'D') {alpha[n] = subfilecode[3];}
		else if (alpha[n] == 'e' || alpha[n] == 'E') {alpha[n] = subfilecode[4];}
		else if (alpha[n] == 'f' || alpha[n] == 'E') {alpha[n] = subfilecode[5];}
		else if (alpha[n] == 'g' || alpha[n] == 'G') {alpha[n] = subfilecode[6];}
		else if (alpha[n] == 'h' || alpha[n] == 'H') {alpha[n] = subfilecode[7];}
		else if (alpha[n] == 'i' || alpha[n] == 'I') {alpha[n] = subfilecode[8];}
		else if (alpha[n] == 'j' || alpha[n] == 'J') {alpha[n] = subfilecode[9];}
		else if (alpha[n] == 'k' || alpha[n] == 'K') {alpha[n] = subfilecode[10];}
		else if (alpha[n] == 'l' || alpha[n] == 'L') {alpha[n] = subfilecode[11];}
		else if (alpha[n] == 'm' || alpha[n] == 'M') {alpha[n] = subfilecode[12];}
		else if (alpha[n] == 'n' || alpha[n] == 'N') {alpha[n] = subfilecode[13];}
		else if (alpha[n] == 'o' || alpha[n] == 'O') {alpha[n] = subfilecode[14];}
		else if (alpha[n] == 'p' || alpha[n] == 'P') {alpha[n] = subfilecode[15];}
		else if (alpha[n] == 'q' || alpha[n] == 'Q') {alpha[n] = subfilecode[16];}
		else if (alpha[n] == 'r' || alpha[n] == 'R') {alpha[n] = subfilecode[17];}
		else if (alpha[n] == 's' || alpha[n] == 'S') {alpha[n] = subfilecode[18];}
		else if (alpha[n] == 't' || alpha[n] == 'T') {alpha[n] = subfilecode[19];}
		else if (alpha[n] == 'u' || alpha[n] == 'U') {alpha[n] = subfilecode[20];}
		else if (alpha[n] == 'v' || alpha[n] == 'V') {alpha[n] = subfilecode[21];}
		else if (alpha[n] == 'w' || alpha[n] == 'W') {alpha[n] = subfilecode[22];}
		else if (alpha[n] == 'x' || alpha[n] == 'X') {alpha[n] = subfilecode[23];}
		else if (alpha[n] == 'y' || alpha[n] == 'Y') {alpha[n] = subfilecode[24];}
		else if (alpha[n] == 'z' || alpha[n] == 'Z') {alpha[n] = subfilecode[25];}
		else if (alpha[n] == 32) {alpha[n] = 32;}
		}
		
		system("@cls||clear");
		printf("Encrypted Message: %s \n", alpha);
	// Saves the encrypted substitute message in the subencrypt.txt file
	f = fopen("subencrypt.txt","w+");
	fprintf(f,"%s",alpha);
	fclose(f);
	
	printf("\n");
	printf("\n");
	printf("\033[1;35m(0) - Quit\033[0m: \n");
	printf("\033[1;35m(1) - Retry\033[0m: \n");
	scanf(" %d", &repeat);
	}
	
	if (strcmp(input1, "decrypt")== 0)
		{
		system("@cls||clear");
		printf("===================================== \n");
		printf("Enter the file name to \033[1;35mDecrypt\033[0m: \n");
		printf("Default \033[1;35msubencrypt.txt\033[0m: \n");
		printf("===================================== \n");
		printf("\n");
		printf("File name (add.txt):");
		scanf(" %100[^\n]", alphacode);
		
		while (stat(alphacode, &st) == -1)
		{
		system("@cls||clear");
		printf("===================================== \n");
		printf("Enter the file name to \033[1;35mDecrypt\033[0m: \n");
		printf("===================================== \n");
		printf("\n");
		printf("File name (add.txt):");
		scanf(" %100[^\n]", alphacode);
		}
		
		FILE *f;
		f = fopen(alphacode,"r");
		fgets(alpha, 100, f);
		fclose(f);
		
		system("@cls||clear");
		printf("===================================== \n");
		printf("Enter the file name of the \033[1;35mEncrypted Key\033[0m: \n");
		printf("===================================== \n");
		printf("\n");
		printf("File name (add.txt):");
		scanf(" %100[^\n]", subfile);
		
		while (stat(subfile, &st) == -1)
		{
		system("@cls||clear");
		printf("===================================== \n");
		printf("Enter the file name of the \033[1;35mEncrypted Key\033[0m: \n");
		printf("===================================== \n");
		printf("\n");
		printf("File name (add.txt):");
		scanf(" %100[^\n]", subfile);
		}
		
		f = fopen(subfile,"r");
		fgets(subfilecode, 100, f);
		fclose(f);
		
		for (int n=0; alpha[n] != '\0'; n++)
		{
		     if (alpha[n] == subfilecode[0]) {alpha[n] = 'a';}
		else if (alpha[n] == subfilecode[1]) {alpha[n] = 'b';}
		else if (alpha[n] == subfilecode[2]) {alpha[n] = 'c';}
		else if (alpha[n] == subfilecode[3]) {alpha[n] = 'd';}
		else if (alpha[n] == subfilecode[4]) {alpha[n] = 'e';}
		else if (alpha[n] == subfilecode[5]) {alpha[n] = 'f';}
		else if (alpha[n] == subfilecode[6]) {alpha[n] = 'g';}
		else if (alpha[n] == subfilecode[7]) {alpha[n] = 'h';}
		else if (alpha[n] == subfilecode[8]) {alpha[n] = 'i';}
		else if (alpha[n] == subfilecode[9]) {alpha[n] = 'j';}
		else if (alpha[n] == subfilecode[10]) {alpha[n] = 'k';}
		else if (alpha[n] == subfilecode[11]) {alpha[n] = 'l';}
		else if (alpha[n] == subfilecode[12]) {alpha[n] = 'm';}
		else if (alpha[n] == subfilecode[13]) {alpha[n] = 'n';}
		else if (alpha[n] == subfilecode[14]) {alpha[n] = 'o';}
		else if (alpha[n] == subfilecode[15]) {alpha[n] = 'p';}
		else if (alpha[n] == subfilecode[16]) {alpha[n] = 'q';}
		else if (alpha[n] == subfilecode[17]) {alpha[n] = 'r';}
		else if (alpha[n] == subfilecode[18]) {alpha[n] = 's';}
		else if (alpha[n] == subfilecode[19]) {alpha[n] = 't';}
		else if (alpha[n] == subfilecode[20]) {alpha[n] = 'u';}
		else if (alpha[n] == subfilecode[21]) {alpha[n] = 'v';}
		else if (alpha[n] == subfilecode[22]) {alpha[n] = 'w';}
		else if (alpha[n] == subfilecode[23]) {alpha[n] = 'x';}
		else if (alpha[n] == subfilecode[24]) {alpha[n] = 'y';}
		else if (alpha[n] == subfilecode[25]) {alpha[n] = 'z';}
		else if (alpha[n] == 32) {alpha[n] = 32;}
		}
		system("@cls||clear");
		printf("Encrypted Message: %s \n", alpha);
		
		f = fopen("subdecrypt.txt","w+");
		fprintf(f,"%s",alpha);
		fclose(f);
		
		printf("\n");
		printf("\n");
		printf("\033[1;35m(0) - Quit\033[0m: \n");
		printf("\033[1;35m(1) - Retry\033[0m: \n");
		scanf(" %d", &repeat);
		}
		
		if (strcmp(input1, "special")== 0)
		{
			   char string[100];
				int c = 0, count[26] = {0}, x;
 
				printf("Enter a string\n");
				scanf(" %100[^\n]", string);
 
				while (string[c] != '\0') 
				{
		/** Considering characters from 'a' to 'z' only and ignoring others. */
 
				if (string[c] >= 'a' && string[c] <= 'z') 
				{
				x = string[c] - 'a';
				count[x]++;
				}
 
				c++;
				}
 
				for (c = 0; c < 26; c++)
				printf("%c occurs %d times in the string.\n", c + 'a', count[c]);
				printf("\n");
				printf("\n");
				printf("\033[1;35m(0) - Quit\033[0m: \n");
				printf("\033[1;35m(1) - Retry\033[0m: \n");
				scanf(" %d", &repeat);
 
		}
		}	
	}
}


// END OF SUBSTITUTE //
///////////////////////////////////////////////////////////////////////////////////////////////
int freq()
{
   char string[100];
   int c = 0, count[26] = {0}, x;
 
   printf("Enter a string\n");
   gets(string);
 
   while (string[c] != '\0') {
   /** Considering characters from 'a' to 'z' only and ignoring others. */
 
      if (string[c] >= 'a' && string[c] <= 'z') {
         x = string[c] - 'a';
         count[x]++;
      }
 
      c++;
   }
 
   for (c = 0; c < 26; c++)
         printf("%c occurs %d times in the string.\n", c + 'a', count[c]);
 
   return 0;
}


/////////////////////////////////////////////////////////////////////////


