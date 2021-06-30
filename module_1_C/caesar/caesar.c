/* 
 * caesar.c
 *
 * Decrypt the given ciphertext to find the encrypted plaintext. 
 *
 * Compile with: gcc -o caesar caesar.c
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() 
{
    char msg[] = "dahhk pdana cajanwh gajkxe";

    char* tmp = malloc(strlen(msg) + 1);
    tmp = strcpy(tmp, msg);

        printf("%s\n", tmp);

    for (int key = 0; key < 25; key++) {
        for (int ii = 0; ii < strlen(tmp); ii++) {
            char c = tmp[ii];
            if ((c > 'z' + 1) || (c < 'a' - 1)) {
                continue;
            }
            c = tmp[ii] + 1;
            if (c > 'z') {
                c = c - 'z' + 'a' - 1;
            }
            tmp[ii] = c;
        }
        printf("%s\n", tmp);
    }

    free(tmp);

    return 0;
}