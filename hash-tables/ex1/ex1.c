#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  /* YOUR CODE HERE */
  int index1;
  int index2;
  int weight;
  Answer *answer = malloc(sizeof(Answer));
  // loop through the weights and add them to the hash table
  for (int i = 0; i < length; i++){
    hash_table_insert(ht, weights[i], i);
    if (hash_table_retrieve(ht, limit-weights[i]) != -1){  
      index1 = hash_table_retrieve(ht, limit-weights[i]);
      weight = weights[i];
    }
    //index1 = hash_table_retrieve(ht, weights[i]);
    // index2 = hash_table_retrieve(ht, limit-weights[i]);
    // if ( index2 != -1){
    //   answer->index_1 = index1;
    //   answer->index_2 = index2;
    // }
  }
  index2 = hash_table_retrieve(ht, weight);
  printf("found index1: %d , index2: %d, weight: %d\n", index1, index2, weight);

  if (index1 == -1 || index2 == -1){
    return NULL;
  }
  if (index1 < index2){
    answer->index_1 = index2;
    answer->index_2 = index1;
    return answer;
  } else {
    answer->index_1 = index1;
    return answer;
  }
  

  
  
  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{
  // TEST 1
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1);  // NULL
  free(answer_1);
  // TEST 2
  int weights_2[] = {4, 4};
  Answer* answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2);  // {1, 0}
  free(answer_2);
  // TEST 3
  int weights_3[] = {4, 6, 10, 15, 16};
  Answer* answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3);  // {3, 1}
  free(answer_3);
  // TEST 4
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4);  // {6, 2}
  free(answer_4);
  return 0;
}

#endif
