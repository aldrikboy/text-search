#ifndef INCLUDE_PLATFORM
#define INCLUDE_PLATFORM

typedef struct t_platform_window platform_window;

typedef struct t_file_content
{
	s64 content_length;
	void *content;
} file_content;

typedef enum t_time_type
{
	TIME_FULL,     // realtime
	TIME_THREAD,   // run time for calling thread
	TIME_PROCESS,  // run time for calling process
} time_type;

typedef enum t_time_precision
{
	TIME_NS, // nanoseconds
	TIME_US, // microseconds
	TIME_MS, // miliseconds
	TIME_S,  // seconds
} time_precision;

typedef struct t_cpu_info
{
	s32 model;
	char model_name[255];
	float32 frequency;
	u32 cache_size;
	u32 cache_alignment;
} cpu_info;

typedef enum t_file_dialog_type
{
	OPEN_FILE,
	OPEN_DIRECTORY,
} file_dialog_type;

platform_window platform_open_window(char *name, u16 width, u16 height);
void platform_close_window(platform_window *window);
void platform_handle_events(platform_window *window, mouse_input *mouse, keyboard_input *keyboard);
void platform_window_swap_buffers(platform_window *window);
file_content platform_read_file_content(char *path, const char *mode);
void platform_destroy_file_content(file_content *content);
bool get_active_directory(char *buffer);
bool set_active_directory(char *path);
void platform_list_files(array *list, char *start_dir, bool recursive);
void platform_open_file_dialog(file_dialog_type type, char *buffer);

u64 platform_get_time(time_type time_type, time_precision precision);
s32 platform_get_memory_size();
s32 platform_get_cpu_count();
cpu_info platform_get_cpu_info();

#endif