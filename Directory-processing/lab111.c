//pizza bakery 1058998 665 59.99 0.05 15 15 4 180 110 118

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 500
#define MAXLEN 1000

struct Node2 {
    char* value;
    struct Node2* next;
    struct Node2* prev;

}; typedef struct Node2 Node;


typedef struct list2 {
    size_t size;
    Node* head;
    Node* tail;
} list2;

struct CATALOG {
    char name[MAX_NAME];
    Node* section;
    int code;
    int number_of_consignment;
    float price;
    float weight;
    int size[3];
    int was_bought[3];


}; typedef struct CATALOG CTL;

void clear(os)
{
    if (os == 1)
    {
        system("cls");
    }
    else
    {
        system("clear");
    }
}

list2* Create() {
    list2* tmp = (list2*)malloc(sizeof(list2));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
    return tmp;
}

void save(CTL lst[MAXLEN], FILE* df, int size) {
    for (int i = 0; i < size; i++) {
        CTL elm = lst[i];
        char line[MAXLEN];
        if (i != size - 1)
        {
            snprintf(line, sizeof(line), "%s;%s%d;%d;%.3f;%.3f;%d;%d;%d;%d;%d;%d\n",
                        elm.name, elm.section->value, elm.code, elm.number_of_consignment,
                        elm.price, elm.weight, elm.size[0], elm.size[1], elm.size[2],
                        elm.was_bought[0], elm.was_bought[1], elm.was_bought[2]);
        }
        else
        {
            snprintf(line, sizeof(line), "%s;%s%d;%d;%.3f;%.3f;%d;%d;%d;%d;%d;%d\0",
                elm.name, elm.section->value, elm.code, elm.number_of_consignment,
                elm.price, elm.weight, elm.size[0], elm.size[1], elm.size[2],
                elm.was_bought[0], elm.was_bought[1], elm.was_bought[2]);
        }
        

        for (int j = 0; line[j] != '\0'; j++) {
            if (line[j] == '\n') {
                line[j] = ';';
                break;
            }
        }

        fprintf(df, "%s", line);
    }
}
CTL inpup(char s1[MAXLEN], CTL list, list2* lst, char sep[1]) {
    int j = 0;
    char* istr;
    istr = strtok(s1, sep);
    strcpy(list.name, istr);
    istr = strtok(NULL, sep);
    Node* current = lst->head;
    Node* target = NULL;
    while (current != NULL) {
        if (strncmp(current->value, istr, strlen(istr)) == 0) {
            target = current;
        }
        current = current->next;
    }
    list.section = target;
    istr = strtok(NULL, sep);
    list.code = atoi(istr);
    istr = strtok(NULL, sep);
    list.number_of_consignment = atoi(istr);
    istr = strtok(NULL, sep);
    list.price = atof(istr);
    istr = strtok(NULL, sep);
    list.weight = atof(istr);
    for (j = 0; j < 3; j++) {
        istr = strtok(NULL, sep);
        list.size[j] = atoi(istr);
    }
    for (j = 0; j < 3; j++) {
        istr = strtok(NULL, sep);
        list.was_bought[j] = atoi(istr);
    }

    return list;
}

void head()
{
    printf("%s\n", "        Name       |    Section   |   Code   | Consignment |   Price    |    Weight  | Size (x,y,z)  | Was bought (3 days)\n");
    printf("%s\n", "*******************|**************|**********|*************|************|************|***************|*******************");
}

void little_outpup(CTL list) {
    int i, j;
    char temp[MAXLEN];

    strcpy(temp, "          ");
    strncpy(temp, list.section->value, strlen(list.section->value) - 1);
    printf("%3s %15s|%13s |%10i|%13i|%12f|%12f|", " ", list.name, temp, list.code, list.number_of_consignment, list.price, list.weight);
    for (j = 0; j < 3; j++) {
        printf("%4i ", list.size[j]);
    }
    printf("%c", '|');
    for (j = 0; j < 3; j++) {
        printf("%4i ", list.was_bought[j]);
    }
    printf("%s", "| ");
    puts("  ");
}

void outpup(CTL* list, int c) {
    int i, j;
    char temp[MAXLEN];
    head();
    for (i = 0; i < c; i++)
    {
        strcpy(temp, "          ");
        strncpy(temp, list[i].section->value, strlen(list[i].section->value) - 1);
        printf("%3i|%15s|%13s |%10i|%13i|%12f|%12f|", i, list[i].name, temp, list[i].code, list[i].number_of_consignment, list[i].price, list[i].weight);
        for (j = 0; j < 3; j++) {
            printf("%4i ", list[i].size[j]);
        }
        printf("%c", '|');
        for (j = 0; j < 3; j++) {
            printf("%4i ", list[i].was_bought[j]);
        }
        printf("%s", "| ");
        puts("  ");
    }
}

int count_strings(FILE* df) {
    int strs = 0;
    char s1[MAXLEN], ch;
    if (df != NULL) {

        fgets(s1, MAXLEN, df);
        ch = s1[strlen(s1) - 1];

        while (ch == '\n') {
            strs++;
            fgets(s1, MAXLEN, df);
            ch = s1[strlen(s1) - 1];
        }

        strs++;
        return strs;
    }
    else {
        return -1;
    }
}

int delete_mass(CTL* list, char* name, int code, int size) {
    int cnt = 0;
    while (((strcmp(list[cnt].name, name) != 0) || (code != list[cnt].code)) && (cnt != (size - 1))) {
        cnt++;
    }
    if (cnt == (size - 1)) {
        return 0;
    }
    else {
        for (int i = cnt; i < size - 1; i++) {
            list[i] = list[i + 1];
        }
        return 1;
    }
}

void add(list2* list, char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Segmentation error\n");
        return;
    }
    newNode->value = malloc(MAXLEN);
    strcpy(newNode->value, value);
    newNode->prev = NULL;
    newNode->next = list->head;
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    }
    else {
        list->head->prev = newNode;
        list->head = newNode;
    }
    list->size++;
}

CTL edit(CTL card)
{
    int flag_card, flag_field, temp_num;
    char temp_ch[MAXLEN];
    double temp_d[MAXLEN];
    puts("Which field do you want to edit? ");
    puts("1 - name\n 2 - section\n 3 - code\n 4 - number of consignment\n 5 - price\n 6 - weight\n 7 - size\n 8 - was bough\n 9 - << back");
    scanf("%i", &flag_field);
    if (flag_field == 1)
    {
        puts("Put new name: ");
        scanf("%s", card.name);
    }
    else if (flag_field == 2)
    {
        puts("Put new section: ");
        scanf("%s", card.section->value);
    }
    else if (flag_field == 3)
    {
        puts("Put new code: ");
        scanf("%i", &card.code);
    }
    else if (flag_field == 4)
    {
        puts("Put new number of consignment: ");
        scanf("%d", &card.number_of_consignment);
    }
    else if (flag_field == 5)
    {
        puts("Put new price: ");
        scanf("%f", &card.price);
    }
    else if (flag_field == 6)
    {
        puts("Put new weight (kg): ");
        scanf("%f", &card.weight);
    }
    else if (flag_field == 7)
    {
        puts("Put new size (x, y, z separated with spaces): ");
        scanf("%i %i %i", &card.size[0], &card.size[1], &card.size[2]);
    }
    else if (flag_field == 8)
    {
        puts("Put new values how much product was bought in three days (separated with spaces): ");
        scanf("%i %i %i", &card.was_bought[0], &card.was_bought[1], &card.was_bought[2]);
    }
    return card;
}

void find_card(CTL* mass, int flag, int size)
{
    if (flag == 1)
    {
        char temp[MAXLEN];
        int new_flag = -1;
        puts("Put the name you're looking for: ");
        scanf("%s", &temp);
        head();
        for (int i = 0; i < size; i++)
        {
            if (strcmp(temp, mass[i].name) == 0)
            {
                little_outpup(mass[i]);
                new_flag = 0;
            }
        }
        if (new_flag == -1)
        {
            puts("Sorry, nothing has been found :( ");
        }

    }

    else if (flag == 2)
    {
        char temp[MAXLEN];
        int new_flag = -1;
        puts("Put the section you're looking for: ");
        scanf("%s", &temp);
        head();
        for (int i = 0; i < size; i++)
        {
            if (strncmp(temp, mass[i].section->value, strlen(mass[i].section->value) - 1) == 0)
            {
                little_outpup(mass[i]);
                new_flag = 0;
            }
        }
        if (new_flag == -1)
        {
            puts("Sorry, nothing has been found :( ");
        }
    }

    else if (flag == 3)
    {
        int temp, new_flag = -1;
        puts("Put the code you're looking for: ");
        scanf("%i", &temp);
        head();
        for (int i = 0; i < size; i++)
        {
            if (temp == mass[i].code)
            {
                little_outpup(mass[i]);
                new_flag = 0;
            }
        }
        if (new_flag == -1)
        {
            puts("Sorry, nothing has been found :( ");
        }

    }

    else if (flag == 4)
    {
        int temp = 0, new_flag = -1;
        puts("Put the number of consignment you're looking for: ");
        scanf("%i", &temp);
        for (int i = 0; i < size; i++)
        {
            if (temp == mass[i].number_of_consignment)
            {
                little_outpup(mass[i]);
                new_flag = 0;
            }
        }
        if (new_flag == -1)
        {
            puts("Sorry, nothing has been found :( ");
        }

    }

    else if (flag == 5)
    {
        int temp;
        int new_flag = -1;
        puts("Put the price (+- 1 ruble) you're looking for: ");
        scanf("%i", &temp);
        double temp1;
        for (int i = 0; i < size; i++)
        {
            temp1 = mass[i].price;
            int t_int = (int)temp1;
            int t_max_int = temp + 10;
            int t_min_int = temp - 10;
            if ((t_min_int <= t_int) && (t_int <= t_max_int))
            {
                little_outpup(mass[i]);
                new_flag = 0;
            }
        }
        if (new_flag == -1)
        {
            puts("Sorry, nothing has been found :( ");
        }

    }

}

void sort(CTL* mass, int flag, int size)
{
    CTL temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (flag == 1)
            {
                if (mass[i].name > mass[j].name)
                {
                    temp = mass[i];
                    mass[i] = mass[j];
                    mass[j] = temp;

                }
            }

            else if (flag == 2)
            {
                if (mass[i].section > mass[j].section)
                {
                    temp = mass[i];
                    mass[i] = mass[j];
                    mass[j] = temp;

                }
            }

            else if (flag == 3)
            {
                if (mass[i].code > mass[j].code)
                {
                    temp = mass[i];
                    mass[i] = mass[j];
                    mass[j] = temp;
                }
            }

            else if (flag == 4)
            {
                if (mass[i].number_of_consignment > mass[j].number_of_consignment)
                {
                    temp = mass[i];
                    mass[i] = mass[j];
                    mass[j] = temp;

                }
            }

            else if (flag == 5)
            {
                if (mass[i].price > mass[j].price)
                {
                    temp = mass[i];
                    mass[i] = mass[j];
                    mass[j] = temp;

                }
            }

            else if (flag == 6)
            {
                if (mass[i].weight > mass[j].weight)
                {
                    temp = mass[i];
                    mass[i] = mass[j];
                    mass[j] = temp;

                }
            }

            else if (flag == 7)
            {
                if (mass[i].size[0] * mass[i].size[1] * mass[i].size[2] > mass[j].size[0] * mass[j].size[1] * mass[j].size[2])
                {
                    temp = mass[i];
                    mass[i] = mass[j];
                    mass[j] = temp;

                }
            }

            else if (flag == 9)
            {
                if (mass[i].was_bought[0] + mass[i].was_bought[1] + mass[i].was_bought[2] > mass[j].was_bought[0] + mass[j].was_bought[1] + mass[j].was_bought[2])
                {
                    temp = mass[i];
                    mass[i] = mass[j];
                    mass[j] = temp;

                }
            }

        }
    }
}

int main()
{
    FILE* df;
    FILE* categories;
    int strs = 0, i, c_strs, flag = 0, new_flag, os;
    CTL lst[MAXLEN], temp;
    char s1[MAXLEN], new_card[MAXLEN], s2[MAXLEN];
    char* istr;
    list2* category = Create();

    categories = fopen("new_data.csv", "r");
    c_strs = count_strings(categories);
    fclose(categories);

    if (c_strs == 1) {
        puts("The list of sections is empty");
        puts("Do you want to add some?\n 1 - yes\n 2 - no");
        scanf("%i", &flag);
        if (flag == 2)
        {
            puts("Bye-bye!");
            return 0;
        }
        else
        {
            puts("Put all the sections you want to add (separate with spaces):");
            rewind(stdin);
            gets(s2);
            categories = fopen("new_data.csv", "w");
            istr = strtok(s2, " ");
            fputs(istr, categories);
            while (istr != NULL)
            {
                istr = strtok(NULL, " ");
                fputs("\n", categories);
                fputs(istr, categories);
            }

            fclose(categories);

        }
    }

    categories = fopen("new_data.csv", "r");
    for (i = 0; i < c_strs; i++) {
        fgets(s2, MAXLEN, categories);
        if (i != c_strs - 1)
        {
            add(category, s2);
        }
        else
        {
            sprintf(s2, "%s\n", s2);
            add(category, s2);
        }
       
    }
    fclose(categories);

    df = fopen("data.csv", "r");
    strs = count_strings(df);
    fclose(df);

    if (strs != 1)
    {
        df = fopen("data.csv", "r");
        for (i = 0; i < strs; i++) {
            fgets(s1, MAXLEN, df);
            lst[i] = inpup(s1, lst[i], category, ";");
        }
        fclose(df);
    }

    puts("Hi. Please, choose your OS:\n 1 - windows\n 2 - MacOS / Linux");
    scanf("%i", &os);
    clear(os);

    puts("What do you want to do?\n 1 - add one mode card\n 2 - edit some cards\n 3 - search cards\n 4 - delete card\n 5 - sort cards\n 6 - show all cards\n 7 - exit program");
    scanf("%i", &flag);
    clear(os);
    temp = lst[0];

    while (flag != 7)
    {
        rewind(stdin);
        if (flag == 1)
        {
            puts("Put the card (separate fields with spaces) or type '-1' if you want to back to the menu: ");
            gets(new_card);
            if (strcmp(new_card, "-1") != 0)
            {
                temp = inpup(new_card, temp, category, " ");
                strs++;
                lst[strs-1] = temp;
            }

        }
        else if (flag == 2)
        {
            puts("Put the number the card you want to edit (it's in the rightmost column) or type '-1' if you want to back to the menu");
            outpup(lst, strs);
            scanf("%i", &new_flag);
            if (new_flag != -1)
            {
                lst[new_flag] = edit(lst[new_flag]);
                puts("Ready. This is result: ");
                outpup(lst, strs);
            }

        }
        else if (flag == 3)
        {
            puts("What do you want to find?\n 1 - name\n 2 - section\n 3 - code\n 4 - number of consignment\n 5 - price\n 6 - << back");
            scanf("%i", &new_flag);
            if (new_flag != 6)
            {
                find_card(lst, new_flag, strs);
            }

        }
        else if (flag == 4)
        {
            puts("Put the number the card you want to delete (it's in the rightmost column) or type '-1' if you want to back to the menu");
            outpup(lst, strs);
            scanf("%i", &new_flag);
            if (new_flag != -1)
            {
                delete_mass(lst, lst[new_flag].name, lst[new_flag].code, strs);
                strs--;
                puts("Ready. This is result: ");
                outpup(lst, strs);
            }

        }
        else if (flag == 5)
        {
            puts("Which category do you want to sort the list by?");
            puts("1 - name\n 2 - section\n 3 - code\n 4 - number of consignment\n 5 - price\n 6 - weight\n 7 - << back");
            scanf("%i", &new_flag);
            if (new_flag != 7)
            {
                sort(lst, new_flag, strs);
                puts("Result: ");
                outpup(lst, strs);
            }

        }
        else if (flag == 6)
        {
            outpup(lst, strs);
        }
        puts("Do you want to do something more?");
        puts(" 1 - yes\n 2 - no");
        scanf("%i", &flag);
        if (flag == 2)
        {
            flag = 7;
        }
        else if (flag == 1)
        {
            clear(os);
            puts("What do you want to do?\n 1 - add one mode card\n 2 - edit some cards\n 3 - search cards\n 4 - delete card\n 5 - sort cards\n 6 - show all cards\n 7 - exit program");
            scanf("%i", &flag);
        }

        clear(os);
    }
    puts("Do you want to save changes?");
    puts(" 1 - yes\n 2 - no");
    scanf("%i", &flag);
    if (flag == 1)
    {
        df = fopen("data.csv", "w");
        save(lst, df, strs);
        fclose(df);
        puts("Successfully saved");
    }
    clear(os);
    puts("Bye-bye!");
    return 0;

}
