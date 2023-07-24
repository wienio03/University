//-------------------------------------------------------//
//obsługa pamięci
//-------------------------------------------------------//
NODE_STRUCT* NewNode(void)
{
    NODE_STRUCT* new_node = new NODE_STRUCT;
    new_node->object = new OBJECT_TYPE[SIZE];
    new_node->use = 0;
    new_node->next = NULL;
    return new_node;
}

void DeleteNode(NODE_STRUCT* node)
{
    if (node->object != NULL) delete[] node->object;
    if (node->next != NULL) node->next = NULL;
    if (node != NULL) delete node;
    node = NULL;
}
void Clear(NODE_STRUCT** list_node)
{
    NODE_STRUCT* tmp;
    while (*list_node != NULL) {
        tmp = *list_node;
        *list_node = (*list_node)->next;
        DeleteNode(tmp);
    }
}
//-------------------------------------------------------//
//dodawanie obiektów
//-------------------------------------------------------//
void AddFirst(NODE_STRUCT** list_node, OBJECT_TYPE* added_object)
{
    if (*list_node == NULL)
    {
        *list_node = NewNode();
        (*list_node)->use++;
        *((*list_node)->object) = *added_object;
    }
    else
    {
        if ((*list_node)->use == SIZE) {
            NODE_STRUCT* first_node = NewNode();
            first_node->use++;
            *(first_node->object) = *added_object;
            first_node->next = *list_node;
            *list_node = first_node;
        }
        else {
            (*list_node)->use++;
            for (int i = (*list_node)->use - 1; i >= 0; i--) {
                *((*list_node)->object + i) = *((*list_node)->object + i - 1);
            }
            *((*list_node)->object) = *added_object;
        }
    }
}
void AddLast(NODE_STRUCT** list_node, OBJECT_TYPE* added_object)
{
    if (*list_node == NULL) {
        *list_node = NewNode();
        (*list_node)->use++;
        *((*list_node)->object) = *added_object;
    }
    else {
        NODE_STRUCT* tmp = *list_node;
        while (tmp->next != NULL)
            tmp = tmp->next;

        if (tmp->use < SIZE)
        {
            tmp->use++;
            *(tmp->object + tmp->use - 1) = *added_object;
        }
        else {
            NODE_STRUCT* last_node = NewNode();
            tmp->next = last_node;
            last_node->use++;
            *(last_node->object) = *added_object;
        }
    }
}
//-------------------------------------------------------//
//pobieranie obiektów
//-------------------------------------------------------//
void GetFirst(NODE_STRUCT* node_list, NODE_STRUCT** first_node, BYTE* first_byte) {
    if (node_list == NULL) {
        *first_node = NULL;
    }
    else {
        *first_node = node_list;
        *first_byte = 0;
    }
}
void GetPrev(NODE_STRUCT* node_list, NODE_STRUCT* current_node, BYTE current_byte, NODE_STRUCT** previous_node, BYTE* previous_byte) {
    NODE_STRUCT* tmp = node_list;
    if (node_list->next != NULL) while (node_list->next != current_node)node_list = node_list->next;
    if (current_byte == 0) {
        if (current_node != node_list) {
            *previous_byte = node_list->use - 1;
            *previous_node = node_list;
        }
        else {
            *previous_node = NULL;
        }
    }
    else {
        *previous_byte = current_byte - 1;
        *previous_node = current_node;
    }
    node_list = tmp;
}
void GetLast(NODE_STRUCT* node_list, NODE_STRUCT** last_node, BYTE* last_byte) {
    if (node_list == NULL) {
        *last_node = NULL;
    }
    else {
        NODE_STRUCT* tmp = node_list;
        while (node_list->next != NULL)node_list = node_list->next;
        *last_byte = node_list->use - 1;
        *last_node = node_list;
        node_list = tmp;
    }
}
void GetNext(NODE_STRUCT* node_list, NODE_STRUCT* current_node, BYTE current_byte, NODE_STRUCT** next_node, BYTE* next_byte) {
    NODE_STRUCT* tmp = node_list;
    if (current_byte == current_node->use - 1) {
        if (current_node->next != NULL) {
            while (node_list != current_node->next)node_list = node_list->next;
            *next_byte = 0;
            *next_node = node_list;
            node_list = tmp;
        }
        else {
            *next_node = NULL;
        }
    }
    else {
        *next_byte = current_byte + 1;
        *next_node = current_node;
    }
}

//-------------------------------------------------------//
//usuwanie obiektów
//-------------------------------------------------------//
void RemoveCurrent(NODE_STRUCT** list_node, NODE_STRUCT* current_node, BYTE current_byte);
void RemoveFirst(NODE_STRUCT** list_node) {
    if (*list_node != NULL) {
        (*list_node)->use--;
        if ((*list_node)->use == 0) {
            NODE_STRUCT* tmp = *list_node;
            *list_node = tmp->next;
            DeleteNode(tmp);
        }
        else {
            for (int i = 0; i < (*list_node)->use + 1; i++) {
                *((*list_node)->object + i) = *((*list_node)->object + i + 1);
            }
        }
    }
}
void RemovePrev(NODE_STRUCT** list_node, NODE_STRUCT* current_node, BYTE current_byte)
{

    if (*list_node == current_node) {
        if (current_byte != 0) {
            RemoveCurrent(list_node, current_node, current_byte - 1);
        }
    }
    else {
        if (current_byte == 0) {
            NODE_STRUCT* iterator = *list_node;
            while (iterator->next != current_node) iterator = iterator->next;
            RemoveCurrent(list_node, iterator, iterator->use - 1);
        }
        else {
            RemoveCurrent(list_node, current_node, current_byte - 1);
        }
    }
}
void RemoveCurrent(NODE_STRUCT** list_node, NODE_STRUCT* current_node, BYTE current_byte)
{
    if (*list_node != NULL) {
        NODE_STRUCT* tmp = *list_node;
        current_node->use--;
        if (current_node->use == 0) {
            if (*list_node != current_node)
            {
                while ((*list_node)->next != current_node) *list_node = (*list_node)->next;
                (*list_node)->next = current_node->next;
                *list_node = tmp;
                DeleteNode(current_node);
            }
            else {
                if ((*list_node)->next != NULL)*list_node = (*list_node)->next;
                else *list_node = NULL;
                DeleteNode(tmp);
            }
        }
        else {
            for (int i = current_byte; i < current_node->use; i++) {
                *(current_node->object + i) = *(current_node->object + i + 1);
            }
        }
    }
}
void RemoveNext(NODE_STRUCT* node_list, NODE_STRUCT* current_node, BYTE current_byte)
{
    if (node_list == current_node) {
        if (current_byte == current_node->use - 1) {
            NODE_STRUCT** head = &node_list;
            *head = node_list;
            if ((*head)->next != NULL)RemoveCurrent(head, (*head)->next, 0);
        }
        else {
            NODE_STRUCT** head = &node_list;
            *head = node_list;
            RemoveCurrent(head, current_node, current_byte + 1);
        }
    }
    else {
        if (current_byte == current_node->use - 1) {
            NODE_STRUCT** head = &node_list;
            *head = node_list;
            if (current_node->next != NULL)RemoveCurrent(head, current_node->next, 0);
        }
        else {
            NODE_STRUCT** head = &node_list;
            *head = node_list;
            RemoveCurrent(head, current_node, current_byte + 1);
        }
    }
}
void RemoveLast(NODE_STRUCT** list_node) {
    if (*list_node != NULL) {
        NODE_STRUCT** head;
        BYTE last_byte = 0;
        GetLast(*list_node, head, &last_byte);
        if(*head!=NULL)RemoveCurrent(list_node, *head, last_byte);
    }
}
//-------------------------------------------------------//
//wstawianie obiektów
//-------------------------------------------------------//
void InsertPrev(NODE_STRUCT** list_node, NODE_STRUCT* current_node, BYTE current_byte, OBJECT_TYPE* inserted_object)
{   
    if (*list_node != NULL) {
        if (current_byte == 0) {
            if (current_node == *list_node && current_node->use == SIZE) {
                NODE_STRUCT* inserted_node = NewNode();
                inserted_node->next = *list_node;
                *list_node = inserted_node;
                inserted_node->use++;
                *(inserted_node->object) = *inserted_object;
            }
            else if (current_node == *list_node && current_node->use < SIZE) {
                current_node->use++;
                for (int i = current_node->use - 1; i > 0; i--) {
                    *(current_node->object + i) = *(current_node->object + i - 1);
                    *current_node->object = *inserted_object;
                }
            }
            else if (current_node != *list_node){
                NODE_STRUCT* tmp = *list_node;
                while ((*list_node)->next != current_node)*list_node = (*list_node)->next;
                if (current_node->use == SIZE) {
                    if ((*list_node)->use == SIZE) {
                        NODE_STRUCT* inserted_node = NewNode();
                        inserted_node->next = current_node;
                        (*list_node)->next = inserted_node;
                        inserted_node->use++;
                        *(inserted_node->object) = *inserted_object;
                        
                    }
                    else{
                        (*list_node)->use++;
                        *((*list_node)->object + (*list_node)->use - 1) = *inserted_object;
                    }
                }
                else {
                    current_node->use++;
                    for (int i = current_node->use - 1; i > 0; i--) {
                        *(current_node->object + i) = *(current_node->object + i - 1);
                    }
                    *current_node->object = *inserted_object;
                    
                }
                *list_node = tmp;
            }
        }
        else {
            if (current_node == *list_node) {
                if (current_node->use == SIZE) {
                    NODE_STRUCT* inserted_node = NewNode();
                    inserted_node->use++;
                    *(inserted_node->object) = *((*list_node)->object);
                    for (int i = 0; i < current_byte - 1; i++) {
                        *((*list_node)->object + i) = *((*list_node)->object + i + 1);
                    }
                    *((*list_node)->object + current_byte - 1) = *inserted_object;
                    inserted_node->next = *list_node;
                    *list_node = inserted_node;
                    current_node = inserted_node->next;
                }
                else {
                    current_node->use++;
                    for (int i = current_node->use - 1; i > current_byte; i--) {
                        *(current_node->object + i) = *(current_node->object + i - 1);
                    }
                    *(current_node->object + current_byte) = *(inserted_object);
                }
            }
            else {
                NODE_STRUCT* tmp = *list_node;
                while ((*list_node)->next != current_node)*list_node = (*list_node)->next;
                if (current_node->use == SIZE) {
                    if ((*list_node)->use == SIZE) {
                        NODE_STRUCT* inserted_node = NewNode();
                        inserted_node->use++;
                        *(inserted_node->object) = *(current_node->object);
                        for (int i = 0; i < current_byte - 1; i++) {
                            *(current_node->object + i) = *(current_node->object + i + 1);
                        }
                        *(current_node->object + current_byte - 1) = *inserted_object;
                        inserted_node->next = current_node;
                        (*list_node)->next = inserted_node;
                        *list_node = tmp;
                    }
                    else {
                        (*list_node)->use++;
                        *((*list_node)->object + (*list_node)->use - 1) = *(current_node->object);
                        for (int i = 0; i < current_byte - 1; i++) {
                            *(current_node->object + i) = *(current_node->object + i + 1);
                        }
                        *((*list_node)->object + (*list_node)->use - 1) = *(current_node->object);
                        *(current_node->object + current_byte - 1) = *inserted_object;
                    }
                }
                else {
                    current_node->use++;
                    for (int i = current_node->use - 1; i > current_byte; i--) {
                        *(current_node->object + i) = *(current_node->object + i - 1);
                    }
                    *(current_node->object + current_byte) = *inserted_object;

                }
            }
        }

    }

    else {
        AddFirst(list_node, inserted_object);
    }
}
void InsertNext(NODE_STRUCT* list_node, NODE_STRUCT* current_node, BYTE current_byte, OBJECT_TYPE* inserted_object)
{
    if (list_node != NULL) {
        if (current_byte == current_node->use - 1) {
            if (current_node->use == SIZE) {
                if (current_node->next != NULL) {
                    if (current_node->next->use == SIZE) {
                        NODE_STRUCT* inserted_node = NewNode();
                        inserted_node->use++;
                        *(inserted_node->object) = *inserted_object;
                        inserted_node->next = current_node->next;
                        current_node->next = inserted_node;
                    }
                    else
                    {
                        if (current_node->next != NULL) {
                            current_node->next->use++;
                            for (int i = current_node->next->use - 1; i > 0; i--) {
                                *(current_node->next->object + i) = *(current_node->next->object + i - 1);
                            }
                            *(current_node->next->object) = *(inserted_object);
                        }
                    }
                }
            }
            else {
                current_node->use++;
                *(current_node->object + current_node->use - 1) = *inserted_object;
            }
        }
        else {
            while (list_node != current_node)list_node = list_node->next;
            if (current_node->use == SIZE) {
                if (current_node->next != NULL) {
                    if (current_node->next->use == SIZE) {
                        NODE_STRUCT* inserted_node = NewNode();
                        inserted_node->use++;
                        *(inserted_node->object) = *(current_node->object + current_node->use - 1);
                        for (int i = current_node->use - 1; i > current_byte + 1; i--) {
                            *(current_node->object + i) = *(current_node->object + i - 1);
                        }
                        *(current_node->object + current_byte + 1) = *inserted_object;
                        inserted_node->next = current_node->next;
                        current_node->next = inserted_node;
                    }
                    else {
                        current_node->next->use++;
                        for (int i = current_node->next->use - 1; i > 0; i--) {
                            *(current_node->next->object + i) = *(current_node->next->object + i - 1);
                        }
                        *(current_node->next->object) = *(current_node->object + current_node->use - 1);
                        for (int i = current_node->use - 1; i > current_byte + 1; i--) {
                            *(current_node->object + i) = *(current_node->object + i - 1);
                        }
                        *(current_node->object + current_byte + 1) = *inserted_object;
                    }
                }
                else {
                    NODE_STRUCT* inserted_node = NewNode();
                    inserted_node->use++;
                    *(inserted_node->object) = *(current_node->object + current_node->use - 1);
                    for (int i = current_node->use - 1; i > current_byte + 1; i--) {
                        *(current_node->object + i) = *(current_node->object + i - 1);
                    }
                    *(current_node->object + current_byte + 1) = *inserted_object;
                    current_node->next = inserted_node;
                }
            }
            else {
                current_node->use++;
                for (int i = current_node->use - 1; i > current_byte + 1; i--) {
                    *(current_node->object + i) = *(current_node->object + i - 1);
                }
                *(current_node->object + current_byte + 1) = *(inserted_object);
            }
        }
    }
}
//-------------------------------------------------------//
//działania dodatkwoe
//-------------------------------------------------------//
void Find(NODE_STRUCT* list_node, OBJECT_TYPE* search, NODE_STRUCT** found, BYTE* found_byte)
{
    if (list_node == NULL) {
        *found = NULL;
    }
    else {
        bool flag = false;
        NODE_STRUCT* tmp = list_node;
        while (true) {
            for (int i = 0; i < list_node->use; i++) {
                if (*(list_node->object + i) == *search) {
                    *found = list_node;
                    *found_byte = i;
                    flag = true;
                    break;
                }
            }
            if (flag == true)break;
            if (list_node->next == NULL) {
                *found = NULL;
                break;
            }
            list_node = list_node->next;

        }
        list_node = tmp;
    }
}
void Compress(NODE_STRUCT* list_node)
{
    if (list_node != NULL) {
        NODE_STRUCT* new_first = NewNode();
        NODE_STRUCT** new_head = &new_first;
        *new_head = new_first;
        NODE_STRUCT* tmp_head = *new_head;
        NODE_STRUCT* tmp = list_node;
        while (list_node != NULL) {
            int i = 0;
            while (i != list_node->use) {
                AddLast(new_head, (list_node->object + i));
                i++;
            }
            list_node = list_node->next;
        }
        *new_head = tmp_head;
        list_node = tmp;
        while ((*new_head) != NULL) {
            list_node->use = (*new_head)->use;
            for (int i = 0; i < (*new_head)->use; i++) {
                *(list_node->object + i) = *((*new_head)->object + i);
            }
            if ((*new_head)->next != NULL) {
                list_node = list_node->next;
            }
            (*new_head) = ((*new_head)->next);
        }
        NODE_STRUCT* cpy = list_node->next;
        list_node->next = NULL;
        list_node = cpy;
        Clear(&list_node);
        list_node = tmp;
        *new_head = tmp_head;
        Clear(new_head);
    }
}
void Reverse(NODE_STRUCT* list_node)
{
    if (list_node != NULL) {
        NODE_STRUCT* temp_list = NewNode();
        NODE_STRUCT* temp_list_swap = temp_list;
        NODE_STRUCT* list_node_swap = list_node;
            while (list_node != NULL)
            {
                temp_list->use = list_node->use;
                for (int i = 0; i < list_node->use; i++) {
                    *(temp_list->object + i) = *(list_node->object + i);
            }
                if (list_node->next != NULL) {
                    temp_list->next = NewNode();
                    temp_list = temp_list->next;
                }
                list_node = list_node->next;
            }
            temp_list = temp_list_swap;
            list_node = list_node_swap;

        //obracanie
            NODE_STRUCT* new_start = NULL;
            NODE_STRUCT* tmp;
            while (temp_list != NULL) {
                tmp = temp_list->next;
                temp_list->next = new_start;
                new_start = temp_list;
                temp_list = tmp;
            }
            temp_list = new_start;
        //
        while (temp_list != NULL) {
            for (int i = 0; i < temp_list->use / 2; i++) {
                OBJECT_TYPE swap = *(temp_list->object + i);
                *(temp_list->object + i) = *(temp_list->object + temp_list->use - 1 - i);
                *(temp_list->object + temp_list->use - 1 - i) = swap;
            }
            temp_list = temp_list->next;
        }
        temp_list = new_start;
        while (temp_list != NULL) {
            list_node->use = temp_list->use;
            for (int i = 0; i < temp_list->use; i++) {
                *(list_node->object + i) = *(temp_list->object + i);
            }
            list_node = list_node->next;
            temp_list = temp_list->next;
        }
        temp_list = new_start;
        list_node = list_node_swap;
        Clear(&temp_list);
        Compress(list_node);
    }
}
