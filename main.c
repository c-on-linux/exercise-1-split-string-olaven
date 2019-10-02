#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

struct Token {
  const char *token;
  size_t token_length; // Number of characters
};

int count_tokens(const char * input) {

    int count = 0;
    int i = 0;

    char value = *input;
    while(value != '\0') {

        if (value == ' ') {
            count++;
        }

        i++;
        value = input[i];
    }

    return count + 1;                                                                                                                                       }

int split_into_strings(const char *input, char ***output) {

    char** buffer = malloc(sizeof(struct Token) * 200);

    char* string = malloc(20 * sizeof(char));
    int stringIndex = 0;
    int tokenIndex = 0;

    for (int i = 0; 1; ++i) {

        if (input[i] == ' ' || input[i] == '\0') {

            char* pointer = malloc(20 * sizeof(char));
            for (int j = 0; string[j] != '\0'; ++j) {

                pointer[j] = string[j];
            }

            buffer[tokenIndex] = pointer;

            memset(string, 0, strlen(string));
            stringIndex = 0;
            tokenIndex++;

            if (input[i] == '\0') {
                break;
            }
        } else {

            string[stringIndex] = input[i];
            stringIndex++;
        }
    }

    *output = buffer;
    return tokenIndex;
}

int split_into_tokens(const char *input, struct Token **output) {

    struct Token* buffer = malloc(sizeof(struct Token) * 200);

    char* string = malloc(20 * sizeof(char));
    int stringIndex = 0;
    int tokenIndex = 0;

    for (int i = 0; 1; ++i) {

        if (input[i] == ' ' || input[i] == '\0') {

            char* pointer = malloc(20 * sizeof(char));
            for (int j = 0; string[j] != '\0'; ++j) {

                pointer[j] = string[j];
            }

            struct Token token = {
                .token = pointer,
                .token_length = strlen(pointer)
            };

            buffer[tokenIndex] = token;

            memset(string, 0, strlen(string));
            stringIndex = 0;
            tokenIndex++;

            if (input[i] == '\0') {
                break;
            }
        } else {

            string[stringIndex] = input[i];
            stringIndex++;
        }
    }


    *output = buffer;
    return ++tokenIndex;
}

void testCountTokens() {
  char input[17];
  strcpy(input, "This is a string");
  assert(4 == count_tokens(input));
}

void testMakeTokenStrings() {
  char input[17];
  strcpy(input, "This is a string");

  char **tokens = 0;
  assert(4 == split_into_strings(input, &tokens));
  assert(0 == strcmp(tokens[0], "This"));
  assert(0 == strcmp(tokens[1], "is"));
  assert(0 == strcmp(tokens[2], "a"));
  assert(0 == strcmp(tokens[3], "string"));
}

void testMakeTokenStructs() {
  char input[17];
  strcpy(input, "This is a string");

  struct Token *tokens = 0;
  split_into_tokens(input, &tokens);
  //assert(4 == );


  assert(tokens[0].token_length == 4);
  assert(0 == strncmp(tokens[0].token, "This", 4));
  assert(tokens[1].token_length == 2);
  assert(0 == strncmp(tokens[1].token, "is", 2));
  assert(tokens[2].token_length == 1);
  assert(0 == strncmp(tokens[2].token, "a", 1));
  assert(tokens[3].token_length == 6);
  assert(0 == strncmp(tokens[3].token, "string", 6));
}


void update_string(char*** pointerToString) {

    **pointerToString = "updated";
}


int main() {

    testCountTokens();
    testMakeTokenStrings();
    testMakeTokenStructs();
    //return EXIT_SUCCESS;
}
