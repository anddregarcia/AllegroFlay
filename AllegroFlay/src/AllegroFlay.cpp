#include <iostream>
#include <signal.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_primitives.h>

#include "iostream"

using namespace std;

enum KEYS {UP, DOWN, LEFT, RIGHT};

int firstProgram(void)
{
    ALLEGRO_DISPLAY *display = NULL;

    if(!al_init())
    {
        al_show_native_message_box(NULL, NULL, NULL, "Failed to initialize allegro", NULL, NULL);
        return -1;
    }

    display = al_create_display(640, 480);

    if(!display)
    {
        al_show_native_message_box(NULL, NULL, NULL, "Failed to initialize display", NULL, NULL);
        return -1;
    }

    al_clear_to_color(al_map_rgb(255,150,255));
    al_flip_display();
    al_rest(5.0);
    al_destroy_display(display);

    al_show_native_message_box(NULL,
                               "Primeiro programa",
                               "Bem vindo",
                               "All is right",
                               NULL,
                               0);

    if(al_show_native_message_box(NULL,
                                  "Primeiro programa",
                                  "Bem vindo",
                                  "Será aberta outra janela!",
                                  NULL,
                                  0)==1)
    {
        if(al_show_native_message_box(NULL,
                                  "Primeiro programa",
                                  "Bem vindo",
                                  "Finalizar?!",
                                  NULL,
                                  ALLEGRO_MESSAGEBOX_YES_NO) != 2)
          {
                return 0;
          }
          else
          {
                al_show_native_message_box(NULL,
                      "Primeiro programa",
                      "Bem vindo",
                      "Encerrando!",
                      NULL,
                      ALLEGRO_MESSAGEBOX_ERROR);
          }
    }
}

int secondProgram(void)
{

    ALLEGRO_DISPLAY *display = NULL;

    if(!al_init())
    {
        al_show_native_message_box(NULL, NULL, NULL, "Failed to initialize allegro", NULL, NULL);
        return -1;
    }

    display = al_create_display(640, 480);

    if(!display)
    {
        al_show_native_message_box(NULL, NULL, NULL, "Failed to initialize display", NULL, NULL);
        return -1;
    }

    al_init_font_addon();
    al_init_ttf_addon();

    ALLEGRO_FONT *font = al_load_font("cactus.ttf", 24, 0);
    ALLEGRO_FONT *font_2 = al_load_font("cactus.ttf", 36, 0);
    ALLEGRO_FONT *font_3 = al_load_font("cactus.ttf", 18, 0);

    al_clear_to_color(al_map_rgb(0,0,0));

    al_draw_text(font, al_map_rgb(255,0,25), 50, 50, 0, "Hello World, teste fonte");
    al_draw_text(font_2, al_map_rgb(255,0,25), 640 / 2, 480 / 2, ALLEGRO_ALIGN_CENTER, "Hello World, teste fonte");
    al_draw_text(font_3, al_map_rgb(255,0,25), 640 / 2, 480 - 100, ALLEGRO_ALIGN_LEFT, "Hello World, teste fonte");

    int screen_w = al_get_display_width(display);
    int screen_h = al_get_display_height(display);

    al_draw_textf(font_3, al_map_rgb(255,255,255), 380, 400, ALLEGRO_ALIGN_CENTER,
                  "teste ");

    al_flip_display();

    al_rest(5.0);

    al_destroy_display(display);

}

int thirdProgram(void)
{
    int width = 640;
    int height = 480;

    ALLEGRO_DISPLAY *display = NULL;

    if(!al_init())
        return -1;

    cout << "Allegro starts";

    display = al_create_display(width, height);

    if(!display)
        return -1;

    cout << "Display created";

    al_init_primitives_addon();

    al_draw_pixel(100, 100, al_map_rgb(255, 0, 0));
    al_draw_line(100, 100, width - 100, 100,  al_map_rgb(255, 0, 0), 1);
    al_draw_line(50, 200, width - 50, 200, al_map_rgb(0, 0, 255), 5);
    al_draw_line(0, 300, width, 300, al_map_rgb(255, 0, 255), 10);
    al_draw_line(50, 50, 50, 400, al_map_rgb(0, 255, 0), 3);
    al_draw_line(50, 200, width - 50, 400, al_map_rgb(0, 0, 255), 5);

    al_draw_triangle(10, 200, 100, 10, 190, 200, al_map_rgb(255, 0, 255), 5);
    al_draw_filled_triangle(10, 200, 100, 10, 190, 200, al_map_rgb(255, 0, 255));

    al_draw_rectangle(10, 10, 250, 250, al_map_rgb(255, 0, 255), 5);
    al_draw_rounded_rectangle(width - 200, 10, width - 10, 50, 5, 5, al_map_rgb(0, 0, 255), 15);
    al_draw_filled_rectangle(10, 280, 250, height - 10, al_map_rgb(255, 255, 255));
    al_draw_filled_rounded_rectangle(width - 200, 180, width - 10, height - 10, 10, 5, al_map_rgb(0, 255, 0));

    al_draw_circle(100, 100, 50, al_map_rgb(255, 0, 255), 7);
    al_draw_filled_circle(400, 400, 70, al_map_rgb(255, 255, 255));

    al_draw_ellipse(150, 100, 100, 50, al_map_rgb(127, 3, 34), 6);
    al_draw_filled_ellipse(400, 250, 100, 200, al_map_rgb(0, 255, 255));

    float points[] = {0, 0, 0, 400, 100, 50, 500, width, height};
    al_draw_spline(points, al_map_rgb(255, 0, 255), 1);

    float points2[] = {0, height, 200, 100, 400, 200, width, height};
    al_draw_spline(points2, al_map_rgb(0, 255, 0), 3);

    al_flip_display();

    al_rest(2.0);

    al_destroy_display(display);

    return 0;
}

int fourthProgram(void)
{
    int width = 640;
    int height = 480;
    bool done = false;
    int pos_x = width / 2;
    int pos_y = height / 2;

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;

    if(!al_init())
        return -1;

    cout << "Allegro starts";

    display = al_create_display(width, height);

    if(!display)
        return -1;


    al_init_primitives_addon();
    al_install_keyboard();

    event_queue = al_create_event_queue();

    al_register_event_source(event_queue, al_get_keyboard_event_source());

    while(!done)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(ev.keyboard.keycode)
            {

            case ALLEGRO_KEY_U:
                pos_y -= 10;
                break;
            case ALLEGRO_KEY_DOWN:
                pos_y += 10;
                break;
            case ALLEGRO_KEY_LEFT:
                pos_x -= 10;
                break;
            case ALLEGRO_KEY_RIGHT:
                pos_x += 10;
                break;
            }
        }

        if(ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                done == true;
        }

        al_draw_filled_rectangle(pos_x, pos_y, pos_x + 30, pos_y + 30, al_map_rgb(255, 0, 255));
        al_flip_display();
        al_clear_to_color(al_map_rgb(0, 0, 0)); //clear
    }

    al_destroy_display(display);
}

int fifthProgram(void)
{
    int width = 1024;
    int height = 768;
    bool done = false;
    int pos_x = width / 2;
    int pos_y = height / 2;
    bool keys[4] = {false, false, false, false};

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;

    if(!al_init())
        return -1;

    al_init_primitives_addon();
    al_install_keyboard();

    display = al_create_display(width, height);

    if(!display)
        return -1;

    event_queue = al_create_event_queue();

    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));

    while(!done)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_UP:
                keys[UP] = true;
                break;
            case ALLEGRO_KEY_DOWN:
                keys[DOWN] = true;
                break;
            case ALLEGRO_KEY_RIGHT:
                keys[RIGHT] = true;
                break;
            case ALLEGRO_KEY_LEFT:
                keys[LEFT] = true;
                break;
            }
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            switch(ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_UP:
                keys[UP] = false;
                break;
            case ALLEGRO_KEY_DOWN:
                keys[DOWN] = false;
                break;
            case ALLEGRO_KEY_RIGHT:
                keys[RIGHT] = false;
                break;
            case ALLEGRO_KEY_LEFT:
                keys[LEFT] = false;
                break;
            case ALLEGRO_KEY_ESCAPE:
                done = true;
                break;
            }
        }
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            done = true;
        }

        pos_y -= keys[UP] * 10;
        pos_y += keys[DOWN] * 10;
        pos_x -= keys[LEFT] * 10;
        pos_x += keys[RIGHT] * 10;

        al_draw_filled_rectangle(pos_x, pos_y, pos_x + 30, pos_y + 30, al_map_rgb(255, 0, 255));
        al_flip_display();
        al_clear_to_color(al_map_rgb(0, 0, 0)); //clear
    }

    al_destroy_event_queue(event_queue);
    al_destroy_display(display);

}

int main(void) {

    fifthProgram();

    return 0;
}



