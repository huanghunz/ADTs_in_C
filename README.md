# ADTs_in_C
ADTs and usage cases in C languages

This file contains ADTs and its examples. 
All implementation and example refer to:

Data Structures A Pseudocode Approach with C by Richard F. Gilberg & Behrouz A. Forouzan 2nd Edition

Some ADTs may have minor changes from the givens examples:

e.x. in the textbook, dequeue of QueueADT recieves an address of pointer so that the address can contain data


bool dequeue(QUEUE* queue, void** dataOut); // from the textbook

in this file, dequeue is 
void* dequeue(QUEUE* queue); // minor changes
