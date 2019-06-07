#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *ht = create_hash_table(length);
  char **route = malloc(length * sizeof(char *));
  /* YOUR CODE HERE */
  // for (int i = 0; i < length; i++){
  //   hash_table_insert(ht, tickets[i]->source, tickets[i]->destination);
  //   route[i] = hash_table_retrieve(ht, tickets[i]->source);
  //   printf("Source: %s, des: %s\n", tickets[i]->source, tickets[i]->destination);
  // }

  for (int i = 0; i < length; i++){
    hash_table_insert(ht, tickets[i]->source, tickets[i]->destination);
    // printf("inserting %s, %s\n", tickets[i]->source, tickets[i]->destination);
  }
  char *start = hash_table_retrieve(ht, "NONE");
  for (int i = 0; i < length; i++){
    route[i] = start;
    start = hash_table_retrieve(ht, start);
  }
  destroy_hash_table(ht);
  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++) {
    printf("%s\n", route[i]);
  }
}



#ifndef TESTING
int main(void)
{
  // Short test

  Ticket **tickets = malloc(3 * sizeof(Ticket *));

  Ticket *ticket_1 = malloc(sizeof(Ticket));
  ticket_1->source = "NONE";
  ticket_1->destination = "PDX";
  tickets[0] = ticket_1;

  Ticket *ticket_2 = malloc(sizeof(Ticket));
  ticket_2->source = "PDX";
  ticket_2->destination = "DCA";
  tickets[1] = ticket_2;

  Ticket *ticket_3 = malloc(sizeof(Ticket));
  ticket_3->source = "DCA";
  ticket_3->destination = "NONE";
  tickets[2] = ticket_3;

  print_route(reconstruct_trip(tickets, 3), 3); // PDX, DCA, NONE

  // Ticket **tickets = malloc(10 * sizeof(Ticket *));

  // Ticket *ticket_1 = malloc(sizeof(Ticket));
  // ticket_1->source = "PIT";
  // ticket_1->destination = "ORD";
  // tickets[0] = ticket_1;

  // Ticket *ticket_2 = malloc(sizeof(Ticket));
  // ticket_2->source = "XNA";
  // ticket_2->destination = "CID";
  // tickets[1] = ticket_2;

  // Ticket *ticket_3 = malloc(sizeof(Ticket));
  // ticket_3->source = "SFO";
  // ticket_3->destination = "BHM";
  // tickets[2] = ticket_3;

  // Ticket *ticket_4 = malloc(sizeof(Ticket));
  // ticket_4->source = "FLG";
  // ticket_4->destination = "XNA";
  // tickets[3] = ticket_4;

  // Ticket *ticket_5 = malloc(sizeof(Ticket));
  // ticket_5->source = "NONE";
  // ticket_5->destination = "LAX";
  // tickets[4] = ticket_5;

  // Ticket *ticket_6 = malloc(sizeof(Ticket));
  // ticket_6->source = "LAX";
  // ticket_6->destination = "SFO";
  // tickets[5] = ticket_6;

  // Ticket *ticket_7 = malloc(sizeof(Ticket));
  // ticket_7->source = "CID";
  // ticket_7->destination = "SLC";
  // tickets[6] = ticket_7;

  // Ticket *ticket_8 = malloc(sizeof(Ticket));
  // ticket_8->source = "ORD";
  // ticket_8->destination = "NONE";
  // tickets[7] = ticket_8;

  // Ticket *ticket_9 = malloc(sizeof(Ticket));
  // ticket_9->source = "SLC";
  // ticket_9->destination = "PIT";
  // tickets[8] = ticket_9;

  // Ticket *ticket_10 = malloc(sizeof(Ticket));
  // ticket_10->source = "BHM";
  // ticket_10->destination = "FLG";
  // tickets[9] = ticket_10;

  // reconstruct_trip(tickets, 10);
  // print_route(reconstruct_trip(tickets, 10), 10); // PDX, DCA, NONE

  for (int i = 0; i < 3; i++) {
    free(tickets[i]);
  }

  free(tickets);

  return 0;
}
#endif
