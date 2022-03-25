#include "reflect.c"
#include "stp_print.h"
/*********************************/
#include "stp_print.c"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**********************************************/
REFLECTIVE(item1,
           FIELD(int, id);
           FIELD(char *, name);
           );
REFLECTIVE(item,
           FIELD(int, id);
           FIELD(item1 *, item);
           FIELD(int, age);
           FIELD(char *, content);
           );
REFLECTIVE(account_t,
           FIELD(int, id);
           FIELD(char *, name);
           FIELD(int, age);
           FIELD(int, cash);
           );
/**********************************************/
stp_print_begin(account_t, 4) {
  stp_print_field_int(id);
  stp_print_field_string(name);
  stp_print_field_int(age);
  stp_print_field_int(cash);
  stp_print_end();
}


/**********************************************/


void print_data(account_t *ptr, int level){
  char msg[1024];

  printf("----\n");
  stp_snprintf(account_t, msg, sizeof(msg), ptr, "Account", level);
  printf("%s", msg);
  printf("\n----\n");
}


void demo1(){
  account_t *acc1 = malloc(sizeof(account_t));

  acc1->id   = 10;
  acc1->name = strdup("Bob");
  acc1->cash = 1000;
  acc1->cash++;
  acc1->age = 30;

  print_data(acc1, 1);
  print_data(acc1, 2);
  print_data(acc1, 3);

  int   num_acc1     = account_t_get_num_fields();
  field *acc1_fields = account_t_get_fields();

  printf("%d fields\n", num_acc1);
  for (int i = 0; i < num_acc1; ++i) {
    printf("%s(%db), ", acc1_fields[i].name, acc1_fields[i].size);
  }
  printf("\n");
}


void xxxxxxxxx(){
  item  *item1      = malloc(sizeof(item1));
  int   num_fields1 = item1_get_num_fields();
  field *fields1    = item1_get_fields();

  printf("%d fields\n", num_fields1);
  for (int i = 0; i < num_fields1; ++i) {
    printf("\t%s\t(%db)\n", fields1[i].name, fields1[i].size);
  }

  item  *item      = malloc(sizeof(item));
  int   num_fields = item_get_num_fields();
  field *fields    = item_get_fields();

  printf("%d fields\n", num_fields);

  for (int i = 0; i < num_fields; ++i) {
    printf("\t%s\t(%db)\n", fields[i].name, fields[i].size);
  }

  free(item);
  free(item1);
}


int main() {
  demo1();
  return(0);
}
