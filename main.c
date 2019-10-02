#include <string.h>
#include <assert.h>
#include <stdlib.h>

struct Token {
  const char *token;
  size_t token_length; // Number of characters
};

/**
 * Counts the number of tokens in the input string
 * Tokens are delimited by one or more spaces
 * @param input
 * @return the number of tokens in input
 */
int count_tokens(const char *input) {
  (void) input;
  return 0;
}

/**
 * Splits the input string into tokens
 * Tokens are delimited by one or more spaces
 * @param input string to be split
 * @param output the tokens
 * @return the number of tokens in input
 */
int split_into_strings(const char *input, char ***output) {
  (void) input;
  (void) output;
  return 0;
}

/**
 * Splits the input string into Token structs
 * @param input string to be split
 * @param output array of Token
 * @return the number of tokens in input
 */
int split_into_tokens(const char *input, struct Token **output) {
  (void) input;
  (void) output;
  return 0;
}

void testCountTokens() {
  assert(0 == count_tokens(""));
  assert(0 == count_tokens(0));
  assert(4 == count_tokens("This is a string"));
  assert(1 == count_tokens(" One "));
  assert(2 == count_tokens("One  Two "));
  assert(6 == count_tokens("This is an  even longer  string "));
}

void testMakeTokenStrings() {
  char **tokens = 0;
  assert(4 == split_into_strings("This is a string", &tokens));
  assert(0 == strcmp(tokens[0], "This"));
  assert(0 == strcmp(tokens[1], "is"));
  assert(0 == strcmp(tokens[2], "a"));
  assert(0 == strcmp(tokens[3], "string"));
}

void testMakeTokenStructs() {
  struct Token *tokens = 0;
  assert(4 == split_into_tokens("This is a string", &tokens));
  assert(tokens[0].token_length == 4);
  assert(0 == strncmp(tokens[0].token, "This", 4));
  assert(tokens[1].token_length == 2);
  assert(0 == strncmp(tokens[1].token, "is", 2));
  assert(tokens[2].token_length == 1);
  assert(0 == strncmp(tokens[2].token, "a", 1));
  assert(tokens[3].token_length == 6);
  assert(0 == strncmp(tokens[3].token, "string", 6));
}

int main() {
  testCountTokens();
  testMakeTokenStrings();
  testMakeTokenStructs();
  return EXIT_SUCCESS;
}
