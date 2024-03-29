/*
	CCPROG2 MP1 SOURCE CODE

	Do not forget to encode your name, section and date of submission.

	LASTNAME1, FIRSTNAME1: AQUINO, Bon Windel E.                              SECTION1: S11A
	LASTNAME2, FIRSTNAME2: SILVA, Paulo Grane Gabriel C.                      SECTION2: S12A

	DATE SUBMITTED     : March XXXXX, 2024

	Rename this file using your last names in alphabetical order, for example CRUZ_TAN.c

	Make sure to compile your C source code with a -Wall directive.
	   Example: CCPROG2> gcc -Wall LASTNAME1_LASTNAME2.c

	Fix all warnings.  Do NOT run the program if you still have a warning.  You must have
	0 error, 0 warning before running the program.

	Run the resulting a.exe file in the command line with input and output (I/O) redirection.
	   Example: a < SoGA_DATASET.TXT > OUTPUT_LASTNAME1_LASTNAME2.TXT

*/

#include <stdio.h>
#include <string.h>
#include "AQUINO_SILVA.h"
#define MAX_ROWS 203
/* Do NOT include other header files. */

/*
	HARD REQUIREMENTS: NON-COMPLIANCE WILL MAKE YOUR SOLUTION INCORRECT or CAUSE POINT DEDUCTIONS!

	1. You must apply arrays and strings in MP Part 1 (MP1).
	2. Document your codes with SENSIBLE comments.
	3. Use double data type (not float) for all floating point
	   values/variables/functions/return type
	4. Do NOT use any global variables.
	5. Do NOT call printf() except inside the main() function.
	6. Do NOT use the following yet this MP.
		a. struct data type
		b. file processing functions such as fopen(), fclose(), etc.
	7. Do NOT use library functions that were NOT discussed in our class.
 */

 /*
	 You may declare any typedef that you need below this comment.
 */

typedef char string[50]; //32 highest string length in data provided but for buffer just set 50 as size

/*
	Define any function that you need below this comment.

	The following should be included as comments and appear BEFORE EACH function definition:
	   a. Purpose: describe succintly what the function is supposed to accomplish.
	   b. Parameters: describe succintly the nature/purpose of each parameter.
	   c. Return type: if the function is not void, describe succintly what it will return as a result.

	For functions that serve as answers to the questions, include the following as comments
	BEFORE the function definition itself:
	   a. Question number, and the actual question.
	   b. Thereafter, type the answer number, and the corresponding expected answer.

	For example:
	  Q1:  Which country has the lowest baseline life expectancy?
	  A1:  Lesotho

	Document the body of the function by including comments alongside codes that you think
	may not be easy to understand to the person reading the codes.
*/

/* <<<<<<<<<<FUNCTION HEADER COMMENT>>>>>>>>>>>
	a. Purpose: This function retrieves the dataset fed/provided to it by using the scan function to get values.
	b. Parameters: The parameters serve as the dataset's parameter risk factors (while also including the location and the Base Life Expectancy)
	c. Return type: This function returns an integer value which indicates how many rows of values were retrieved and scanned
*/
int
getDataSet(dataSetStruct territory[], FILE *fp_source)
{
	int rowsOfData = 0, currentRow = 0;
	while (fscanf(fp_source, " %s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", 
		territory[currentRow].name, 
		&territory[currentRow].baseLE, &territory[currentRow].airPollution, &territory[currentRow].ambientPM, &territory[currentRow].ozone, 
		&territory[currentRow].HAP, &territory[currentRow].environ, &territory[currentRow].occup, &territory[currentRow].unsafeWash, 
		&territory[currentRow].metabolic, &territory[currentRow].dietary, &territory[currentRow].plasma, &territory[currentRow].tobacco, 
		&territory[currentRow].smoking, &territory[currentRow].secondhandSmoke, &territory[currentRow].unsafeSex) == 16)
	{
		currentRow++;
		rowsOfData++;
	}
	return rowsOfData;
}

void
printDataSet(dataSetStruct territory[], int rowsOfData, FILE *fp_dest)
{
	for (int currentRow = 0; currentRow < rowsOfData; currentRow++)
	{
		fprintf(fp_dest, "\n\t%s \t%.6lf \t%.6lf \t%.6lf \t%.6lf \t%.6lf \t%.6lf \t%.6lf \t%.6lf \t%.6lf \t%.6lf \t%.6lf \t%.6lf \t%.6lf \t%.6lf \t%.6lf\n", territory[currentRow].name, territory[currentRow].baseLE, territory[currentRow].airPollution, territory[currentRow].ambientPM, territory[currentRow].ozone, territory[currentRow].HAP, territory[currentRow].environ, territory[currentRow].occup, territory[currentRow].unsafeWash, territory[currentRow].metabolic, territory[currentRow].dietary, territory[currentRow].plasma, territory[currentRow].tobacco, territory[currentRow].smoking, territory[currentRow].secondhandSmoke, territory[currentRow].unsafeSex);
	}
}

void
indexSetter(string indexLabel, int index)
{
	switch (index)
	{
	case 0:
		strcpy(indexLabel, "base life expectancy");
		break;
	case 1:
		strcpy(indexLabel, "air pollution");
		break;
	case 2:
		strcpy(indexLabel, "ambient PM");
		break;
	case 3:
		strcpy(indexLabel, "ozone");
		break;
	case 4:
		strcpy(indexLabel, "HAP");
		break;
	case 5:
		strcpy(indexLabel, "environ");
		break;
	case 6:
		strcpy(indexLabel, "occup");
		break;
	case 7:
		strcpy(indexLabel, "unsafeWash");
		break;
	case 8:
		strcpy(indexLabel, "metabolic");
		break;
	case 9:
		strcpy(indexLabel, "dietary");
		break;
	case 10:
		strcpy(indexLabel, "plasma");
		break;
	case 11:
		strcpy(indexLabel, "tobacco");
		break;
	case 12:
		strcpy(indexLabel, "smoking");
		break;
	case 13:
		strcpy(indexLabel, "second hand smoke");
		break;
	case 14:
		strcpy(indexLabel, "unsafe sex");
		break;
	}
}

/* <<<<<<<<<<FUNCTION HEADER COMMENT>>>>>>>>>>>
	a. Purpose: This function uses a linear search algorithm in attempting to find if a given string is present in the provided dataset
	b. Parameters: string arrString[] is the general dataset or the array of strings where key will be performed a linear search upon. string key is the string that the algorithm is trying to find. n is the number of values in the array dataset.
	c. Return type:
*/
int
linearSearchString(string arrString[], string key, int n)
{
	for (int i = 0; i < n; i++)
		if (strcmp(arrString[i], key) == 0)
			return i;
	return -1;
}

/* <<<<<<<<<<FUNCTION HEADER COMMENT>>>>>>>>>>>
	a. Purpose: This function utilizes a selectionSort algorithm to sort an array of type double.
	b. Parameters: double arrDouble[] is the general array dataset that is trying to be sorted. int n indicates the number of elements in the provided dataset.
*/
void
selectionSortDouble(double arrDouble[], int n)
{
	double temp = 0;
	int max = 0;
	for (int i = 0; i < n - 1; i++)
	{
		max = i;
		for (int j = i + 1; j < n; j++)
			if (arrDouble[max] < arrDouble[j])
				max = j;

		if (max != i)
		{
			temp = arrDouble[i];
			arrDouble[i] = arrDouble[max];
			arrDouble[max] = temp;
		}
	}
}

/* <<<<<<<<<<FUNCTION HEADER COMMENT>>>>>>>>>>>
	a. Purpose: This function resets the contents of an array
	b. Parameters: string array[] contains the dataset that we want to reset. int n contains the number of elements in the given dataset.
*/
void
stringArrayResetter(string array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		strcpy(array[n], "\0");
	}
}

/* <<<<<<<<<<FUNCTION HEADER COMMENT>>>>>>>>>>>
	a. Purpose: This function is used to answer Question 1 by checking the users' options and thereby comparing numbers to see if the condition is met and how many countries have met the condition provided.
	b. Parameters: This function uses location - countries that qualify the condition are copied into an array found in main.
					Other parameters are the general self-explanatory param_risk_factor which are selected by the user and used as filters or conditions
					int rowsOfData contains the number of data in the given dataset
					double number is the number being compared with a country's param_risk_factor
					string qualifiedterritories[] is the array where qualifying countries will be stored
					string parameter is the selected and specified parameter_risk_factor used as filter/condition
					string option is the selected option or operator - greater than or less than

	c. Return type: this function returns an integer which indicate how many countries qualified given the conditions.

	a. Q1: What is the highest average loss of life expectancy among all risk factors? Display the value and the name of the risk factor. 
	b. A1: 5.77 years (Metabolic risk factor)

*/
int
Q1(dataSetStruct territory[], int rowsOfData, double *highestAverage)
{
	int max = 0;
	double averagedDataSet[14] = {0};

	for (int f = 0; f < rowsOfData; f++)
	{
		averagedDataSet[0] += ((territory[f].airPollution) / rowsOfData);
		averagedDataSet[1] += ((territory[f].ambientPM) / rowsOfData);
		averagedDataSet[2] += ((territory[f].ozone) / rowsOfData);
		averagedDataSet[3] += ((territory[f].HAP) / rowsOfData);
		averagedDataSet[4] += ((territory[f].environ) / rowsOfData);
		averagedDataSet[5] += ((territory[f].occup) / rowsOfData);
		averagedDataSet[6] += ((territory[f].unsafeWash) / rowsOfData);
		averagedDataSet[7] += ((territory[f].metabolic) / rowsOfData);
		averagedDataSet[8] += ((territory[f].dietary) / rowsOfData);
		averagedDataSet[9] += ((territory[f].plasma) / rowsOfData);
		averagedDataSet[10] += ((territory[f].tobacco) / rowsOfData);
		averagedDataSet[11] += ((territory[f].smoking) / rowsOfData);
		averagedDataSet[12] += ((territory[f].secondhandSmoke) / rowsOfData);
		averagedDataSet[13] += ((territory[f].unsafeSex) / rowsOfData);
	}

	for (int g = 1; g < 13; g++)
		if (averagedDataSet[max] < averagedDataSet[g + 1])
			max = g + 1;

	*highestAverage = (averagedDataSet[max]);
	return max+1;
}

/* <<<<<<<<<<FUNCTION HEADER COMMENT>>>>>>>>>>>
	a. Purpose: This function answers Q2 by handling assignment operations with pointers and arrays.
	b. Parameters: This function is 'overloaded' with parameters. It takes the variables' addresses from main so that it can modify it while also taking values from param_risk_factors in main.

	Q2: What is the overall reduction in life expectancy in <parameter-territory> as a result of smoking-related risk factors (tobacco, smoking, and secondhand smoke)? [algorithm(s): linear search or binary search, sum]

	A2: Case 1: <parameter-territory> = Gambia
		  2.13 years
	
		Case 2: <parameter-territory> = Samoa
			  6.25 years

		Case 3: <parameter-territory> = Australasia
			  Invalid input. Name of the territory is not included in the dataset.
*/

int 
territoryIndexFinder(dataSetStruct territory[], int rowsOfData, string territoryName)
{
	for (int i = 0; i < rowsOfData; i++)
		if (strcmp(territory[i].name, territoryName) == 0)
			return i;

	return -1;
}

double 
Q2(dataSetStruct territory[], int rowsOfData, int index)
{
	int i;
	double sumSmoking = 0;
	
	dataSetStruct *ptr[rowsOfData];
	
	for(i = 0; i < rowsOfData; i++)
		ptr[i] = &territory[i];

	sumSmoking += ptr[index]->tobacco + ptr[index]->smoking + ptr[index]->secondhandSmoke;
	
	return sumSmoking;
}


/* <<<<<<<<<<FUNCTION HEADER COMMENT>>>>>>>>>>>
	a. Purpose: This function is used to answer Question 3 by modifying the array found in main and assigning the correct values to them.
	b. Parameters: This function uses location - countries that qualify the condition are copied into an array found in main.
					Other parameters are the general self-explanatory param_risk_factor which are selected by the user and used as filters or conditions
					int rowsOfData contains the number of data in the given dataset
					double countryStats is the array that the function is modifying and storing correct values in

	Q3: Which territory has their life expectancy shortened the least due to occupational hazards? [algorithm(s): minimum]

	A3: Saint Vincent and the Grenadines
*/
int
Q3(dataSetStruct territory[], int rowsOfData)
{
	int min = 0;

	for(int i = 0; i < rowsOfData; i++)
		if (territory[min].occup > territory[i].occup)
			min = i;

	return min;
}


/* <<<<<<<<<<FUNCTION HEADER COMMENT>>>>>>>>>>>
	a. Purpose: This function uses selection sort to find the territories with top highest base LE and determines their
				greatest risk factor along with its value. All values are stored in arrays.
	b. Parameters: 	territory[] is the array containing the SoGA Dataset
					terrList[] is the array containing the countries with top <number> highest base LE
					maxRisk[] is the array containing the names of the greatest risk factors of the territores in terrList[]
					maxRiskVal[] is the array containing the values of the greatest risk factors in maxRisk[]
					rowsOfData is the rows of data
					num is the number of countries to be listed
	c. Return type:	An integer value is returned to indicate if program executed properly or if input is invalid
*/

int Q4(dataSetStruct territory[], dataSetStruct terrList[], string maxRisk[],
		double maxRiskVal[], int rowsOfData, int num) {
	int i, j, k, max;
	double maxVal;
	dataSetStruct temp;
	dataSetStruct tempTerritory[rowsOfData];
	
	// Copy original array of structs into temporary array
	if(strcmp(territory[0].name, "Global") == 0) {
		for(i = 1; i < rowsOfData; i++) {
			tempTerritory[i] = territory[i];
			rowsOfData--;
		}
	}
	else {
		for(i = 0; i < rowsOfData; i++) {
			tempTerritory[i] = territory[i];
		}
	}
	
	// Indicate if user input is invalid
	if(num < 0)
		return -1;
	
	// Arrange the array of structs in decreasing value of base LE
	else {
		for(i = 0; i < rowsOfData - 1; i++) {
			max = i;
			
			for(j = i + 1; j < rowsOfData; j++)
				if(tempTerritory[max].baseLE < tempTerritory[j].baseLE)
					max = j;
					
			if(i != max) {
				temp = tempTerritory[i];
				tempTerritory[i] = tempTerritory[max];
				tempTerritory[max] = temp;
			}
		}
	}
	
	// Copy top territories with highest base LE into new array
	for(i = 0; i < num; i++)
		terrList[i] = tempTerritory[i];
	
	//Determine the maximum risk per territory and their respective values
	for(i = 0; i < num; i++) {
		double riskVals[14] = {terrList[i].airPollution, terrList[i].ambientPM, terrList[i].ozone, terrList[i].HAP,
							terrList[i].environ, terrList[i].occup, terrList[i].unsafeWash, terrList[i].metabolic,
							terrList[i].dietary, terrList[i].plasma, terrList[i].tobacco, terrList[i].smoking, 
							terrList[i].secondhandSmoke, terrList[i].unsafeSex};
		
		maxVal = 0;
		
		for(j = 0; j < 14; j++)
			if(riskVals[j] > maxVal) {
				maxVal = riskVals[j];
				k = j;
			}
		
		switch(k) {
			case 0:
				strcpy(maxRisk[i], "Air Pollution");
				break;
			case 1:
				strcpy(maxRisk[i], "Ambient PM");
				break;
			case 2:
				strcpy(maxRisk[i], "Ozone");
				break;
			case 3:
				strcpy(maxRisk[i], "HAP");
				break;
			case 4:
				strcpy(maxRisk[i], "Environ/Occup");
				break;
			case 5:
				strcpy(maxRisk[i], "Occup");
				break;
			case 6:
				strcpy(maxRisk[i], "Unsafe WaSH");
				break;
			case 7:
				strcpy(maxRisk[i], "Metabolic");
				break;
			case 8:
				strcpy(maxRisk[i], "Dietary");
				break;
			case 9:
				strcpy(maxRisk[i], "High Fasting Plasma Glucose");
				break;
			case 10:
				strcpy(maxRisk[i], "Tobacco");
				break;
			case 11:
				strcpy(maxRisk[i], "Smoking");
				break;
			case 12:
				strcpy(maxRisk[i], "Secondhand Smoke");
				break;
			case 13:
				strcpy(maxRisk[i], "Unsafe Sex");
				break;
		}
		
		maxRiskVal[i] = maxVal;
	}
	
	return 1;
}

/* <<<<<<<<<<FUNCTION HEADER COMMENT>>>>>>>>>>>
	a. Purpose: This function counts how many risk factors decrease life expectency by at least a specific number in a
				specific territory
	b. Parameters: 	territory[] is the array containing the SoGA Dataset
					country is the specified territory
					rowsOfData is the rows of data
					num is the specific number that listed risk factors are greater than or equal to in value
	c. Return type:	An integer equal to the number of risk factors that meet the criteria above is returned.
					-2 and -1 also represent invalid input values.
*/

int Q5(dataSetStruct territory[], string country, int rowsOfData, double num) {
	int i, j, ctr = 0;
	
	dataSetStruct *ptr[rowsOfData];
	
	for(i = 0; i < rowsOfData; i++)
		ptr[i] = &territory[i];
	
	for(i = 0; i < rowsOfData; i++) {
		if(strcmp(territory[i].name, country) == 0) {
			double terrVals[14] = {(*ptr[i]).airPollution, (*ptr[i]).ambientPM, (*ptr[i]).ozone, (*ptr[i]).HAP,
							(*ptr[i]).environ, (*ptr[i]).occup, (*ptr[i]).unsafeWash, (*ptr[i]).metabolic,
							(*ptr[i]).dietary, (*ptr[i]).plasma, (*ptr[i]).tobacco, (*ptr[i]).smoking, 
							(*ptr[i]).secondhandSmoke, (*ptr[i]).unsafeSex};
							
			for(j = 0; j < 14; j++)
				if(terrVals[j] > num)
					ctr++;
		}
	}
	
	if(num < 0)
		ctr = -1; //parameter-number is invalid due to being negative
	if(ctr == 0)
		ctr = -2; //parameter-territory is invalid and was not located
	
	return ctr;
}

int
main()
{
	//DECLARATIONS
	FILE *fp_source, *fp_dest;
	fp_source = fopen("SOGA_DATASET.txt","r");
	fp_dest = fopen("OUTPUT_AQUINO_SILVA.txt","w");

	dataSetStruct territory[MAX_ROWS];
	string indexLabel = { ' ' };
	int numOfTestCases = 3, rowsOfData = getDataSet(territory, fp_source);
	int i, j; //used in for loops

	
	printDataSet(territory, rowsOfData, fp_source);

	/***********************************************************************|Q-U-E-S-T-I-O-N|*************************************************************************
	 ****************************************************************************|O-N-E|************************************************************************/
	int max = 0;
	double highestAverage = 0;
	max = Q1(territory, rowsOfData, &highestAverage);
	indexSetter(indexLabel, max);
	
	fprintf(fp_dest, "Q1: What is the highest average loss of life expectancy among all risk factors? Display the value and the name of the risk factor?\n");
	fprintf(fp_dest, "A1: %.2lf years (%s risk factor)\n\n", highestAverage, indexLabel);

	/************************************************************************|Q-U-E-S-T-I-O-N|*************************************************************************
	 *****************************************************************************|T-W-O|************************************************************************/
	string Q2ParameterTerritory[3] = {"Gambia", "Samoa", "Australasia"};
	int index;
	
	fprintf(fp_dest, "Q2: What is the overall reduction in life expectancy in <parameter-territory> as a result of smoking-related risk factors (tobacco, smoking, and secondhand smoke)?\n");
	for (int i = 0; i < numOfTestCases; i++)
	{
		index = territoryIndexFinder(territory, rowsOfData, Q2ParameterTerritory[i]);
		fprintf(fp_dest, "Case %d: <parameter-territory> = %s\n", i+1, Q2ParameterTerritory[i]);
		if (index == -1)
			fprintf(fp_dest, "\t\tInvalid input. Name of the territory is not included in the dataset.\n\n");
		else
			fprintf(fp_dest, "\t\t%.2lf years\n\n",Q2(territory, rowsOfData, index));
	}

	/*************************************************************************|Q-U-E-S-T-I-O-N|*************************************************************************
	 ****************************************************************************|T-H-R-E-E|************************************************************************/
	fprintf(fp_dest, "Q3: Which territory has their life expectancy shortened the least due to occupational hazards?\n");
	fprintf(fp_dest, "A3: %s", territory[Q3(territory, rowsOfData)].name);











	/*************************************************************************|Q-U-E-S-T-I-O-N|*************************************************************************
	 *****************************************************************************|F-O-U-R|************************************************************************/
	dataSetStruct terrList[rowsOfData];
	double maxRiskVal[rowsOfData];
	string maxRisk[rowsOfData];
	int testQ4[3] = {-34, 3, 5};
	int valid;
	
	fprintf(fp_dest, "\n\nQ4. What are the <parameter-number> countries with the highest life expectancy and which risk factor affects them "
		"the most respectively? Display in order the territory's name, their base line life expectancy, and the greatest risk "
		"factor for lowering life expectancy, along with its value. [algorithm(s): selection sort, maximum]");
	
	for(i = 0; i < 3; i++) {
		fprintf(fp_dest, "\nTest case %d: ", (i + 1));
		fprintf(fp_dest, "<parameter_number> is %d\n", testQ4[i]);
		
		valid = Q4(territory, terrList, maxRisk, maxRiskVal, rowsOfData, testQ4[i]);
		
		if(valid < 0)
			fprintf(fp_dest, "Invalid input. Please input a nonnegative integer.\n");
		
		else for(j = 0; j < testQ4[i]; j++) {
			fprintf(fp_dest, "%20s %10lf %10s %10lf\n", terrList[j].name, terrList[j].baseLE, maxRisk[j], maxRiskVal[j]);
		}
	}
	 







	/*************************************************************************|Q-U-E-S-T-I-O-N|*************************************************************************
	 ****************************************************************************|F-I-V-E|************************************************************************/
	int ctrQ5;
	
	fprintf(fp_dest, "\n\nQ5. How many of the 14 risk factors reduce the life expectancy of <parameter-territory> "
			"by at least <parameter-number> years? [algorithm(s): linear search or binary search, count]");
	
	string testTerrQ5[3] = {"Switzerland", "Pakistan", "United_States_Virgin_Islands"};
	double testValsQ5[3] = {-1, 2, 4};
	
	for(i = 0; i < 3; i++) {
		fprintf(fp_dest, "\nTest case %d: ", (i + 1));
		fprintf(fp_dest, "<parameter-territory> is %s\n", testTerrQ5[i]);
		fprintf(fp_dest, "<parameter-number> is %.6lf\n", testValsQ5[i]);
		
		ctrQ5 = Q5(territory, testTerrQ5[i], rowsOfData, testValsQ5[i]);
		
		if(ctrQ5 == -1)
			fprintf(fp_dest, "Invalid input. Number of years should be a nonnegative integer.\n");
		
		if(ctrQ5 == -2)
			fprintf(fp_dest, "Invalid input. Name of the territory is not included in the dataset.\n");
		
		if(ctrQ5 >= 0)
			fprintf(fp_dest, "%d risk factors\n", ctrQ5);
	}

	fclose(fp_dest);
	fclose(fp_source);
	return 0;
}
