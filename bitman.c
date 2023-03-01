#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Bit should be able to convert between binary, decimal and hex
*/

/* This structs is to make it easier for me to manipulate strings */
typedef struct {
  char value[100];
  int len;
} str;

void swap(char *x, char *y) {
  char tmp = *x;
  *x = *y;
  *y = tmp;
}

/* matches a hex character with the corresponding decimal */
// pardon the numerous if else
int hex_decimal_dict(char c) {
  if (c == 'F' || c == 'f') {
    return 15;
  } else if (c == 'E' || c == 'e') {
    return 14;
  } else if (c == 'D' || c == 'd') {
    return 13;
  } else if (c == 'C' || c == 'c') {
    return 12;
  } else if (c == 'B' || c == 'b') {
    return 11;
  } else if (c == 'A' || c == 'a') {
    return 10;
  }
  return 0;
}

char decimal_hex_dict(int num) {
  if (num == 10) {
    return 'A';
  } else if (num == 11) {
    return 'B';
  } else if (num == 12) {
    return 'C';
  } else if (num == 13) {
    return 'D';
  } else if (num == 14) {
    return 'E';
  } else if (num == 15) {
    return 'F';
  }
  return num + '0';
}

void reverse_str(str *target) {
  int j = target->len - 1;
  for (int i = 0; i < j; i++) {
    swap(&target->value[i], &target->value[j]);
    j--;
  }
}

void decimal_to_bin(int number, str *result) {
  int current_num = number;

  while (current_num != 0) {
    int remainder = current_num % 2;
    result->value[result->len] = remainder + '0';
    result->len++;
    current_num = current_num / 2;
  }
  reverse_str(result);
}

int bin_to_decimal(str bin) {
  int pow_v = bin.len - 1;
  int result = 0;
  for (int i = 0; i < bin.len; i++) {
    int v = bin.value[i] - '0';
    result += v * pow(2, pow_v);
    pow_v--;
  }
  return result;
}

void hex_to_bin(str hex, str *result) {
  result->len = 0;
  for (int i = 0; i < hex.len; i++) {
    int p_int = hex.value[i] - '0'; // just a potential integer partner
    str d2br = {.value = ""};
    if (p_int < 10) {
      decimal_to_bin(p_int, &d2br);
      strcat(result->value, d2br.value);
    } else {
      int d_value = hex_decimal_dict(hex.value[i]);
      decimal_to_bin(d_value, &d2br);
      strcat(result->value, d2br.value);
    }
    result->len++;
  }
}

// this doesn't work right
void decimal_to_hex(int number, str *result) {
  int current_num = number;

  while (current_num != 0) {
    int remainder = current_num % 16;
    result->value[result->len] = decimal_hex_dict(remainder);
    result->len++;
    current_num = current_num / 16;
  }
  reverse_str(result);
}

int main(int argc, char *argv[]) {
  char *converter = argv[1];
  char *value = argv[2];

  if (!strcmp(converter, "db")) {
    str result;
    decimal_to_bin(atoi(value), &result);
    printf("-> %s\n", result.value);
  } else if (!strcmp(converter, "dh")) {
    str result;
    decimal_to_hex(atoi(value), &result);
    printf("-> %s\n", result.value);
  } else if (!strcmp(converter, "bd")) {
    str result;
    str i_value;
    strcpy(i_value.value, value);
    i_value.len = strlen(value);
    int d = bin_to_decimal(i_value);
    printf("-> %d \n", d);
  } else if (!strcmp(converter, "bh")) {
    str result;
    str i_value;
    strcpy(i_value.value, value);
    i_value.len = strlen(value);
    int d = bin_to_decimal(i_value);
    result.len = d; // probably a bad idea
    decimal_to_hex(d, &result);
    printf("-> %s\n", result.value);
  } else if (!strcmp(converter, "hd")) {
    str result;
    str i_value;
    strcpy(i_value.value, value);
    i_value.len = strlen(value);
    hex_to_bin(i_value, &result);
    result.len = strlen(result.value);
    int d = bin_to_decimal(result);
    printf("-> %d\n", d);
  } else if (!strcmp(converter, "hb")) {
    str result;
    str i_value;
    strcpy(i_value.value, value);
    i_value.len = strlen(value);
    hex_to_bin(i_value, &result);
    printf("-> %s\n", result.value);
  } else {
    puts("Unknown command");
  }
  return 0;
}