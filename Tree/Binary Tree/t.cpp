/*
- Simplified Data Encryption Standard (SDES)    		   

- A simplified version of the famous algorithm DES.                                                                         
- Author: Thiago O. Ribeiro		                                               
- January 2014															   
- Version 0.1    							   
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Global variables

char output[9];	// ciphertext
char key_tmp[11];	// used as intermediate  
char k1[9];		// subkey k1
char k2[9];		// subkey k2
char l[5];		
char r[5];
char binary_tmp[3]; 
char s0_box[4][4];
char s1_box[4][4];

// --------------------------------------------------
// -- Constants used for Permutation and Switching --
// --------------------------------------------------

const int IP[8] = 
{
	1, 5, 2, 0, 3, 7, 4, 6
};

const int IPI[8] = 
{
	3, 0, 2, 4, 6, 1, 7, 5
};

const int EP[8] = 
{
	3, 0, 1, 2, 1, 2, 3, 0
};

const int P4[4] =
{
	1, 3, 2, 0
};

const int P10[11] = 
{
	2, 4, 1, 6, 3, 9, 0, 8, 7, 5
};

const int P8[8] =
{
	5, 2, 6, 3, 7, 4, 9, 8
};

const int SW[8] =
{
	4, 5, 6, 7, 0, 1, 2, 3
};

// ------------------------------------------------
// ---		     Encryption Functions			---
// ------------------------------------------------

void initial_permutation(char *input)
{
	int i;

	for (i = 0; i < 8; i++) output[i] = input[IP[i]];
	output[8] = '\0';
}

void initial_permutation_inverse(char *input)
{
	char output_final[9];
	int i;

	for (i = 0; i < 8; i++) output_final[i] = input[IPI[i]];
	output_final[8] = '\0';

	strcpy(output, output_final);
}

void switch_halves(char *input)
{
	char out_tmp_switched[9];
	int i;

	for (i = 0; i < 8; i++) out_tmp_switched[i] = input[SW[i]];
	out_tmp_switched[8] = '\0';	
	
	strcpy(output, out_tmp_switched);
}

void expansion_permutation(char *input)
{
	int i;

	for (i = 0; i < 8; i++) output[i] = input[EP[i]];
	output[8] = '\0';
}

void p4_permutation(char *input)
{
	char F_output[5];
	int i;

	for (i = 0; i < 4; i++) F_output[i] = input[P4[i]];
	F_output[4] = '\0';	

	strcpy(output, F_output);
}

/*
	This function divides a 8-bit input
	into l (left) and r (right) with 
	4 bits each.
*/
void divide_block(char *output)
{	
	int i, j;

	for (i = 0; i < 4; i++) {
		l[i] = output[i];
	}
	l[i] = '\0';

	for (j = 0; j < 4; j++) {
		r[j] = output[i];
		i++;
	}
	r[j] = '\0';
}

int convert_to_decimal(char *str)
{
	if(strlen(str)!=2)
	return -1;

	if (strcmp(str,"00")==0)
	return 0;

	if (strcmp(str,"01")==0)
	return 1;

	if (strcmp(str,"10")==0)
	return 2;

	if (strcmp(str,"11")==0)
	return 3;

	return -1;
}

void convert_to_binary(int num, char *binary)
{
	if(num == 0)
	strcpy(binary,"00");

	if(num == 1)
	strcpy(binary,"01");

	if(num == 2)
	strcpy(binary,"10");

	if(num == 3)
	strcpy(binary,"11");
}

void xor(char *str1, char *str2)
{
	unsigned long int i;

	if (strlen(str1) != strlen(str2)) {
		printf("Error: xor operation does not support different string lengths.\n");
		exit(0);
	}

	for (i = 0; i < strlen(str1); i++) {
		if (str1[i] == str2[i]) {
			output[i] = '0';
		}
		else output[i] = '1';
	}
	output[i] = '\0';
}

void s0_items()
{
	int i, j, k = 0;
	int item[16] = {1, 0, 3, 2,
					3, 2, 1, 0,
					0, 2, 1, 3,
					3, 1, 3, 2};

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			s0_box[i][j] = item[k];
			k++;
		}
	}
}

void s1_items()
{
	int i, j, k = 0;
	int item[16] = {0, 1, 2, 3,
					2, 0, 1, 3,
					3, 0, 1, 0,
					2, 1, 0, 3};

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			s1_box[i][j] = item[k];
			k++;
		}
	}
}


/*
	Calculates the output for given sbox (0 or 1),
	returning a decimal number.
*/
int sbox_s(char *output, int i)
{
	char tmp[3];
	int row;
	int column;
	int s0;
	int s1;

	if (i == 0) {
		//sbox_s0
		tmp[0] = output[0];
		tmp[1] = output[3];
		tmp[2] = '\0';
		row = convert_to_decimal(tmp);
		tmp[0] = output[1];
		tmp[1] = output[2];
		tmp[2] = '\0';
		column = convert_to_decimal(tmp);
		s0_items();
		s0 = s0_box[row][column];
		return s0;
	} else	if (i == 1) {
		//sbox_s1
		tmp[0] = output[4];
		tmp[1] = output[7];
		tmp[2] = '\0';
		row = convert_to_decimal(tmp);
		tmp[0] = output[5];
		tmp[1] = output[6];
		tmp[2] = '\0';
		column = convert_to_decimal(tmp);
		s1_items();
		s1 = s1_box[row][column];
		return s1;
	} else return -1;
}

/*
	This mapping is an intermediate process
	between the input and subkey passed
	to the fk function
*/
void F_mapping(char *output, char *subkey)
{
	char binary[3];
	int s0;
	int s1;
	char output_sbox[5];

	divide_block(output);
	expansion_permutation(r);
	xor(output, subkey);

	s0 = sbox_s(output, 0);
	convert_to_binary(s0, binary);
	strcpy(output_sbox, binary);

	s1 = sbox_s(output, 1);
	convert_to_binary(s1, binary);
	strcat(output_sbox, binary);

	p4_permutation(output_sbox);
}

void fk(char *output, char *subkey)
{
	F_mapping(output, subkey);
	xor(l, output);
	strcat(output, r);
}

// ------------------------------------------------
// ---		   Keys Generation Functions		---
// ------------------------------------------------

void p10_key_permutation(char *key)
{
	int i; 

	for (i = 0; i < 10; i++) key_tmp[i] = key[P10[i]];
	key_tmp[10] = '\0';
}

void circular_left_shift(char *key_tmp)
{
	char temp = key_tmp[0];
	int i;

	for (i = 0; i < 5; i++) {
		key_tmp[i] = key_tmp[i+1];
	}	
	key_tmp[4] = temp;
	temp = key_tmp[5];
	for (i = 5 ; i < 10; i++) {
		key_tmp[i] = key_tmp[i+1];
	}	
	key_tmp[9] = temp;
}

void p8_key_permutation(char *key_tmp, int k)
{
	int i;
	if (k == 1) {
		for (i = 0; i < 8; i++) k1[i] = key_tmp[P8[i]];
		k1[8] = '\0';
	}
	else if(k == 2) {
		for (i = 0; i < 8; i++) k2[i] = key_tmp[P8[i]];
		k2[8] = '\0';	
	} else return;
}

void keys_generation(char *key)
{
	// generating k1
	p10_key_permutation(key);
	circular_left_shift(key_tmp);
	p8_key_permutation(key_tmp, 1);

	// generating k2
	circular_left_shift(key_tmp); 
	circular_left_shift(key_tmp); // repeated 
	p8_key_permutation(key_tmp, 2);
}

// ------------------------------------------------
// ---            Encrypt Function   			---
// ------------------------------------------------

void encrypt(char *input, char *key)
{
	initial_permutation(input);
	fk(output, k1);
	switch_halves(output);
	fk(output, k2);
	initial_permutation_inverse(output);
}

// ------------------------------------------------
// ---              Main Function   			---
// ------------------------------------------------

int main(int argc, char const *argv[])
{	
	char input[9];
	char key[11];
	int opt;

	do {
		printf("\nPlaintext (8-bit): ");
		scanf("%s", input);
	} while (strlen(input) != 8);	

	do {
		printf("Key (10-bit): ");
		scanf("%s", key);
	} while (strlen(key) != 10);

	keys_generation(key);
	encrypt(input, key);
	printf("Ciphertext (8-bit): %s\n", output);
	
	printf("\n");

	return 0;
}
