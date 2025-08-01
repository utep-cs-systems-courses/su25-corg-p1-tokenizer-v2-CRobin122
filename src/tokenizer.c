#ifndef _TOKENIZER_
#define _TOKENIZER_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  return (c == ' ' || c == '\t');
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  return (c != ' ' && c != '\t' && c != '\0');
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str){
  if (str == NULL) return NULL;

  while (space_char(*str)){
    str++;
  }

  if (*str == '\0'){
    return NULL;
  }

  return str;
}

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token){
  if (token == NULL) return NULL;

  while (non_space_char(*token)){
    token++;
  }

  return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str){
  if (str == NULL); return 0;

  int count = 0;
  char *current = token_start(str);

  while (current != NULL){
    count++;
    current = token_terminator(current);
    current = token_start(current);
  }

  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  if (inStr == NULL || len < 0) return NULL;

  char *newStr = (char *)malloc((len + 1) * sizeof(char));
  if (new_str == NULL) return NULL;

  //copys the len characters
  int i;
  for (i = 0; i < len && inStr != '\0'; i++){
    new_str[i] = inStr[i];
  }

  //terminate
  new_str[i] = '\0';

  return new_str;
}
/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
  if (str == NULL) return NULL;

  int num_tokens = count_tokens(str);
  if (num_tokens == 0) return NULL;

  //allocate array of string pointers and a extra for terminator
  char **tokens = (char**)malloc((num_tokens + 1) * sizeof(char *));
  if (tokens == NULL) return NULL;

  char *current = token_start(str);
  int token_index = 0;

  while (current != NULL && token_index < num_tokens){
    char *end = token_terminator(current);
    int token_len = end - current;

    //copy token
    tokens[token_index] = copy_str(current, token_len);
    if (tokens[token_index] == NULL){
      //free tokens on error
      for (int i = 0; i < token_index; i++){
	free(tokens[i]);
      }
      free(tokens);
      return NULL;
    }

    token_index++;
    current = token_start(end);
  }
  //terminate array
  tokens[token_index] = NULL;

  return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
  if (tokens == NULL){
    printf("No tokens to print.\n");
    return;
  }

  int i = 0;
  while (tokens != NULL){
    printf("Token %d: \"%s\"\n", i, tokens[i]);
    i++;
  }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
  if (tokens == NULL) return;

  //free each string token individually
  int i = 0;
  while (tokens[i] != NULL){
    free(tokens[i]);
    i++;
  }

  //free array of pointers
  free(tokens);
}

#endif
