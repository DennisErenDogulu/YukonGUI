#ifndef MASKIN_PROJEKT2_VIEW_H
#define MASKIN_PROJEKT2_VIEW_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include "deck.h"
#include "Linkedlist.h"

#define NUM_OF_COLUMNS 7
#define MAX_ROWS_PER_COLUMN 8

void emptyView(char lastCommand[], char message[]);

void showDeck(Linked_list *deck_list, char command[], char statusMessage[]);

void generatePlayView(Linked_list *C_ptr[NUM_OF_COLUMNS], Linked_list *F_ptr[4], char lastCommand[], char message[]);

int calculateMaxRows(Linked_list *columns[]);

void generateColumns();

void clearView();

void printCC(char lastCommand[], char message[]);

#endif //MASKIN_PROJEKT2_VIEW_H
