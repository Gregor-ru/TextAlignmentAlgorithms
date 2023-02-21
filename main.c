#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <Windows.h>
#include <conio.h>

#define MAXLEN 4096

char* concat(char* s1, char* s2) {

	size_t len1 = strlen(s1);
	size_t len2 = strlen(s2);

	char* result = malloc(len1 + len2 + 1);

	if (!result) {
		fprintf(stderr, "malloc() failed: insufficient memory!\n");
		return NULL;
	}

	memcpy(result, s1, len1);
	memcpy(result + len1, s2, len2 + 1);

	return result;
}

void left_alignment(char* FilePath, int SymbolsInStringCount) {

	char* StringNow = malloc(MAXLEN);

	FILE* file;

	if ((file = fopen(FilePath, "r")) == NULL) {perror("The selected file does not exit");}
	else {

		printf("%s", "\n");

		while (!feof(file)) {

			if (fgets(StringNow, MAXLEN, file)) {

				int SymbolsCountNow = strlen(StringNow), LeftBorder = 0, RightBorder = 0, SymbolsValue = SymbolsInStringCount;

				if (SymbolsCountNow > SymbolsInStringCount) {

					while (LeftBorder < SymbolsCountNow) {

						while (SymbolsValue > LeftBorder) {

							if (StringNow[SymbolsValue] == ' ') {

								RightBorder = SymbolsValue;
								
								for (int i = LeftBorder; i < RightBorder; i++) {printf("%c", StringNow[i]);}

								printf("%s", "\n");

								LeftBorder = (RightBorder + 1);

								if ((RightBorder + SymbolsInStringCount) > SymbolsCountNow) {

									for (int i = LeftBorder; i < SymbolsCountNow; i++) {printf("%c", StringNow[i]);}

									LeftBorder = SymbolsCountNow;

									break;
								}
								else {SymbolsValue = (RightBorder + SymbolsInStringCount);}
							}
							else {SymbolsValue--;}
						}
					}
				}
				else {printf("%s", StringNow);}
			}
		}
	}
	printf("%s", "\n");
}

void right_alignment(char* FilePath, int SymbolsInStringCount) {

	char* StringNow = malloc(MAXLEN);

	FILE* file;

	if ((file = fopen(FilePath, "r")) == NULL) { perror("The selected file does not exit"); }
	else {

		printf("%s", "\n");

		while (!feof(file)) {

			if (fgets(StringNow, MAXLEN, file)) {

				int SymbolsCountNow = strlen(StringNow), LeftBorder = 0, RightBorder = 0, SymbolsValue = SymbolsInStringCount;

				if (SymbolsCountNow > SymbolsInStringCount) {

					while (LeftBorder < SymbolsCountNow) {

						while (SymbolsValue > LeftBorder) {

							if (StringNow[SymbolsValue] == ' ') {

								RightBorder = SymbolsValue;

								for (int i = 0 ; i < (SymbolsInStringCount - abs(RightBorder-LeftBorder) + 1); i++) { printf("%c", ' '); }

								for (int i = LeftBorder; i < RightBorder; i++) { printf("%c", StringNow[i]); }

								printf("%s", "\n");

								LeftBorder = (RightBorder + 1);

								if ((RightBorder + SymbolsInStringCount) > SymbolsCountNow) {

									for (int i = 0; i < (SymbolsInStringCount - abs(SymbolsCountNow - LeftBorder) + 1); i++) { printf("%c", ' '); }

									for (int i = LeftBorder; i < SymbolsCountNow; i++) { printf("%c", StringNow[i]); }

									LeftBorder = SymbolsCountNow;

									break;
								}
								else { SymbolsValue = (RightBorder + SymbolsInStringCount); }
							}
							else { SymbolsValue--; }
						}
					}
				}
				else {

					for (int i = 0; i < (SymbolsInStringCount - strlen(StringNow)+1); i++) { printf("%c", ' '); }
					printf("%s", StringNow); 
				}
			}
		}
	}
	printf("%s", "\n");
}

void center_alignment(char* FilePath, int SymbolsInStringCount) {

	char* StringNow = malloc(MAXLEN);

	FILE* file;

	if ((file = fopen(FilePath, "r")) == NULL) { perror("The selected file does not exit"); }
	else {

		printf("%s", "\n");

		while (!feof(file)) {

			if (fgets(StringNow, MAXLEN, file)) {

				int SymbolsCountNow = strlen(StringNow), LeftBorder = 0, RightBorder = 0, SymbolsValue = SymbolsInStringCount;

				if (SymbolsCountNow > SymbolsInStringCount) {

					while (LeftBorder < SymbolsCountNow) {

						while (SymbolsValue > LeftBorder) {

							if (StringNow[SymbolsValue] == ' ') {

								RightBorder = SymbolsValue;

								for (int i = 0; i < ((SymbolsInStringCount - abs(RightBorder - LeftBorder) + 1)/2); i++) { printf("%c", ' '); }

								for (int i = LeftBorder; i < RightBorder; i++) { printf("%c", StringNow[i]); }

								printf("%s", "\n");

								LeftBorder = (RightBorder + 1);

								if ((RightBorder + SymbolsInStringCount) > SymbolsCountNow) {

									for (int i = 0; i < ((SymbolsInStringCount - abs(SymbolsCountNow - LeftBorder) + 1) / 2); i++) { printf("%c", ' '); }

									for (int i = LeftBorder; i < SymbolsCountNow; i++) { printf("%c", StringNow[i]); }

									LeftBorder = SymbolsCountNow;

									break;
								}
								else { SymbolsValue = (RightBorder + SymbolsInStringCount); }
							}
							else { SymbolsValue--; }
						}
					}
				}
				else {

					for (int i = 0; i < ((SymbolsInStringCount - strlen(StringNow) + 1)/2); i++) { printf("%c", ' '); }

					printf("%s", StringNow);
				}
			}
		}
	}
	printf("%s", "\n");
}

void width_alignment(char* FilePath, int SymbolsInStringCount) {

	char* StringNow = malloc(MAXLEN);

	FILE* file;

	if ((file = fopen(FilePath, "r")) == NULL) { perror("The selected file does not exit"); }
	else {

		printf("%s", "\n");

		while (!feof(file)) {

			if (fgets(StringNow, MAXLEN, file)) {

				int SymbolsCountNow = strlen(StringNow), LeftBorder = 0, RightBorder = 0, SymbolsValue = SymbolsInStringCount, SpaceCount = 0, SpaceCountNow=0;

				if (SymbolsCountNow > SymbolsInStringCount) {

					while (LeftBorder < SymbolsCountNow) {

						while (SymbolsValue > LeftBorder) {

							if (StringNow[SymbolsValue] == ' ') {

								RightBorder = SymbolsValue;

								for (int i = LeftBorder; i < RightBorder; i++) {
									if (StringNow[i] = ' ') {
										SpaceCount++;
									}
								}

								int SpaceValue = (SymbolsInStringCount - abs(RightBorder - LeftBorder) - SpaceCount) / SpaceCount;
								int LastSpaceCount = SpaceValue + (SymbolsInStringCount - abs(RightBorder - LeftBorder) - SpaceCount) % SpaceCount;

								for (int i = LeftBorder; i < RightBorder; i++) {

									if (StringNow[i] = ' ') {

										SpaceCountNow++;

										if (SpaceCountNow == SpaceCount) {
											for (int j = 0; j < LastSpaceCount; j++) {
												printf("%c", ' ');
											}
										}
										else {
											for (int j = 0; j < SpaceCount; j++) {
												printf("%c", ' ');
											}
										}
									}
									else {
										printf("%c", StringNow[i]);
									}
								}

								printf("%s", "\n");

								LeftBorder = (RightBorder + 1);

								if ((RightBorder + SymbolsInStringCount) > SymbolsCountNow) {

									for (int i = LeftBorder; i < SymbolsCountNow; i++) {
										if (StringNow[i] = ' ') {
											SpaceCount++;
										}
									}

									int SpaceValue = (SymbolsInStringCount - abs(SymbolsCountNow - LeftBorder) - SpaceCount) / SpaceCount;
									int LastSpaceCount = SpaceValue + (SymbolsInStringCount - abs(SymbolsCountNow - LeftBorder) - SpaceCount) % SpaceCount;

									for (int i = LeftBorder; i < SymbolsCountNow; i++) {

										if (StringNow[i] = ' ') {

											SpaceCountNow++;

											if (SpaceCountNow == SpaceCount) {
												for (int j = 0; j < LastSpaceCount; j++) {
													printf("%c", ' ');
												}
											}
											else {
												for (int j = 0; j < SpaceCount; j++) {
													printf("%c", ' ');
												}
											}
										}
										else {
											printf("%c", StringNow[i]);
										}
									}

									LeftBorder = SymbolsCountNow;

									break;
								}
								else { SymbolsValue = (RightBorder + SymbolsInStringCount); }
							}
							else { SymbolsValue--; }
						}
					}
				}
				else {

					for (int i = 0; i < ((SymbolsInStringCount - strlen(StringNow) + 1) / 2); i++) { printf("%c", ' '); }

					printf("%s", StringNow);
				}
			}
		}
	}
	printf("%s", "\n");
}

int main() {
	
	char FileNameInDirect[MAXLEN] = { 0 };
	char EnterFlag[2] = "";

	printf("%s", "\nEnter file name: ");
	if (scanf("%s", &FileNameInDirect));
	printf("%s", "\n");

	char* FilePath = concat("D:/C-C++Projects/Files/", FileNameInDirect);
	int Type, SymbolsInStringCount;

	while (TRUE){

		printf("%s", "|Type 1: Left alignment|\t|Type 2: Right alignment|\t|Type 3: Center alignment|\t|Type 4: Justify|\n\n");
		printf("%s", "Enter type (1-4): ");					//Выравнивание по ширине не работает
		if (scanf("%d", &Type));
		printf("%s", "Enter count symbols in one string: ");
		if (scanf("%d", &SymbolsInStringCount));

		switch (Type)
		{

		case 1:
			left_alignment(FilePath, SymbolsInStringCount);
			break;
		case 2:
			right_alignment(FilePath, SymbolsInStringCount);
			break;

		case 3:
			center_alignment(FilePath, SymbolsInStringCount);
			break;

		case 4:
			width_alignment(FilePath, SymbolsInStringCount);
			break;

		default:
			printf("%s", "This type does not exist");
			break;
		}

		printf("%s", "\n");

		printf("Enter (Y) to continue or (N) for exit: ");
		if (scanf("%s", &EnterFlag));
		printf("%s", "\n");

		if (EnterFlag[0] != 'Y') { break; }

	}
}
