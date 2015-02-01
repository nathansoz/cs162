/* Author: Nathan Sosnovske
*
* Created: 1/29/15
*
* Edited: 1/29/15
*
* Files: Item.cpp, Item.h, List.cpp, List.h, main.cpp
*
* Overview:
* Menu logic for grocery list program.
*
* Input:
*  User choice
*
* Output:
*  User choice
*
*/

//library imports
#include <fstream>
#include <iostream>
#include <string>
#include <ncurses.h>
#include <menu.h>
#include <string.h>
#include <form.h>


//custom headers
#include "List.h"
#include "Item.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

//Helper functions to validate user input of numbers



//end helper functions

const char *menuItems[] = {
        "Add Item",
        "Remove Item",
        "Print List",
        "Save List to file",
        "Load list from file",
        "Exit",
};

int main()
{
    List groceryList;
    ITEM **my_items;
    int c;
    MENU *my_menu;
    int n_choices;
    ITEM *cur_item;

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);

    n_choices = ARRAY_SIZE(menuItems);
    my_items = (ITEM**)calloc(n_choices + 1, sizeof(ITEM *));

    for(int i = 0; i < n_choices; i++)
    {
        my_items[i] = new_item(menuItems[i], NULL);
    }
    my_items[n_choices] = (ITEM*)NULL;

    my_menu = new_menu(my_items);
    mvprintw(LINES-2, 0, "F1 to Exit");
    post_menu(my_menu);
    refresh();

    while((c = getch()) != KEY_F(1))
    {
        switch(c)
        {
            case KEY_DOWN:
                menu_driver(my_menu, REQ_DOWN_ITEM);
                break;
            case KEY_UP:
                menu_driver(my_menu, REQ_UP_ITEM);
                break;
            case 10:
            {
                //key_enter doesn't work?
                ITEM *cur;
                cur = current_item(my_menu);
                if(strcmp(item_name(cur), "Add Item") == 0)
                {
                    unpost_menu(my_menu);
                    groceryList.AddItem();
                    clear();
                    mvprintw(LINES-2, 0, "F1 to Exit");
                    post_menu(my_menu);
                    refresh();
                    break;
                }

                if (strcmp(item_name(cur), "Print List") == 0)
                {
                    unpost_menu(my_menu);
                    groceryList.PrintList();
                    clear();
                    mvprintw(LINES-2, 0, "F1 to Exit");
                    post_menu(my_menu);
                    refresh();
                    break;
                }

                if(strcmp(item_name(cur), "Load list from file") == 0)
                {
                    WINDOW* fileDiag;
                    int height = 10;
                    int width = 30;
                    int starty = (LINES - height) / 2;
                    int startx = (COLS - width) / 2;

                    fileDiag = newwin(height, width, starty, startx);

                    //WINDOW SETUP

                    wmove(fileDiag, 1, 1);
                    wprintw(fileDiag, "Enter filename: ");

                    FIELD *field[2];
                    FORM *load_form;
                    field[0] = new_field(1, 50, 3, 0, 0, 0);
                    field[1] = NULL;
                    set_field_back(field[0], A_UNDERLINE);
                    field_opts_off(field[0], O_AUTOSKIP);

                    load_form = new_form(field);
                    set_form_win(load_form, fileDiag);
                    set_form_sub(load_form, derwin(fileDiag, 10, 30, 1, 0));
                    box(fileDiag, 0, 0);
                    wrefresh(fileDiag);
                    refresh();
                    keypad(fileDiag, TRUE);
                    post_form(load_form);
                    wrefresh(fileDiag);
                    refresh();

                    int ic;
                    bool quit = false;
                    while((ic = wgetch(fileDiag)) != 27 && !quit) //escape key
                    {
                        switch(ic)
                        {
                            case KEY_DOWN:
                                form_driver(load_form, REQ_NEXT_FIELD);
                                break;
                            case KEY_ENTER:
                                quit = true;
                                break;
                            default:
                                form_driver(load_form, ic);
                                break;
                        }
                    }




                }

                break;


            }

        }
    }

    free_item(my_items[0]);
    free_item(my_items[1]);
    free_menu(my_menu);
    endwin();

    return 0;
}