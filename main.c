#include <allegro5/allegro.h>						
#include <allegro5/allegro_image.h>					
#include <stdio.h>									
#include <allegro5/allegro_acodec.h>				
#include <allegro5/allegro_audio.h>					


int main()
{
	bool left_button_down = false;

	ALLEGRO_DISPLAY* display;
	ALLEGRO_BITMAP* cursor;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_SAMPLE* sample;
	ALLEGRO_EVENT event;
	ALLEGRO_BITMAP* blockbackline;
	ALLEGRO_BITMAP* leveldesign;
	ALLEGRO_BITMAP* arrow;
	ALLEGRO_BITMAP* premenu;
	ALLEGRO_BITMAP* menu;
	ALLEGRO_BITMAP* levelmenu;


	ALLEGRO_BITMAP* blocke1;
	ALLEGRO_BITMAP* blocke2;
	ALLEGRO_BITMAP* blocke3;

	ALLEGRO_BITMAP* blockm1;
	ALLEGRO_BITMAP* blockm2;
	ALLEGRO_BITMAP* blockm3;
	ALLEGRO_BITMAP* blockm4;

	ALLEGRO_BITMAP* blockh1;
	ALLEGRO_BITMAP* blockh2;
	ALLEGRO_BITMAP* blockh3;
	ALLEGRO_BITMAP* blockh4;
	ALLEGRO_BITMAP* blockh5;


	int mx = 0;
	int my = 0;

	int blocke1x = 50;
	int blocke1y = 100;
	int blocke2x = 690;
	int blocke2y = 250;
	int blocke3x = 670;
	int blocke3y = 450;

	int blockm1x = 30;
	int blockm1y = 170;
	int blockm2x = 30;
	int blockm2y = 320;
	int blockm3x = 700;
	int blockm3y = 170;
	int blockm4x = 700;
	int blockm4y = 530;

	int blockh1x = 100;
	int blockh1y = 70;
	int blockh2x = 100;
	int blockh2y = 550;
	int blockh3x = 350;
	int blockh3y = 40;
	int blockh4x = 670;
	int blockh4y = 170;
	int blockh5x = 670;
	int blockh5y = 430;

	int piece = 100;

	int echeck = 0;
	int mcheck = 0;
	int hcheck = 0;

	int heldblock1 = 0;
	int heldblock2 = 0;
	int heldblock3 = 0;
	int heldblock4 = 0;
	int heldblock5 = 0;

	int heldwelcome = 0;
	int heldlevel = 0;

	int easy = 0;
	int medium = 0;
	int hard = 0;
	int levels = 0;
	int welcome = 0;
	int matrix = 1;

	if (!al_init())
	{
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	al_install_mouse();
	al_install_keyboard();
	al_init_image_addon();
	al_install_audio();
	al_init_acodec_addon();

	display = al_create_display(900, 800);
	if (!display)
	{
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}

	al_hide_mouse_cursor(display);

	blocke1 = al_load_bitmap("files/easya.png");
	if (!blocke1)
	{
		fprintf(stderr, "Error loading easy block 1!\n");
	}

	blocke2 = al_load_bitmap("files/easyb.png");
	if (!blocke2)
	{
		fprintf(stderr, "Error loading easy block 2!\n");
	}

	blocke3 = al_load_bitmap("files/easyc.png");
	if (!blocke3)
	{
		fprintf(stderr, "Error loading easy block 3!\n");
	}

	blockm1 = al_load_bitmap("files/mediuma.png");
	if (!blocke1)
	{
		fprintf(stderr, "Error loading medium block 1!\n");
	}

	blockm2 = al_load_bitmap("files/mediumb.png");
	if (!blocke2)
	{
		fprintf(stderr, "Error loading medium block 2!\n");
	}

	blockm3 = al_load_bitmap("files/mediumc.png");
	if (!blocke3)
	{
		fprintf(stderr, "Error loading medium block 3!\n");
	}

	blockm4 = al_load_bitmap("files/mediumd.png");
	if (!blocke1)
	{
		fprintf(stderr, "Error loading medium block 4!\n");
	}

	blockh1 = al_load_bitmap("files/harda.png");
	if (!blockh1)
	{
		fprintf(stderr, "Error loading hard block 1!\n");
	}

	blockh2 = al_load_bitmap("files/hardb.png");
	if (!blockh2)
	{
		fprintf(stderr, "Error loading hard block 2!\n");
	}

	blockh3 = al_load_bitmap("files/hardc.png");
	if (!blockh3)
	{
		fprintf(stderr, "Error loading hard block 3!\n");
	}

	blockh4 = al_load_bitmap("files/hardd.png");
	if (!blockh4)
	{
		fprintf(stderr, "Error loading hard block 4!\n");
	}

	blockh5 = al_load_bitmap("files/harde.png");
	if (!blockh5)
	{
		fprintf(stderr, "Error loading hard block 5!\n");
	}

	if (!al_install_audio())
	{
		fprintf(stderr, "failed to initialize audio!\n");
		return -1;
	}
	if (!al_init_acodec_addon())
	{
		fprintf(stderr, "failed to initialize audio codecs!\n");
		return -1;
	}

	if (!al_reserve_samples(1))
	{
		fprintf(stderr, "failed to reserve samples!\n");
		return -1;
	}

	sample = al_load_sample("files/undertale.mp3");

	if (!sample)
	{
		printf("Audio clip sample not loaded!\n");
		return -1;
	}

	al_hide_mouse_cursor(display);
	leveldesign = al_load_bitmap("files/main.png");
	if (!leveldesign)
	{
		fprintf(stderr, "Error loading leveldesign!\n");
	}

	premenu = al_load_bitmap("files/matrix.png");
	if (!premenu)
	{
		fprintf(stderr, "Error loading premenu!\n");
	}

	menu = al_load_bitmap("files/welcome.png");
	if (!menu)
	{
		fprintf(stderr, "Error loading menu!\n");
	}

	levelmenu = al_load_bitmap("files/levels.png");
	if (!levelmenu)
	{
		fprintf(stderr, "Error loading levelmenu!\n");
	}

	arrow = al_load_bitmap("files/ok.png");
	if (!arrow)
	{
		fprintf(stderr, "Error loading leveldesign!\n");
	}

	blockbackline = al_load_bitmap("files/blockbackline.png");
	if (!blockbackline)
	{
		fprintf(stderr, "Error loading blockbackline!\n");
	}

	cursor = al_load_bitmap("files/cursor.png");
	if (!cursor)
	{
		fprintf(stderr, "Error loading cursor!\n");
	}


	queue = al_create_event_queue();
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));

	while (1)
	{
		if (matrix == 1)
		{


			al_draw_bitmap(premenu, 0, 0, 0);
			al_draw_bitmap(cursor, mx, my, 0);

			if (560 <= mx && 800 >= mx && 490 <= my && 695 >= my)
			{
				if (left_button_down)
				{
					goto done;
				}
			}

			if (100 <= mx && 345 >= mx && 490 <= my && 695 >= my)
			{
				if (left_button_down)
				{
					matrix = 0;
					welcome = 1;
				}
			}

			al_flip_display();
		}


		if (welcome == 1)
		{
			al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			al_draw_bitmap(menu, 0, 0, 0);
			al_draw_bitmap(cursor, mx, my, 0);


			if (470 <= mx && 715 >= mx && 330 <= my && 410 >= my)
			{
				if (left_button_down)
				{
					levels = 1;
					welcome = 0;
					heldwelcome = 1;
				}
			}

			al_flip_display();
		}

		if (levels)
		{
			if (!left_button_down)
			{
				heldwelcome = 0;
			}


			blocke1x = 30;
			blocke1y = 200;
			blocke2x = 670;
			blocke2y = 150;
			blocke3x = 670;
			blocke3y = 450;

			blockm1x = 30;
			blockm1y = 170;
			blockm2x = 30;
			blockm2y = 320;
			blockm3x = 700;
			blockm3y = 170;
			blockm4x = 700;
			blockm4y = 530;

			blockh1x = 100;
			blockh1y = 70;
			blockh2x = 100;
			blockh2y = 550;
			blockh3x = 350;
			blockh3y = 40;
			blockh4x = 670;
			blockh4y = 170;
			blockh5x = 670;
			blockh5y = 430;

			echeck = 0;
			mcheck = 0;
			hcheck = 0;

			al_draw_bitmap(levelmenu, 0, 0, 0);
			al_draw_bitmap(cursor, mx, my, 0);
			if (95 <= mx && 285 >= mx && 330 <= my && 720 >= my)
			{
				if (left_button_down && heldwelcome == 0)
				{
					levels = 0;
					easy = 1;
					heldlevel = 1;
				}
			}

			if (351 <= mx && 545 >= mx && 330 <= my && 720 >= my)
			{
				if (left_button_down && heldwelcome == 0)
				{
					levels = 0;
					medium = 1;

				}
			}
			if (610 <= mx && 804 >= mx && 330 <= my && 720 >= my)
			{
				if (left_button_down && heldwelcome == 0)
				{
					levels = 0;
					hard = 1;
				}
			}
			al_flip_display();
		}

		if (easy == 1)
		{



			if (blocke1x + piece <= mx && blocke1x + (2 * piece) >= mx && blocke1y <= my && blocke1y + (piece * 4) >= my
				|| blocke1x <= mx && blocke1x + piece >= mx && blocke1y <= my && blocke1y + piece >= my)
			{

				if (left_button_down && heldblock2 == 0 && heldblock3 == 0 && heldlevel == 0)
				{
					heldblock1 = 1;
					blocke1x = event.mouse.x - piece - (piece / 2);
					blocke1y = event.mouse.y - (2 * piece);
				}
			}

			if (blocke2x + piece <= mx && blocke2x + (piece * 2) >= mx && blocke2y <= my && blocke2y + (piece * 2) >= my
				|| blocke2x <= mx && blocke2x + (piece * 2) >= mx && blocke2y + piece <= my && blocke2y + (piece * 2) >= my)
			{
				if (left_button_down && heldblock1 == 0 && heldblock3 == 0)
				{
					heldblock2 = 1;
					blocke2x = event.mouse.x - 150;
					blocke2y = event.mouse.y - 150;
				}
			}

			if (blocke3x <= mx && blocke3x + piece >= mx && blocke3y <= my && blocke3y + (piece * 3) >= my
				|| blocke3x + piece <= mx && blocke3x + (piece * 2) >= mx && blocke3y + piece <= my && blocke3y + (piece * 2) >= my)
			{
				if (left_button_down && heldblock2 == 0 && heldblock1 == 0)
				{
					heldblock3 = 1;
					blocke3x = event.mouse.x - 100;
					blocke3y = event.mouse.y - 150;
				}
			}

			if (400 - 10 <= blocke1x && blocke1x <= 400 + 10 && 200 - 10 <= blocke1y && blocke1y <= 200 + 10
				&& 300 - 10 <= blocke2x && blocke2x <= 300 + 10 && 400 - 10 <= blocke2y && blocke2y <= 400 + 10
				&& 300 - 10 <= blocke3x && blocke3x <= 300 + 10 && 200 - 10 <= blocke3y && blocke3y <= 200 + 10)
			{
				echeck = 1;
			}
			else
			{
				echeck = 0;
			}

			if (echeck == 1 && 750 <= mx && 830 >= mx && 40 <= my && 100 >= my)
			{
				if (left_button_down)
				{

					easy = 0;
					levels = 1;

				}
			}

			if (!left_button_down)
			{
				heldblock1 = 0;
				heldblock2 = 0;
				heldblock3 = 0;
				heldlevel = 0;
			}

			al_draw_bitmap(leveldesign, 0, 0, 0);
			al_draw_bitmap(arrow, 750, 30, 0);
			al_draw_bitmap(blockbackline, 300, 200, 0);
			al_draw_bitmap(blocke1, blocke1x, blocke1y, 0);
			al_draw_bitmap(blocke2, blocke2x, blocke2y, 0);
			al_draw_bitmap(blocke3, blocke3x, blocke3y, 0);
			al_draw_bitmap(cursor, mx, my, 0);
			al_flip_display();
		}

		if (medium == 1)
		{


			if (blockm1x <= mx && blockm1x + (2 * piece) >= mx && blockm1y <= my && blockm1y + piece >= my)
			{

				if (left_button_down && heldblock2 == 0 && heldblock3 == 0 && heldblock4 == 0)
				{
					heldblock1 = 1;
					blockm1x = event.mouse.x - piece;
					blockm1y = event.mouse.y - (piece / 2);
				}
			}

			if (blockm2x + piece <= mx && blockm2x + (piece * 2) >= mx && blockm2y <= my && blockm2y + (piece * 4) >= my
				|| blockm2x <= mx && blockm2x + piece >= mx && blockm2y + (piece * 2) <= my && blockm2y + (piece * 3) >= my)
			{
				if (left_button_down && heldblock1 == 0 && heldblock3 == 0 && heldblock4 == 0)
				{
					heldblock2 = 1;
					blockm2x = event.mouse.x - piece - (piece / 4);
					blockm2y = event.mouse.y - (piece * 2) - (piece / 2);
				}
			}

			if (blockm3x <= mx && blockm3x + piece >= mx && blockm3y <= my && blockm3y + (piece * 3) >= my)
			{
				if (left_button_down && heldblock2 == 0 && heldblock1 == 0 && heldblock4 == 0)
				{
					heldblock3 = 1;
					blockm3x = event.mouse.x - (piece / 2);
					blockm3y = event.mouse.y - piece - (piece / 2);
				}
			}

			if (blockm4x <= mx && blockm4x + piece >= mx && blockm4y <= my && blockm4y + (piece * 2) >= my)
			{
				if (left_button_down && heldblock2 == 0 && heldblock1 == 0 && heldblock3 == 0)
				{
					heldblock4 = 1;
					blockm4x = event.mouse.x - (piece / 2);
					blockm4y = event.mouse.y - piece;
				}
			}

			if (300 - 10 <= blockm1x && blockm1x <= 300 + 10 && 500 - 10 <= blockm1y && blockm1y <= 500 + 10
				&& 400 - 10 <= blockm2x && blockm2x <= 400 + 10 && 200 - 10 <= blockm2y && blockm2y <= 200 + 10
				&& 300 - 10 <= blockm3x && blockm3x <= 300 + 10 && 200 - 10 <= blockm3y && blockm3y <= 200 + 10
				&& 400 - 10 <= blockm4x && blockm4x <= 400 + 10 && 200 - 10 <= blockm4y && blockm4y <= 200 + 10) 
			{
				mcheck = 1;
			}
			else
			{
				mcheck = 0;
			}

			if (mcheck == 1 && 750 <= mx && 830 >= mx && 40 <= my && 100 >= my)
			{
				if (left_button_down)
				{

					medium = 0;
					levels = 1;

				}
			}

			if (!left_button_down)
			{
				heldblock1 = 0;
				heldblock2 = 0;
				heldblock3 = 0;
				heldblock4 = 0;
				heldlevel = 0;
			}

			al_draw_bitmap(leveldesign, 0, 0, 0);
			al_draw_bitmap(arrow, 750, 30, 0);
			al_draw_bitmap(blockbackline, 300, 200, 0);
			al_draw_bitmap(blockm1, blockm1x, blockm1y, 0);
			al_draw_bitmap(blockm2, blockm2x, blockm2y, 0);
			al_draw_bitmap(blockm3, blockm3x, blockm3y, 0);
			al_draw_bitmap(blockm4, blockm4x, blockm4y, 0);
			al_draw_bitmap(cursor, mx, my, 0);
			al_flip_display();
		}

		if (hard == 1)
		{


			if (blockh1x <= mx && blockh1x + piece >= mx && blockh1y <= my && blockh1y + piece >= my
				|| blockh1x <= mx && blockh1x + piece >= mx && blockh1y + (piece * 2) <= my && blockh1y + (piece * 4) >= my)
			{
				if (left_button_down && heldblock2 == 0 && heldblock3 == 0 && heldblock4 == 0 && heldblock5 == 0)
				{
					heldblock1 = 1;
					blockh1x = event.mouse.x - (piece / 2);
					blockh1y = event.mouse.y - (piece * 3) + (piece / 2);
				}
			}

			if (blockh2x <= mx && blockh2x + piece >= mx && blockh2y <= my && blockh2y + (piece * 2) >= my)
			{
				if (left_button_down && heldblock1 == 0 && heldblock3 == 0 && heldblock4 == 0 && heldblock5 == 0)
				{
					heldblock2 = 1;
					blockh2x = event.mouse.x - (piece / 2);
					blockh2y = event.mouse.y - piece;
				}
			}

			if (blockh3x <= mx && blockh3x + (piece * 2) >= mx && blockh3y <= my && blockh3y + piece >= my)
			{
				if (left_button_down && heldblock2 == 0 && heldblock1 == 0 && heldblock4 == 0 && heldblock5 == 0)
				{
					heldblock3 = 1;
					blockh3x = event.mouse.x - piece;
					blockh3y = event.mouse.y - (piece / 2);
				}
			}

			if (blockh4x <= mx && blockh4x + piece >= mx && blockh4y <= my && blockh4y + piece >= my
				|| blockh4x + piece <= mx && blockh4x + (piece * 2) >= mx && blockh4y + piece <= my && blockh4y + (piece * 2) >= my)
			{
				if (left_button_down && heldblock2 == 0 && heldblock1 == 0 && heldblock3 == 0 && heldblock5 == 0)
				{
					heldblock4 = 1;
					blockh4x = event.mouse.x - (piece / 2);
					blockh4y = event.mouse.y - (piece / 2);
				}
			}

			if (blockh5x <= mx && blockh5x + piece >= mx && blockh5y <= my && blockh5y + piece >= my
				|| blockh5x + piece <= mx && blockh5x + (piece * 2) >= mx && blockh5y + piece <= my && blockh5y + (piece * 2) >= my
				|| blockh5x <= mx && blockh5x + piece >= mx && blockh5y + (piece * 2) <= my && blockh5y + (piece * 3) >= my)
			{
				if (left_button_down && heldblock2 == 0 && heldblock1 == 0 && heldblock3 == 0 && heldblock4 == 0)
				{
					heldblock5 = 1;
					blockh5x = event.mouse.x - (piece / 2);
					blockh5y = event.mouse.y - (piece / 2);
				}
			}

			if (500 - 10 <= blockh1x && blockh1x <= 500 + 10 && 200 - 10 <= blockh1y && blockh1y <= 200 + 10
				&& 300 - 10 <= blockh2x && blockh2x <= 300 + 10 && 300 - 10 <= blockh2y && blockh2y <= 300 + 10
				&& 300 - 10 <= blockh3x && blockh3x <= 300 + 10 && 500 - 10 <= blockh3y && blockh3y <= 500 + 10
				&& 300 - 10 <= blockh4x && blockh4x <= 300 + 10 && 200 - 10 <= blockh4y && blockh4y <= 200 + 10
				&& 400 - 10 <= blockh5x && blockh5x <= 400 + 10 && 200 - 10 <= blockh5y && blockh5y <= 200 + 10)
			{
				hcheck = 1;
			}
			else
			{
				hcheck = 0;
			}

			if (hcheck == 1 && 750 <= mx && 830 >= mx && 40 <= my && 100 >= my)
			{
				if (left_button_down)
				{

					hard = 0;
					levels = 1;

				}
			}

			if (!left_button_down)
			{
				heldblock1 = 0;
				heldblock2 = 0;
				heldblock3 = 0;
				heldblock4 = 0;
				heldblock5 = 0;
				heldlevel = 0;
			}

			al_draw_bitmap(leveldesign, 0, 0, 0);
			al_draw_bitmap(arrow, 750, 30, 0);
			al_draw_bitmap(blockbackline, 300, 200, 0);
			al_draw_bitmap(blockh1, blockh1x, blockh1y, 0);
			al_draw_bitmap(blockh2, blockh2x, blockh2y, 0);
			al_draw_bitmap(blockh3, blockh3x, blockh3y, 0);
			al_draw_bitmap(blockh4, blockh4x, blockh4y, 0);
			al_draw_bitmap(blockh5, blockh5x, blockh5y, 0);
			al_draw_bitmap(cursor, mx, my, 0);
			al_flip_display();
		}

		al_wait_for_event(queue, &event);
		switch (event.type)
		{

		case ALLEGRO_EVENT_MOUSE_AXES:
			mx = event.mouse.x;
			my = event.mouse.y;

		case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
			if (event.mouse.button == 1)
			{
				left_button_down = true;
			}
			break;

		case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
			if (event.mouse.button == 1)
			{
				left_button_down = false;
			}
			break;

		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			goto done;
		}
	}
done:

	al_destroy_event_queue(queue);
	return 0;
}