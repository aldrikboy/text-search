
void settings_page_create()
{
	global_settings_page.active = false;
	global_settings_page.font_small = assets_load_font("data/fonts/mono.ttf", 16);
	global_settings_page.sloth_small_img = assets_load_image("data/imgs/sloth_small.png", true);
	global_settings_page.keyboard = keyboard_input_create();
	global_settings_page.mouse = mouse_input_create();
	
	global_settings_page.btn_close = ui_create_button();
	global_settings_page.textbox_max_file_size = ui_create_textbox(7);
	global_settings_page.textbox_max_thread_count = ui_create_textbox(7);
}

void settings_page_update_render()
{
	if (global_settings_page.active)
	{
		platform_window_make_current(&global_settings_page.window);
		platform_handle_events(&global_settings_page.window, &global_settings_page.mouse, &global_settings_page.keyboard);
		
		glClearColor(255/255.0, 255/255.0, 255/255.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		global_ui_context.layout.active_window = &global_settings_page.window;
		global_ui_context.keyboard = &global_settings_page.keyboard;
		global_ui_context.mouse = &global_settings_page.mouse;
		
		ui_begin(3);
		{
			ui_begin_menu_bar();
			{
				if (ui_push_menu(localize("general")))
				{
					global_settings_page.selected_tab_index = 0;
				}
				if (ui_push_menu(localize("language")))
				{
					global_settings_page.selected_tab_index = 1;
				}
			}
			ui_end_menu_bar();
			
			ui_push_separator();
			
			if (global_settings_page.selected_tab_index == 0)
			{
				ui_block_begin(LAYOUT_HORIZONTAL);
				{
					ui_push_text(localize("max_file_size"));
					ui_push_text(localize("zero_for_no_limit"));
				}
				ui_block_end();
				ui_block_begin(LAYOUT_HORIZONTAL);
				{
					if (ui_push_textbox(&global_settings_page.textbox_max_file_size, "0"))
					{
						keyboard_set_input_mode(&global_settings_page.keyboard, INPUT_NUMERIC);
					}
					ui_push_text("KB");
				}
				ui_block_end();
				
				global_ui_context.layout.offset_y += 10;
				
				ui_block_begin(LAYOUT_HORIZONTAL);
				{
					ui_push_text(localize("max_threads"));
					ui_push_text(localize("zero_for_no_limit"));
				}
				ui_block_end();
				ui_block_begin(LAYOUT_HORIZONTAL);
				{
					if (ui_push_textbox(&global_settings_page.textbox_max_thread_count, "0"))
					{
						keyboard_set_input_mode(&global_settings_page.keyboard, INPUT_NUMERIC);
					}
					ui_push_text("Threads");
				}
				ui_block_end();
			}
			
			global_ui_context.layout.offset_y = global_settings_page.window.height - 33;
			
			ui_block_begin(LAYOUT_HORIZONTAL);
			{
				if (ui_push_button(&global_settings_page.btn_close, localize("close")))
				{
					global_settings_page.active = false;
					settings_page_hide();
					return;
				}
				if (ui_push_button(&global_settings_page.btn_close, localize("save")))
				{
					global_settings_page.max_thread_count = string_to_s32(global_settings_page.textbox_max_thread_count.buffer);
					global_settings_page.max_file_size = string_to_s32(global_settings_page.textbox_max_file_size.buffer);
					
					global_settings_page.active = false;
					settings_page_hide();
					return;
				}
			}
			ui_block_end();
		}
		ui_end();
		
		if (!global_settings_page.window.is_open)
		{
			global_settings_page.active = false;
			settings_page_hide();
			return;
		}
		
		platform_window_swap_buffers(&global_settings_page.window);
	}
}

void settings_page_show()
{
	if (global_settings_page.max_thread_count != 0)
		sprintf(global_settings_page.textbox_max_thread_count.buffer, "%d",global_settings_page.max_thread_count);
	
	if (global_settings_page.max_file_size != 0)
		sprintf(global_settings_page.textbox_max_file_size.buffer, "%d", global_settings_page.max_file_size);
	
	global_settings_page.window = platform_open_window("Text-search settings", 450, 250, 450, 450);
	global_settings_page.active = true;
	global_settings_page.selected_tab_index = 0;
	platform_set_icon(&global_settings_page.window, global_settings_page.sloth_small_img);
}

void settings_page_hide()
{
	if (global_settings_page.window.display)
	{
		platform_close_window(&global_settings_page.window);
		global_settings_page.window.display = 0;
		global_settings_page.window.window = 0;
	}
}

void settings_page_destroy()
{
	keyboard_input_destroy(&global_settings_page.keyboard);
	ui_destroy_textbox(&global_settings_page.textbox_max_file_size);
	ui_destroy_textbox(&global_settings_page.textbox_max_thread_count);
	assets_destroy_font(global_settings_page.font_small);
	assets_destroy_image(global_settings_page.sloth_small_img);
}