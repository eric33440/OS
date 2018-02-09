/*
 * chained_list.h
 *
 *  Created on: Feb 9, 2018
 *      Author: Ricod
 */

#ifndef CHAINED_LIST_H_
#define CHAINED_LIST_H_
#include "OSV1.h"
void chained_list_pop_first(T_elem_list_process **list);
void chained_list_append(T_elem_list_process * list, T_elem_list_process * elem);
//T_elem_list_process *chained_list_get_first(T_elem_list_process *list);
#define chained_list_get_first(list) (list)
T_elem_list_process *chained_list_create_element(T_process *process);

#endif /* CHAINED_LIST_H_ */
