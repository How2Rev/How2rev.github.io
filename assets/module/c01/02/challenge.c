#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>


const char encoded_secure[] = "WUVQR1N7ZTBnMTNfT25GMXBfTnl0Yn0=";

void rot13(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            char base = (str[i] >= 'a') ? 'a' : 'A';
            str[i] = (str[i] - base + 13) % 26 + base;
        }
    }
}

char *base64_encode(const char *input) {
    BIO *bio, *b64;
    BUF_MEM *bptr;

    b64 = BIO_new(BIO_f_base64());
    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);

    bio = BIO_new(BIO_s_mem());
    BIO_push(b64, bio);

    BIO_write(b64, input, strlen(input));
    BIO_flush(b64);

    BIO_get_mem_ptr(b64, &bptr);

    char *encoded_output = (char *)malloc(bptr->length + 1);
    memcpy(encoded_output, bptr->data, bptr->length);
    encoded_output[bptr->length] = 0;

    BIO_free_all(b64);

    return encoded_output;
}

int main() {
    char user_input[50];
    printf("Enter flag: ");
    scanf("%23s", user_input);

    rot13(user_input);  
    
    char *encoded_input = base64_encode(user_input);


     if (strcmp(encoded_input, encoded_secure) == 0) {
        printf("Valid flag!\n");    
    } else {
        printf("No...\n");
        exit(1);
    }

    return 0;
}
