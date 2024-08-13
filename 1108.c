// Defanging an IP adress

#include <stdio.h>

char* defangIPaddr(char* address){
    char* string = (char*)malloc(100 * sizeof(char));
    int i = 0, j = 0;;
    while (address[i] != '\0') {
        if (address[i] == '.') {
            string[j ++] = '[';
            string[j ++] = '.';
            string[j ++] = ']';
        } else{
            string[j ++] = address[i];
        }

        i ++;
    }
    string[j] = '\0';

    return string;
}